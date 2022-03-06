#include <iostream>
#include <cmath>
#include <cstdlib>

using namespace std;

int main(){
float a,b,c,x,x1,x2,D;
cout  << "Enter = a, b, c " <<  endl;
cin  >>  a  >>  b  >>  c;
if(a==0 and b==0){
cout << "No sqrt" << endl;
}
else if (a==0){
x=-c/b;
cout  << "x= " << x << endl;
}
else{
D=(pow(b,2))-(4*a*c);
}
if (D>0) {
x1=(-b+sqrt(D))/(2*a);
x2=(-b-sqrt(D))/(2*a);
cout  <<  "x1= " <<  x1  << "x2= " <<  x2  << endl;
}
else if (D==0){
x=-b/(2*a);
cout << "x= " <<  x  <<  endl;
}
else {
cout << "no sqrt" <<  endl;
}
system("pause");
}