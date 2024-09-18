static int A[100'001];
class Solution {
public:
    int maxProfitAssignment( vector<int>& difficulty, vector<int>& profit, vector<int>& worker ) {
        int result = 0;
        memset(A, 0, sizeof(A));
        for (int i = 0; i < profit.size(); ++i)
            A[difficulty[i]] = max( A[difficulty[i]], profit[i] );
        int bestProfit = 0;
        for (int i = 0; i < 100'001; ++i)
        {
            bestProfit = max( bestProfit, A[i] );
            A[i] = bestProfit;
        }
        for (int w : worker)
            result += A[w];
        return result;
    }
};