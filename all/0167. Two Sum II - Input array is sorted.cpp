class Solution {
public:
    vector<int> twoSum( vector<int>& numbers, int target ) {
        vector<int> result;
        for (int i = 0; i < numbers.size() - 1; ++i)
            if (binary_search( numbers.begin() + i + 1, numbers.end(), target - numbers[i] ))
            {
                result.push_back( i + 1 );
                result.push_back( distance(numbers.begin(), lower_bound( numbers.begin() + i + 1, numbers.end(), target - numbers[i] ) ) +  1 );
            }
        return result;
    }
};