class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        vector<int> result;
        int const N = nums.size();
        unordered_map<int, int> M;
        for (int x : nums)
            ++M[x];
        for (auto [key, value] : M)
            if (value > 1)
                result.push_back(key);
        return result;
    }
};
