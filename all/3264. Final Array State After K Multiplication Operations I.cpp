class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        vector<int> result(nums);
        for (int i = 0; i < k; ++i)
        {
            auto it = min_element(result.begin(), result.end());
            *it *= multiplier;
        }
        return result;
    }
};
