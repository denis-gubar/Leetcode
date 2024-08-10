class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        vector<int> A(3);
        for (int x : stones)
            ++A[x % 3];
        if (A[0] % 2 == 0)
            return A[1] > 0 && A[2] > 0;
        return abs(A[1] - A[2]) > 2;
    }
};
