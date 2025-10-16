class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int N = blocks.size();
        int result = N;
        vector<int> A(N + 1);
        for (int i = 0; i < N; ++i)
            A[i + 1] = A[i] + (blocks[i] == 'W');
        for (int i = 0; i + k <= N; ++i)
            result = min(result, A[i + k] - A[i]);
        return result;
    }
};
