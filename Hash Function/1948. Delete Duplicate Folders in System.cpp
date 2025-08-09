class Solution {
public:
    struct Trie
    {
        Trie() : nodeLabel(-1)
        {

        }
        unordered_map<long long, Trie*> children;
        int nodeLabel;
    };
    vector<vector<string>> deleteDuplicateFolder(vector<vector<string>>& paths) {
        vector<vector<string>> result;
        int const N = paths.size();
        result.reserve(N);
        vector<bool> isGood(N, true);
        Trie trie;
        auto hash = [](string const& s) -> long long
            {
                long long result = 0;
                for (char c : s)
                    result = (result << 5) | (c - 'a');
                return result;
            };
        auto addPath = [&](int V) -> void
            {
                Trie* node = &trie;
                for (string const& nodePath : paths[V])
                {
                    long long const nodeKey = hash(nodePath);
                    if (auto it = node->children.find(nodeKey); it == node->children.end())
                        node->children[nodeKey] = new Trie();
                    node = node->children[nodeKey];
                }
                node->nodeLabel = V;
            };
        for (int V = 0; V < N; ++V)
            addPath(V);
        vector<int> parents(N), leaves;
        leaves.reserve(N);
        auto dfs = [&](this auto const& self, Trie* root) -> void
            {
                for (auto [key, node] : root->children)
                    self(node), parents[node->nodeLabel] = root->nodeLabel;
                if (root->children.empty())
                    leaves.push_back(root->nodeLabel);
            };
        dfs(&trie);
        Trie suffixTrie;
        vector<set<int>> suffixes(N + 1);
        vector<string> suffixes2(N + 1);
        int suffixNo = 0;
        auto addSuffix = [&](int V) -> void
            {
                Trie* node = &suffixTrie;
                int currentNode = V;
                int const N = paths[V].size();
                for (int i = N - 1; i >= 0; --i)
                {
                    string const& nodePath = paths[V][i];
                    long long const nodeKey = hash(nodePath);
                    if (auto it = node->children.find(nodeKey); it == node->children.end())
                        node->children[nodeKey] = new Trie(), node->children[nodeKey]->nodeLabel = suffixNo, ++suffixNo;
                    node = node->children[nodeKey];
                    currentNode = parents[currentNode];
                    suffixes[currentNode + 1].insert(node->nodeLabel);
                }
            };
        for (int V : leaves)
            addSuffix(V);
        map<string, vector<int>> M;
        for (int V = 0; V <= N; ++V)
        {
            for (int x : suffixes[V])
            {
                suffixes2[V] += to_string(x);
                suffixes2[V] += '/';
            }
            M[suffixes2[V]].push_back(V);
        }
        for (auto& [key, value] : M)
            if (!key.empty() && value.size() > 1)
                for (int V : value)
                    if (V > 0)
                        isGood[V - 1] = false;
        for (int V = 0; V < N; ++V)
            if (parents[V] != -1 && !isGood[parents[V]])
                isGood[V] = false;
        for (int V = 0; V < N; ++V)
            if (isGood[V])
                result.push_back(paths[V]);
        return result;
    }
};
