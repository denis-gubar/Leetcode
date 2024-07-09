class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int result = 0;
        int length = 0;
        vector<int> A(colors);
        int N = colors.size();
        A.reserve(2 * N);
        for (int i = 0; i < N; ++i)
            A.push_back(A[i]);
        for (int i = 1; i < 2 * N; ++i)
        {
            if (i == N)
                result = 0;
            if (A[i] != A[i - 1])
                ++length;
            else
                length = 1;
            if (length >= k)
                ++result;
        }
        return result;
    }
};
