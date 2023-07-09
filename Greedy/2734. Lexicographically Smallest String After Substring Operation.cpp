class Solution {
public:
    string smallestString(string s) {
        int N = s.size();
        int pos = 0;
        while (pos < N && s[pos] == 'a')
            ++pos;
        if (pos == N)
            s.back() = 'z';
        else
            for (; pos < N && s[pos] != 'a'; ++pos)
                --s[pos];
        return s;
    }
};
