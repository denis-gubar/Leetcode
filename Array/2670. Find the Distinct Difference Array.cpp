class Solution {
public:
    vector<int> distinctDifferenceArray(vector<int>& nums) {
        int N = nums.size();
        vector<int> result(N);
        auto calc = [&nums](int first, int last)
        {
            set<int> A(nums.begin() + first, nums.begin() + last + 1);
            return A.size();
        };
        for (int i = 0; i < N; ++i)
            result[i] = calc(0, i) - calc(i + 1, N - 1);
        return result;
    }
};
