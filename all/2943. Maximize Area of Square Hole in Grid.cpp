class Solution {
public:
    int calc(vector<int> const& A)
    {
        int result = 1;
        int N = A.size();
        int count = 1;
        for (int i = 1; i < N; ++i)
            if (A[i] == A[i - 1] + 1)
                ++count;
            else
            {
                result = max(result, count);
                count = 1;
            }
        return max(result, count);
    }
    int maximizeSquareHoleArea(int N, int M, vector<int>& hBars, vector<int>& vBars) {
        int result = 0;
        sort(hBars.begin(), hBars.end());
        sort(vBars.begin(), vBars.end());
        int x = min(calc(hBars), calc(vBars)) + 1;
        return x * x;
    }
};
