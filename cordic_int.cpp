#include <bits/stdc++.h>

#include <chrono>
using namespace std;
using namespace std::chrono;

int main() {
    // ofstream MyFile("cordicSin.txt");
    vector<int> angle{
        45000,
        26565,
        14036,
        7125,
        3576,
        1790,
        895,
        448,
        224,
        112,
        56,
        28,
        14,
        7,
        3,
    };

    // cordic for 0-90 degree
    for (int j = 0; j <= 90; ++j) {
        // to scale xi just multiply the scaling factor with 0.607254
        // xi should be >= (1<<16) since its right shifted by 16 times during the processing and we might loose accuracy then
        int xi = 607254, yi = 0, xi1, yi1;
        int q = j * 1000;
        int sign = 1;

        // 15 iteration for each angle
        for (int i = 0; i < angle.size(); ++i) {
            if (q > 0)
                sign = 1;
            else
                sign = -1;

            xi1 = xi - sign * (yi >> i);
            yi1 = yi + sign * (xi >> i);
            q -= sign * angle[i];
            xi = xi1;
            yi = yi1;
        }
        // cout << "sin:" << yi << "   cos:" << xi << endl;
        // cout << "sin:" << sin(j * 3.14 / 180)*1000000 << "   cos:" << cos(j * 3.14 / 180)*1000000;
        // MyFile << yi <<",";
    }
    // MyFile.close();
    return 0;
}
