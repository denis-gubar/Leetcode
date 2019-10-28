class Solution {
public:
    bool canPermutePalindrome(string s) {
        vector<int> M(127);
        for(int c: s)
            ++M[c];
        int oddCount = 0;
        for(int m: M)            
            oddCount += m & 1;
        return oddCount < 2;
    }
};