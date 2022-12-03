//
// Created by WaitForever on 2022/11/26.
//

#ifndef COMPLEX_NUMBER_COMPLEX_NUMBER_H
#define COMPLEX_NUMBER_COMPLEX_NUMBER_H

#include <iostream>
#include "cmath"
using namespace std;


template<typename T>
class ComplexNumber {
public:
    ComplexNumber();
    ComplexNumber(T real, T image);
    ~ComplexNumber();

public:
    void print();
    void printreal();
    void printimage();
    ComplexNumber& set();
    ComplexNumber& setreal();
    ComplexNumber& setimage();
    T getmodulus();
    T getangle();
    void printmodulus();
    void printangle();
    void getpolar();
    void getcartesian();

public:
    ComplexNumber& getconjugate(const ComplexNumber &c);
    ComplexNumber& operator=(const ComplexNumber &c);
    ComplexNumber& operator+(const ComplexNumber &c);
    ComplexNumber& operator-(const ComplexNumber &c);
    ComplexNumber& operator*(const ComplexNumber &c);
    ComplexNumber& operator/(const ComplexNumber &c);
    ComplexNumber& operator+=(const ComplexNumber &c);
    ComplexNumber& operator-=(const ComplexNumber &c);
    ComplexNumber& operator*=(const ComplexNumber &c);
    ComplexNumber& operator/=(const ComplexNumber &c);
    bool operator==(const ComplexNumber &c);
    bool operator!=(const ComplexNumber &c);
    ComplexNumber& power(int n);
    ComplexNumber& root(int n);
    ComplexNumber& Exp(const ComplexNumber &c);
    ComplexNumber& Log(const ComplexNumber &c);
    ComplexNumber& Sin(const ComplexNumber &c);
    ComplexNumber& Cos(const ComplexNumber &c);
    ComplexNumber& Tan(const ComplexNumber &c);
    ComplexNumber& Sinh(const ComplexNumber &c);
    ComplexNumber& Cosh(const ComplexNumber &c);
    ComplexNumber& Tanh(const ComplexNumber &c);

private:
    T _real;
    T _image;
};

template<typename T>
ComplexNumber<T>::ComplexNumber() {
    _real  = 0;
    _image = 0;
}

template<typename T>
ComplexNumber<T>::ComplexNumber(T real, T image) {
    _real  = real;
    _image = image;
}

template<typename T>
ComplexNumber<T>::~ComplexNumber() {
}

template<typename T>
void ComplexNumber<T>::print() {
    cout << "complex number is " << round(_real*1e6)/1e6;
    if (_image>0) {
        cout << "+" << round(_image*1e6)/1e6 << "i";
    } else if (_image<0) {
        cout << "-" << round(fabs(_image)*1e6)/1e6 << "i";
    }
    cout << "\n";
}

template<typename T>
ComplexNumber<T>& ComplexNumber<T>::set() {
    ComplexNumber a;
    cout << "please enter the real part and the image part you want to set" << endl;
    cin >> a._real >> a._image;
    this->_real = a._real;
    this->_image = a._image;
    return *this;
}

template<typename T>
void ComplexNumber<T>::printreal() {
    cout << "the real part is " << _real << endl;
}

template<typename T>
void ComplexNumber<T>::printimage() {
    cout << "the image part is " << _image << endl;
}

template<typename T>
ComplexNumber<T>& ComplexNumber<T>::setreal() {
    ComplexNumber a;
    cout << "please enter the value you want to set the real part" << endl;
    cin >> a._real;
    this->_real = a._real;
    return *this;
}

template<typename T>
ComplexNumber<T>& ComplexNumber<T>::setimage() {
    ComplexNumber a;
    cout << "please enter the value you want to set the image part" << endl;
    cin >> a._image;
    this->_image = a._image;
    return *this;
}

template<typename T>
T ComplexNumber<T>::getmodulus() {
    T modulus = 0;
    modulus = sqrt(_real*_real + _image*_image);
    return modulus;
}

template<typename T>
void ComplexNumber<T>::printmodulus() {
    cout << "the modulus is " << round(getmodulus()*1e6)/1e6 << endl;
}

template<typename T>
T ComplexNumber<T>::getangle() {
    T angle = 0;
    angle = atan2(_image , _real);
    return angle;
}

template<typename T>
void ComplexNumber<T>::printangle() {
    cout << "the angle is " << round((getangle()/M_PI)*1e6)/1e6 << "pi" << endl;
    cout << "the degree is " << round((180*getangle()/M_PI)*1e6)/1e6 << endl;
}

template<typename T>
void ComplexNumber<T>::getpolar() {
    double r,theta;
    r = getmodulus();
    theta = getangle();
    cout << "cartesian to polar system is " << r << "e^i" << theta/M_PI << "pi"<< endl;
    cout << "equal to " << r << "(cos" << theta/M_PI << "pi+i*sin" << theta/M_PI << "pi)" << endl;
}

template<typename T>
void ComplexNumber<T>::getcartesian() {
    double r,degree,theta;
    cout << "please enter the polar parameters r and degree" << endl;
    cin >> r >> degree;
    theta = degree * M_PI / 180;
    double real,image;
    real = r * cos(theta);
    image = r * sin(theta);
    cout << "polar to cartesian system is " << round(real*1e6)/1e6;
    if (image>0) {
        cout << "+" << round(image*1e6)/1e6 << "i";
    } else if (image<0) {
        cout << "-" << round(fabs(image)*1e6)/1e6 << "i";
    }
    cout << "\n";
}

template<typename T>
ComplexNumber<T>& ComplexNumber<T>::getconjugate(const ComplexNumber &c) {
    ComplexNumber a;
    a._real = _real;
    a._image = -_image;
    return a;
}

template<typename T>
ComplexNumber<T>& ComplexNumber<T>::operator=(const ComplexNumber<T> &c) {
    this->_real  = c._real;
    this->_image = c._image;
    return *this;
}

template<typename T>
ComplexNumber<T>& ComplexNumber<T>::operator+(const ComplexNumber<T> &c) {
    ComplexNumber a;
    a._real = this->_real + c._real;
    a._image = this->_image + c._image;
    return a;
}

template<typename T>
ComplexNumber<T>& ComplexNumber<T>::operator-(const ComplexNumber<T> &c) {
    ComplexNumber a;
    a._real = this->_real - c._real;
    a._image = this->_image - c._image;
    return a;
}

template<typename T>
ComplexNumber<T>& ComplexNumber<T>::operator*(const ComplexNumber<T> &c) {
    ComplexNumber a;
    a._real = this->_real * c._real - this->_image * c._image;
    a._image = this->_real * c._image + this->_image * c._real;
    return a;
}

template<typename T>
ComplexNumber<T>& ComplexNumber<T>::operator/(const ComplexNumber<T> &c) {
    ComplexNumber a;
    a._real = (this->_real * c._real + this->_image * c._image) / (c._real * c._real + c._image * c._image);
    a._image = (this->_image * c._real - this->_real * c._image) / (c._real * c._real + c._image * c._image);
    return a;
}

template<typename T>
ComplexNumber<T>& ComplexNumber<T>::operator+=(const ComplexNumber<T> &c) {
    this->_real  += c._real;
    this->_image += c._image;
    return *this;
}

template<typename T>
ComplexNumber<T>& ComplexNumber<T>::operator-=(const ComplexNumber<T> &c) {
    this->_real  -= c._real;
    this->_image -= c._image;
    return *this;
}

template<typename T>
ComplexNumber<T>& ComplexNumber<T>::operator*=(const ComplexNumber<T> &c) {
    ComplexNumber a;
    a._real=this->_real;
    a._image=this->_image;
    this->_real = a._real * c._real - a._image * c._image;
    this->_image = a._real * c._image + a._image * c._real;
    return *this;
}

template<typename T>
ComplexNumber<T>& ComplexNumber<T>::operator/=(const ComplexNumber<T> &c) {
    ComplexNumber a;
    a._real=this->_real;
    a._image=this->_image;
    this->_real = (a._real * c._real + a._image * c._image) / (c._real * c._real + c._image * c._image);
    this->_image = (a._image * c._real - a._real * c._image) / (c._real * c._real + c._image * c._image);
    return *this;
}

template<typename T>
bool ComplexNumber<T>::operator==(const ComplexNumber<T> &c) {
    if (this->_real == c._real && this->_image == c._image){
        return true;
    }
    else
        return false;
}

template<typename T>
bool ComplexNumber<T>::operator!=(const ComplexNumber<T> &c) {
    if (this->_real != c._real || this->_image != c._image){
        return true;
    }
    else
        return false;
}

template<typename T>
ComplexNumber<T>& ComplexNumber<T>::power(int n) {
    ComplexNumber a;
    a._real = pow(getmodulus(),n) * cos(n * getangle());
    a._image = pow(getmodulus(),n) * sin(n * getangle());
    return a;
}

template<typename T>
ComplexNumber<T>& ComplexNumber<T>::root(int n) {
    ComplexNumber a;
    int k;
    for(k=1;k<n+1;k++){
        a._real = pow(getmodulus(),(double)1/n) * cos(getangle() / n + 2*k*M_PI/n);
        a._image = pow(getmodulus(),(double)1/n) * sin(getangle() / n + 2*k*M_PI/n);
        cout << "the "<<k<<"th "<<endl;
        a.print();
    }
    cout << "enter kth root you want (1<=k<=n)" << endl;
    cin >> k;
    a._real = pow(getmodulus(),(double)1/n) * cos(getangle() / n + 2*k*M_PI/n);
    a._image = pow(getmodulus(),(double)1/n) * sin(getangle() / n + 2*k*M_PI/n);
    return a;
}

template<typename T>
ComplexNumber<T>& ComplexNumber<T>::Exp(const ComplexNumber &c) {
    ComplexNumber a;
    a._real = exp(_real) * cos(_image);
    a._image = exp(_real) * sin(_image);
    return a;
}

template<typename T>
ComplexNumber<T>& ComplexNumber<T>::Log(const ComplexNumber &c) {
    ComplexNumber a;
    a._real = log(getmodulus());
    a._image = getangle();
    cout << "if you want to get other log values, use set() to add 2npi, n is any integer number" << endl;
    return a;
}

template<typename T>
ComplexNumber<T>& ComplexNumber<T>::Sin(const ComplexNumber &c) {
    ComplexNumber a;
    a._real = sin(_real) * cosh(_image);
    a._image = cos(_real) * sinh(_image);
    return a;
}

template<typename T>
ComplexNumber<T>& ComplexNumber<T>::Cos(const ComplexNumber &c) {
    ComplexNumber a;
    a._real = cos(_real) * cosh(_image);
    a._image = -sin(_real) * sinh(_image);
    return a;
}

template<typename T>
ComplexNumber<T>& ComplexNumber<T>::Tan(const ComplexNumber &c) {
    ComplexNumber a,b,d;
    a = Sin(c);
    b = Cos(c);
    d = a / b;
    return d;
}

template<typename T>
ComplexNumber<T>& ComplexNumber<T>::Sinh(const ComplexNumber &c) {
    ComplexNumber a;
    a._real = sinh(_real) * cos(_image);
    a._image = cosh(_real) * sin(_image);
    return a;
}

template<typename T>
ComplexNumber<T>& ComplexNumber<T>::Cosh(const ComplexNumber &c) {
    ComplexNumber a;
    a._real = cosh(_real) * cos(_image);
    a._image = sinh(_real) * sin(_image);
    return a;
}

template<typename T>
ComplexNumber<T>& ComplexNumber<T>::Tanh(const ComplexNumber &c) {
    ComplexNumber a,b,d;
    a = Sinh(c);
    b = Cosh(c);
    d = a / b;
    return d;
}

#endif //COMPLEX_NUMBER_COMPLEX_NUMBER_H
