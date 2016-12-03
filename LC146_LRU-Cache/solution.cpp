class LRUCache{
public:
    LRUCache(int capacity) {
        lru_queue.clear();
        key_value_table.clear();
        capacity_ = capacity;
    }
    
    int get(int key) {
        auto it = key_value_table.find(key);
        if (it == key_value_table.end()) return -1;
        // if exist
        int v = it->second.second;
        // erase the list node in the cache
        lru_queue.erase(it->second.first);
        
        // add the key to the font of the list
        lru_queue.emplace_front(key);
        
        // update the table entry
        it->second.first = lru_queue.begin();
        
        // reuturn its value
        return v;
    }
    
    void set(int key, int value) {
        /* search the table first:
                if exist, overwirte and update the queue and the value in the table
                if not exist, check capacity: 
                    if reach max, remove the last enrty in the queue
                    append the key to the queue and add to the table
        */
        auto it = key_value_table.find(key);
        if (it != key_value_table.end()) {
             lru_queue.erase(it->second.first);
        }
        else {
            if (lru_queue.size() == capacity_) {
                key_value_table.erase(lru_queue.back());
                lru_queue.pop_back();
            }
        }
        lru_queue.emplace_front(key);
        key_value_table[key] = {lru_queue.begin(), value};
    }
private:
    typedef unordered_map<int, pair< list<int>::iterator, int>> Table;
    Table key_value_table;
    list<int> lru_queue;
    int capacity_;
};