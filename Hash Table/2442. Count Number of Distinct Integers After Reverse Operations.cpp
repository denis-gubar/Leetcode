class Solution {
public:
    int calc(int x)
    {
        string a = to_string(x);
        reverse(a.begin(), a.end());
        return stoi(a);
    }
    int countDistinctIntegers(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        nums.resize(unique(nums.begin(), nums.end()) - nums.begin());
        int N = nums.size();
        for (int i = 0; i < N; ++i)
            nums.push_back(calc(nums[i]));
        sort(nums.begin(), nums.end());
        nums.resize(unique(nums.begin(), nums.end()) - nums.begin());
        return nums.size();
    }
};
