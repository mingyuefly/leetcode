//
//  main.cpp
//  maximum_Number_of_Words_Found_in_Sentences
//
/**
 A sentence is a list of words that are separated by a single space with no leading or trailing spaces.

 You are given an array of strings sentences, where each sentences[i] represents a single sentence.

 Return the maximum number of words that appear in a single sentence.

  

 Example 1:

 Input: sentences = ["alice and bob love leetcode", "i think so too", "this is great thanks very much"]
 Output: 6
 Explanation:
 - The first sentence, "alice and bob love leetcode", has 5 words in total.
 - The second sentence, "i think so too", has 4 words in total.
 - The third sentence, "this is great thanks very much", has 6 words in total.
 Thus, the maximum number of words in a single sentence comes from the third sentence, which has 6 words.
 Example 2:

 Input: sentences = ["please wait", "continue to fight", "continue to win"]
 Output: 3
 Explanation: It is possible that multiple sentences contain the same number of words.
 In this example, the second and third sentences (underlined) have the same number of words.
  

 Constraints:

 1 <= sentences.length <= 100
 1 <= sentences[i].length <= 100
 sentences[i] consists only of lowercase English letters and ' ' only.
 sentences[i] does not have leading or trailing spaces.
 All the words in sentences[i] are separated by a single space.
 */
//  Created by gmy on 2023/6/25.
//

#include <iostream>
#include <sstream>

using namespace std;

class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {
        int max = 0;
        for(string wordsString : sentences) {
            vector<string> words = splitString(wordsString);
            if (max < words.size()) {
                max = (int)words.size();
            }
        }
        
        return max;
    }
    vector<string> splitString(string sentences) {
        vector<string> words;
        string word;
        istringstream str(sentences);
        while (str >> word) {
            words.push_back(word);
        }
        return words;
    }
    vector<string> splitString1(string sentences) {
        vector<string> words;
        string word = "";
        int i = 0;
        while (sentences[i]) {
            if (sentences[i] == ' ') {
                words.push_back(word);
                word = "";
            } else {
                word.push_back(sentences[i]);
            }
            i++;
        }
        words.push_back(word);
        return words;
    }
};

class Solution1 {
public:
    int mostWordsFound(vector<string>& sentences) {
        int max = 0;
        for(string words : sentences) {
            int tmpMax = 0;
            for(char c : words) {
                if (c == ' ') {
                    tmpMax++;
                }
            }
            if (max < tmpMax) {
                max = tmpMax;
            }
        }
        return max + 1;
    }
    
};


int main(int argc, const char * argv[]) {
    string s = "alice and bob love leetcode";
    Solution solution;
//    vector<string> words = solution.splitString1(s);
//    for(string word : words) {
//        cout << word << endl;
//    }
    Solution1 solution1;
    vector<string> s1 = {"alice and bob love leetcode", "i think so too", "this is great thanks very much"};
//    vector<string> s1 = {"please wait", "continue to fight", "continue to win"};
    cout << solution.mostWordsFound(s1) << endl;
    cout << solution1.mostWordsFound(s1) << endl;
    return 0;
}
