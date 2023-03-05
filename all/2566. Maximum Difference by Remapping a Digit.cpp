class Solution {
public:
    int minMaxDifference(int num) {
        string s = to_string(num);
        int N = s.size();
        int a = num, b = num;
        for (int j = '0'; j <= '9'; ++j)
            for (int k = '0'; k <= '9'; ++k)
            {
                string t = s;
                for (int i = 0; i < N; ++i)
                    if (t[i] == j)
                        t[i] = k;
                int x = stoi(t);
                a = min(a, x);
                b = max(b, x);
            }
        return b - a;
    }
};
