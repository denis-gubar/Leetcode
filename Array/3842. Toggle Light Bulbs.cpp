class Solution {
public:
    vector<int> toggleLightBulbs(vector<int>& bulbs) {
        set<int> S;
        for (int x : bulbs)
            if (S.find(x) != S.end())
                S.erase(x);
            else
                S.insert(x);
        return vector<int>(S.begin(), S.end());
    }
};
