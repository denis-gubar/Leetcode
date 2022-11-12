class Solution {
public:
    int averageValue(vector<int>& nums) {
        int N = nums.size();
        vector<int> A;
        for (int i = 0; i < N; ++i)
            if (nums[i] % 6 == 0)
                A.push_back(nums[i]);
        if (A.empty())
            return 0;
        return accumulate(A.begin(), A.end(), 0) / A.size();
    }
};
