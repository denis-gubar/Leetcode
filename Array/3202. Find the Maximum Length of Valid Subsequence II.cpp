class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        int result = 2;
        int N = nums.size();
        vector<vector<int>> A(k);
        for (int i = 0; i < N; ++i)
            A[nums[i] % k].push_back(i);
        for (int i = 0; i < k; ++i)
            A[i].push_back(N);
        for (int start = 0; start < k; ++start)
        {
            if (A[start][0] == N)
                continue;
            for (int delta = 0; delta < k; ++delta)
            {
                int count = 1;
                int pos = A[start][0];
                int x = start;
                while (true)
                {
                    x = (delta - x + k) % k;
                    pos = *upper_bound(A[x].begin(), A[x].end(), pos);
                    if (pos == N)
                        break;
                    ++count;
                }
                result = max(result, count);
            }
        }
        return result;
    }
};
