class Solution {
public:
    int fib(int N) {
        vector<int> F{0, 1};
        for(int i = 2; i <= N; ++i)
            F.push_back(F[i - 2] + F[i - 1]);
        return F[N];
    }
};