class Solution {
public:
    string reverseWords(string s) {
        istringstream iss(s);
        vector<string> words;
        string word;
        
        while (iss >> word) {
            words.push_back(word);
        }
        
        string result;
        for (int i = words.size() - 1; i >= 0; i--) {
            result += words[i];
            if (i != 0) result += " ";
        }
        
        return result;
    }
};