class Solution {
public:
    string buffer;
    vector<int> parent;
    string s;
    int N;
    vector<vector<int>> children;
    vector<bool> result;
    vector<int> start, length;
    void dfs(int x)
    {
        start[x] = buffer.size() + 1;
        for (int y : children[x])
            dfs(y);
        buffer += '#';
        buffer += s[x];
        length[x] = buffer.size() - start[x];
    }
    vector<bool> findAnswer(vector<int>& parent, string s) {
        this->parent = parent;
        this->s = s;
        N = parent.size();
        buffer.reserve(4 * N);
        buffer += '^';
        start = vector<int>(N);
        length = vector<int>(N);
        children = vector<vector<int>>(N);
        for (int i = 1; i < N; ++i)
            children[parent[i]].push_back(i);
        result = vector<bool>(N);
        dfs(0);
        buffer += '#';
        buffer += '$';
        int B = buffer.size();
        vector<int> LPS(B);
        LPS[2] = 1;
        int C = 2, R = 3;
        for (int i = 3; i < B; ++i)
        {
            int iMirror = 2 * C - i;
            int diff = R - i;
            if (diff > 0)
                LPS[i] = min(LPS[iMirror], diff);
            while (buffer[i - LPS[i] - 1] == buffer[i + LPS[i] + 1])
                ++LPS[i];
            if (i + LPS[i] > R)
                R = i + LPS[i], C = i;
        }
        for (int i = 0; i < N; ++i)
            result[i] = LPS[start[i] + length[i] / 2] >= (length[i] + 1) / 2;
        return result;
    }
};
