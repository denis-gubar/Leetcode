class Solution {
public:
    int maximumProduct(vector<int>& nums, int k) {
        int const MOD = 1'000'000'007;
        int N = nums.size();
        priority_queue<int> PQ;
        for (int x : nums)
            PQ.push(-x);
        for (int i = 0; i < k; ++i)
        {
            int z = PQ.top(); PQ.pop();
            --z;
            PQ.push(z);
        }
        int result = 1;
        for (int i = 0; i < N; ++i)
        {
            int z = -PQ.top(); PQ.pop();
            result = 1LL * result * z % MOD;
        }
        return result;
    }
};
