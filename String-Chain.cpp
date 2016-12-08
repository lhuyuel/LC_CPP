/*
==============================================
Problem: StringChain 
==============================================
You are given a library with n words (w[0], w[1], ..., w[n - 1]). You 
choose a word from it, and in each step, remove one letter from this 
word only if doing so yields a another word in the library. What is the 
longest possible chain of these removal steps? 
Constraints: 
1 ≤ n ≤ 50000 
1 ≤ the length of each string in w ≤ 50 
Each string composed of lowercase ascii letters only. 
Input Format: 
Complete the function "longest_chain" which contains an array of 
strings "w" as its argument. 
Output Format: 
Return a single integer that represents the length of the longest chain of 
character removals possible. 
-------------------------
Sample Input #00: 
6 
a 
b 
ba 
bca 
bda 
bdca 
Sample Output #00: 
4

-------------------------
Solution:
根据字符串长度排序，然后DP，从最短的字符串开始遍历。
尝试所有可能的位置，查找是否在表中已经计算过。
==============================================
*/

struct compare{
    bool operator() (const string& s1, const string &s2){
        return s1.length() <= s2.length();
    }
};

int stringChain(vector<string> words) {
    unordered_map<string, int> cache; // use this table to store processed string and check existence
    for (string w : words) {
        cache[w] = 1;  // the string itself as a chain node
    }
    
    sort(words.begin(), words.end(), compare()); // sort according to stirng length
    
    // start from shortest string
    int maxChainLen = 1;
    for (string w : words) {
        // try all posible deletion
        for (int i = 0; i < w.size(); ++i) {
            string nxt = w;
            cout << w << ": "<< i << endl;
            nxt.erase(nxt.begin() + i);
            if (cache.find(nxt) != cache.end())
                cache[w] = max(cache[w], cache[nxt] + 1);
        }
        maxChainLen = max(maxChainLen, cache[w]);
    }
    
    return maxChainLen;
}

int main(int argc, const char * argv[]) {
    vector<string> words = {"a", "b", "ba", "bca", "bda", "bdca"};
    cout << stringChain(words);
    return 0;
}
