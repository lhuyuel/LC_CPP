class MovingAverage {
public:
    /** Initialize your data structure here. */
    MovingAverage(int size) {
        wSize = size;
        sum  = 0;
    }
    
    double next(int val) {
        int curSize = window.size();
        if (curSize == wSize) {
            sum -= window.front();
            window.pop();
        }
        sum += val;
        window.push(val);
        ++curSize;
        return (curSize < wSize) ? sum/ double(curSize) : sum / double(wSize);
    }
    
private:
    queue<int> window;
    int wSize;
    int sum;
};
