class Solution {
public:
    bool canChange(string start, string target) {
        int N = start.size();
        vector<pair<int, int>> P, T;
        for (int i = 0; i < N; ++i)
            if (start[i] == 'L')
                P.emplace_back(i, 0);
            else if (start[i] == 'R')
                P.emplace_back(i, 1);
        for (int i = 0; i < N; ++i)
            if (target[i] == 'L')
                T.emplace_back(i, 0);
            else if (target[i] == 'R')
                T.emplace_back(i, 1);
        if (count(start.begin(), start.end(), 'L') != count(target.begin(), target.end(), 'L'))
            return false;
        if (count(start.begin(), start.end(), 'R') != count(target.begin(), target.end(), 'R'))
            return false;
        int M = P.size();
        for (int i = 0; i < M; ++i)
        {
            if (P[i].second != T[i].second)
                return false;
            if (P[i].second == 0 && P[i].first < T[i].first)
                return false;
            if (P[i].second == 1 && P[i].first > T[i].first)
                return false;
        }
        return true;
    }
};
