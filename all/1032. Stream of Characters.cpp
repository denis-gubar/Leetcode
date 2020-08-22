class StreamChecker {
public:
	StreamChecker(vector<string>& words) : w(words), dictionary(vector<vector<string>>(26)) {
		buffer.reserve(40'000);
		for (int i = 0; i < w.size(); ++i)
			dictionary[w[i].back() - 'a'].push_back(w[i]);
		for (int i = 0; i < 26; ++i)
			sort(dictionary[i].begin(), dictionary[i].end(),
				[](string const& a, string const& b)
				{
					return a.size() < b.size();
				});
	}

	bool query(char letter) {
		buffer += letter;
		for (int i = 0; i < dictionary[letter - 'a'].size(); ++i)
		{
			string const& word = dictionary[letter - 'a'][i];
			if (word.size() > buffer.size())
				return false;
			if (equal(word.begin(), word.end(), buffer.begin() + (buffer.size() - word.size()), buffer.end()))
				return true;
		}
		return false;
	}
	string buffer;
	vector<string> w;
	vector<vector<string>> dictionary;
};


/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */