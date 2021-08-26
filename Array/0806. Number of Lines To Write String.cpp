class Solution {
public:
    vector<int> numberOfLines( vector<int>& widths, string S ) {
        int w = 0;
        int rows = 1;
        for (int c : S)
        {
            if (w + widths[c - 'a'] <= 100)
                w += widths[c - 'a'];
            else
            {
                w = widths[c - 'a'];
                ++rows;
            }
        }
        return {rows, w};
    }
};