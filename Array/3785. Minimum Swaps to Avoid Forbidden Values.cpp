class Solution {
public:
    int minSwaps(vector<int>& nums, vector<int>& forbidden) {
        int result = 0;
        int const N = nums.size();
        unordered_map<int, array<int, 3>> M;
        unordered_map<int, int> C;
        for (int i = 0; i < N; ++i)
        {
            int const& key = nums[i];
            if (M.find(key) == M.end())
                M[key] = { 0, 0, 0 };
            ++M[key][0];
            ++M[key][1 + (forbidden[i] != key)];
            ++C[forbidden[i]];
        }
        int total = 0, top = 0;
        for (auto [key, value] : M)
        {
            if (value[1] > N - value[0] || C.find(key) != C.end() && value[0] > N - C[key])
                return -1;
            total += value[1];
            top = max(top, value[1]);
        }
        return max(top, (total + 1) / 2);
    }
};
