class Solution {
public:
    typedef array<int, 26> A;
    A calc(string const& s)
    {
        A result;
        result.fill(0);
        for(char c: s)
            ++result[c - 'a'];
        return result;
    }
    int minSteps(string s, string t) {
        int result = 0, balance = 0;
        A a = calc(s), b = calc(t);
        for(int i = 0; i < 26; ++i)
        {
            int delta = abs(a[i] - b[i]);
            if (balance >= delta)
            {
                result += delta;
                balance -= delta;
            }
            else
            {
                result += balance;
                balance = delta - balance;
            }
        }
        return result + balance / 2;
    }
};