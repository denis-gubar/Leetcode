/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

	// Encodes a tree to a single string.
	string serialize(TreeNode* root) {
		string result;
		queue<TreeNode*> Q;
		auto writeNode = [&result, &Q](TreeNode* node)
		{
			result += ',';
			if (node)
			{
				result += to_string(node->val);
				Q.push(node->left);
				Q.push(node->right);
			}
			else
				result += "null";
			
		};
		writeNode(root);
		while (!Q.empty())
		{
			TreeNode* node = Q.front(); Q.pop();
			writeNode(node);
		}
		return result.substr(1);
	}

	// Decodes your encoded data to tree.
	TreeNode* deserialize(string data) {
		data += ',';
		string buffer;
		queue<TreeNode*> Q;
		for (char c : data)
		{
			if (c == ',')
			{
				TreeNode* node = nullptr;                
				if (buffer != "null")
					node = new TreeNode(stoi(buffer));
				buffer.clear();
				Q.push(node);
			}
			else
				buffer += c;
		}
		TreeNode* result = Q.front(); Q.pop();
		queue<TreeNode*> parentQueue;
		parentQueue.push(result);
		while (!parentQueue.empty())
		{            
			TreeNode* parentNode = parentQueue.front(); parentQueue.pop();
			if (parentNode)                
			{
				parentNode->left = Q.front(); Q.pop();
				parentNode->right = Q.front(); Q.pop();
				parentQueue.push(parentNode->left);
				parentQueue.push(parentNode->right);
			}
		}
		return result;
	}
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));