class Solution {
public:
    int numberOfSubstrings(string s) {
        int result = 0;
        int const N = s.size();
        vector<int> A;
        A.reserve(N + 2);
        A.push_back(-1);
        for (int i = 0; i < N; ++i)
            if (s[i] == '0')
                A.push_back(i);
        A.push_back(N);
        int const X = sqrt(N) + 2;
        int const M = A.size();
        for(int L = 0; L < M; ++L)
            for (int R = L + 1; R - L < X && R < M; ++R)
            {
                int length = A[R] - A[L] - 1;
                int zeroCount = R - L - 1;
                if (zeroCount == 0)
                {
                    result += length * (length + 1) / 2;
                    continue;
                }
                int onesCount = length - zeroCount;
                if (onesCount < zeroCount * zeroCount)
                    continue;
                int left = A[L + 1] - A[L] - 1;
                int right = A[R] - A[R - 1] - 1;
                int delta = min(left + right, onesCount - zeroCount * zeroCount);
                if (left > right)
                    swap(left, right);
                int z = min(left, delta);
                for (int x = 0; x <= z; ++x)
                    result += min(right, delta - x) + 1;
            }
        return result;
    }
};
