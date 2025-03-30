class Solution {
public:
    string decodeString(string s) {
        stack<pair<int, string>> S;
        S.push({}); 
        S.top().second.reserve(100'000);
        for (char c : s)
        {
            if (isdigit(c))
                S.top().first = S.top().first * 10 + (c - '0');
            else if (c >= 'a' && c <= 'z')
                S.top().second += c;
            else if (c == '[')
            {
                S.push({});
                S.top().second.reserve(100'000);
            }
            else
            {
                string buffer;
                buffer.swap(S.top().second);
                S.pop();
                for (int k = 0; k < S.top().first; ++k)
                    S.top().second += buffer;
                S.top().first = 0;
            }
        }
        return S.top().second;
    }
};
