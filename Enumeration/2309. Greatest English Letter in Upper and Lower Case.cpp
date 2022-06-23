class Solution {
public:
    string greatestLetter(string s) {
        string result;
        vector<bool> A(128);
        for (char c : s)
            A[c] = true;
        for (char c = 'a'; c <= 'z'; ++c)
            if (A[c] && A[c + 'A' - 'a'])
                result = string(1, c + 'A' - 'a');
        return result;
    }
};
