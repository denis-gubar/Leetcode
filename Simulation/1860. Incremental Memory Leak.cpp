class Solution {
public:
	vector<int> memLeak(int memory1, int memory2) {
		vector<int> result{ 0, memory1, memory2 };
		int x = 1;
		int& count = result[0];
		int& a = result[1];
		int& b = result[2];
		while (true)
		{
			++count;
			if (a >= b)
            {
                if (a >= x)
				    a -= x;
                else
                    break;
            }
			else
            {
                if (b >= x)
				    b -= x;
                else
                    break;
            }
			++x;
		}
		return result;
	}
};