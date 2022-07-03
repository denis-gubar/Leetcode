class Solution {
public:
    string decodeMessage(string key, string message) {
        string result;
        unordered_map<int, int> M;
        for(char c : key)
            if (c != ' ' && M.find(c - 'a') == M.end())
                M[c - 'a'] = M.size() + 'a';
        for (char c : message)
            if (c == ' ')
                result += ' ';
            else
                result += M[c - 'a'];
        return result;
    }
};
