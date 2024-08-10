class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        priority_queue<int, vector<int>, greater<int>> PQ;
        sort(events.begin(), events.end());
        int result = 0;
        int pos = 0;
        int const N = events.size();
        for (int t = 0; t <= 100'000; ++t)
        {
            while (!PQ.empty() && t > PQ.top())
                PQ.pop();
            if (pos < N)
            {
                while(pos < N && events[pos][0] == t)
                    PQ.push(events[pos][1]), ++pos;
            }
            if (!PQ.empty())
                PQ.pop(), ++result;
        }
        return result;
    }
};
