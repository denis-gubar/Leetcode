class Solution {
public:
    string bestHand(vector<int>& ranks, vector<char>& suits) {
        for (int i = 0; i < 5; ++i)
        {
            vector<char> A(suits);
            sort(A.begin(), A.end());
            if (A[0] == A[4])
                return "Flush";
            unordered_map<int, int> M;
            for (int x : ranks)
                ++M[x];
            for (auto [key, value] : M)
                if (value >= 3)
                    return "Three of a Kind";
            for (auto [key, value] : M)
                if (value == 2)
                    return "Pair";
        }
        return "High Card";
    }
};
