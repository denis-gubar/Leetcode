class Solution {
public:
    vector<int> colorTheArray(int N, vector<vector<int>>& queries) {
        int Q = queries.size();
        int balance = 0;
        vector<int> result(Q), A(N);
        auto add = [&A, N](int index, int color) -> int
        {
            int result = 0;
            if (index > 0 && A[index - 1] == color)
                ++result;
            if (index + 1 < N && A[index + 1] == color)
                ++result;
            return result;
        };
        auto remove = [&A, N](int index, int color) -> int
        {
            int result = 0;
            if (index > 0 && A[index - 1] == color)
                --result;
            if (index + 1 < N && A[index + 1] == color)
                --result;
            return result;
        };
        for (int i = 0; i < Q; ++i)
        {
            int const& index = queries[i][0];
            int const& color = queries[i][1];
            if (A[index] > 0)
            {
                balance += remove(index, A[index]);
                A[index] = color;
                balance += add(index, color);
            }
            else
            {
                A[index] = color;
                balance += add(index, color);
            }
            result[i] = balance;
        }
        return result;
    }
};
