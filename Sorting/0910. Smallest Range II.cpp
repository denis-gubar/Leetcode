class Solution {
public:
    int smallestRangeII(vector<int>& A, int K) {
        sort(A.begin(), A.end());
        int result = A.back() - A[0];
        for(int i = 0; i + 1 < A.size(); ++i)
        {
            int high = max(A.back() - K, A[i] + K);
            int low = min(A[0] + K, A[i + 1] - K);
            result = min(result, high - low);
        }
        return result;
    }
};