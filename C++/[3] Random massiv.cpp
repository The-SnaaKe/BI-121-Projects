#include <iostream>
#include <ctime>

using namespace std;

int main()
{
    int i, a[15], sum;
    sum = 0;
    cout << "Massiv = ";
    srand(time(NULL));

    for (int i = 0; i < 15; i++)
    {
        a[i] = rand() % 31 - 15;
        cout << a[i] << " ";
        sum = sum + a[i];
    }

    cout << endl;
    cout << "Addition = " << sum << endl;
    
    return 0;
}