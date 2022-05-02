class Encrypter {
public:
    Encrypter(vector<char>& keys, vector<string>& values, vector<string>& dictionary) {
        codes = vector<string>(26);
        for (int k = 0; k < keys.size(); ++k)
        {
            int i = keys[k] - 'a';
            codes[i] = values[k];
        }
        for (string const& s : dictionary)
        {
            string t = encrypt(s);
            M[s] = t;
            ++INV[t];
        }
    }
    
    string encrypt(string const& word1) {
        string result;
        for (char c : word1)
        {
            int i = c - 'a';
            result += codes[i];
        }
        return result;
    }
    
    int decrypt(string const& word2) {
        return INV[word2];
    }
    vector<string> codes;
    unordered_map<string, string> M;
    unordered_map<string, int> INV;
};

/**
 * Your Encrypter object will be instantiated and called as such:
 * Encrypter* obj = new Encrypter(keys, values, dictionary);
 * string param_1 = obj->encrypt(word1);
 * int param_2 = obj->decrypt(word2);
 */
