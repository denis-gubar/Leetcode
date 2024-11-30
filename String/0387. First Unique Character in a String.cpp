class Solution {
public:
    int firstUniqChar(string s) {
        int result = -1;
        vector<int> A(26, -1);
        int const N = s.size();
        for (int i = 0; i < N; ++i)
        {
            int x = s[i] - 'a';
            if (A[x] == -1)
                A[x] = i;
            else
                A[x] = -2;
        }
        for (int c = 0; c < 26; ++c)
            if (A[c] >= 0 && (result == -1 || result > A[c]))
                result = A[c];
        return result;
    }
};
