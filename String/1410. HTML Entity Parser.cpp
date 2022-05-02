class Solution {
public:
	string entityParser(string text) {
		string result;
		vector<string> S{ "&quot;", "&apos;", "&amp;", "&gt;", "&lt;", "&frasl;" };
		string s = ""'&></";
		for (int i = 0; i < text.size(); ++i)
			if (text[i] != '&')
				result += text[i];
			else
			{
                bool found = false;
				for(int z = 0; z < S.size(); ++z)
					if (text.substr(i, S[z].size()) == S[z])
					{
						i += S[z].size() - 1;
                        result += s[z];
                        found = true;
						break;						
					}
                if (!found)
                    result += text[i];
			}
		return result;
	}
};