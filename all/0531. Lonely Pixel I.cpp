class Solution {
public:
    int findLonelyPixel(vector<vector<char>>& picture) {
        int N = picture.size(), M = picture[0].size();
        vector<int> rows(N), columns(M);
        for(int i = 0; i < N; ++i)
            for(int j = 0; j < M; ++j)
                if (picture[i][j] == 'B')
                    ++rows[i], ++columns[j];
        int result = 0;
        for(int i = 0; i < N; ++i)
            for(int j = 0; j < M; ++j)
                result += (rows[i] == 1 && columns[j] == 1 && picture[i][j] == 'B');
        return result;
    }
};