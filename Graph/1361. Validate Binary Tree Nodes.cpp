class Solution {
public:
	void calc(int root, vector<int> const& leftChild, vector<int> const& rightChild, vector<set<int>>& visited)
	{
		if (root == -1) return;
		if (leftChild[root] != -1)
		{
			if (visited[leftChild[root]].insert(root).second)
			    calc(leftChild[root], leftChild, rightChild, visited);
		}
		if (rightChild[root] != -1)
		{
			if (visited[rightChild[root]].insert(root).second)
			    calc(rightChild[root], leftChild, rightChild, visited);
		}
	}
	bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
		vector<set<int>> visited(n);
		vector<int> target(n, 1), v;
		target[0] = 0;
		for (int i = 0; i < n; ++i)
            if (visited[i].empty())
			    calc(i, leftChild, rightChild, visited);
        for(auto const& vis: visited)
            v.push_back(vis.size());
		sort(v.begin(), v.end());
        for(int i: v)
            cout << i << ' ';
		return v == target;
	}
};