class Solution {
public:
    int countTexts(string pressedKeys) {
        constexpr int MOD = 1'000'000'007;
        int N = pressedKeys.size();
        vector<int> F(N + 1);
        F[0] = 1;
        for (int i = 0; i < N; ++i)
            for (int k = 0; k < 3 + (pressedKeys[i] == '9' || pressedKeys[i] == '7') && i - k >= 0 && pressedKeys[i - k] == pressedKeys[i]; ++k)
            {
                F[i + 1] += F[i - k];
                F[i + 1] %= MOD;
            }
        return F[N];
    }
};
