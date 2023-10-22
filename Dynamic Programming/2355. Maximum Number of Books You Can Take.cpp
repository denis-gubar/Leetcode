class Solution {
public:
    long long calc(vector<int> const& books, int L, int R)
    {
        long long x = min(books[R], R - L + 1);
        return (2 * books[R] - x + 1) * x / 2;
    }
    long long maximumBooks(vector<int>& books) {
        int N = books.size();
        vector<long long> F(N);
        stack<int> S;
        for (int i = 0; i < N; ++i)
        {
            while (!S.empty() && books[S.top()] - S.top() >= books[i] - i)
                S.pop();
            if (S.empty())
                F[i] = calc(books, 0, i);
            else
            {
                int j = S.top();
                F[i] = F[j] + calc(books, j + 1, i);
            }
            S.push(i);
        }
        return *max_element(F.begin(), F.end());
    }
};
