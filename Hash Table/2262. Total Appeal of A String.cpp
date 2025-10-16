class Solution {
public:
    long long appealSum(string const& s) {
        long long result = 0;
        vector<vector<int>> A(26);
        int N = s.size();
        for (int i = 0; i < N; ++i)
            A[s[i] - 'a'].push_back(i);
        set<pair<int, int>> D;
        for (int c = 0; c < 26; ++c)
            if (auto it = lower_bound(A[c].begin(), A[c].end(), 0); it != A[c].end())
                D.insert({ *it, c });
        for (int i = 0; i < N; ++i)
        {   
            D.insert({ N, -1 });
            int appeal = 0;
            for (auto it = D.begin(), sit = next(it); sit != D.end(); ++it, ++sit)
            {
                int count = sit->first - it->first;
                ++appeal;
                result += count * appeal;
            }
            int c = D.begin()->second;
            D.erase(D.begin());
            if (auto it = lower_bound(A[c].begin(), A[c].end(), i + 1); it != A[c].end())
                D.insert({ *it, c });
        }
        return result;
    }
};
