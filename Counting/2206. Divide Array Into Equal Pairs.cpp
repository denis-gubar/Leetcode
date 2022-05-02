class Solution {
public:
    bool divideArray(vector<int>& nums) {
        vector<int> M(501);
        for (int x : nums)
            ++M[x];
        for (int x : M)
            if (x % 2 == 1)
                return false;
        return true;
    }
};