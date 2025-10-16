class Solution {
public:
    int calc(string s)
    {
        int result = 0;
        int x = stoi(s);
        result += x / 100 * 60;
        result += x % 100;
        return result;
    }
    vector<string> findHighAccessEmployees(vector<vector<string>>& access_times) {
        int N = access_times.size();
        vector<string> result;
        unordered_map<string, vector<int>> M;
        for (int i = 0; i < N; ++i)
        {
            string const& key = access_times[i][0];
            int time = calc(access_times[i][1]);
            M[key].push_back(time);
        }
        for (auto& [key, value] : M)
        {
            sort(value.begin(), value.end());
            int N = value.size();
            for (int i = 2; i < N; ++i)
                if (value[i] - value[i - 2] < 60)
                {
                    result.push_back(key);
                    break;
                }
        }
        return result;
    }
};
