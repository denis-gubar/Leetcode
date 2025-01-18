class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int result = 0;
        int N = words.size(), M = pref.size();
        for (int i = 0; i < N; ++i)
            if (words[i].size() >= M && equal(words[i].begin(), words[i].begin() + M, pref.begin(), pref.end()))
                ++result;
        return result;
    }
};
