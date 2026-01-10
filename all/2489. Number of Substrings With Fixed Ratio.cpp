class Solution {
public:
    long long fixedRatio(string s, int num1, int num2) {
        unordered_map<int, int> M;
        int const N = s.size();
        long long result = 0;
        int balance = 0;
        ++M[0];
        for (int i = 0; i < N; ++i)
        {
            if (s[i] == '0')
                balance += num2;
            else
                balance -= num1;
            if (M.find(balance) != M.end())
                result += M[balance];
            ++M[balance];
        }
        return result;
    }
};
