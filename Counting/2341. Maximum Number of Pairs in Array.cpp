class Solution {
public:
    vector<int> numberOfPairs(vector<int>& nums) {
        vector<int> result;
        int N = nums.size();
        vector<int> M(101);
        for (int x : nums)
            ++M[x];
        int a = 0;
        for (int x : M)
            a += x / 2;
        return { a, N - a * 2 };
    }
};
