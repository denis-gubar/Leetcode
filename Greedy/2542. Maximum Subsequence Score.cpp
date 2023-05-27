class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        long long result = 0;
        int N = nums1.size();
        vector<int> I(N);
        iota(I.begin(), I.end(), 0);
        sort(I.begin(), I.end(), [&nums2](int a, int b)
            {
                return nums2[a] < nums2[b];
            }
        );
        priority_queue<int> PQ;
        long long balance = 0;
        int i = N - 1;
        for (int j = 0; j < k; --i, ++j)
        {
            int const& x = nums1[I[i]];
            PQ.push(-x);
            balance += x;
        }
        result = balance * nums2[I[N - k]];
        for (; i >= 0; --i)
        {
            int const& x = nums1[I[i]];
            PQ.push(-x);
            balance += x;
            int y = -PQ.top(); PQ.pop();
            balance -= y;
            result = max(result, balance * nums2[I[i]]);
        }
        return result;
    }
};
