#include <iostream>
#include <cmath>
#include <cstdlib>

using namespace std;

int main(){

int a, b, action;
char var;

do{
cout << "Enter 2 numbers: " << endl;
cin >> a >> b;

cout << "Сhoose an action: " << endl <<
"1. Addition (+)"<< endl <<
"2. Subtraction (-)" << endl <<
"3. Multiplication (*)" << endl <<
"4. Division (/)" << endl;
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
cout << "Result of division:  " << (float) a / b << endl;
break;

default:
cout << "Error" << endl;
break;
}
cout << "Do you want to continue? (y/n)" << endl;
cin >> var;
}
while (var == 'y');

}