#include <bits/stdc++.h>
using namespace std;

int main() {
    // tan^-1 of negative powers of 2
    ofstream MyFile("Sin.txt");

    vector<double> angle{
        45.000,
        26.565,
        14.036,
        7.125,
        3.576,
        1.790,
        0.895,
        0.448,
        0.224,
        0.112,
        0.056,
        0.028,
        0.014,
        0.007,
        0.003,
    };

    // finding the scaling factor
    // double x = 1;
    // for (int i = 0; i < angle.size(); ++i) {
    //     x *= cos((angle[i] * 3.141593) / 180.0);
    // }
    // cout << x << endl;

    // cordic for 0-90 degree
    for (int j = 0; j <= 90; ++j) {
        double xi = 0.607254, yi = 0, xi1, yi1;
        // int xi = 1<<16, yi = 0, xi1, yi1;
        double q = j;
        // double xi = 5, yi = 0, xi1, yi1, multiplier = 0.607254;
        int sign = 1, divisor = 1;

        // 15 iteration for each angle
        for (int i = 1; i <= angle.size(); ++i) {
            if (q > 0)
                sign = 1;
            else
                sign = -1;

            xi1 = xi - sign * (yi / divisor);
            yi1 = yi + sign * (xi / divisor);
            q -= sign * angle[i - 1];
            xi = xi1;
            yi = yi1;
            divisor *= 2;
        }
        // cout << endl;
        // cout << "sin:" << sin((j * 3.141593) / 180.0) - yi << "   cos:" << cos((j * 3.141593) / 180.0) - xi << endl;
        // cout << "sin:" << (double(yi) / (1 << 16)) * 0.607254 << "   cos:" << (double(xi) / (1 << 16)) * 0.607254 << endl;
        // cout << "sin:" << sin(j*3.14/180) << "   cos:" << cos(j*3.14/180);
        MyFile << int(sin(j*3.14/180)*1000000) << ",";
    }
    MyFile.close();
    return 0;
}