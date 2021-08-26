class Solution {
public:
	int countElements(vector<int>& arr) {
        int result = 0;
		vector<int> A(1001);
		for(int a: arr)
            ++A[a];        
		for(int i = 1; i <= 1000; ++i)
            result += A[i] ? A[i - 1] : 0;
        return result;
	}
};