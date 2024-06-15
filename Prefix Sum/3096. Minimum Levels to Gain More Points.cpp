class Solution {
public:
    int minimumLevels(vector<int>& possible) {
        int N = possible.size();
        vector<int> A(N + 1);
        for (int i = 0; i < N; ++i)
            A[i + 1] = A[i] + possible[i] * 2 - 1;
        for (int i = 1; i < N; ++i)
        {
            int D = A[i];
            int B = A[N] - A[i];
            if (D > B)
                return i;
        }
        return -1;
    }
};
