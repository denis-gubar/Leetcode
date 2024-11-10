class Solution {
public:
    int possibleStringCount(string word) {
        int result = 1;
        word += '$';
        char prev = '^';
        int count = 1;
        for (char c : word)
            if (c == prev)
                ++count;
            else
                result += count - 1, count = 1, prev = c;
        return result;
    }
};
