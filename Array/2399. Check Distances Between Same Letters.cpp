class Solution {
public:
    bool checkDistances(string s, vector<int>& distance) {
        vector<vector<int>> A(26);
        int N = s.size();
        for (int i = 0; i < N; ++i)
            A[s[i] - 'a'].push_back(i);
        for (int i = 0; i < N; ++i)
            if (A[s[i] - 'a'][1] - A[s[i] - 'a'][0] != distance[s[i] - 'a'] + 1)
                return false;
        return true;
    }
};
