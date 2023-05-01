class Solution {
public:
    int isWinner(vector<int>& player1, vector<int>& player2) {
        int N = player1.size();
        int A = 0, B = 0;
        for (int i = 0; i < N; ++i)
        {
            int x = player1[i];
            A += x;
            if (i > 0 && player1[i - 1] == 10 || i > 1 && player1[i - 2] == 10)
                A += x;
        }
        for (int i = 0; i < N; ++i)
        {
            int x = player2[i];
            B += x;
            if (i > 0 && player2[i - 1] == 10 || i > 1 && player2[i - 2] == 10)
                B += x;
        }
        if (A == B)
            return 0;
        if (A > B)
            return 1;
        return 2;
    }
};
