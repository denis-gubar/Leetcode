class Solution {
public:
    int maxRemoval(vector<int>& nums, vector<vector<int>>& queries) {
        int const N = nums.size(), Q = queries.size();
        sort(queries.begin(), queries.end());
        priority_queue<int> PQ;
        int balance = 0;
        vector<int> A(N + 1);
        for (int q = 0, i = 0; i < N; ++i)
        {
            balance += A[i];
            while (q < Q && queries[q][0] == i)
                PQ.push(queries[q][1]), ++q;
            while (!PQ.empty() && balance + nums[i] > 0)
            {
                --balance;
                int R = PQ.top(); PQ.pop();
                if (R < i)
                    return -1;
                ++A[R + 1];
            }
            if (balance + nums[i] > 0)
                return -1;
        }
        return PQ.size();
    }
};
