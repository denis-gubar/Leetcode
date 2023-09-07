class Solution {
public:
    struct Trie
    {
        void add(string const& s)
        {
            Trie* node = this;
            for (char c : s)
            {
                auto it = node->children.find(c);
                if (it == node->children.end())
                    node->children[c] = new Trie();
                node = node->children[c];
            }
            auto it = node->children.find('$');
            if (it == node->children.end())
                node->children['$'] = new Trie();
        }
        int search(string_view s)
        {
            int result = 0;
            Trie* node = this;
            for (char c : s)
            {
                auto it = node->children.find(c);
                if (it == node->children.end())
                    break;
                ++result;
                node = node->children[c];
                if (node->children.find('$') != node->children.end())
                    return result;
            }
            return 11;
        }
        unordered_map<char, Trie*> children;
    };
    int longestValidSubstring(string word, vector<string>& forbidden) {
        int result = 0;
        string_view W(word);
        int N = word.size();
        Trie T;
        for (string const& s : forbidden)
            T.add(s);
        int a = 0, b = 0;
        vector<int> A(N);
        for (int i = 0; i < N; ++i)
            A[i] = T.search(W.substr(i, min(N - i, 10)));
        while (b < N)
        {
            int x = 11;
            for (int k = 0; k < 10 && b - k >= a; ++k)
            {
                if (A[b - k] - k == 1)
                    a = b - k + 1;
                x = min(x, A[b - k] - k);
            }
            if (x > 1)
                result = max(result, b - a + 1);
            ++b;
        }
        return result;
    }
};
