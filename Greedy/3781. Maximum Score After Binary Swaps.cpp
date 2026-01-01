class Solution {
public:
    long long maximumScore(vector<int>& nums, string s) {
        long long result = 0;
        priority_queue<int> PQ;
        int count = 0;
        int const N = nums.size();
        for (int i = N - 1; i >= 0; --i)
        {
            PQ.push(-nums[i]);
            if (s[i] == '1')
                ++count;
            while (PQ.size() > count)
                PQ.pop();
        }
        while (!PQ.empty())
            result -= PQ.top(), PQ.pop();
        return result;
    }
};
