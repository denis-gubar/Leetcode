class Solution {
public:
    int brightestPosition(vector<vector<int>>& lights) {
        multiset<pair<int, int>> S;
        for (vector<int> const& L : lights)
        {
            int const& position = L[0];
            int const& range = L[1];
            S.insert({ position - range, -1 });
            S.insert({ position + range, 1 });
        }
        int balance = 0;
        int result = 0, best = 0;
        for (pair<int, int> P : S)
        {
            balance -= P.second;
            if (balance > best)
                best = balance, result = P.first;
        }
        return result;
    }
};
