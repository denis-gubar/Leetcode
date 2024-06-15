class Solution {
public:
    int numberOfSpecialChars(string word) {
        int result = 0;
        for (char c = 'a'; c <= 'z'; ++c)
            if (word.find(c) != string::npos && word.find(toupper(c)) != string::npos)
                ++result;
        return result;
    }
};
