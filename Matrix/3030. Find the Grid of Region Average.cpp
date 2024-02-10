class Solution {
public:
    vector<vector<int>> resultGrid(vector<vector<int>>& image, int threshold) {
        int N = image.size(), M = image[0].size();
        vector<vector<int>> result(N, vector<int>(M));
        vector<vector<int>> A(N, vector<int>(M));
        vector<vector<int>> S(N, vector<int>(M));
        for(int i = 0; i + 3 <= N; ++i)
            for (int j = 0; j + 3 <= M; ++j)
            {
                bool isGood = true;
                int sum = 0;
                for(int dx = 0; isGood && dx < 3; ++dx)
                    for (int dy = 0; dy < 3; ++dy)
                    {
                        if (dx < 2 && abs(image[i + dx][j + dy] - image[i + dx + 1][j + dy]) > threshold)
                        {
                            isGood = false;
                            break;
                        }
                        if (dy < 2 && abs(image[i + dx][j + dy] - image[i + dx][j + dy + 1]) > threshold)
                        {
                            isGood = false;
                            break;
                        }
                        sum += image[i + dx][j + dy];
                    }
                if (isGood)
                    for (int dx = 0; dx < 3; ++dx)
                        for (int dy = 0; dy < 3; ++dy)
                            ++A[i + dx][j + dy], S[i + dx][j + dy] += sum / 9;
            }
        for (int i = 0; i < N; ++i)
            for (int j = 0; j < M; ++j)
                if (A[i][j] == 0)
                    result[i][j] = image[i][j];
                else
                    result[i][j] = S[i][j] / A[i][j];
        return result;
    }
};
