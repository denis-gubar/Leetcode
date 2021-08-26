class Solution {
public:
    map<int, int> parents;
    map<int, TreeNode*> positions;
    set<int> leaves;
    set<int> visited;
    void traverse( TreeNode* root )
    {
        positions[root->val] = root;
        if (root->left)
        {
            parents[root->left->val] = root->val;
            traverse( root->left );
        }
        if (root->right)
        {
            parents[root->right->val] = root->val;
            traverse( root->right );
        }
        if (!root->left && !root->right)
            leaves.insert( root->val );
    }
    pair<int, int> find( TreeNode* root, int level )
    {
        pair<int, int> result = make_pair( INT_MAX, INT_MAX );
        if (!root->left && !root->right)
            return make_pair( level, root->val );
        if (root->left && visited.find( root->left->val ) == visited.end())
        {
            pair<int, int> L = find( root->left, level + 1 );
            if (L.first < result.first)
                result = L;
        }
        if (root->right && visited.find( root->right->val ) == visited.end())
        {
            pair<int, int> R = find( root->right, level + 1 );
            if (R.first < result.first)
                result = R;
        }
        return result;
    }
    int findClosestLeaf( TreeNode* root, int k ) {
        parents = map<int, int>();
        leaves = set<int>();
        visited = set<int>();
        positions = map<int, TreeNode*>();
        traverse( root );
        pair<int, int> result = make_pair( INT_MAX, INT_MAX );
        int level = 0;
        for(TreeNode* node = positions[k]; true; )
        {
            pair<int, int> current = find( node, level );
            if (current.first < result.first)
                result = current;
            ++level;
            visited.insert( node->val );
            if (parents.find( node->val ) != parents.end())
            {
                node = positions[parents[node->val]];
            }
            else
                break;
        }
        return result.second;
    }
};