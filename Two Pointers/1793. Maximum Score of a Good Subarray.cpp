class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        int result = 0;
        int N = nums.size();
        vector<pair<int, int>> P(N);
        for (int i = 0; i < N; ++i)
            P[i] = { nums[i], i };
        sort(P.begin(), P.end());
        vector<int> L(N, -1), R(N, -1);
        while (!P.empty())
        {
            int const& x = P.back().first;
            int const& pos = P.back().second;
            int left = pos, right = pos;
            if (left > 0 && L[pos - 1] >= 0)
                left = L[pos - 1];
            if (right < N - 1 && R[pos + 1] >= 0)
                right = R[pos + 1];
            R[left] = right; L[right] = left;
            if (left <= k && k <= right)
                result = max(result, (right - left + 1) * x);
            P.pop_back();
        }
        return result;
    }
};
