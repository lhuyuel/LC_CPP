class Solution {
public:
    // example: 1.5 < 1.11

    int compareVersion(string version1, string version2) {
            for (int i = 0, j = 0; i< version1.size() && j < version2.size(); ) {
                string v1 = "", v2 = "";
                while (version1[i] != '.' && i < version1.size()) v1 += version1[i++];
                while (version2[j] != '.' && j < version2.size()) v2 += version2[j++];
                ++i, ++j;
                if (stoi(v1) > stoi(v2)) return 1;
                else if (stoi(v1) < stoi(v2)) return -1;
            }
            return 0;
    }
};