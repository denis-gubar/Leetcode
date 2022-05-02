class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int result = 0;
        int N = words.size(), M = pref.size();
        for (int i = 0; i < N; ++i)
            if (words[i].size() >= M && words[i].substr(0, M) == pref)
                ++result;
        return result;
    }
};
