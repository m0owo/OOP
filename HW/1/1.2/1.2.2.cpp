// INIT c
// PRINT table header
// FOR i from 0 and 300 with step 40 
//     c = (i - 32)(5/9)
//     PRINT i and c
// ENDFOR

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

int main() {
    float c;
    cout << setw(5) << "Fahr " << setw(7) << "Celcius" << endl;
    for (int i = 0; i <= 300; i+=40) {
        c = (i - 32) * (5.0 / 9.0);
        cout << fixed << right << setw(4) << i << setw(8) << setprecision(1) << c << endl;
        
    }
}

