class Solution {
public:
	int maxDiff(int num) {
		string s = to_string(num);
		int result = 0;
		for (char x1 = '0'; x1 <= '9'; ++x1)
			for (char y1 = '0'; y1 <= '9'; ++y1)
			{
				string t1(s);
				replace(t1.begin(), t1.end(), x1, y1);
				int T1 = stoi(t1);
				if (T1 && to_string(T1) == t1)
				{
					for (char x2 = '0'; x2 <= '9'; ++x2)
						for (char y2 = '0'; y2 <= '9'; ++y2)
						{
							string t2(s);
							replace(t2.begin(), t2.end(), x2, y2);
							int T2 = stoi(t2);
							if (T2 && to_string(T2) == t2)
								result = max(result, abs(T1 - T2));
						}

				}
			}
		return result;
	}
};