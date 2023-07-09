class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int K) {
        vector<vector<int>> result;
        result.reserve(K);
        int N = nums1.size(), M = nums2.size();
        auto cmp = [&nums1, &nums2](vector<int>& a, vector<int>& b)
        {
            return nums1[a[0]] + nums2[a[1]] > nums1[b[0]] + nums2[b[1]];
        };
        priority_queue<vector<int>, vector<vector<int>>, decltype(cmp)> PQ(cmp);
        PQ.push({ 0, 0 });
        for (int k = 0; k < K && !PQ.empty(); ++k)
        {
            vector<int> V = PQ.top(); PQ.pop();
            if (V[1] == 0 && V[0] < N - 1)
                PQ.push({ V[0] + 1, 0 });
            if (V[1] < M - 1)
                PQ.push({ V[0], V[1] + 1 });
            result.push_back({ nums1[V[0]], nums2[V[1]] });
        }
        return result;
    }
};
