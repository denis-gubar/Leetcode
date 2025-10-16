class Solution {
public:
    bool checkValidCuts(int N, vector<vector<int>>& rectangles) {
        int const R = rectangles.size();
        map<int, int> A;
        for (int i = 0; i < R; ++i)
        {
            int const& startX = rectangles[i][0];
            int const& endX = rectangles[i][2];
            ++A[startX + 1];
            --A[endX];
        }
        int balance = 0;
        int count = 0;
        for (auto [key, value] : A)
        {
            balance += value;
            count += balance == 0;
        }
        if (count > 2)
            return true;
        A.clear();
        for (int i = 0; i < R; ++i)
        {
            int const& startY = rectangles[i][1];
            int const& endY = rectangles[i][3];
            ++A[startY + 1];
            --A[endY];
        }
        balance = 0;
        count = 0;
        for (auto [key, value] : A)
        {
            balance += value;
            count += balance == 0;
        }
        return count > 2;
    }
};
