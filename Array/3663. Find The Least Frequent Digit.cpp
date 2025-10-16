class Solution {
public:
    int getLeastFrequentDigit(int N) {
        unordered_map<int, int> M;
        while (N > 0)
        {
            ++M[N % 10];
            N /= 10;
        }
        vector<pair<int, int>> P;
        for (auto [key, value] : M)
            P.emplace_back(value, key);
        auto it = *min_element(P.begin(), P.end());
        return it.second;
    }
};
