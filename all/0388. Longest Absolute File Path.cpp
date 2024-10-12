class Solution {
public:
    int lengthLongestPath(string input) {
        int result = 0;
        vector<int> A(10'000);
        string buffer;
        buffer.reserve(10'000);
        bool dotFound = false;
        int level = 1;
        input += '
';
        for (char c : input)
        {
            if (c == '
')
            {
                if (dotFound)
                    result = max<int>(result, A[level - 1] + buffer.size() + level - 1);
                else
                    A[level] = A[level - 1] + buffer.size();
                buffer.clear();
                level = 1;
                dotFound = false;
            }
            else if (c == '	')
                ++level;
            else if (c == '.')
            {
                dotFound = true;
                buffer += c;
            }
            else
                buffer += c;
        }
        return result;
    }
};
