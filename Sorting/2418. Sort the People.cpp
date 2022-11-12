class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        vector<string> result;
        int N = names.size();
        vector<int> A(N);
        iota(A.begin(), A.end(), 0);
        sort(A.begin(), A.end(), [&heights](int a, int b)
            {
                return heights[a] > heights[b];
            });
        for (int i = 0; i < N; ++i)
            result.push_back(names[A[i]]);
        return result;
    }
};
