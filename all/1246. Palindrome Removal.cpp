static unsigned char F[100][100];
class Solution {
public:
    int minimumMoves(vector<int>& arr) {
        int const N = arr.size();
        memset(F, 200, sizeof(F));
        for (int i = 0; i < N; ++i)
            F[i][i] = 1;
        for (int i = 1; i < N; ++i)
            F[i - 1][i] = 1 + (arr[i - 1] != arr[i]);
        auto update = [](unsigned char& x, unsigned char value)
            {
                if (x > value)
                    x = value;
            };
        for (int length = 3; length <= N; ++length)
            for (int start = 0; start + length <= N; ++start)
            {
                update(F[start][start + length - 1], F[start + 1][start + length - 2] + 2 * (arr[start] != arr[start + length - 1]));
                for (int mid = start; mid < start + length - 1; ++mid)
                    update(F[start][start + length - 1], F[start][mid] + F[mid + 1][start + length - 1]);
            }
        return F[0][N - 1];
    }
};
