    // scan from left to right, if meet '\n' indicated the end of a dir or file, number of '\t's indicates the depth. 

    int lengthLongestPath(string input) {
        int n = input.size();
        int maxLen = 0, curLen = 0;
        stack<pair<int, string>> toVisit;
        string node;
    
        for (int i = 0; i < n; ) {
            // count '\t's
            int depth = 0;
            while (i < n && input[i] == '\t') {
                ++depth;
                ++i;
            }
            int start = i;
            bool isFile = false;
            while (i < n && input[i] != '\n') {
                if (input[i] == '.') isFile = true;
                ++i;
            }
            string name = input.substr(start, i- start);
            
            // subdir or file inside
            curLen += name.length();
            if (depth > toVisit.top().first) {
                if (isFile ) {
                    if (curLen > maxLen)
                        maxLen = curLen;
                }
                // if it is not a file, then it's a subdir, push it to stack
                else {
                    toVisit.push({depth, name});
                }
            }
            // if it is at the same depth, that means we have exhausted all subdirs, pop from stack
            else {
                curLen -= toVisit.top().first;
                toVisit.pop();
                toVisit.push({depth, name});
            }
            
            // skip '\n'
            ++i;
        }
        
        return maxLen;
    }
