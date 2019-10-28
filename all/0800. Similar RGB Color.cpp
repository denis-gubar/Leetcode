class Solution {
public:
    string similarRGB( string color ) {
        int x = 0, y = 0, z = 0;
        int bx = 256, by = 256, bz = 256;
        string digits{ "0123456789abcdef" };
        for (int i = 0; i < 16; ++i)
            if (abs( static_cast<int>(digits.find( color[1] )) * 16 +
                     static_cast<int>(digits.find( color[2] )) - i * 17 ) < bx)
            {
                bx = abs( static_cast<int>(digits.find( color[1] )) * 16 +
                          static_cast<int>(digits.find( color[2] )) - i * 17 );
                x = i;
            }
        for (int i = 0; i < 16; ++i)
            if (abs( static_cast<int>(digits.find( color[3] )) * 16 +
                     static_cast<int>(digits.find( color[4] )) - i * 17 ) < by)
            {
                by = abs( static_cast<int>(digits.find( color[3] )) * 16 +
                          static_cast<int>(digits.find( color[4] )) - i * 17 );
                y = i;
            }
        for (int i = 0; i < 16; ++i)
            if (abs( static_cast<int>(digits.find( color[5] )) * 16 +
                     static_cast<int>(digits.find( color[6] )) - i * 17 ) < bz)
            {
                bz = abs( static_cast<int>(digits.find( color[5] )) * 16 +
                          static_cast<int>(digits.find( color[6] )) - i * 17 );
                z = i;
            }
        return "#" + string( 2, digits[x] ) + string( 2, digits[y] ) + string( 2, digits[z] );
    }
};