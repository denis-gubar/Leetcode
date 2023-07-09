class Solution {
public:
    long long coloredCells(int N) {
        long long result = 1LL + 4LL * N * (N - 1) / 2;        
        return result;
    }
};
