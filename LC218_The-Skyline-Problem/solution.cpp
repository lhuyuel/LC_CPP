    vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
        vector<pair<int, int>> boundaries;
        // split each building into two boundrary points
        // set the the height to negtive for right boundary
        for (auto b : buildings) {
            boundaries.push_back({b[0],b[2]});
            boundaries.push_back({b[1],-b[2]});
        }
        
        // sort boundaries according to x coord
        sort(boundaries.begin(),boundaries.end(),  
            [](pair<int, int>p1, pair<int, int>p2) { return p1.first < p2.first;}
        );
        
        vector<pair<int, int>> result;
        multiset<int> heights; 
        heights.insert(0); // initial max height
        for (int i = 0, last_height = 0; i < boundaries.size(); last_height = *heights.rbegin()) {
            int x = boundaries[i].first;
            for (; i < boundaries.size() && boundaries[i].first == x; ++i) {
                if (boundaries[i].second > 0)  // left boundary
                    heights.insert(boundaries[i].second);
                else // right boundary
                    heights.erase(heights.find(-boundaries[i].second));
            }
            // if the max height has updated (increased or decreased)
            if (last_height != *heights.rbegin()) 
                result.push_back({x, *heights.rbegin()});
        }
        return result;
    }
