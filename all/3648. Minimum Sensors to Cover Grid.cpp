class Solution {
public:
    int minSensors(int N, int M, int K) {
        int const a = (N + 2 * K) / (2 * K + 1);
        int const b = (M + 2 * K) / (2 * K + 1);
        return a * b;
    }
};