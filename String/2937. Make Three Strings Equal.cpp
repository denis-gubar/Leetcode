class Solution {
public:
    int findMinimumOperations(string s1, string s2, string s3) {
        int N = min({ s1.size(), s2.size(), s3.size() });
        int total = s1.size() + s2.size() + s3.size();
        if (N == 1 && s1[0] == s2[0] && s1[0] == s3[0])
            return total - 3;
        for (int i = N - 1; i >= 0; --i)
            if (s1.substr(0, i + 1) == s2.substr(0, i + 1) &&
                s1.substr(0, i + 1) == s3.substr(0, i + 1))
                return total - i * 3 - 3;
        return -1;
    }
};
