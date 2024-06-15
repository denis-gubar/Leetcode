class Solution {
public:
    vector<int> calc(int N)
    {
        vector<int> result;
        while (N > 0)
        {
            result.push_back(N % 2);
            N /= 2;
        }
        return result;
    }
    long long minEnd(int N, int X) {
        long long result = 0;
        vector<int> A = calc(N - 1);
        vector<int> B = calc(X);
        int pos = 0;
        for (int x : A)
        {
            while (pos < B.size() && B[pos] == 1)
                ++pos;
            if (pos == B.size())
                B.push_back(x);
            else
                B[pos] = x;
            ++pos;
        }
        long long P = 1;
        for (int x : B)
        {
            result += P * x;
            P += P;
        }
        return result;
    }
};
