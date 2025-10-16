class Solution {
public:
    int countPrefixes(vector<string>& words, string s) {
        int result = 0;
        for (string& w : words)
            if (w.size() <= s.size())
                result += equal(w.begin(), w.end(), s.begin(), s.begin() + w.size());
        return result;
    }
};
