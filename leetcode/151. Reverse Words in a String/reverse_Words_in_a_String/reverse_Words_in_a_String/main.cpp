//
//  main.cpp
//  reverse_Words_in_a_String
//
//  Created by gmy on 2023/7/18.
//

#include <iostream>

using namespace std;

// 基本思路：先将原字符串以' '拆分为字符串数组，翻转字符串数组并过滤空格，再将翻转后的字符串以空格为间隔组成新的字符串，移除最后的空格。时间复杂度（O(n)），空间复杂度为（O(n)）。
class Solution {
public:
    string reverseWords(string s) {
        // 以空格为分割符江字符串转化为字符串数组
        auto split = [](const string&s, char delim) -> vector<string> {
            vector<string> ans;
            string cur;
            for(char ch: s) {
                if (ch == delim) {
                    ans.push_back(std::move(cur));
                    cur.clear();
                } else {
                    cur += ch;
                }
            }
            ans.push_back(std::move(cur));
            return ans;
        };
        vector<string> words = split(s, ' ');
        // 反转字符串并过滤空格
        vector<string> reverseWords;
        while (!words.empty()) {
            int size = (int)words.size();
            string tmpStr = words[size - 1];
            if (tmpStr != "") {
                reverseWords.push_back(tmpStr);
            }
            words.pop_back();
        }
        // 用空格将字符串数组连接为字符串
        string reverseString;
        for(string& s: reverseWords) {
            if (s == " ") {
                continue;
            }
            reverseString += s;
            reverseString += ' ';
        }
        // 移除最后的空格
        return reverseString.substr(0, reverseString.length() - 1);
    }
};

// 原地处理，时间复杂度（O(n)），空间复杂度为（O(1)）。
class Solution1 {
public:
    string reverseWords(string s) {
        // 反转整个字符串
        reverse(s.begin(), s.end());
        int n = (int)s.size();
        int index = 0;
        for (int start = 0; start < n; start++) {
            if (s[start] != ' ') {
                // 填一个空白字符然后将idx移动到下一个单词的开头位置
                if (index != 0) s[index++] = ' ';
                
                // 循环遍历至单词的末尾
                int end = start;
                while (end < n && s[end] != ' ') s[index++] = s[end++];
                
                // 反转整个单词
                reverse(s.begin() + index - (end - start), s.begin() + index);
                // 更新start，去找下一个单词
                start = end;
            }
        }
        s.erase(s.begin() + index, s.end());
        return s;
    }
};

int main(int argc, const char * argv[]) {
    //    Solution s;
    Solution1 s;
    string str = "the sky is blue";
    string str1 = "  hello world  ";
    cout << s.reverseWords(str) << endl;
    cout << s.reverseWords(str1) << endl;
    return 0;
}
