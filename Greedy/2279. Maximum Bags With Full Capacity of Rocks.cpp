class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        int N = capacity.size();
        int result = 0;
        vector<int> A(N);
        for (int i = 0; i < N; ++i)
            A[i] = capacity[i] - rocks[i];
        sort(A.begin(), A.end());
        for (int i = 0; i < N; ++i)
        {
            if (A[i] > additionalRocks)
                break;
            additionalRocks -= A[i];
            ++result;
        }
        return result;
    }
};
