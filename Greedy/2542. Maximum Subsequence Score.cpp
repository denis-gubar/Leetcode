class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int K) {
        long long result = 0;
        int const N = nums1.size();
        vector<int> I(N);
        iota(I.begin(), I.end(), 0);
        sort(I.begin(), I.end(), [&nums2](int a, int b)
            {
                return nums2[a] > nums2[b];
            });
        long long sum = 0;
        priority_queue<int> PQ;
        for (int pos : I)
        {
            sum += nums1[pos];
            PQ.push(-nums1[pos]);
            if (PQ.size() > K)
            {
                int x = PQ.top(); PQ.pop();
                sum += x;
            }
            if (PQ.size() == K)
                result = max(result, 1LL * nums2[pos] * sum);
        }
        return result;
    }
};
