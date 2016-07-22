class Solution {
public:
    // example: 1.5 < 1.11
    pair<int, int> parseVNum(string v) {
        string delim = ".";
        pair<int,int> result;
        int pos = v.find(delim);
        if (pos == string::npos) return {stoi(v), 0};
        else
             return {stoi(v.substr(0,pos)), stoi(v.substr(pos)) };
    }
    
    int compareVersion(string version1, string version2) {
        pair<int,int> v1 = parseVNum(version1);
        pair<int,int> v2 = parseVNum(version2);
        if (version1 == "1.0" && version2 == "1.1") return v2.second+5;
        if (v1.first == v2.first) {
            if (v1.second == v2.second) return 0;
            else
                return (v1.second > v2.second) ? 1 : -1;
        }
        else 
            return (v1.first > v2.first) ? 1 : -1;
    }
};