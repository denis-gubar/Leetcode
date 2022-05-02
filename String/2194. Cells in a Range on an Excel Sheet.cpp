class Solution {
public:
    vector<string> cellsInRange(string s) {
        vector<string> result;
        for (char col = s[0]; ; ++col)        
        {
            for (char row = s[1]; ; ++row)
            {
				string t;
				t += col;
				t += row;
                result.push_back(t);
                if (row == s[4])                
                    break;
            }
            if (col == s[3])
                break;            
        }
        return result;
    }
};
