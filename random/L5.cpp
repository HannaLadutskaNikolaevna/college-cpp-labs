#include <iostream.h>
#include <math.h>
void main ()
{
    double x,y,z;
    cout<<”\n Input x: \n”;
    cin>>x;
    if (x<=9) y=pow(x, 3) – 6.5;
        else y=sqrt(x+8.7) + 5.2;
    cout<<”y = “<<y <<”\n”;
    if (y<8) z = y;
        else if (y==8) z=pow(y, 2);
            else z=pow(y, 3);
    cout<<”z = “<<z<<”\n”;
}