class Solution {
public:
    long long numberOfWays(string s) {
        long long result = 0;
        vector<vector<long long>> F{ {0, 0}, {0, 0} };
        for(char c : s)
        {
            int i = c - '0';
            result += F[1][1 - i];
            F[1][i] += F[0][1 - i];
            ++F[0][i];
        }            
        return result;
    }
};
