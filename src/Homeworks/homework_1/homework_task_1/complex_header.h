#ifndef HOMEWORK_TASK_1_COMPLEX_HEADER_H
#define HOMEWORK_TASK_1_COMPLEX_HEADER_H

#include "istream"
#include "ostream"


class complex_number {
private:
    double a, b;
public:
    complex_number(double a_ = 0, double b_ = 0);

    double get_re() const;

    double get_im() const;

    complex_number &operator+=(const complex_number &c_);

    complex_number &operator+=(const double n);

    friend complex_number& operator+=(const double n, complex_number &c_);

    complex_number &operator-=(const complex_number &c_);

    complex_number &operator-=(const double n);

    friend complex_number& operator-=(const double n, complex_number &c_);

    complex_number &operator*=(const complex_number &c_);

    complex_number &operator*=(const double n);

    friend complex_number& operator*=(const double n, complex_number &c_);

    complex_number &operator/=(const complex_number &c_);

    complex_number &operator/=(const double n);

    friend complex_number& operator/=(const double n, complex_number &c_);

    complex_number& operator+();

    complex_number operator-() const;

    complex_number operator+ (const complex_number& c_) const;

    complex_number operator+ (const double n) const;

    friend complex_number operator+ (const double n, const complex_number& c_);

    complex_number operator- (const complex_number& c_) const;

    complex_number operator- (const double n) const;

    friend complex_number operator- (const double n, const complex_number& c_);

    complex_number operator* (const complex_number& c_) const;

    complex_number operator* (const double n) const;

    friend complex_number operator* (const double n, const complex_number& c_);

    complex_number operator/ (const complex_number& c_) const;

    complex_number operator/ (const double n) const;

    friend complex_number operator/ (const double n, const complex_number& c_);

    complex_number& operator=(const complex_number& c_);

    complex_number& operator=(const double n);

    bool operator==(const complex_number &c_) const;

    bool operator==(const double n) const;

    friend bool operator==(const double n, const complex_number& c_);

    bool operator< (const complex_number& c_) const;

    bool operator< (const double n) const;

    friend bool operator< (const double n, const complex_number& c_);

    bool operator> (const complex_number& c_) const;

    bool operator> (const double n) const;

    friend bool operator> (const double n, const complex_number& c_);

    bool operator<= (const complex_number& c_) const;

    bool operator<= (const double n) const;

    friend bool operator<= (const double n, const complex_number& c_);

    bool operator>= (const complex_number& c_) const;

    bool operator>= (const double n) const;

    friend bool operator>= (const double n, const complex_number& c_);

    friend bool operator>= (const double n, const complex_number& c_);

    double c_abs() const;

    complex_number conjugate() const;

    friend std::ostream& operator<< (std::ostream& stream, const complex_number& c_);

    friend std::istream& operator>> (std::istream& stream, complex_number& c_);
};

#endif
