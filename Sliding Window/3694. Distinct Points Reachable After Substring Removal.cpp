static int X[100'001];
static int Y[100'001];
class Solution {
public:
    int distinctPoints(string s, int K) {
        set<pair<int, int>> S;
        X[0] = Y[0];
        int const N = s.size();
        for(int i = 0; i < N; ++i)
            switch (s[i])
            {
            case 'U':
                X[i + 1] = X[i], Y[i + 1] = Y[i] + 1;
                break;
            case 'D':
                X[i + 1] = X[i], Y[i + 1] = Y[i] - 1;
                break;
            case 'L':
                X[i + 1] = X[i] - 1, Y[i + 1] = Y[i];
                break;
            case 'R':
                X[i + 1] = X[i] + 1, Y[i + 1] = Y[i];
                break;
            default:
                break;
            }
        for (int i = 0; i + K <= N; ++i)
            S.insert({ X[i] + X[N] - X[i + K], Y[i] + Y[N] - Y[i + K] });
        return S.size();
    }
};
