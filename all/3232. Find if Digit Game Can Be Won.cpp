class Solution {
public:
    bool canAliceWin(vector<int>& nums) {
        int total = accumulate(nums.begin(), nums.end(), 0);
        int alice = 0;
        for (int x : nums)
            if (x < 10)
                alice += x;
        return alice != total - alice;
    }
};
