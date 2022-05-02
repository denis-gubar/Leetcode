class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string> result;
        int N = s.size();
        for (int i = 0; i < N; i += k)
        {
            string t = s.substr(i, k);
            while (t.size() < k)
                t += fill;
            result.push_back(t);
        }
        return result;
    }
};
