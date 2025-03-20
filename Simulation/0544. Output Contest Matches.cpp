class Solution {
public:
    string findContestMatch(int N) {
        string result;
        vector<int> A, B;
        A.reserve(N), B.reserve(N);
        A.push_back(1); A.push_back(2);
        while (A.size() < N)
        {
            B.clear();
            for (int M = A.size(), i = 0; i < M; ++i)
                B.push_back(A[i]), B.push_back(2 * M + 1 - A[i]);
            A.swap(B);
        }
        for (int i = 0; i < N; i += 2)
        {
            if (i == 0)
            {
                int x = N;
                while (x % 2 == 0)
                {
                    x >>= 1;
                    result += '(';
                }
            }
            else
            {
                int x = i;
                while (x % 2 == 0)
                {
                    x >>= 1;
                    result += ')';
                }
                result += ',';
                x = i;
                while (x % 2 == 0)
                {
                    x >>= 1;
                    result += '(';
                }
            }
            result += to_string(A[i]);
            result += ',';
            result += to_string(A[i + 1]);
        }
        int x = N;
        while (x > 1)
        {
            x >>= 1;
            result += ')';
        }
        return result;
    }
};
