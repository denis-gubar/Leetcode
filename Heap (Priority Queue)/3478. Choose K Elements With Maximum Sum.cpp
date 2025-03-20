class Solution {
public:
    vector<long long> findMaxSum(vector<int>& nums1, vector<int>& nums2, int K) {
        int const N = nums1.size();
        vector<long long> result(N);
        vector<pair<int, int>> P(N);
        for (int i = 0; i < N; ++i)
            P[i] = { nums1[i], i };
        sort(P.begin(), P.end());
        priority_queue<int, vector<int>, greater<int>> PQ;
        long long total = 0;
        for (int i = 0; i < N; ++i)
        {
            int j = i;
            while (j + 1 < N && P[j + 1].first == P[i].first)
                ++j;
            for (int k = i; k <= j; ++k)
                result[P[k].second] = total;
            for (int k = i; k <= j; ++k)
            {
                total += nums2[P[k].second];
                PQ.push(nums2[P[k].second]);
                if (PQ.size() > K)
                {
                    total -= PQ.top(); PQ.pop();
                }
            }            
            i = j;
        }
        return result;
    }
};
