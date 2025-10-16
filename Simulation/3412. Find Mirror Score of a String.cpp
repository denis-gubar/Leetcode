class Solution {
public:
    long long calculateScore(string s) {
        long long result = 0;
        int const N = s.size();
        vector<set<int>> A(26);
        for (int i = 0; i < N; ++i)
            A[s[i] - 'a'].insert(i);
        for (int i = 0; i < N; ++i)
        {
            int c = s[i] - 'a';
            int m = 25 - c;
            if(!A[m].empty())
            {
                auto it = A[m].upper_bound(i);
                if (it != A[m].begin())
                {
                    --it;
                    int j = *it;
                    A[m].erase(it);
                    result += i - j;
                    A[c].erase(i);
                }
            }
        }
        return result;
    }
};
