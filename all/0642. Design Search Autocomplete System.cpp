class AutocompleteSystem {
public:
	struct Trie
	{		
        set<pair<int, int>> S;
		unordered_map<char, Trie*> children;
	};
	AutocompleteSystem(vector<string>& sentences, vector<int>& times) {
        buffer.clear();
        N = times.size();
        for (int i = 0; i < N; ++i)
        {
            int key = getIndex(sentences[i]);
            add(key, times[i]);
            A[key] += times[i];
        }
        root = &T;
    }
    
    void add(int ind, int delta)
    {
        string const s = V[ind];
        int const count = A[ind];
        Trie* node = &T;
        for (char c : s)
        {
            if (node->children.find(c) == node->children.end())
                node->children[c] = new Trie();
            node = node->children[c];
            if (auto it = node->S.find({ -count, ind }); it == node->S.end())
                node->S.insert({ -count - delta, ind });
            else
            {
                node->S.erase(it);
                node->S.insert({ -count - delta, ind });
            }
        }
    }

    int getIndex(string const& s)
    {
        if (auto it = M.find(s); it != M.end())
            return it->second;
        A.push_back(0);
        V.push_back(s);
        return M[s] = A.size() - 1;
    }

    vector<string> input(char c) {
        if (c == '#')
        {
            if (!buffer.empty())
            {
                int key = getIndex(buffer);
                add(key, 1);
                A[key] += 1;
            }
            buffer.clear();
            root = &T;
            return {};
        }
        buffer += c;
        if (root)
        {
            if (auto it = root->children.find(c); it == root->children.end())
            {
                root = nullptr;
                return {};
            }
            else
            {
                root = it->second;
                vector<string> result;
                vector<pair<int, string>> P;
                for (auto it = root->S.begin(); it != root->S.end(); ++it)
                    P.emplace_back(-A[it->second], V[it->second]);
                sort(P.begin(), P.end());
                for (int i = 0; i < P.size(); ++i)
                {
                    if (result.size() == 3)
                        break;
                    result.emplace_back(P[i].second);
                }
                return result;
            }
        }
        return {};
    }
    string buffer;
    int N;
    vector<int> A;
    vector<string> V;
    unordered_map<string, int> M;
    Trie T;
    Trie* root = nullptr;
};

/**
 * Your AutocompleteSystem object will be instantiated and called as such:
 * AutocompleteSystem* obj = new AutocompleteSystem(sentences, times);
 * vector<string> param_1 = obj->input(c);
 */
