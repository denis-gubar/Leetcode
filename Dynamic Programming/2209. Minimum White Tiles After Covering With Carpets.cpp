class Solution {
public:
    int minimumWhiteTiles(string floor, int numCarpets, int carpetLen) {
        int result = 0;
        int N = floor.size();
        if (numCarpets * carpetLen >= N)
            return 0;
        vector<int> A(N + 1);
        for (int i = 0; i < N; ++i)
            A[i + 1] = A[i] + (floor[i] - '0');
        if (carpetLen == 1)
            return max(0, A[N] - numCarpets);
        if (carpetLen == 2)
        {
            int result = A[N];
            list<char> L(floor.begin(), floor.end());
            auto it = L.begin();
            while (numCarpets > 0 && it != L.end() && next(it) != L.end())
            {
                if (*it == '1' && *next(it) == '1')
                {
                    it = L.erase(L.erase(it));
                    --numCarpets, result -= 2;
                    continue;
                }
                ++it;
            }
            result = max(0, result - numCarpets);
            return result;
        }
        vector<vector<int>> F(N + 1, vector<int>(numCarpets + 1, N + 2));
        F[0][0] = A[N];
        for(int i = 0; i < N; ++i)
            for (int j = 0, jmax = min(numCarpets, (i + carpetLen - 1) / carpetLen); j <= jmax; ++j)
            {
                F[i + 1][j] = min(F[i + 1][j], F[i][j]);
                if (i + carpetLen > N)
                    continue;
                F[i + carpetLen][j] = min(F[i + carpetLen][j], F[i][j]);
                if (j < numCarpets)
                    F[i + carpetLen][j + 1] = min(F[i + carpetLen][j + 1], F[i][j] - (A[i + carpetLen] - A[i]));
            }        
        return *min_element(F[N].begin(), F[N].end());
    }
};
