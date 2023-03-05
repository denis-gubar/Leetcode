class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle == "")
            return 0;
        int N = needle.size();
        for(int i = 0; i + N <= haystack.size(); ++i)
            if (equal(haystack.begin() + i, haystack.begin() + i + N, needle.begin(), needle.end()))
                return i;
        return -1;
    }
};