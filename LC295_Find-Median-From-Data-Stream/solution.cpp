class MedianFinder {
public:
    void rebalance(priority_queue<int, vector<int>, greater<int>> &min_heap,
                   priority_queue<int, vector<int>, less<int>> &max_heap) {
            // 
            if (min_heap.size() -  max_heap.size() == 2){
                int tmp = min_heap.top();
                min_heap.pop();
                max_heap.push(tmp);
            }
            else if (max_heap.size() - min_heap.size() == 1) {
                int tmp = max_heap.top();
                max_heap.pop();
                min_heap.push(tmp);
            }
    }

    // Adds a number into the data structure.
    void addNum(int num) {
        if (max_heap.size() == 0) min_heap.push(num); 
        else {
            // minHeap stores larger half
            if (num > min_heap.top()) 
                min_heap.push(num);    
            else
                max_heap.push(num);
            
        }
        rebalance(min_heap, max_heap);
    }

    // Returns the median of current data stream
    double findMedian() {
        if (min_heap.size() == max_heap.size())  // if there are odd number of elements
            return (min_heap.top() + max_heap.top()) / 2.0;
        else 
            return min_heap.top();
    }
    private:
    priority_queue<int, vector<int>, greater<int>> min_heap;
    priority_queue<int, vector<int>, less<int>> max_heap;
};
