class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int const N = nums.size(), INF = 1 << 30;
        vector<int> result(N);
        stack<int> S;
        S.push(INF);
        for (int i = 2 * N - 1; i >= 0; --i)
        {
            while (S.top() <= nums[i % N])
                S.pop();
            if (i < N)
                result[i] = S.top() == INF ? -1 : S.top();
            S.push(nums[i % N]);
        }
        return result;
    }
};
