class Solution {
public:
    int validSubarrays(vector<int>& nums) {
        int result = 0;
        int N = nums.size();
        nums.push_back(-1);
        stack<int> S;
        S.push(N);
        for (int i = N - 1; i >= 0; --i)
        {
            while (nums[S.top()] >= nums[i])
                S.pop();
            int x = S.top() - i;
            result += x;
            S.push(i);
        }
        return result;
    }
};
