class Codec {
public:

	// Encodes a list of strings to a single string.
	string encode(vector<string>& strs) {
		string result;
		result += to_string(strs.size());
		result += ';';
		for (const string& s : strs)
		{
			result += to_string(s.size());
			result += ';';
			result += s;
		}
		return result;
	}

	// Decodes a single string to a list of strings.
	vector<string> decode(string s) {
		vector<string> result;
		string t;
		int i = 0;
		for (; s[i] != ';'; ++i)
			t += s[i];        
        ++i;
		result = vector<string>(atoi(t.c_str()));
		for (int j = 0; j < result.size(); ++j)
		{
			t.clear();
			for (; s[i] != ';'; ++i)
				t += s[i];            
            ++i;
			int x = atoi(t.c_str());
			for (int k = 0; k < x; ++k, ++i)
				result[j] += s[i];
		}
		return result;
	}
};


// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));