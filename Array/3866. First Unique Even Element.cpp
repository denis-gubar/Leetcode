class Solution {
public:
    int firstUniqueEven(vector<int>& nums) {
        unordered_map<int, int> M;
        for(int x : nums)
            ++M[x];
        for(int x : nums)
            if (M[x] == 1 && x % 2 == 0)
                return x;
        return -1;
    }
};