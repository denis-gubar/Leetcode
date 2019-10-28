class Solution {
public:
	int reachNumber(int target) {
		int result = 0, pos = 0;
		if (target < 0)
			target = -target;
		while (pos < target)
		{
			++result;
			pos += result;
		}
        while(true)
        {
            if (target == pos)
                return result;
            if ((pos - target) % 2 == 0)
                return result;
            ++result;
            pos += result;
        }
	}
};