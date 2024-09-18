class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int const& V = edges[0][0];
        int const& U = edges[0][1];
        int const& A = edges[1][0];
        int const& B = edges[1][1];
        if (V == A || V == B)
            return V;
        return U;
    }
};