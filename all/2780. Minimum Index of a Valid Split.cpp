class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        int N = nums.size();
        unordered_map<int, int> M;
        for (int x : nums)
            ++M[x];
        int x = 0, count = 0;
        for (auto [key, value] : M)
            if (value > count)
                x = key, count = value;
        int left = 0, right = count;
        for (int i = 0; i < N; ++i)
        {
            if (nums[i] == x)
                ++left, --right;
            if (left * 2 > i + 1 && right * 2 > N - i - 1)
                return i;
        }
        return -1;
    }
};
