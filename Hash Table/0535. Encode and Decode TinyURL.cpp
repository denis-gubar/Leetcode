class Solution {
public:

    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        auto it = M.find(longUrl);
        if (it == M.end())
        {
            it = M.insert({longUrl, inverse.size()}).first;
            inverse.push_back(longUrl);
        }
        return prefix + to_string(it->second);
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        size_t i = stoi(shortUrl.substr(prefix.size()));
        return inverse[i];
    }
    unordered_map<string, size_t> M;
    vector<string> inverse;
    string const prefix{"http://tinyurl.com/"s};
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));