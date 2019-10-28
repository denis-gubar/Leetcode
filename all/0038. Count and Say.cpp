class Solution {
public:
    string countAndSay(int n) {
        vector<string> F(n + 1);
        F[1] = "1";
        for(int i = 2; i <= n; ++i)
        {
            int count = 1;
            for(int pos = 1; pos <= F[i - 1].size(); ++pos)
                if (pos == F[i - 1].size() || F[i - 1][pos - 1] != F[i - 1][pos])
                {
                    F[i] += to_string(count);
                    F[i] += F[i - 1][pos - 1];
                    count = 1;
                }
                else
                    ++count;
        }
        return F[n];
    }
};