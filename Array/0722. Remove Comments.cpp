class Solution {
public:
    vector<string> removeComments(vector<string>& source) {
        vector<string> result;
        int const N = source.size();
        result.reserve(N);
        bool isMultilineComment = false;
        string buffer;
        buffer.reserve(80);
        for (int i = 0; i < N; ++i)
        {
            for(int j = 0, M = source[i].size(); j < M; ++j)
                if (isMultilineComment)
                {
                    if (source[i][j] == '*' && j < M - 1 && source[i][j + 1] == '/')
                        ++j, isMultilineComment = false;
                }
                else
                {
                    if (source[i][j] == '/' && j < M - 1 && source[i][j + 1] == '/')
                        break;
                    if (source[i][j] == '/' && j < M - 1 && source[i][j + 1] == '*')
                        ++j, isMultilineComment = true;
                    else
                        buffer += source[i][j];
                }
            if (isMultilineComment)
                continue;
            if (!buffer.empty())
                result.emplace_back(buffer);
            buffer.clear();
        }
        return result;
    }
};
