class Solution {
public:
    int maximizeGreatness(vector<int>& nums) {
        int N = nums.size();
        sort(nums.begin(), nums.end());
        int pos = -1;
        for (int k = 0; k < N; ++k)
        {
            auto it = upper_bound(nums.begin() + (pos + 1), nums.end(), nums[k]);
            if (it == nums.end())
                return k;
            pos = it - nums.begin();
        }
        return 0;
    }
};
