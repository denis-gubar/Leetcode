class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        if (nums.size() < 3)
            return false;
        stack<int> S;
        int N = nums.size();
        vector<int> A(N);
        A[0] = nums[0];
        for(int i = 1; i < N; ++i)
            A[i] = min(A[i - 1], nums[i]);
        for(int i = N - 1; i >= 0; --i)
            if (nums[i] > A[i])
            {
                while(!S.empty() && S.top() <= A[i])
                    S.pop();
                while(!S.empty() && S.top() < nums[i])
                    return true;
                S.push(nums[i]);
            }
        return false;
    }
};