class Solution {
public:
    bool isBalanced(string num) {
        vector<int> A(2);
        int const N = num.size();
        for (int i = 0; i < N; ++i)
            A[i % 2] += num[i] - '0';
        return A[0] == A[1];
    }
};
