class Solution {
public:
	vector<int> findEvenNumbers(vector<int>& digits) {
		vector<int> result;
        result.reserve(450);
        char M1[10], M2[10];        
        memset(M2, 0, sizeof(M2));
        for (int d : digits)
				++M2[d];
		for (int x = 100; x < 1000; x += 2)
		{
			int count = 0;
            memset(M1, 0, sizeof(M1));
            ++M1[x % 10];
            ++M1[x / 10 % 10];
            ++M1[x / 100 % 10];
			bool isOk = true;            
			for (char d = 0; d < 10; ++ d)
				isOk &= M2[d] >= M1[d];
			if (isOk)
				result.push_back(x);
		}
		return result;
	}
};