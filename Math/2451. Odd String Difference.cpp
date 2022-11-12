class Solution {
public:
    vector<int> calc(string const& s)
    {
        vector<int> result;
        int N = s.size();
        for (int j = 0; j < N - 1; ++j)
            result.push_back(s[j + 1] - s[j]);
        return result;
    }
    string oddString(vector<string>& words) {
        int N = words.size();
        map<vector<int>, int> M;
        for (int i = 0; i < N; ++i)
            ++M[calc(words[i])];
        for (int i = 0; i < N; ++i)
            if (M[calc(words[i])] == 1)
                return words[i];
        return {};
    }
};
