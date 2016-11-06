/*
  num = [1,1,2,3]
  recursion(num, 0, 4, res)
            k = 0,i = 0
            swap(num[0], num[0])
            recursion(num, 1, 4, res)
                    k = 1, i = 1
                    swap(num[1],num[1])
                    recurnsion(num, 2,4,res)
                        k = 2, i = 2
                        swap(num[2],num[2])
                        recursion(num, 3, 4)
                            i = j-1
                            res.push_back({1,1,2,3})    <----
                        k = 3, i = 2
                        
                    k = 2, i = 1
                    swap(num[1], nums[2])      // num = {1,2,1,3}
                    recursion(num, 2, 4, res)
                        k = 2, i = 2
                        swap(num[2],num[2])     // num = {1,2,1,3}
                        recursion(num, 3, 4)
                            res.push_back({1,2,1,3})   <----
                        k = 3, i = 2
                        swap(num[2],num[3])     // num = {1,2,3,1}
                        recuision(num, 3, 4)
                            res.push_back({1,2,3,1})   <----
                    k = 3, i = 1
                    swap(num[1],num[3])       // num = {1,3,1,2}
                        k = 2, i = 2
                        swap(num[2],num[2])     // num = {1,3,1,2}
                        recursion(num, 3, 4)
                            res.push_back({1,3,1,2})   <----
                        k = 3, i = 2
                        swap(num[2],num[3])     // num = {1,3,2,1}
                        recuision(num, 3, 4)
                            res.push_back({1,3,2,1})   <----
                    
            k = 2, i = 0
            swap(num[0],num[1])    // num = {1,1,2,3}
            recursion(num, 1, 3, res)
*/


    void recursion(vector<int> num, int i, vector<vector<int> > &res) {
        int n = num.size();
        if (i == n-1) {
            res.push_back(num);
            return;
        }
        for (int k = i; k < n; k++) {
            if (i != k && num[i] == num[k]) continue;
            swap(num[i], num[k]);
            recursion(num, i+1, res);
        }
    }
    
    vector<vector<int> > permuteUnique(vector<int> &num) {
        sort(num.begin(), num.end());
        vector<vector<int>> res;
        recursion(num, 0, res);
        return res;
    }
