static int const MOD = 1'000'000'007;
class Solution {
public:
    int countPermutations(vector<int>& complexity) {
        int const N = complexity.size();
        int root = complexity[0];
        sort(complexity.begin(), complexity.end());
        if (complexity[0] < root || complexity[0] == root && complexity[1] == root)
            return 0;
        int result = 1;
        for (int i = 1; i < N; ++i)
            result = 1LL * result * i % MOD;
        return result;
    }
};
