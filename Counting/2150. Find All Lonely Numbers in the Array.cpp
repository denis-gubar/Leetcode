class Solution {
public:
    vector<int> findLonely(vector<int>& nums) {
        vector<int> result;
        int N = nums.size();
        vector<int> M(1'000'003);
        for (int x : nums)
            ++M[x + 1];
        for (int x = 0; x <= 1'000'000; ++x)
            if (M[x] == 0 && M[x + 1] == 1 && M[x + 2] == 0)
                result.push_back(x);
        return result;
    }
};
