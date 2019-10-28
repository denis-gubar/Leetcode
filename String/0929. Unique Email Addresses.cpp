class Solution {
public:
	int numUniqueEmails(vector<string>& emails) {
		set<string> S;
		for (const string& e : emails)
		{
			vector<string> parts(2);
			int pos = e.find('@');
			parts[0] = e.substr(0, pos);
			parts[1] = e.substr(pos + 1);
			parts[0] += '+';
			string t;
			swap(t, parts[0]);
			for (char c : t)
				if (c != '.')
					parts[0] += c;
			parts[0] = parts[0].substr(0, parts[0].find('+'));
			S.insert(parts[0] + "@" + parts[1]);
		}
		return S.size();
	}
};