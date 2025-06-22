static short M[30'001][2][2];
class Solution {
public:
    int maxDifference(string s, int K) {
        int const N = s.size();
        short const INF = 30'001;
        short result = -30'000;
        vector<vector<short>> positions(5);
        for (int i = 0; i < 5; ++i)
            positions.reserve(N + 1);
        for (int i = 0; i < N; ++i)
        {
            short const x = s[i] - '0';
            positions[x].push_back(i);
        }
        for (int i = 0; i < 5; ++i)
            positions[i].push_back(N);
        for (int a = 0; a < 5; ++a)
            if (positions[a].size() > 1)
                for (int b = 0; b < 5; ++b)
                    if (a != b && positions[b].size() > 2)
                    {
                        short i = 0;
                        short j = 0;
                        for (short next = 0; next < N; ++next)
                        {
                            if (positions[a][i] == next)
                                ++i;
                            if (positions[b][j] == next)
                                ++j;
                            if (next == 0)
                            {
                                M[0][0][0] = 0;
                                M[0][0][1] = INF;
                                M[0][1][0] = INF;
                                M[0][1][1] = INF;
                            }
                            M[next + 1][0][0] = M[next][0][0];
                            M[next + 1][0][1] = M[next][0][1];
                            M[next + 1][1][0] = M[next][1][0];
                            M[next + 1][1][1] = M[next][1][1];
                            M[next + 1][i % 2][j % 2] = min<short>(M[next + 1][i % 2][j % 2], i - j);
                            if (i == 0 || j < 2)
                                continue;
                            short val = min({ static_cast<short>(next - K), positions[a][i - 1], positions[b][j - 2] });
                            if (val < -1)
                                continue;
                            if (M[val + 1][1 - i % 2][j % 2] != INF && result < (i - j) - M[val + 1][1 - i % 2][j % 2])
                                result = (i - j) - M[val + 1][1 - i % 2][j % 2];
                        }
                    }
        return result;
    }
};
