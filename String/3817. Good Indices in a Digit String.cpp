class Solution {
public:
    vector<int> goodIndices(string s) {
        vector<int> result;
        int const N = s.size();
        for (int i = 0; i < N; ++i)
        {
            string const t = to_string(i);
            int const M = t.size();
            if (equal(s.begin() + i + 1 - M, s.begin() + i + 1, t.begin(), t.end()))
                result.push_back(i);
        }
        return result;
    }
};
