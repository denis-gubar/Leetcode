class Solution {
public:
    int maxBoxesInWarehouse(vector<int>& boxes, vector<int>& warehouse) {
        int result = 0;
        sort(boxes.begin(), boxes.end());
        int N = warehouse.size();
        vector<int> A(N), B(N);
        for (int i = 0; i < N; ++i)
            if (i == 0 || A[i - 1] > warehouse[i])
                A[i] = warehouse[i];
            else
                A[i] = A[i - 1];
        for (int i = N - 1; i >= 0; --i)
            if (i == N - 1 || B[i + 1] > warehouse[i])
                B[i] = warehouse[i];
            else
                B[i] = B[i + 1];
        for (int i = 0; i < N; ++i)
            if (B[i] > A[i])
                A[i] = B[i];
        sort(A.begin(), A.end());
        while (!boxes.empty() && !A.empty())
        {
            if (boxes.back() <= A.back())
                A.pop_back(), ++result;
            boxes.pop_back();
        }
        return result;
    }
};
