class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int const N = nums.size();
        if (N < 3)
            return N;
        int result = 2;
        while (result <= N)
            result <<= 1;
        return result;
    }
};