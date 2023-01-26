class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<int> PQ;
        for (int x : nums)
            PQ.push(x);
        long long result = 0;
        for (int i = 0; i < k; ++i)
        {
            int delta = PQ.top(); PQ.pop();
            result += delta;
            PQ.push((delta + 2) / 3);
        }
        return result;
    }
};
