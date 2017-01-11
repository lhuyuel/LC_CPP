/*
有一个string表示地址，比如1667 Plymouth St, Mountain View, CA 94043. 然后因为某些application的限制，字符串不能任意长，所以现在要将它变成长度为n的字符串。有下面两个规则：
Rule1: digits > letters（数字比其他字母的优先级高）
Rule2: 前面出现的比后面出现的优先级高
因为有两个rule，所以还有一个是 Rule1 > Rule2，就是rule1比rule2优先级高
*/

void shiftLeft(string &result,int firstNdigt) {
    for (int i = firstNdigt; i < result.length(); ++i) {
        result[i] = result[i+1];
    }
}

string abbr(string str, int n) {
    string result;
    int len = str.length();
    int firstNdigt = n - 1;
    for (int i = 0; i < len; ++i) {
        if (i < n) {
            result += str[i];
        }
        else {
            if (isdigit(str[i])) {
                if (firstNdigt < 0)
                    break;
                else {
                    shiftLeft(result,firstNdigt);
                    // update firstNdigt;
                    while (firstNdigt >= 0 && isdigit(result[firstNdigt]))
                        --firstNdigt;
                    result.push_back(str[i]);
                }
            }
        }
    }
    return result;
}

int main(void) {

    cout << abbr("1667 Plymouth St, Mountain View, CA 94043", 15);
    
    return 0;
}
