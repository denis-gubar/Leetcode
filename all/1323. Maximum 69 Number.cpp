class Solution {
public:
	int maximum69Number(int num) {
		int result = num;
		string s = to_string(num);
		for(int i = 0; i < s.size(); ++i)
		{
			string t = s;
			t[i] = '9';
			result = max(result, atoi(t.c_str()));
		}
		return result;
	}
};