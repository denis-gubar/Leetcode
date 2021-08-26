/**
 * // This is the ArrayReader's API interface.
 * // You should not implement it, or speculate about its implementation
 * class ArrayReader {
 *   public:
 *     // Compares the sum of arr[l..r] with the sum of arr[x..y] 
 *     // return 1 if sum(arr[l..r]) > sum(arr[x..y])
 *     // return 0 if sum(arr[l..r]) == sum(arr[x..y])
 *     // return -1 if sum(arr[l..r]) < sum(arr[x..y])
 *     int compareSub(int l, int r, int x, int y);
 *
 *     // Returns the length of the array
 *     int length();
 * };
 */

class Solution {
public:
	int getIndex(ArrayReader& reader) {
		int a = 0, b = reader.length() - 1;
		while (a < b)
		{
			int length = (b - a + 1) / 2;
			int x = reader.compareSub(a, a + length - 1, b - length + 1, b);
			if (x == 0)
				return a + length;
			if (x == 1)
				b = a + length - 1;
			else
				a = b - length + 1;
		}
		return a;
	}
};