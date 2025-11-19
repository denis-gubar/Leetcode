class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int result = 0;
        int const N = nums.size();
        vector<pair<int, int>> A;
        A.reserve(N);
        int last = -1;
        for (int i = 0; i < N; ++i)
        {
            int j = i;
            while (j + 1 < N && nums[j] <= nums[j + 1])
                ++j;
            A.emplace_back(i, j);
            i = j;
        }
        int const P = A.size();
        for (int i = 0; i < P; ++i)
        {
            int const& x = A[i].first;
            int const& y = A[i].second;
            result = max(result, y - x + 1 + (x > 0 || y < N - 1));
            if (y > 0 && y < N - 1 && nums[y - 1] <= nums[y + 1])
                result = max(result, A[i + 1].second - x + 1);
            if (y > 0 && y < N - 2 && nums[y] <= nums[y + 2])
                result = max(result, A[i + 1].second - x + 1);
        }
        return result;
    }
};
