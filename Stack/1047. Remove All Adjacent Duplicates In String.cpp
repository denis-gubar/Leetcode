class Solution {
public:
	string removeDuplicates(string S) {
		string result;
		stack<char> C;
		C.push('!');
		for (char c : S)
		{
			if (c == C.top())
				C.pop();
			else
				C.push(c);
		}
		while (!C.empty())
		{
			char x = C.top(); C.pop();
			if (x != '!')
				result += x;
		}
		reverse(result.begin(), result.end());
		return result;
	}
};