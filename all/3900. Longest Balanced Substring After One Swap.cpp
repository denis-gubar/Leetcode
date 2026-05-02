static int A[100'001];
static int D[100'001][2];
class Solution {
public:
    int longestBalanced(string s) {
        int result = 0;
        int const N = s.size();
        A[0] = D[0][0] = D[0][1] = 0;        
        unordered_map<int, vector<int>> M, inv;
        M[0].push_back(0);
        for (int i = 0; i < N; ++i)
        {
            D[i + 1][0] = D[i][0] + (s[i] == '0');
            D[i + 1][1] = D[i][1] + (s[i] == '1');
            A[i + 1] = A[i] + 2 * (s[i] - '0') - 1;
            if (auto it = M.find(A[i + 1]); it == M.end())
                M[A[i + 1]].push_back(i + 1);
            else
            {
                it->second.push_back(i + 1);
                result = max(result, i + 1 - it->second[0]);
            }
        }
        auto calc = [N](int left, int right, int d) -> bool
            {
                return left < right && (left > 0 && D[left][d] > 0 || D[N][d] > D[right][d]);
            };
        for (int i = 0; i < N; ++i)
        {
            if (auto it = M.find(A[i] - 2); it != M.end())
            {
                for (int j : it->second)
                    if (calc(i, j, 1))
                        result = max(result, j - i);
            }
            if (auto it = M.find(A[i] + 2); it != M.end())
            {
                for(int j : it->second)
                    if (calc(i, j, 0))
                        result = max(result, j - i);
            }
        }
        return result;
    }
};
