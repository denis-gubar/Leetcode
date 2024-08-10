class Solution {
public:
    int minimumCost(int N, int M, vector<int>& horizontalCut, vector<int>& verticalCut) {
        vector<pair<int, int>> P;
        for (int i = 0; i < N - 1; ++i)
            P.emplace_back(horizontalCut[i], i);
        for (int j = 0; j < M - 1; ++j)
            P.emplace_back(verticalCut[j], j + 1'000);
        sort(P.begin(), P.end());
        int x = 1, y = 1;
        int result = 0;
        while(!P.empty())
        {
            int pos = P.back().second; P.pop_back();
            if (pos < 1'000)
                result += horizontalCut[pos] * y, ++x;
            else
                result += verticalCut[pos - 1'000] * x, ++y;
        }
        return result;
    }
};
