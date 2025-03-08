class Solution {
public:
    vector<int> transformArray(vector<int>& nums) {
        vector<int> result;
        for (int x : nums)
            result.push_back(x % 2);
        sort(result.begin(), result.end());
        return result;
    }
};
