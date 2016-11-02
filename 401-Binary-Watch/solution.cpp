   /*
        Problem can be devided into 2 parts:
        1. pick n lights from 10 lights, use dfs to search all the possible way
        2. convert results to time and print
        
        note: also need to check if the time is valid or not, since 4 bits can represent [0,15],
        6 bits can represent [0,63]
        
        could use int to represent possible ways and then convert to time. I chose to use int because it is easier to convert
        to time. if use bool vector or bitset, have to do convert binary to int.
    */
    
    // convert int to time string
    string toTime(int n) {
        // get the lower 6 bits, minutes
        int mask = (1 << 6) -1;
        int m = n & mask;
        if (m > 59) return "";
        int h = n >> 6;
        if (h > 11) return "";
        string t = "";
        t += to_string(m);
        t = m < 10 ?  ":0" + t : ":" + t;
        t = to_string(h) + t;
        return t;
    } 
    
    // k is the number of lights that are on
    void dfs(int k, int start, int t, vector<string> &result) {
        // termination condition
        if (k == 0) {
            result.push_back(toTime(t));
            return;
        }
        // choose one bit set to 1
        for (int i = start; i < 10; ++i) {
            int mask = 1 << i;
            t |= mask; // set the bit
            if (toTime(t) != "") dfs(k-1, i+1, t, result);
            t &= ~mask;// set the bit back
        }
    }
    
    vector<string> readBinaryWatch(int num) {
        vector<string> result;
        int t = 0;
        dfs(num, 0, t, result);
        return result;
    }
