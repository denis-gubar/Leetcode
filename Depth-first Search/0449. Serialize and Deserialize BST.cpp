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
	void serialize(TreeNode* root, string& result)
	{
		if (!root)
        {
            result += '#';
            return;
        }
		result += to_string(root->val);
		result += ',';
		serialize(root->left, result);
		result += ',';
		serialize(root->right, result);
	}

	// Encodes a tree to a single string.
	string serialize(TreeNode* root) {
		string result;
		serialize(root, result);
		return result;
	}

	TreeNode* deserialize(string_view& data)
	{
		if (data[0] == '#')
        {
            if (data.size() > 1)
                data = data.substr(2);
            else
                data = data.substr(1);
			return nullptr;
        }
		string buffer;
		while (data[0] != ',')
		{
			buffer += data[0];
			data = data.substr(1);
		}
		data = data.substr(1);
		TreeNode* result = new TreeNode(atoi(buffer.c_str()));
		result->left = deserialize(data);
		result->right = deserialize(data);
		return result;
	}

	// Decodes your encoded data to tree.
	TreeNode* deserialize(string data) {
        string_view sv(data);
		return deserialize(sv);
	}
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;