class Solution {
public:
    int similarPairs(vector<string>& words) {
        int N = words.size();
        int result = 0;
        for (int i = 0; i < N; ++i)
        {
            set<char> a(words[i].begin(), words[i].end());
            for (int j = i + 1; j < N; ++j)
            {
                set<char> b(words[j].begin(), words[j].end());
                result += a == b;
            }
        }
        return result;
    }
};
