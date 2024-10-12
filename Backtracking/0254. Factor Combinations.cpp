class Solution {
public:
    int N, D;
    vector<int> divs;
    vector<vector<int>> result;
    vector<int> A;
    void calc(int x, int i = 0, int last = -1)
    {
        for (int ni = i; ni < D; ++ni)
        {
            if (ni > 0 && divs[ni] == divs[ni - 1] && ni > last + 1)
                continue;
            if (1LL * x * divs[ni] > N)
                break;            
            if (divs[ni] * x == N)
            {
                A.push_back(divs[ni]);
                result.push_back(A);
                A.pop_back();
                continue;
            }
            A.push_back(divs[ni]);
            calc(divs[ni] * x, ni + 1, ni);
            A.pop_back();
        }
    }
    vector<vector<int>> getFactors(int N) {
        this->N = N;
        result.clear();
        divs.reserve(500);
        A.reserve(25);
        auto add = [this, N](int x)
            {
                long long k = x;
                while (N >= k && N % k == 0)
                    divs.push_back(x), k *= x;
            };
        for (int x = 2; x * x <= N; ++x)
            if (N % x == 0)
            {
                add(x);
                if (x != N / x)
                    add(N / x);
            }
        sort(divs.begin(), divs.end());
        D = divs.size();
        calc(1);
        return result;
    }
};
