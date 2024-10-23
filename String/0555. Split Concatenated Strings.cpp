class Solution {
public:
    string splitLoopedString(vector<string>& strs) {
        string result;
        string s;
        s.reserve(2'000);
        for(string const& str : strs)
        {
            if (lexicographical_compare(str.rbegin(), str.rend(), str.begin(), str.end()))
                s += str;
            else
                copy(str.rbegin(), str.rend(), back_inserter(s));
        }
        int const N = s.size();
        s += s;
        vector<bool> chars(26);
        for (int i = 0; i < N; ++i)
            chars[s[i] - 'a'] = true;
        char c = 'z';
        while(true)
        {
            if (chars[c - 'a'])
                break;
            --c;
        }
        int j = 0;
        for (string const& str : strs)
        {
            int i = j;
            for (int k = 0; k < str.size(); ++j, ++k)
            {
                if (s[j] == c && lexicographical_compare(result.begin(), result.end(), s.begin() + j, s.begin() + j + N))
                    result = s.substr(j, N);
            }
            reverse(s.begin() + i, s.begin() + j);
            reverse(s.begin() + i + N, s.begin() + j + N);
            j = i;
            for (int k = 0; k < str.size(); ++j, ++k)
            {
                if (s[j] == c && lexicographical_compare(result.begin(), result.end(), s.begin() + j, s.begin() + j + N))
                    result = s.substr(j, N);
            }
            reverse(s.begin() + i + N, s.begin() + j + N);
        }
        return result;
    }
};
