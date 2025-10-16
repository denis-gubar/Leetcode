class Solution {
public:
    long long distinctNames(vector<string>& ideas) {
        long long result = 0;
        int N = ideas.size();        
        vector<vector<int>> A(26, vector<int>(26));
        unordered_map<string, vector<int>> X;
        for (int i = 0; i < N; ++i)
        {
            string suffix = ideas[i].substr(1);
            int k = ideas[i][0] - 'a';

            if (auto it = X.find(suffix); it != X.end())
                ++it->second[k];
            else
            {
                vector<int> Z(26);
                Z[k] = 1;
                X[suffix] = Z;
            }
        }
        for (auto& [key, value] : X)
            for (int i = 0; i < 26; ++i)
                if (value[i] > 0)
                    for(int j = 0; j < 26; ++j)
                        if (value[j] == 0)
                            A[i][j] += value[i];
        for (auto& [key, value] : X)
            for (int i = 0; i < 26; ++i)
                if (value[i] > 0)
                    for (int j = 0; j < 26; ++j)
                        if (value[j] == 0)
                            result += A[j][i];
        return result;
    }
};
