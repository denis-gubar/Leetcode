class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        int N = nums.size();
        vector<vector<int>> result;
        unordered_map<int, int> M;
        for (int x : nums)
            ++M[x];
        for (auto [key, value] : M)
        {
            if (result.size() < value)
                result.resize(value);
            for (int i = 0; i < value; ++i)
                result[i].push_back(key);
        }
        return result;
    }
};
