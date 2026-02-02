class Solution {
public:
    string reverseByType(string s) {
        string result;
        vector<int> A, B;
        for (char c : s)
            if (c >= 'a' && c <= 'z')
                A.push_back(c);
            else
                B.push_back(c);
        for (char c : s)
            if (c >= 'a' && c <= 'z')
                result += A.back(), A.pop_back();
            else
                result += B.back(), B.pop_back();
        return result;
    }
};