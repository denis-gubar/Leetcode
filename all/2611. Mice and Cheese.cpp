class Solution {
public:
    int miceAndCheese(vector<int>& reward1, vector<int>& reward2, int k) {
        int N = reward1.size();
        int result = 0;
        vector<pair<int, int>> A(N);
        for (int i = 0; i < N; ++i)
            A[i] = { reward2[i] - reward1[i], i };
        sort(A.begin(), A.end());
        for (int i = 0; i < k; ++i)
            result += reward1[A[i].second];
        for(int i = k; i < N; ++i)
            result += reward2[A[i].second];
        return result;
    }
};
