class Solution {
public:
    vector<double> internalAngles(vector<int>& sides) {
        double const PI = 3.14159265358979323846;
        sort(sides.begin(), sides.end());
        int const& A = sides[0];
        int const& B = sides[1];
        int const& C = sides[2];
        if (A >= B + C || B >= A + C || C >= A + B)
            return {};
        vector<double> result(3);
        auto calc = [PI](int a, int b, int c) -> double
            {
                return acos(1.0 * (b * b + c * c - a * a) / (2 * b * c)) / PI * 180;
            };
        result[0] = calc(A, B, C);
        result[1] = calc(B, A, C);
        result[2] = calc(C, A, B);
        sort(result.begin(), result.end());
        return result;
    }
};
