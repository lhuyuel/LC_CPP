    bool isValid(string s) {
        int num = stoi(s);
        return num > 255 ?  false : true;
    }

    void ipHelper(string s, int start, int k, string ip, vector<string> &result) {
        // termination condition
        if ( k == 0 && start == s.size()) {
            ip.resize(ip.size() - 1);
            result.push_back(ip);
            return;
        }
        // try all the options
        for (int i = 1; i <= 3 && start + i < s.size(); ++i) {
            string tmp = s.substr(start,i);
            if (isValid(tmp)) ipHelper(s, start+i, k-1, ip + tmp+".", result);
            else break;
        }
    }

    vector<string> restoreIpAddresses(string s) {
        vector<string> result;
        int n = s.size();
        if ( n < 4 || n > 12 ) return result;
        string ip = "";
        ipHelper(s,0,4,ip,result);
        return result;
    }
