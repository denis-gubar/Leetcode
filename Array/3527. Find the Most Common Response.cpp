class Solution {
public:
    string findCommonResponse(vector<vector<string>>& responses) {
        int const N = responses.size();
        string result;
        result += ('z' + 1);
        unordered_map<string, int> M;
        for (vector<string>& r : responses)
        {
            sort(r.begin(), r.end());
            r.resize(unique(r.begin(), r.end()) - r.begin());
            for (string const& s : r)
                ++M[s];
        }
        int best = 0;
        for (auto [key, value] : M)
            if (best < value)
                best = value;
        for (auto [key, value] : M)
            if (best == value && result > key)
                result = key;
        return result;
    }
};
