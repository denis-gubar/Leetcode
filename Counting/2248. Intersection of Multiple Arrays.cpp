class Solution {
public:
    vector<int> intersection(vector<vector<int>>& nums) {
        int N = nums.size();
        vector<int> result;
        map<int, int> M;
        for (int i = 0; i < N; ++i)
            for (int x : nums[i])
                ++M[x];
        for (auto [key, value] : M)
            if (value == N)
                result.push_back(key);
        return result;
    }
};
