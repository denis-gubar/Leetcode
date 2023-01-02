class Solution {
public:
    int bestClosingTime(string customers) {
        int N = customers.size();
        int result = N;
        int best = N;
        vector<int> A(N);
        for (int i = N - 1; i >= 0; --i)
        {
            A[i] += customers[i] == 'Y';
            if (i < N - 1)
                A[i] += A[i + 1];
        }
        int x = 0;
        for (int i = 0; i < N; ++i)
        {
            int current = A[i] + x;
            if (best > current)
                best = current, result = i;
            x += customers[i] == 'N';
        }
        if (best > x)
            result = N;
        return result;
    }
};
