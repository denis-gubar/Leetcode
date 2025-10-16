class Solution {
public:
    bool matchReplacement(string s, string sub, vector<vector<char>>& mappings) {
        int N = s.size(), M = sub.size();
        vector<vector<bool>> F(128, vector<bool>(128));
        for (vector<char> const& row : mappings)
        {
            char const& old_i = row[0];
            char const& new_i = row[1];
            F[old_i][new_i] = true;
        }
        for (int i = 0; i < 128; ++i)
            F[i][i] = true;
        for (int start = 0; start + M <= N; ++start)
        {
            bool found = true;
            for(int i = 0; i < M; ++i)
                if (!F[sub[i]][s[start + i]])
                {
                    found = false;
                    break;
                }
            if (found)
                return true;
        }
        return false;
    }
};
