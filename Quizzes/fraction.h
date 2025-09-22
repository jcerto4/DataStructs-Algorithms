// fraction.h
// Header-only class
#ifndef FRACTION_H
#define FRACTION_H
#include <iostream>

class fraction {
private:
    int numer = 0;                      // Numerator
    int denom = 1;                      // Denominator
public:
    fraction(int numer, int denom);     // Forward declatations of all class methods
    fraction(int numer);
    fraction  operator+( const fraction &rhs);
    fraction  operator-( const fraction &rhs);
    fraction  operator*( const fraction &rhs);
    fraction  operator/( const fraction &rhs);
    fraction& operator+=(const fraction &rhs);
    fraction& operator-=(const fraction &rhs);
    fraction  operator-();                       // Unary negative
    void reduce();
    friend std::ostream &operator<<(std::ostream &os, const fraction &f);
};

// Compute greatest common denominator helper function
int gcd(int a, int b) {
    int rem;
    while ( (a % b) > 0 ) {
        rem = a % b;
        a = b;
        b = rem;
    }
    return b;
}

// Define fraction class constructors, methods, and operators
// within scope of class

// Constructors
fraction::fraction(int numer, int denom) {
    if (denom == 0) { throw "Error: fractions may not have a 0 denominator."; }
    this->numer = numer;
    this->denom = denom;
    reduce();
}
// Delegated constructor
fraction::fraction(int numer) : fraction::fraction(numer, 1) {}

// Define operators
fraction fraction::operator+(const fraction &rhs) {
    double num = this->numer*rhs.denom + this->denom*rhs.numer;
    double den = this->denom*rhs.denom;
    fraction f( num, den);
    f.reduce();
    return f;
}

fraction fraction::operator-(const fraction &rhs) {
    fraction f(this->numer*rhs.denom - this->denom*rhs.numer, this->denom*rhs.denom);
    f.reduce();
    return f;
}

fraction fraction::operator-() {
    fraction f(-this->numer, this->denom);
    f.reduce();
    return f;
}

fraction fraction::operator*(const fraction &rhs) {
    fraction f(this->numer * rhs.numer, this->denom * rhs.denom);
    f.reduce();
    return f;
}

fraction fraction::operator/(const fraction &rhs) {
    if (rhs.numer == 0) {
        throw "Error: Cannot divide by zero";
    }

    fraction f(this->numer * rhs.denom, this->denom * rhs.numer);
    f.reduce();
    return f;
}

fraction& fraction::operator+=(const fraction &rhs) {
    int n = this->numer*rhs.denom + this->denom*rhs.numer;
    int d = this->denom*rhs.denom;
    this->numer = n;
    this->denom = d;
    this->reduce();
    return *this;
}

fraction& fraction::operator-=(const fraction &rhs) {
    int n = this->numer*rhs.denom - this->denom*rhs.numer;
    int d = this->denom*rhs.denom;
    this->numer = n;
    this->denom = d;
    this->reduce();
    return *this;
}

// Reduce a fraction in place by diving out gcd from numerator and denominator
void fraction::reduce() {
    if (numer == 0) {
        denom = 1;
    } else {
        bool neg = false;
        if ((numer < 0 && denom > 0) || (numer > 0 && denom < 0)) {
            neg = true;
        }

        numer  = abs(numer);
        denom  = abs(denom);
        int dn = gcd(numer, denom);
        numer /= dn;
        denom /= dn;

        if (neg) numer = -numer;
    }
}

// Overload global << operator so fraction objects may be printed
std::ostream &operator<<(std::ostream &os, const fraction &f) {
    if (f.denom == 1) {
        os << f.numer;
    } else {
        os << f.numer << "/" << f.denom;
    }
    return os;
}

#endif