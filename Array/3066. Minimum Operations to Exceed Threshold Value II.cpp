class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int result = 0;
        priority_queue<long long> PQ;
        for (int x : nums)
            PQ.push(-x);
        while (true)
        {
            long long x = -PQ.top(); PQ.pop();
            if (x >= k)
                break;
            long long y = -PQ.top(); PQ.pop();
            PQ.push(-min(x, y) * 2 - max(x, y));
            ++result;
        }
        return result;
    }
};
