class Solution {
public:
    int longestContinuousSubstring(string s) {
        int result = 1;
        int current = 1;
        s.push_back('#');
        char prev = '$';
        for (char c : s)
        {
            if (prev + 1 != c)
            {
                result = max(result, current);
                current = 1;
            }
            else
                ++current;
            prev = c;
        }
        return result;
    }
};
