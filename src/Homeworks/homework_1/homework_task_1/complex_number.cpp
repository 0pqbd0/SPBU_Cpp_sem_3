#include "complex_header.h"
#include "cmath"

complex_number::complex_number(double a_, double b_) : a(a_), b(b_) {}

double complex_number::get_re() const {
    return a;
}

double complex_number::get_im() const {
    return b;
}

complex_number& complex_number::operator+=(const complex_number &c_) {
    a += c_.a;
    b += c_.b;
    return *this;
}

complex_number& complex_number::operator+=(const double n) {
    a += n;
    return *this;
}

complex_number& operator+= (const double n, complex_number& c_) {
    c_+=n;
    return c_;
}

complex_number& complex_number::operator-=(const complex_number &c_) {
    a -= c_.a;
    b -= c_.b;
    return *this;
}

complex_number& complex_number::operator-=(const double n) {
    a -= n;
    return *this;
}

complex_number& operator-= (const double n, complex_number& c_) {
    c_-=n;
    return c_;
}

complex_number& complex_number::operator*=(const complex_number &c_) {
    double a_old = a;
    a = a * c_.a - b * c_.b;
    b = a_old * c_.b + b * c_.a;
    return *this;
}

complex_number& complex_number::operator*=(const double n) {
    a *= n;
    b *= n;
    return *this;
}

complex_number& operator*=(const double n, complex_number &c_) {
    c_ *= n;
    return c_;
}

complex_number& complex_number::operator/=(const complex_number &c_) {
    double a_old = a;
    a = (a * c_.a + b * c_.b) / (c_.a * c_.a + c_.b * c_.b);
    b = (c_.a * b - a_old * c_.b) / (c_.a * c_.a + c_.b * c_.b);
    return *this;
}

complex_number& complex_number::operator/=(const double n) {
    a /= n;
    b /= n;
    return *this;
}

complex_number& operator/=(const double n, complex_number &c_) {
    c_ /= n;
    return c_;
}

complex_number& complex_number::operator+() {
    return *this;
}

complex_number complex_number::operator-() const{
    complex_number c;
    c.a = -a;
    c.b = -b;
    return c;
}

complex_number complex_number::operator+ (const complex_number& c_) const{
    return complex_number(a + c_.a, b + c_.b);
}

complex_number complex_number::operator+ (const double n) const{
    return complex_number(a + n, b);
}

complex_number operator+ (const double n, const complex_number& c_) {
    return complex_number( c_.a + n, c_.b);
}

complex_number complex_number::operator- (const complex_number& c_) const{
    return complex_number(a - c_.a, b - c_.b);
}

complex_number complex_number::operator- (const double n) const{
    return complex_number(a - n, b);
}

complex_number operator- (const double n, const complex_number& c_) {
    return complex_number(  n - c_.a, -c_.b);
}

complex_number complex_number::operator* (const complex_number& c_) const{
    return complex_number(a * c_.a - b * c_.b, a * c_.b + b * c_.a);
}

complex_number complex_number::operator* (const double n) const{
    return complex_number(a * n, b * n);
}

complex_number operator* (const double n, const complex_number& c_) {
    return complex_number(c_.a * n, c_.b * n);
}

complex_number complex_number::operator/ (const complex_number& c_) const{
    return complex_number((a * c_.a + b * c_.b) / (c_.a * c_.a + c_.b * c_.b), (c_.a * b - a * c_.b) / (c_.a * c_.a + c_.b * c_.b));
}

complex_number complex_number::operator/ (const double n) const{
    return complex_number(a / n, b / n);
}

complex_number operator/ (const double n, const complex_number& c_) {
    complex_number result;
    result.a = n;
    result /= c_;
    return result;
}

complex_number& complex_number::operator=(const complex_number& c_) = default;

/*a = c_.a;
b = c_.b;
return *this;*/

complex_number& complex_number::operator=(const double n) {
    a = n;
    b = 0;
    return *this;
}

bool complex_number::operator==(const double n) const {
    return a == n && b == 0;
}

bool complex_number::operator==(const complex_number &c_) const {
    return a == c_.a && b == c_.b;
}

bool operator==(const double n, const complex_number& c_) {
    return c_.a == n && c_.b == 0;
}

bool complex_number::operator< (const complex_number& c_) const {
    return ((a < c_.a) || ((a == c_.a) && (b < c_.b)));
}

bool complex_number::operator< (const double n) const {
    return ((a < n) || (a == n && b < 0));
}

bool operator< (const double n, const complex_number& c_) {
    return (n < c_.a);
}

bool complex_number::operator> (const complex_number& c_) const {
    return ((a > c_.a) || ((a >= c_.a) && (b > c_.b)));
}

bool complex_number::operator> (const double n) const {
    return ((a > n) || (a == n && b > 0));
}

bool operator> (const double n, const complex_number& c_) {
    return (n > c_.a);
}

bool complex_number::operator<= (const complex_number& c_) const {
    return ((a < c_.a) || ((a == c_.a) && (b <= c_.b)));
}

bool complex_number::operator<= (const double n) const {
    return (*this < n) || (*this == n);
}

bool operator<= (const double n, const complex_number& c_) {
    return (n < c_) || (n == c_);
}

bool complex_number::operator>= (const complex_number& c_) const {
    return (a >= c_.a) && (b >= c_.b);
}

bool complex_number::operator>= (const double n) const {
    return (*this > n) || (*this == n);
}

bool operator>= (const double n, const complex_number& c_){
    return (n > c_) || (n == c_);
}

double complex_number::c_abs() const {
    return sqrt(a * a + b * b);
}

complex_number complex_number::conjugate() const{
    return complex_number(a, -b);
}

std::ostream& operator<< (std::ostream& stream, const complex_number& c_) {
    if (c_.b < 0) {
        return (stream << c_.a << " " << "-" << " " << -c_.b << "i");
    } else return (stream << c_.a << " " << "+" << " " << c_.b << "i");
}

std::istream& operator>> (std::istream& stream, complex_number& c_) {
    double a_;
    double b_;
    char sign;
    char i;
    stream >> a_ >> sign >> b_ >> i;
    if (stream) {
        c_.a = a_;
        if (sign == '+') {
            c_.b = b_;
        }
        else if (sign == '-') {
            c_.b = -b_;
        }
    }
    return stream;
}