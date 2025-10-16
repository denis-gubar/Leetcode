class Solution {
public:
    string removeSubstring(string s, int K) {
        string result;
        s += '$';
        int const N = s.size();
        vector<int> A, B;
        A.reserve(N);
        B.reserve(N);
        result.reserve(N);
        int count = 0;
        char prev = '^';
        for (char c : s)
            if (c == prev)
                ++count;
            else
            {
                if (count > 0)
                {
                    if (prev == '(')
                        A.push_back(count);
                    else
                        A.push_back(-count);
                }
                prev = c, count = 1;
            }
        auto sign = [](int x)
            {
                if (x > 0)
                    return 1;
                return -1;
            };
        auto add = [&B, &sign](int x)
            {
                if (x == 0)
                    return;
                if (!B.empty() && sign(B.back()) == sign(x))
                    B.back() += x;
                else
                    B.push_back(x);
            };
        for (int x : A)
        {
            B.push_back(x);
            bool flag = true;
            while (flag && B.size() > 1)
            {
                flag = false;
                int a = B[B.size() - 2], b = B.back();
                B.pop_back(), B.pop_back();
                if (a >= K && b <= -K)
                    a -= K, b += K, flag = true;
                add(a);
                add(b);
            }
        }
        for (int x : B)
            if (x < 0)
                for (int k = 0; k < -x; ++k)
                    result += ')';
            else
                for (int k = 0; k < x; ++k)
                    result += '(';
        return result;
    }
};
