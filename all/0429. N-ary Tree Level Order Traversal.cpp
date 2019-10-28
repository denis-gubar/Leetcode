/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
public:
    void calc(Node* root, int level, vector<vector<int>>& Levels)
    {
        if (root)
        {
            if (Levels.size() == level)
                Levels.push_back({});
            Levels[level].push_back(root->val);
            for(Node* child: root->children)
                calc(child, level + 1, Levels);
        }
    }
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> result;
        calc(root, 0, result);
        return result;
    }
};