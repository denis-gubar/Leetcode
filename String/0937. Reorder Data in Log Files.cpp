class Solution {
public:
	vector<string> reorderLogFiles(vector<string>& logs) {
		stable_sort(logs.begin(), logs.end(), [](const string& a, const string& b)
		{
			char A = a[a.find(' ') + 1];
			char B = b[b.find(' ') + 1];
			if (isdigit(B))
				return !isdigit(A);
			if (isdigit(A))
				return false;
			return a.substr(a.find(' ')) < b.substr(b.find(' '));
		});
		return logs;
	}
};