#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int main()
{
    int n, i, left, right;

    cout << "Enter n - ";
    cin >> n;
    int a[n];

    cout << "Before massiv: ";
    for (i = 0; i < n; i++)
    {
        a[i] = rand() % 41 - 19;
        cout << a[i] << " ";
    }

    while (left < right)
    {
        srand(time(NULL));
        left = 0;
        right = n - 1;
        for (i = 0; i < n; i++)
        {
            if (a[i] > a[i + 1])
                swap(a[i], a[i + 1]);
                right--;
        }
        for (i = right; i > left; i--)
        {
            if (a[i] < a[i - 1])
                swap(a[i], a[i + 1]);
                left++;
        }
    }
    cout << endl;
    cout << "After massiv: ";
    for (i = 0; i < n; i++){
        cout << a[i] << " ";
    }
    return(0);
}
 