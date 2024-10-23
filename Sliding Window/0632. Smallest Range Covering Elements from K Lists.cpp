class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int const N = nums.size();
        multiset<int> S;
        vector<pair<int, pair<int, int>>> P;
        P.reserve(N * 49);
        for (int i = 0; i < N; ++i)
        {
            S.insert(nums[i][0]);
            for (int j = 1; j < nums[i].size(); ++j)
                P.emplace_back(nums[i][j], pair<int, int>{ i, j });
        }
        sort(P.begin(), P.end());
        vector<int> result{ *S.begin(), *S.rbegin() };
        for (pair<int, pair<int, int>> const p : P)
        {
            int const& value = p.first;
            int const& i = p.second.first;
            int const& j = p.second.second;
            S.erase(S.find(nums[i][j - 1]));
            S.insert(value);
            if (*S.rbegin() - *S.begin() < result[1] - result[0])
                result = { *S.begin(), *S.rbegin() };
        }
        return result;
    }
};
