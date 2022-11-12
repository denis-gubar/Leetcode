class Solution {
public:
    vector<vector<string>> mostPopularCreator(vector<string>& creators, vector<string>& ids, vector<int>& views) {
        int N = creators.size();
        vector<vector<string>> result;
        unordered_map<string, long long> M;
        unordered_map<string, vector<pair<int, string>>> P;
        for (int i = 0; i < N; ++i)
        {
            M[creators[i]] += views[i];
            P[creators[i]].push_back({ -views[i], ids[i] });
        }
        long long best = 0;
        for (auto [key, value] : M)
            best = max(best, value);
        for (auto const& [key, value] : P)
            if (M[key] == best)
                result.push_back({ key, min_element(value.begin(), value.end())->second });
        return result;
    }
};
