#include <iostream>
#include <cmath>

using namespace std;

int main()
{

    int a, b, action;
    char var;

    cout << "Do you want to start program? (y/n)" << endl;
    cin >> var;

    while (var == 'y')
    {

        cout << "Enter 2 numbers: " << endl;
        cin >> a >> b;

        cout << "Сhoose an action: " << endl
             << "1. Addition (+)" << endl
             << "2. Subtraction (-)" << endl
             << "3. Multiplication (*)" << endl
             << "4. Division (/)" << endl
             << "5. Exponentiation (^)" << endl
             << "6. Operation (%)" << endl;
        cin >> action;

        switch (action)
        {
        case 1:
            cout << "Result of addition: " << a + b << endl;
            break;
        case 2:
            cout << "Result of subtraction: " << a - b << endl;
            break;
        case 3:
            cout << "Result of multiplication: " << a * b << endl;
            break;
        case 4:
            if (b != 0)
            {
                cout << "Result of division:  " << (float)a / b << endl;
            }
            else
            {
                cout << "Error." << endl;
            }
            break;
        case 5:
            cout << "Result of exponentiation: " << pow(a, b) << endl;
            break;
        case 6:
            cout << "Result of operation:  " << (float)a/b * 100 << endl;
            break;

        default:
            cout << "Sorry man, but you can't use that symbol!" << endl;
            break;
        }
        cout << "Do you want to continue? (y/n)" << endl;
        cin >> var;
    }
    return 0;
}