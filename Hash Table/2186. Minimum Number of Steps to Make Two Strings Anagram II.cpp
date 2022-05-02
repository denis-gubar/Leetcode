class Solution {
public:
    int minSteps(string s, string t) {
        vector<int> A(256), B(256);
        for (int c : s)
            ++A[c];
        for (int c : t)
            ++B[c];
        int result = 0;
        for (int i = 0; i < 256; ++i)
            result += abs(A[i] - B[i]);
        return result;
    }
};
