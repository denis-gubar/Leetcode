class Solution {
public:
    char repeatedCharacter(string s) {
        vector<bool> A(128);
        for (char c : s)
            if (A[c])
                return c;
            else
                A[c] = true;
        return 0;
    }
};
