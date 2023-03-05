/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
public:
    vector<vector<int>> grid;
    Node* calc(int x, int y, int N)
    {
        bool isLeaf = true;
        for (int i = x; isLeaf && i < x + N; ++i)
            for (int j = y; isLeaf && j < y + N; ++j)
                isLeaf &= grid[i][j] == grid[x][y];
        if (isLeaf)
            return new Node(grid[x][y], true);
        return new Node(false, isLeaf, calc(x, y, N / 2), calc(x, y + N / 2, N / 2), calc(x + N / 2, y, N / 2), calc(x + N / 2, y + N / 2, N / 2));
    }
    Node* construct(vector<vector<int>>& grid) {
        this->grid = grid;
        int N = grid.size();
        return calc(0, 0, N);
    }
};
