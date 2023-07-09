/**
 * // This is the ArrayReader's API interface.
 * // You should not implement it, or speculate about its implementation
 * class ArrayReader {
 *   public:
 *     // Compares 4 different elements in the array
 *     // return 4 if the values of the 4 elements are the same (0 or 1).
 *     // return 2 if three elements have a value equal to 0 and one element has value equal to 1 or vice versa.
 *     // return 0 : if two element have a value equal to 0 and two elements have a value equal to 1.
 *     int query(int a, int b, int c, int d);
 *
 *     // Returns the length of the array
 *     int length();
 * };
 */

class Solution {
public:
    int guessMajority(ArrayReader &reader) {
			int N = reader.length();
			vector<bool> color(N);
			int first = reader.query(0, 1, 2, 3);
			int second = reader.query(0, 1, 2, 4);
			color[3] = true;
			color[4] = first == second;
			color[0] = (reader.query(1, 2, 3, 4) == first) == color[4];
			color[1] = (reader.query(0, 2, 3, 4) == first) == color[4];
			color[2] = (reader.query(0, 1, 3, 4) == first) == color[4];
			for(int last = 5; last < N; ++last)
				color[last] = reader.query(0, 1, 2, last) == first;
			vector<int> A(2);
			for(int i = 0; i < N; ++i)
				++A[color[i]];
			if (A[0] > A[1])
			{
				for(int i = 0; i < N; ++i)			
					if (!color[i])
						return i;
			}
			if (A[0] < A[1])
				return 3;
			return -1;
		}
};