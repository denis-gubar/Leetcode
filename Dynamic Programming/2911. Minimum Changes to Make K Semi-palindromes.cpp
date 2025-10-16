static int F[200][200];
static int A[201][200];
static bool isInit = false;
static vector<vector<int>> divs(201);
static void init()
{
    if (!isInit)
    {
        isInit = true;
        for (int x = 2; x <= 200; ++x)
            for (int d = 1; d < x; ++d)
                if (x % d == 0)
                    divs[x].push_back(d);
    }
}
class Solution {
public:
    int minimumChanges(string s, int k) {
        init();
        int N = s.size();
        memset(F, 1, sizeof(F));
        memset(A, 1, sizeof(A));
        for (int first = 0; first < N; ++first)
        {
            F[first][first] = 0;
            for (int last = first + 1; last < N; ++last)
            {
                int& best = F[first][last];
                int x = last - first + 1;
                for (int d : divs[x])
                {
                    int current = 0;
                    for (int z = 0; z < d; ++z)
                        for (int a = first + z, b = last + 1 - d + z; a < b; a += d, b -= d)
                            current += s[a] != s[b];
                    best = min(best, current);
                }
            }
        }
        A[0][0] = 0;
        for(int i = 0; i < N; ++i)
            for (int j = 0, jMax = min(i + 1, k); j < jMax; ++j)
                if (A[i][j] <= N)
                {
                    for (int nextI = i + 2; nextI <= N; ++nextI)
                        A[nextI][j + 1] = min(A[nextI][j + 1], A[i][j] + F[i][nextI - 1]);
                }
        return A[N][k];
    }
};
