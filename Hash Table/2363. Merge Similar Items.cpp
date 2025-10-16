class Solution {
public:
    vector<vector<int>> mergeSimilarItems(vector<vector<int>>& items1, vector<vector<int>>& items2) {
        map<int, int> M;
        for (vector<int> const& row : items1)
        {
            int const& value = row[0];
            int const& weight = row[1];
            M[value] += weight;
        }
        for (vector<int> const& row : items2)
        {
            int const& value = row[0];
            int const& weight = row[1];
            M[value] += weight;
        }
        vector<vector<int>> result;
        for (auto [value, weight] : M)
            result.push_back({ value, weight });
        return result;
    }
};
