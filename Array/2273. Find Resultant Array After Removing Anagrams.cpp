class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        vector<string> result;
        int N = words.size();
        for (int i = 0; i < N; ++i)
        {
            if (result.empty())
            {
                result.push_back(words[i]);
                continue;
            }
            string s = result.back();
            string t = words[i];
            sort(s.begin(), s.end());
            sort(t.begin(), t.end());
            if (s != t)
                result.push_back(words[i]);
        }
        return result;
    }
};
