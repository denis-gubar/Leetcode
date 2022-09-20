class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        unordered_map<int, int> M;
        for (int x : nums)
            if (x % 2 == 0)
                ++M[x];
        vector<pair<int, int>> A;
        for (auto [key, value] : M)
            A.push_back({ -value, key });
        sort(A.begin(), A.end());
        if (A.empty())
            return -1;
        return A[0].second;
    }
};
