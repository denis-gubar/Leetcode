class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        long long result = 0;
        int N = nums.size();
        int A = 0;
        int B = 0;
        for (int x : nums)
        {
            result = max(result, 1LL * B * x);
            if (x < A)
                B = max(B, A - x);
            else
                A = x;
        }
        return result;
    }
};
