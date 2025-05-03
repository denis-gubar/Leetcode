static bool F[3][2'048];
class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int result = 0;
        sort(nums.begin(), nums.end());
        nums.resize(unique(nums.begin(), nums.end()) - nums.begin());
        int const N = nums.size();
        memset(F, 0, sizeof(F));
        for (int x : nums)
            F[0][x] = true;
        for (int k = 0; k < 2; ++k)
            for (int i = 0; i < 2'048; ++i)
                if (F[k][i])
                    for (int x : nums)
                        F[k + 1][i ^ x] = true;
        for (int i = 0; i < 2'048; ++i)
            result += F[2][i];
        return result;
    }
};
