class Solution {
public:
	vector<int> asteroidCollision(vector<int>& asteroids) {
		vector<int> result;
		for (int a : asteroids)
		{
            while (!result.empty() && a < 0 && result.back() > 0)
            {
                if (-a == result.back())                
                    a = 0, result.pop_back();
                else if (-a > result.back())
                    result.pop_back();
                else
                    a = 0;
            }
			if (a)
				result.push_back(a);
		}
		return result;
	}
};