class Solution {
public:
    vector<string> stringSequence(string target) {
        int const N = target.size();
        vector<string> result;
        string buffer;
        for (int i = 0; i < N; ++i)
        {
            if (buffer.size() < N)
            {
                buffer.push_back('a');
                result.push_back(buffer);
            }
            while (buffer.back() != target[i])
            {
                buffer.back() = (buffer.back() - 'a' + 1) % 26 + 'a';
                result.push_back(buffer);
            }
        }
        return result;
    }
};
