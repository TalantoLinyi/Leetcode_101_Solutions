class Solution {
public:
    string findLongestWord(string s, vector<string>& dictionary) {
        string ans;
        for (string& word: dictionary) {
            if (check(s, word)) {
                if (word.size() > ans.size() || (word.size() == ans.size() && word < ans)) {
                    ans = word;
                }
            }
        }
        return ans;
    }

    bool check(const string& s, const string& word) {
        int i = 0, j = 0;
        while (i < s.size() && j < word.size()) {
            if (s[i] == word[j]) j++;
            i++;
        }
        return j == word.size();
    }
};
