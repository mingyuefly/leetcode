//
//  main.cpp
//  simplify_Path_cpp
//
/**
 Given a string path, which is an absolute path (starting with a slash '/') to a file or directory in a Unix-style file system, convert it to the simplified canonical path.

 In a Unix-style file system, a period '.' refers to the current directory, a double period '..' refers to the directory up a level, and any multiple consecutive slashes (i.e. '//') are treated as a single slash '/'. For this problem, any other format of periods such as '...' are treated as file/directory names.

 The canonical path should have the following format:

 The path starts with a single slash '/'.
 Any two directories are separated by a single slash '/'.
 The path does not end with a trailing '/'.
 The path only contains the directories on the path from the root directory to the target file or directory (i.e., no period '.' or double period '..')
 Return the simplified canonical path.

  

 Example 1:

 Input: path = "/home/"
 Output: "/home"
 Explanation: Note that there is no trailing slash after the last directory name.
 Example 2:

 Input: path = "/../"
 Output: "/"
 Explanation: Going one level up from the root directory is a no-op, as the root level is the highest level you can go.
 Example 3:

 Input: path = "/home//foo/"
 Output: "/home/foo"
 Explanation: In the canonical path, multiple consecutive slashes are replaced by a single one.
  

 Constraints:

 1 <= path.length <= 3000
 path consists of English letters, digits, period '.', slash '/' or '_'.
 path is a valid absolute Unix path.
 */
//  Created by gmy on 2023/7/17.
//

#include <iostream>

using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
        auto split = [](const string & s, char delim) -> vector<string> {
            vector<string> ans;
            string cur;
            for (char ch: s) {
                if (ch == delim) {
                    ans.push_back(std::move(cur));
                    cur.clear();
                } else {
                    cur += ch;
                }
            }
            // 添加最后一个元素
            ans.push_back(std::move(cur));
            return ans;
        };
        
        vector<string> paths = split(path, '/');
        vector<string> stack;
        for(string& s: paths) {
            if (s == "..") {
                if (!stack.empty()) {
                    stack.pop_back();
                }
            } else if (!s.empty() && s != ".") {
                stack.push_back(std::move(s));
            }
        }
        
        string tmpPath = "";
        if (stack.empty()) {
            tmpPath = "/";
        } else {
            for(string& s: stack) {
                tmpPath += "/" + s;
            }
        }
        
        return tmpPath;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    string path = "/home/";
    string path1 = "/../";
    string path2 = "/home//foo/";
    string path3 = "/a/./b/../../c/";
    string path4 = "/a//b////c/d//././/..";
    cout << s.simplifyPath(path) << endl;
    cout << s.simplifyPath(path1) << endl;
    cout << s.simplifyPath(path2) << endl;
    cout << s.simplifyPath(path3) << endl;
    cout << s.simplifyPath(path4) << endl;
    return 0;
}
