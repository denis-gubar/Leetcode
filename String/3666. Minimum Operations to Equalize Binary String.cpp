static int A[2];
class Solution {
public:
    int minOperations(string s, int K) {
        A[0] = A[1] = 0;
        int const N = s.size();
        for (char c : s)
            ++A[c - '0'];
        queue<int> Q;
        array<set<int>, 2> S{ set<int>{}, set<int>{} };
        for (int i = 0; i <= N; ++i)
            if (i != A[1])
                S[i % 2].insert(i);
        Q.push(A[1]), Q.push(0);
        while (!Q.empty())
        {
            int const x = Q.front(); Q.pop();
            int const t = Q.front(); Q.pop();
            if (x == N)
                return t;
            int nx = abs(x - K);
            int nxEnd = N - abs(N - x - K);
            for (auto it = S[nx % 2].lower_bound(nx); it != S[nx % 2].end() && *it <= nxEnd; it = S[nx % 2].erase(it))
                Q.push(*it), Q.push(t + 1);
        }
        return -1;
    }
};
