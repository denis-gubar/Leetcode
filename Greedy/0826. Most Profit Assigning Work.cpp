class Solution {
public:
    int maxProfitAssignment( vector<int>& difficulty, vector<int>& profit, vector<int>& worker ) {
        int result = 0;
        vector<int> A( 100001 );
        for (int i = 0; i < profit.size(); ++i)
            A[difficulty[i]] = max( A[difficulty[i]], profit[i] );
        int bestProfit = 0;
        for (int i = 0; i < A.size(); ++i)
        {
            bestProfit = max( bestProfit, A[i] );
            A[i] = bestProfit;
        }
        for (int w : worker)
            result += A[w];
        return result;
    }
};