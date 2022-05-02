class Solution {
public:
	int minimumRefill(vector<int>& plants, int capacityA, int capacityB) {
		int result = 0;
		int N = plants.size();
		int A = capacityA, B = capacityB;
		int posA = 0, posB = N - 1;
		while (posA <= posB)
		{
			if (posA < posB)
			{
				if (plants[posA] > A)
					++result, A = capacityA;
				A -= plants[posA];
				++posA;
				if (plants[posB] > B)
					++result, B = capacityB;
				B -= plants[posB];
				--posB;
			}
			else if (A >= B)
			{
				if (plants[posA] > A)
					++result, A = capacityA;
				A -= plants[posA];
				++posA;
			}
			else
			{
				if (plants[posB] > B)
					++result, B = capacityB;
				B -= plants[posB];
				--posB;
			}
		}
		return result;
	}
};