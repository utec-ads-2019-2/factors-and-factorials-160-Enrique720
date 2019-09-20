#include <iostream>
#include <map>
#include <cmath>
#include <iomanip>
using namespace std;

map<int,int> contador;
void primeFactors(int n)
{
    while (n % 2 == 0)
    {
        contador[2]++;
        n = n/2;
    }
    for (int i = 3; i <= sqrt(n); i = i + 2)
    {
        while (n % i == 0)
        {
            contador[i]++;
            n = n/i;
        }
    }
    if (n > 2)
       contador[n]++;
}
int  main() {
    int x;
    while(cin >> x) {
        if (x >= 2) {
            cout << setw(3) << x << "! =";
            for (int i = x; i >= 2; i--) {
                primeFactors(i);
            }
            int p = 0;
            for (auto it = contador.begin(); it != contador.end(); it++) {
                if (p == 15) {
                    cout << endl << "      ";
                }
                p++;
                cout << setw(3) << it->second;
            }
            cout << endl;
            contador.clear();
        }
        else
        {
            return 0;

        }
    }
}
