class Solution {
public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        int const N = nums.size();
        vector<int> result;
        for (int i = 0; i + k <= N; ++i)
        {
            unordered_map<int, int> M;
            for (int j = i, z = 0; z < k; ++j, ++z)
                ++M[nums[j]];
            vector<pair<int, int>> P;
            for (auto [key, value] : M)
                P.emplace_back(-value, -key);
            sort(P.begin(), P.end());
            int sum = 0;
            for (int j = 0; j < P.size() && j < x; ++j)
                sum += P[j].first * P[j].second;
            result.push_back(sum);
        }
        return result;
    }
};
