class Solution {
public:
    vector<int> exclusiveTime(int N, vector<string>& logs) {
        vector<int> result(N + 1);
        stack<pair<int, int>> S;
        S.push({N, 1});
        for (string const& log : logs)
        {
            int id = 0;
            int i = 0;
            while (log[i] != ':')
                id = 10 * id + (log[i] - '0'), ++i;
            int j = log.size() - 1;
            int time = 0, k = 1;
            while (log[j] != ':')
                time += k * (log[j] - '0'), k *= 10, --j;
            if (j - i == 6) //start
            {
                result[S.top().first] += time - S.top().second;
                S.push({ id, time });
            }
            else
            {
                result[S.top().first] += time - S.top().second + 1;
                S.pop();
                S.top().second = time + 1;
            }
        }
        result.pop_back();
        return result;
    }
};
