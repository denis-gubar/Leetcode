/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
	UndirectedGraphNode *clone(UndirectedGraphNode *node) {
		if (!node)
			return nullptr;
		if (visited.find(node->label) != visited.end())
			return visited[node->label];
		UndirectedGraphNode* root = new UndirectedGraphNode(node->label);
		visited[node->label] = root;
		for (auto neighbor : node->neighbors)
			root->neighbors.push_back(clone(neighbor));
		return root;
	}
	UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
		visited.clear();
		return clone(node);
	}
	unordered_map<int, UndirectedGraphNode*> visited;
};