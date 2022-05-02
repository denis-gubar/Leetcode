class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& persons) {
        int K = persons.size();
        vector<int> result(K);
        int N = flowers.size();
        vector<int> P(persons);
        sort(P.begin(), P.end());
        P.resize(unique(P.begin(), P.end()) - P.begin());
        unordered_map<int, int> answers;
        vector<pair<int, int>> events;
        events.reserve(2 * N);
        for (int i = 0; i < N; ++i)
        {
			int const& start = flowers[i][0];
			int const& end = flowers[i][1];
            events.push_back({ start, 1 });
            events.push_back({ end + 1, -1 });
        }
        for (int i = 0; i < P.size(); ++i)
            events.push_back({ P[i], i + 2 });
        sort(events.begin(), events.end());
        int balance = 0;
        for (pair<int, int> e : events)
        {
            if (e.second >= 2)
            {
                answers[P[e.second - 2]] = balance;
                continue;
            }
            balance += e.second;
        }
        for (int i = 0; i < K; ++i)
            result[i] = answers[persons[i]];
        return result;
    }
};
