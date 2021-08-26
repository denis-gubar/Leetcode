class Solution {
public:
	int calPoints(vector<string>& ops) {
		vector<int>	scores;
		for(string const& op: ops)
			if (op == "C")
				scores.pop_back();
			else if (op == "D")
				scores.push_back(scores.back() * 2);
			else if (op == "+")
				scores.push_back(scores.back() + scores[scores.size() - 2]);
			else
				scores.push_back(stoi(op));
		return accumulate(scores.begin(), scores.end(), 0);
	}
};