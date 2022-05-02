class Solution {
public:
	string removeDuplicates(string& S) {
		string result;
		for (char c : S)
			if (!result.empty() && result.back() == c)
				result.pop_back();
			else
				result.push_back(c);
		return result;
	}
};