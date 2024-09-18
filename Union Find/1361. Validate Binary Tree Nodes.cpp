class Solution {
public:
    enum struct Colors
    {
        WHITE=0,
        GREY,
        BLACK
    };
    vector<Colors> colors;
    bool calc1(vector<int>& leftChild, vector<int>& rightChild, int V)
    {
        if (V == -1)
            return true;
        if (colors[V] == Colors::WHITE)
        {
            colors[V] = Colors::GREY;
            return calc1(leftChild, rightChild, leftChild[V]) &&
                calc1(leftChild, rightChild, rightChild[V]);
        }
        return colors[V] == Colors::BLACK;
    }
    void calc2(vector<int>& leftChild, vector<int>& rightChild, int V)
    {
        if (V == -1) return;
        if (colors[V] == Colors::GREY)
        {
            colors[V] = Colors::BLACK;
            calc2(leftChild, rightChild, leftChild[V]);
            calc2(leftChild, rightChild, rightChild[V]);
        }
    }
    bool validateBinaryTreeNodes(int N, vector<int>& leftChild, vector<int>& rightChild) {
        colors = vector<Colors>(N);
        for (int V = 0; V < N; ++V)
            if (!calc1(leftChild, rightChild, V))
                return false;
            else
                calc2(leftChild, rightChild, V);
        vector<bool> isRoot(N, true);
        for (int V = 0; V < N; ++V)
        {
            if (leftChild[V] != -1)
                isRoot[leftChild[V]] = false;
            if (rightChild[V] != -1)
                isRoot[rightChild[V]] = false;
        }
        return accumulate(isRoot.begin(), isRoot.end(), 0) == 1;
    }
};
