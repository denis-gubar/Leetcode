class Solution {
public:
    bool isPossible(vector<int>& nums) {
        auto cmp = [](pair<int, int> a, pair<int, int> b)
        {
            if (a.second == b.second)
                return a.first < b.first;
            return a.second > b.second;
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> PQ(cmp);
        for (int x : nums)
        {
            while (!PQ.empty() && PQ.top().second + 1 < x)
            {
                pair<int, int> p = PQ.top(); PQ.pop();
                if (p.second - p.first < 2)
                    return false;
            }
            if (PQ.empty() || PQ.top().second == x)
                PQ.push({ x, x });
            else
            {
                pair<int, int> p = PQ.top(); PQ.pop();
                PQ.push({ p.first, x });
            }
        }
        while (!PQ.empty())
        {
            pair<int, int> p = PQ.top(); PQ.pop();
            if (p.second - p.first < 2)
                return false;
        }
        return true;
    }
};
