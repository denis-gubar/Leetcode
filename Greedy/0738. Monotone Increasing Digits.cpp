class Solution {
public:
    int monotoneIncreasingDigits(int n) {
        string s{ to_string(n) };
        int const N = s.size();
        string result(N, '0');
        int d = 0;
        for (int i = 0; i < N; ++i)
        {
            for (int j = 9; j >= d; --j)
            {
                for (int k = i; k < N; ++k)
                    result[k] = j + '0';
                if (result <= s)
                {
                    d = j;
                    break;
                }
            }
        }
        return stoi(result);
    }
};
