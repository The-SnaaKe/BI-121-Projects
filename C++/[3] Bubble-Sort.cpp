#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int main()
{

  int i, j, buff, n;
  cout << "Enter n - ";
  cin >> n;
  int a[n];

  cout << "Before massiv: ";
  srand(time(NULL));
  for (i = 0; i < n; i++)
  {
    a[i] = rand() % 37 - 18;
    cout << a[i] << " ";
  }

  for (i = 0; i < n; i++)
  {
    for (j = 0; j < n - 1; j++)
    {

      if (a[j] > a[j + 1])
      {
        buff = a[j];     // создали дополнительную переменную
        a[j] = a[j + 1]; // меняем местами
        a[j + 1] = buff; // значения элементов
      }
    }
  }
  cout << endl;
  cout << "After massiv: ";
  for (i = 0; i < n; i++)
  {
    cout << a[i] << " ";
  }
  cout << endl;
  system("pause");
}