class Solution {
public:
	bool isLongPressedName(string name, string typed) {
		int a = 0, b = 0;
		char lastTyped = ' ';
		while (b < typed.size())
		{
			if (a < name.size() && name[a] == typed[b])
				lastTyped = name[a], ++a, ++b;
			else if ((a == name.size() || name[a] != typed[b]) && typed[b] == lastTyped)
				++b;
			else
				return false;
		}
		return a == name.size();
	}
};