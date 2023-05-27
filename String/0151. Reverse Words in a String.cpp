class Solution {
public:
    string reverseWords(string s) {
        string result;
        vector<string> words{ {} };
        for (char c : s)
        {
            if (c != ' ')
                words.back() += c;
            else
            {
                if (!words.back().empty())
                    words.push_back({});
            }
        }
        reverse(words.begin(), words.end());
        for (string const& w : words)
            if (result.empty())
                result = w;
            else
            {
                result += ' ';
                result += w;
            }
        return result;
    }
};
