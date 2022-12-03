#include "complex number.h"
#include <iostream>

ComplexNumber::ComplexNumber() {
}

ComplexNumber::ComplexNumber(double real, double image) {
    _real  = real;
    _image = image;
}

ComplexNumber::~ComplexNumber() {
}

void ComplexNumber::print() {
    std::cout<<_real;
    if (_image>0) {
        std::cout<<"+"<<_image<<"i";
    } else if (_image<0) {
        std::cout<<"-"<<abs(_image)<<"i";
    }
    std::cout<<"\n";
}

ComplexNumber& ComplexNumber::operator=(const ComplexNumber &c) {
    _real  = c._real;
    _image = c._image;
    return *this;
}

ComplexNumber& ComplexNumber::operator+(const ComplexNumber &c) {
    _real  += c._real;
    _image += c._image;
    return *this;
}

ComplexNumber& ComplexNumber::operator+=(const ComplexNumber &c) {
    _real  += c._real;
    _image += c._image;
    return *this;
}