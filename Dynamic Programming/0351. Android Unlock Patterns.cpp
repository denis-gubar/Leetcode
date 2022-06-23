class Solution {
public:
    unordered_map<int, int> M;
    int calc(int mask, int i, int prev = 0)
    {
        int result = 0;
        if (i <= n)
        {
            for(int k = 1; k < 10; ++k)
                if ((mask & (1 << k)) == 0)
                {
                    bool isOk = true;
                    if (auto it = M.find((1 << k) | (1 << prev)); it != M.end())
                        isOk = (it->second & mask) != 0;
                    if (!isOk)
                        continue;
                    if (i >= m)
                        ++result;
                    int newMask = mask | (1 << k);                    
                    result += calc(newMask, i + 1, k);
                }
        }
        return result;
    }
    int numberOfPatterns(int m, int n) {
        this->m = m; this->n = n;
        auto f = [this](int a, int b, int middle)
        {
            M[(1 << a) | (1 << b)] = 1 << middle;
        };
        f(1, 3, 2);
        f(4, 6, 5);
        f(7, 9, 8);
        f(1, 7, 4);
        f(2, 8, 5);
        f(3, 9, 6);
        f(1, 9, 5);
        f(3, 7, 5);
        return calc(0, 1);
    }
    int m, n;
};