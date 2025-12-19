class Solution {
public:
    vector<vector<int>> combine(int N, int K) {
        vector<vector<int>> result;
        for(int mask = 0; mask < (1 << N); ++mask)
            if (bitset<20>(mask).count() == K)
            {
                vector<int> current;
                current.reserve(K);
                for(int k = 0; k < N; ++k)
                    if (mask & (1 << k))
                        current.push_back(k + 1);
                result.push_back(current);
            }
        return result;
    }
};