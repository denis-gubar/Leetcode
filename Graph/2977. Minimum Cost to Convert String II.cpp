static int F[200][200];
class Solution {
public:
    class WordDictionary {
    public:
        /** Initialize your data structure here. */
        WordDictionary() : children(vector<WordDictionary*>(26)), index(-1), size(0) {}
        ~WordDictionary()
        {
            for (WordDictionary* child : children)
                delete child;
        }

        /** Adds a word into the data structure. */
        void addWord(string const& word, int index) {
            WordDictionary* node = this;
            for (int i : word)
                if (node->children[i - 'a'])
                    node = node->children[i - 'a'];
                else
                    node = node->children[i - 'a'] = new WordDictionary;
            node->index = index;
            node->size = word.size();
        }

        /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
        vector<pair<int, int>> search(string const& word) {
            vector<pair<int, int>> result;
            WordDictionary* node = this;
            for (int i = 0; i < word.size(); ++i)
            {
                if (!node->children[word[i] - 'a'])
                    break;
                node = node->children[word[i] - 'a'];
                if (node->size > 0)
                    result.emplace_back(node->size, node->index);
            }
            return result;
        }
        vector<WordDictionary*> children;
        int index;
        int size;
    };
    long long minimumCost(string source, string target, vector<string>& original, vector<string>& changed, vector<int>& cost) {
        vector<map<string, int>> I(1001);
        vector<vector<vector<int>>> P(1001);
        vector<map<pair<int, int>, int>> FF(1001);
        int N = cost.size();
        for (int i = 0; i < N; ++i)
        {
            string const& o = original[i];
            string const& c = changed[i];
            int const& C = cost[i];
            int O = o.size();
            if (auto it = I[O].find(o); it == I[O].end())
                I[O][o] = I[O].size();
            if (auto it = I[O].find(c); it == I[O].end())
                I[O][c] = I[O].size();
        }
        WordDictionary WD;
        for (int i = 0; i < N; ++i)
        {
            string const& o = original[i];
            string const& c = changed[i];
            int const O = o.size();
            int const V = I[O][o];
            int const U = I[O][c];
            int const& C = cost[i];
            P[O].push_back({V, U, C});
            WD.addWord(o, V);
            WD.addWord(c, U);
        }
        int const INF = 1'000'000'001;
        for(int O = 1; O < 1'001; ++O)
            if (!P[O].empty())
            {
                int const K = I[O].size();
                for (int V = 0; V < K; ++V)
                    for (int U = 0; U < K; ++U)
                        F[V][U] = INF;
                for (int V = 0; V < K; ++V)
                    F[V][V] = 0;
                for (vector<int> const& A : P[O])
                {
                    int const& V = A[0];
                    int const& U = A[1];
                    int const& C = A[2];
                    F[V][U] = min(F[V][U], C);
                }
                for (int k = 0; k < K; ++k)
                    for (int i = 0; i < K; ++i)
                        for (int j = 0; j < K; ++j)
                            F[i][j] = min(F[i][j], F[i][k] + F[k][j]);
                for (int V = 0; V < K; ++V)
                    for (int U = 0; U < K; ++U)
                        if (F[V][U] < INF)
                            FF[O][{ V, U }] = F[V][U];
            }
        int M = source.size();
        vector<long long> D(M + 1, 1000LL * INF);
        D[0] = 0;
        for(int i = 0; i < M; ++i)
            if (D[i] < 1000LL * INF)
            {
                vector<pair<int, int>> X = WD.search(source.substr(i));
                for (auto [size, V] : X)
                {
                    string T = target.substr(i, size);
                    int const O = T.size();
                    if (I[O].find(T) == I[O].end())
                        continue;
                    int const U = I[O][T];
                    if (auto it = FF[O].find({ V, U }); it != FF[O].end())
                        D[i + size] = min(D[i + size], D[i] + it->second);
                }
                for (int j = i; j < M; ++j)
                    if (source[j] != target[j])
                        break;
                    else
                        D[j + 1] = min(D[j + 1], D[i]);
            }
        if (D[M] < 1000LL * INF)
            return D[M];
        return -1;
    }
};
