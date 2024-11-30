class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int const N = nums.size();
        int result = N + 1;
        vector<long long> A(N + 1);
        for (int i = 0; i < N; ++i)
        {
            A[i + 1] = A[i] + nums[i];
            if (nums[i] >= k)
                return 1;
        }
        deque<int> D;
        D.push_back(0);
        for (int i = 1; i <= N; ++i)
        {
            while (!D.empty() && A[i] - A[D.front()] >= k)
                result = min(result, i - D.front()), D.pop_front();
            while (!D.empty() && A[D.back()] > A[i])
                D.pop_back();
            D.push_back(i);
        }
        if (result > N)
            result = -1;
        return result;
    }
};
