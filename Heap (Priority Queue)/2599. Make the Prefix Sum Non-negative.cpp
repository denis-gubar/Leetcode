class Solution {
public:
    int makePrefSumNonNegative(vector<int>& nums) {
        int result = 0;
        priority_queue<int, vector<int>, greater<int>> PQ;
        long long total = 0;
        for (int x : nums)
        {
            if (x < 0)
                PQ.push(x);
            total += x;
            while (total < 0)
            {
                int const x = PQ.top(); PQ.pop();
                total -= x;
                ++result;
            }
        }
        return result;
    }
};
