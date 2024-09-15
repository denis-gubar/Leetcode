class Solution {
public:
    bool checkTwoChessboards(string coordinate1, string coordinate2) {
        return abs(coordinate1[0] + coordinate1[1]) % 2 == abs(coordinate2[0] + coordinate2[1]) % 2;
    }
};
