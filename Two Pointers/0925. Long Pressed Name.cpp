class Solution {
public:
	bool isLongPressedName(string name, string typed) {
		int a = 0, b = 0;
		char prev = '$';
		while (b < typed.size())
		{
			if (name[a] == typed[b])
			{                
				prev = name[a], ++a, ++b;
				if (a == name.size() && b == typed.size()) return true;
				continue;
			}
			if (typed[b] != prev)
				return false;
			++b;
		}
		return a == name.size() && b == typed.size();
	}
};