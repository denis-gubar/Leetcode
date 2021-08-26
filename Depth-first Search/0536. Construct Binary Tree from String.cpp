class Solution {
public:
	TreeNode* str2tree(string s) {		
		if (s.empty())
			return nullptr;
		stack<TreeNode*> S;        
		S.push(new TreeNode(0));
        TreeNode* result = S.top();
		int pos = 0;
		auto read = [&pos, s]()
		{
			string result;
			while (pos < s.size() && s[pos] != ')' && s[pos] != '(')
			{
				result += s[pos];
				++pos;
			}
			return stoi(result);
		};
		while (pos < s.size())
		{
			TreeNode* node = S.top(); S.pop();
			if (s[pos] == ')')
			{
				++pos;
				continue;
			}
			if (s[pos] == '(' && node->left != nullptr)
			{
				S.push(node);
				node->right = new TreeNode(0);
				S.push(node->right);
			}
			else
			{
				node->val = read();
				if (pos < s.size() && s[pos] == '(')
				{
					S.push(node);
					node->left = new TreeNode(0);
					S.push(node->left);
				}
			}
			++pos;
		}
		return result;
    }
};