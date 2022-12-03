#include <iostream>
#include "complex number.h"

int main() {
    ComplexNumber<double> a(1,1);
    std::cout<<"The complex number a is:";
    a.print();
    ComplexNumber<double> b(1,-1);
    std::cout<<"The complex number b is:";
    b.print();
    ComplexNumber<double> c(2,2);
    std::cout<<"The complex number c is:";
    c.print();
    ComplexNumber<double> d(0,0);
    std::cout<<"The complex number d is:";
    d.print();
    a.printreal();
    a.printimage();
    d.set();
    d.print();
    d.setreal();
    d.print();
    d.setimage();
    d.print();
    c.getmodulus();
    c.printmodulus();
    c.getangle();
    c.printangle();
    c.getpolar();
    c.getcartesian();
    c.getconjugate(c);
    d = a; d.print();
    d = a+b; d.print();
    d = a-b; d.print();
    d = a*b; d.print();
    d = a/b; d.print();
    d += a; d.print();
    d -= a; d.print();
    d *= a; d.print();
    d /= a; d.print();
    if(a==b){
        cout<<"equal\n";
    }
    else{
        cout<<"not equal\n";
    }
    if(a!=a){
        cout<<"not equal\n";
    }
    else{
        cout<<"equal\n";
    }
    d = a.power(4);
    d.print();
    //d = a.root(4);
    d.print();
    d = a.Exp(a);
    d.print();
    d = a.Log(a);
    d.print();
    d = a.Sin(a);
    d.print();
    d = a.Cos(a);
    d.print();
    d = a.Tan(a);
    d.print();
    d = a.Sinh(a);
    d.print();
    d = a.Cosh(a);
    d.print();
    d = a.Tanh(a);
    d.print();

    return 0;
}
