class Solution {
public:
    int N;
    vector<int> result;
    void calc(int x)
    {
        if (x > N) return;
        if (x > 0)
            result.push_back(x);
        x *= 10;
        for (int d = (x == 0); d < 10; ++d)
            calc(x + d);
    }
    vector<int> lexicalOrder(int n) {
        N = n;
        result.reserve(N);
        calc(0);
        return result;
    }
};
