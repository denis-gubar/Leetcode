class Solution {
public:
	struct Transaction
	{
		string name;
		int time;
		int amount;
		string city;
		string full;
		bool isInvalid;
		Transaction(string const& s): full(s), isInvalid(false)
		{
			vector<string> S = split(s, ',');
			name = S[0];
			time = atoi(S[1].c_str());
			amount = atoi(S[2].c_str());
			city = S[3];
		}
		vector<string> split(const string& s, char delimeter = ' ')
		{
			vector<string> result;
			istringstream ss(s);
			for (string token; !ss.eof(); )
			{
				getline(ss, token, delimeter);
				result.push_back(token);
			}
			return result;
		}
	};
	vector<string> invalidTransactions(vector<string>& transactions) {
		vector<string> result;
		vector<Transaction> T;
		for (string const& t : transactions)
			T.push_back(Transaction(t));
		for (int i = 0; i < T.size(); ++i)
		{
			if (T[i].amount > 1000)
				T[i].isInvalid = true;
			for (int j = i + 1; j < T.size(); ++j)
				if (T[i].name == T[j].name && T[i].city != T[j].city && abs(T[i].time - T[j].time) <= 60)
					T[i].isInvalid = T[j].isInvalid = true;
		}
		for (int i = 0; i < T.size(); ++i)
			if (T[i].isInvalid)
				result.push_back(T[i].full);
		return result;
	}
};