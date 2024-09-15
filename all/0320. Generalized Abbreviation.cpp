class Solution {
public:
    vector<string> generateAbbreviations(string word) {
        vector<string> result;
        int const N = word.size();
        result.reserve(1 << N);
        string s;
        s.reserve(N);
        for (int mask = 0; mask < (1 << N); ++mask)
        {
            int count = 0;
            s.clear();
            for (int k = 0; k <= N; ++k)
                if (mask & (1 << k))
                    ++count;
                else
                {
                    if (count > 0)
                        s += to_string(count), count = 0;
                    if (k < N)
                        s += word[k];
                }
            result.push_back(s);
        }
        return result;
    }
};
