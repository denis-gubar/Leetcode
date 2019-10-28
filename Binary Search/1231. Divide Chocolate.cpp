class Solution {
public:
	int maximizeSweetness(vector<int>& sweetness, int K) {
		int total = accumulate(sweetness.begin(), sweetness.end(), 0);
		int A = 0, B = total + 1;
		while (A + 1 < B)
		{            
			int M = (A + B) / 2;
			int count = 1, current = 0;
			for (int i = 0; count <= K + 1 && i < sweetness.size(); ++i)
			{
				if (current < M)
					current += sweetness[i];
				else
					current = sweetness[i], ++count;
			}
			if (count > K + 1 || count == K + 1 && current >= M)
				A = M;
			else
				B = M;
        }
		return A;
	}
};