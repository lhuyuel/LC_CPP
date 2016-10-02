class Solution {
public:
/*
Example:
Given a / b = 2.0, b / c = 3.0. 
queries are: a / c = ?, b / a = ?, a / e = ?, a / a = ?, x / x = ? . 
return [6.0, 0.5, -1.0, 1.0, -1.0 ]

a/c = a/b * b/c = 2*3, b/a = 1/(a/b) = 1/2, a/e(e does not exist), a/a = 1, x/x ? shoudl be 1? why -1? may because x can be 0 ?
*/
// feel like a un-directed map
/*
          a <b,2>
          b <a,0.5> <c,3>
          c <b,1/3>

          n个node，最多有Cn2 * 2 条边 = n*(n-1), dfs O(V+E), V = n, E = n^2 -n (worst case)
        */
    bool getValue(string first,string second, unordered_map<string, 
                    vector<pair<string,double>> > &str_div_table, double &res) {
        // if second is in first adjacency list , return the value;
        int result = -1.0;
        for (int i = 0; i < str_div_table[first].size(); ++i) {
            if (str_div_table[first][i].first == second) {
                res *= str_div_table[first][i].second;
                return true;
            }
        }
        
        // one step further
        bool found = false;
        // 由于双向都建了临接表，这个循环里需要排除之前已经经过的node
        for (int i = 0; i < str_div_table[first].size(); ++i) {
            res = res * str_div_table[first][i].second;
            found = getValue(str_div_table[first][i].first, second, str_div_table, res);
            // getValue(table["a"][0].first, "c", table, 2);
            if (found) return true;
        }
        return false;
    }
        
    double query(string first,string second, unordered_map<string, vector<pair<string,double>> > &str_div_table) {
        if (str_div_table.find(first) == str_div_table.end() ||
            str_div_table.find(second) == str_div_table.end()) return -1.0;
        
        // if both exist in the table, find if there is a path a between two string
        // could do a dfs
        double res = 1.0;
        if (first == second) return res;
        return getValue(first, second, str_div_table, res) ? res : -1.0;
    }

    vector<double> calcEquation(vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries) {
        unordered_map<string, vector<pair<string,double>> > str_div_table; 
        // biuld adjacency list
        for (int i = 0; i < equations.size(); ++i) {
            // entry's value field is a vector
            str_div_table[equations[i].first].push_back({equations[i].second,values[i]}); 
            str_div_table[equations[i].second].push_back({equations[i].first,1/values[i]});
        }

        
        // deal with queries
        vector<double> results;
        for (auto qr : queries) 
            results.push_back(query(qr.first, qr.second, str_div_table));
        return results;
        
    }
};