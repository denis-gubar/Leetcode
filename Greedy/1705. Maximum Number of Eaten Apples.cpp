class Solution {
public:
    int eatenApples(vector<int>& apples, vector<int>& days) {
        int N = apples.size();
        int result = 0;
        map<int, int> M;
        for (int i = 0; i < N || !M.empty(); ++i)
        {
            if (M.begin() != M.end() && M.begin()->first == i)
                M.erase(M.begin());
            if (i < N && apples[i])
                M[i + days[i]] += apples[i];
            if (M.empty())
                continue;
            ++result;
            if (--M.begin()->second == 0)
                M.erase(M.begin());
        }
        return result;
    }
};
