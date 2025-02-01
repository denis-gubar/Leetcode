class Solution {
public:
    vector<int> countMentions(int numberOfUsers, vector<vector<string>>& events) {
        int N = events.size();
        vector<int> result(numberOfUsers);
        vector<bool> isOffline(numberOfUsers);
        for (int i = 0; i < N; ++i)
            if (events[i][0] == "OFFLINE")
                events.push_back({ "ONLINE", to_string(stoi(events[i][1]) + 60), events[i][2] });
        N = events.size();
        int all = 0;        
        vector<int> T(N), I(N);
        iota(I.begin(), I.end(), 0);
        for (int i = 0; i < N; ++i)
            T[i] = (events[i][0] == "MESSAGE") * 2 + (events[i][0] == "OFFLINE") + stoi(events[i][1]) * 3;
        sort(I.begin(), I.end(), [&T](int a, int b)
            {
                return T[a] < T[b];
            });
        for (int i = 0; i < N; ++i)
        {
            int const pos = I[i];
            if (events[pos][0] == "MESSAGE")
            {
                string& ms = events[pos][2];
                if (ms == "ALL")
                    ++all;
                else if (ms == "HERE")
                {
                    for (int i = 0; i < numberOfUsers; ++i)
                        if (!isOffline[i])
                            ++result[i];
                }
                else
                {
                    ms.push_back(' ');
                    string buffer;
                    for (char c : ms)
                        if (isdigit(c))
                            buffer += c;
                        else if (!buffer.empty())
                            ++result[stoi(buffer)], buffer.clear();
                    ms.pop_back();
                }
            }
            else
                isOffline[stoi(events[pos][2])] = events[pos][0] == "OFFLINE";
        }
        if (all > 0)
            for (int i = 0; i < numberOfUsers; ++i)
                result[i] += all;
        return result;
    }
};
