class Solution {
public:
    int numJewelsInStones(string J, string S) {
        int result = 0;
        for(char c: S)
            result += J.find(c) != string::npos;
        return result;
    }
};