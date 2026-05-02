static int A[100'000];
class Solution {
public:
    vector<vector<int>> colorGrid(int N, int M, vector<vector<int>>& sources) {
        vector<vector<int>> result(N, vector<int>(M));
        array const dx{ -1, 0, 1, 0 };
        array const dy{ 0, -1, 0, 1 };
        memset(A, 0, sizeof(A));
        queue<int> NQ, Q;
        for (vector<int> const& s : sources)
        {
            int const& x = s[0];
            int const& y = s[1];
            int const& color = s[2];
            A[x * M + y] = color;
        }
        for (vector<int> const& s : sources)
        {
            int const& x = s[0];
            int const& y = s[1];
            for (int z = 0; z < 4; ++z)
            {
                int nx = x + dx[z];
                int ny = y + dy[z];
                if (nx >= 0 && nx < N && ny >= 0 && ny < M && A[nx * M + ny] == 0)
                {
                    A[nx * M + ny] = -1;
                    NQ.push(nx), NQ.push(ny);
                }
            }
        }
        while (!NQ.empty())
        {
            swap(Q, NQ);
            queue<int> updates;
            while (!Q.empty())
            {
                int x = Q.front(); Q.pop();
                int y = Q.front(); Q.pop();
                int color = -1;
                for (int z = 0; z < 4; ++z)
                {
                    int nx = x + dx[z];
                    int ny = y + dy[z];
                    if (nx >= 0 && nx < N && ny >= 0 && ny < M)
                    {
                        if (A[nx * M + ny] > 0)
                            color = max(color, A[nx * M + ny]);
                        else if (A[nx * M + ny] == 0)
                        {
                            A[nx * M + ny] = -1;
                            NQ.push(nx), NQ.push(ny);
                        }
                    }
                }
                updates.push(x * M + y), updates.push(color);
            }
            while (!updates.empty())
            {
                int const pos = updates.front(); updates.pop();
                int const color = updates.front(); updates.pop();
                A[pos] = color;
            }            
        }
        for (int x = 0; x < N; ++x)
            for (int y = 0; y < M; ++y)
                result[x][y] = A[x * M + y];
        return result;
    }
};
