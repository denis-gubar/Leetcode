class Solution {
public:
    int numberCount(int a, int b) {
        int result = 0;
        for(int x = a; x <= b; ++x)
        {
            string s = to_string(x);
            sort(s.begin(), s.end());
            result += unique(s.begin(), s.end()) == s.end();
        }
        return result;
    }
};