class Solution {
public:
	string gcdOfStrings(string str1, string str2) {
		string result;
		for(int i = 1; i <= str1.size() && i <= str2.size(); ++i)
			if (str1.size() % i == 0 && str2.size() % i == 0)
			{
				string x = str1.substr(0, i);
				string x1;
				for (int k = 0; k < str1.size() / i; ++k)
					x1 += x;
				string x2;
				for (int k = 0; k < str2.size() / i; ++k)
					x2 += x;
				if (x1 == str1 && x2 == str2)
					result = x;
			}
		return result;
	}
};