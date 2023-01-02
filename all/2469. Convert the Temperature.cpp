class Solution {
public:
    vector<double> convertTemperature(double celsius) {
        vector<double> result(2);
        result[0] = celsius + 273.15;
        result[1] = celsius * 1.80 + 32.00;
        return result;
    }
};