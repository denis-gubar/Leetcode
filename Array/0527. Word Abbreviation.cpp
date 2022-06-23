vector<string> W;
class Solution {
public:
    struct Trie
    {
        string encode(string const& s)
        {
            string result;
            result += s[0];
            result += s.back();
            size_t N = s.size();
            copy(s.begin() + 1, s.begin() + N - 1, back_inserter(result));
            return result;
        }
        string decode(string const& s)
        {
            string result;
            result += s[0];
            size_t N = s.size();
            copy(s.begin() + 2, s.end(), back_inserter(result));
            result += s[1];
            return result;
        }
        void add(size_t index)
        {
            string s = encode(W[index]);
            Trie* node = this;
            for(char c : s)
            {
                auto it = node->children.find(c);
                if (it == node->children.end())
                    node->children[c] = new Trie();
                node = node->children[c];
                ++node->count;
            }
        }
        string search(size_t index)
        {
            string result;
            string s = encode(W[index]);
            Trie* node = this;
            for(char c : s)
            {
                result += c;
                node = node->children[c];
                if (result.size() > 1 && node->count == 1)
                    break;
            }
            size_t delta = s.size() - result.size();
            if (delta < 2)
                result = s;
            else
                result += to_string(delta);
            return decode(result);
        }
        size_t count;
        unordered_map<char, Trie*> children;
    };    
    vector<string> wordsAbbreviation(vector<string>& words) {
        size_t N = words.size();
        vector<string> result(N);
        W = words;
        vector<Trie> trie(401); 
        for(size_t i = 0; i < N; ++i)
            trie[words[i].size()].add(i);
        for(size_t i = 0; i < N; ++i)
            result[i] = trie[words[i].size()].search(i);
        return result;
    }
};