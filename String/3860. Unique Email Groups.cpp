class Solution {
public:
    int uniqueEmailGroups(vector<string>& emails) {
        unordered_set<string> S;
        string buffer;
        buffer.reserve(100);
        for (string const& s : emails)
        {
            buffer.clear();
            bool isPrefix = true;
            bool isPlus = false;
            for (char c : s)
            {
                if (c == '@')
                    isPrefix = false;
                else if (c == '+')
                {
                    if (isPrefix)
                        isPlus = true;
                }
                else if (c == '.')
                {
                    if (isPrefix)
                        continue;
                }
                if (isPrefix && isPlus)
                    continue;
                buffer += ::tolower(c);
            }
            S.insert(buffer);
        }
        return S.size();
    }
};
