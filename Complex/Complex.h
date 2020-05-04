//
// Created by fell2 on 03.05.2020.
//

#ifndef THEFIRSTAPP_COMPLEX_H
#define THEFIRSTAPP_COMPLEX_H


class Complex {
private:
    double re;
    double im;
public:
    Complex(double re, double im);

    Complex operator+(Complex z) const;

    Complex operator-(Complex z) const;

    Complex operator*(Complex z) const;

    Complex operator/(Complex z) const;

    void print() const;

    ~Complex() = default;
};


#endif //THEFIRSTAPP_COMPLEX_H
