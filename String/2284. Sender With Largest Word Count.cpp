class Solution {
public:
    vector<string> split(const string& s, char delimeter = ' ')
    {
        vector<string> result;
        istringstream ss(s);
        for (string token; !ss.eof(); )
        {
            getline(ss, token, delimeter);
            result.push_back(token);
        }
        return result;
    }
    string largestWordCount(vector<string>& messages, vector<string>& senders) {
        int N = messages.size();
        string result;
        int best = 0;
        unordered_map<string, int> M;
        for (int i = 0; i < N; ++i)
            M[senders[i]] += split(messages[i]).size();
        for (auto [key, value] : M)
            if (value > best)
            {
                best = value;
                result = key;
            }
            else if (value == best && result < key)
                result = key;
        return result;
    }
};
