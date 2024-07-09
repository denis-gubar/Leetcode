class Solution {
public:
    string getEncryptedString(string s, int k) {
        int N = s.size();
        k %= N;
        rotate(s.begin(), s.begin() + k, s.end());
        return s;
    }
};
