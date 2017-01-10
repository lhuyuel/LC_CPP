class ZigzagIterator {
public:
    ZigzagIterator(vector<int>& vec1, vector<int>& vec2) {
        count = 0;
        total = vec1.size() + vec2.size();
        v1 = vec1;
        v2 = vec2;
        idxes[0] = idxes[1] = 0;
        if (v1.size() == 0) idxes[0] = -1;
        if (v2.size() == 0) idxes[1] = -1;
     }

    int next() {
        if (hasNext()) {
            int result;
            if (count % 2 == 0)
                result = idxes[0] != -1 ? v1[idxes[0]++] : v2[idxes[1]++];
            else 
                result = idxes[1] != -1 ? v2[idxes[1]++] : v1[idxes[0]++];
                
            ++count;
            if (idxes[0] >= v1.size()) idxes[0] = -1;
            if (idxes[1] >= v2.size()) idxes[1] = -1;
            return result;  
        }
        return -1;
    }

    bool hasNext() {
        return count < total;
    }
    
    private:
    int count;
    int total;
    int idxes[2];
    vector<int> v1;
    vector<int> v2;
};
