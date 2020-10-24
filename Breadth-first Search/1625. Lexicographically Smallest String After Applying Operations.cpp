class Solution {
public:
	string findLexSmallestString(string s, int a, int b) {
		set<string> S;
		queue<string> Q;
		S.insert(s);
		Q.push(s);
		while (!Q.empty())
		{
			string x = Q.front(); Q.pop();
			string t = x;
			rotate(x.begin(), x.begin() + b, x.end());
			if (S.insert(x).second)
				Q.push(x);
			for(int i = 1; i < t.size(); i += 2)			
				t[i] = (t[i] - '0' + a) % 10 + '0';
			if (S.insert(t).second)
				Q.push(t);
		}
		return *S.begin();
	}
};