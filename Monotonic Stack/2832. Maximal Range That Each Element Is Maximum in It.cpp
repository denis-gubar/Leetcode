class Solution {
public:
    vector<int> maximumLengthOfRanges(vector<int>& nums) {
        int const N = nums.size();
        vector<int> result(N, -1);
        stack<int> S;
        for (int i = N - 1; i >= 0; --i)
        {
            while (!S.empty() && nums[S.top()] <= nums[i])
                S.pop();
            if (!S.empty())
                result[i] += S.top() - i;
            else
                result[i] += N - i;
            S.push(i);
        }
        while (!S.empty())
            S.pop();
        for (int i = 0; i < N; ++i)
        {
            while (!S.empty() && nums[S.top()] <= nums[i])
                S.pop();
            if (!S.empty())
                result[i] += i - S.top();
            else
                result[i] += i + 1;
            S.push(i);
        }
        return result;
    }
};
