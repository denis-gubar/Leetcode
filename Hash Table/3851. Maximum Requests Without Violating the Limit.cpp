class Solution {
public:
    int maxRequests(vector<vector<int>>& requests, int K, int window) {
        int result = 0;
        unordered_map<int, vector<int>> M;
        for (vector<int> const& r : requests)
        {
            int const& USER = r[0];
            int const& TIME = r[1];
            M[USER].push_back(TIME);
        }
        for (auto& [key, value] : M)
        {
            sort(value.begin(), value.end());
            deque<int> D;
            for (int t : value)
            {
                while (!D.empty() && D.front() + window < t)
                    D.pop_front();
                if (D.size() < K)
                    ++result, D.push_back(t);
            }
        }
        return result;
        
    }
};
