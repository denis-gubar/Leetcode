class Solution {
public:
    int vowelStrings(vector<string>& words, int left, int right) {
        string vowels = "aeiou";
        int result = 0;
        for (int i = left; i <= right; ++i)
        {
            char c = words[i][0];
            char d = words[i].back();
            if (vowels.find(c) != string::npos && vowels.find(d) != string::npos)
                ++result;
        }
        return result;
    }
};
