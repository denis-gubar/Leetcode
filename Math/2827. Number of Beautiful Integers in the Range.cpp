static int F[11][11][11][20][2][2][2];
class Solution {
public:
	int numberOfBeautifulIntegers(int low, int high, int k) {
		string A = to_string(low);
		string B = to_string(high);
		reverse(A.begin(), A.end());
		while (A.size() != B.size())
			A.push_back('0');
		reverse(A.begin(), A.end());
		memset(F, 0, sizeof(F));
		F[0][0][0][0][1][1][1] = 1;
		int N = A.size();
		for (int i = 0; i < N; ++i)
			for (int oddCount = 0, a = A[i] - '0', b = B[i] - '0'; oddCount <= i; ++oddCount)
				for (int evenCount = 0; evenCount <= i; ++evenCount)
					for (int j = 0; j < k; ++j)
						for (int isA = 0; isA < 2; ++isA)
							for (int isB = 0; isB < 2; ++isB)
								for (int isZero = 0; isZero < 2; ++isZero)
							{
								int& prevF = F[i][oddCount][evenCount][j][isA][isB][isZero];
								if (prevF)
									for (int d = 0; d < 10; ++d)
										if ((!isA || d >= a) && (!isB || d <= b))
										{
											int& nextF = F[i + 1][oddCount + d % 2][evenCount + (d % 2 == 0 && (!isZero || d > 0))][(j * 10 + d) % k][isA && d == a][isB && d == b][isZero && d == 0];
											nextF += prevF;
										}
							}
		int result = 0;
		for (int oddCount = 1; oddCount < N; ++oddCount)
			for (int isA = 0; isA < 2; ++isA)
				for (int isB = 0; isB < 2; ++isB)
					result += F[N][oddCount][oddCount][0][isA][isB][false];
		return result;
	}
};
