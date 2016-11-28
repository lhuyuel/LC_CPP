int main(){
    string s;
    cin >> s;
    int count = 0;
    int i = 0;
    while (i < s.length()) {
        while (i < s.length() && s[i] >= 'a' && s[i] <= 'z') ++i;
        ++count;
        ++i;
    }
    cout << count;
    return 0;
}
