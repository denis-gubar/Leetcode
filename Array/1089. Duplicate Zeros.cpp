class Solution {
public:
	void duplicateZeros(vector<int>& arr) {
        int N = arr.size();
		vector<int> B;
        for(int i = 0; B.size() < N; ++i)
        {
            B.push_back(arr[i]);
            if (B.size() < N && arr[i] == 0)
                B.push_back(0);
        }
        B.swap(arr);
	}
};