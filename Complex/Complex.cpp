//
// Created by fell2 on 03.05.2020.
//

#include <iostream>
#include "Complex.h"

Complex::Complex(double re, double im) {
    this->re = re;
    this->im = im;
}

Complex Complex::operator+(Complex z) const {
    return Complex(re + z.re, im + z.im);
}

Complex Complex::operator-(Complex z) const {
    return Complex(re - z.re, im - z.im);
}

Complex Complex::operator*(Complex z) const {
    return Complex(this->re * z.re - im * z.im, im * z.re + re * z.im);
}

Complex Complex::operator/(Complex z) const {
    return Complex((re * z.re + im * z.im) / (z.re * z.re + z.im * z.im),
                   (im * z.re - re * z.im) / (z.re * z.re + z.im * z.im));
}

void Complex::print() const {
    std::cout << re << " + i*" << im << std::endl;
}

Complex::Complex() {
    this->re = 0;
    this->im = 0;
}

std::ostream &operator<<(std::ostream &out, Complex z) {
    out << z.re << " + i * " << z.im;
    return out;
}

