#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int main()
{
    char var = 'y';
    int n, sum;

    while (var == 'y')
    {
        cout << "Enter n - ";
        cin >> n;
        int a[n];

        sum = 0;
        cout << "Massiv = ";
        srand(time(NULL));

        for (int i = 0; i < n; i++)
        {
            a[i] = rand() % 31 - 15;
            cout << a[i] << " ";
            sum = sum + a[i];
        }

        cout << endl;
        cout << "Addition = " << sum << endl;
        cout << "Do you want to continue? (y/n)" << endl;
        cin >> var;
    }
    system("pause");
}