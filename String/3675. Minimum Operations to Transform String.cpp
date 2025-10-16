class Solution {
public:
    int minOperations(string s) {
        int result = 0;
        vector<int> A(27);
        for (char c : s)
            ++A[c - 'a'];
        for (int c = 1; c < 26; ++c)
            A[c + 1] += A[c], result += A[c] > 0;
        return result;
    }
};
