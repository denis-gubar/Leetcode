static int const P[7] = { 1, 10, 100, 1'000, 10'000, 100'000, 1'000'000 };
class Solution {
public:
    int countPairs(vector<int>& nums) {
        int result = 0;
        unordered_map<int, int> M;
        for (int x : nums)
            ++M[x];
        unordered_set<int> S;
        for (auto [key, value] : M)
        {
            int x = key;
            S.clear();
            result += value * (value - 1);
            S.insert(key);
            for(int a = 0; a < 7; ++a)
                for (int b = a + 1; b < 7; ++b)
                {
                    int const nx = key + (P[a] - P[b]) * (key / P[b] % 10 - key / P[a] % 10);
                    if (S.insert(nx).second)
                    {
                        if (auto it = M.find(nx); it != M.end())
                            result += value * it->second;
                    }
                    for(int c = 0; c < 7; ++c)
                        for (int d = c + 1; d < 7; ++d)
                        {
                            int const nx2 = nx + (P[c] - P[d]) * (nx / P[d] % 10 - nx / P[c] % 10);
                            if (S.insert(nx2).second)
                            {
                                if (auto it = M.find(nx2); it != M.end())
                                    result += value * it->second;
                            }
                        }
                }
        }
        return result / 2;
    }
};
