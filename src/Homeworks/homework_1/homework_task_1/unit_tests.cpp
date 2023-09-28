#include <cassert>
#include <cmath>
#include "complex_header.h"
#include <sstream>
#include "unit_test_header.h"

void assert_get_part() {
    complex_number t1(11, -3);
    complex_number t2(-7, 5);

    assert((t1.get_re()) == 11);
    assert((t1.get_im()) == -3);
    assert((t2.get_re()) == -7);
    assert((t2.get_im()) == 5);
}

void assert_test_assignment() {
    complex_number t_1(8, 2);
    complex_number t_2(4, 1);

    t_1 = t_2;
    assert ((t_1.get_re() == t_2.get_re()) && (t_1.get_im() == t_2.get_im()));
}

void assert_test_sum() {
    complex_number t1(3, 7);
    complex_number t2(11, -3);
    complex_number t3(-7, 5);
    complex_number t4(-1, -5);

    double n = 7;
    complex_number t1_2(t1.get_re() + t2.get_re(), t1.get_im() + t2.get_im());
    complex_number t3_4(t3.get_re() + t4.get_re(), t3.get_im() + t4.get_im());
    complex_number t1_n(t1.get_re() + n, t1.get_im());
    complex_number t3_n(t3.get_re() + n, t3.get_im());

    assert((t1 + t2) == t1_2);
    assert((t3 + t4) == t3_4);
    assert((t1 + n)  == t1_n);
    assert((n + t1)  == t1_n);
    assert((t3 + n)  == t3_n);
    assert((n + t3)  == t3_n);
}

void assert_test_product() {
    complex_number t1(3, 7);
    complex_number t2(11, -3);
    complex_number t3(-7, 5);
    complex_number t4(-1, -5);

    double n = 7;
    complex_number t1_2(t1.get_re() * t2.get_re() - t1.get_im() * t2.get_im(), t1.get_re() * t2.get_im() + t1.get_im() * t2.get_re());
    complex_number t3_4(t3.get_re() * t4.get_re() - t3.get_im() * t4.get_im(), t3.get_re() * t4.get_im() + t3.get_im() * t4.get_re());
    complex_number t1_n(t1.get_re() * n, t1.get_im() * n);
    complex_number t3_n(t3.get_re() * n, t3.get_im() * n);

    assert((t1 * t2) == t1_2);
    assert((t3 * t4) == t3_4);
    assert((t1 * n) == t1_n);
    assert((n * t1) == t1_n);
    assert((t3 * n) == t3_n);
    assert((n * t3) == t3_n);
}

void assert_test_subtraction() {
    complex_number t1(3, 7);
    complex_number t2(11, -3);
    complex_number t3(-7, 5);

    double n =7;
    complex_number t1_2(t1.get_re() - t2.get_re(), t1.get_im() - t2.get_im());
    complex_number t1_n(t1.get_re() - n, t1.get_im());
    complex_number tn_1(n - t1.get_re(), -(t1.get_im()));
    complex_number t3_n(t3.get_re() - n, t3.get_im());

    assert((t1 - t2) == t1_2);
    assert((t2 - t1) == -t1_2);
    assert((t1 - n) == t1_n);
    assert((n - t1) == tn_1);
    assert((t3 - n) == t3_n);
}

void assert_test_division() {
    complex_number t1(3, 7);
    complex_number t2(11, -3);
    complex_number t3(-7, 5);
    complex_number t4(-1, -5);

    double n =7;
    complex_number t1_2((t1.get_re() * t2.get_re() + t1.get_im() * t2.get_im()) / (t2.get_re() * t2.get_re() + t2.get_im() * t2.get_im()),((t2.get_re() * t1.get_im() - t1.get_re() * t2.get_im()) / (t2.get_re() * t2.get_re() + t2.get_im() * t2.get_im())));
    complex_number t2_1((t1.get_re() * t2.get_re() + t1.get_im() * t2.get_im()) / (t1.get_re() * t1.get_re() + t1.get_im() * t1.get_im()),((t1.get_re() * t2.get_im() - t2.get_re() * t1.get_im()) /(t1.get_re() * t1.get_re() + t1.get_im() * t1.get_im())));
    complex_number t1_n(t1.get_re() / n, t1.get_im() / n);
    complex_number tn_2(n * t2.get_re() / (t2.get_re() * t2.get_re() + t2.get_im() * t2.get_im()),((- n * t2.get_im()) / (t2.get_re() * t2.get_re() + t2.get_im() * t2.get_im())));
    complex_number t3_4((t3.get_re() * t4.get_re() + t3.get_im() * t4.get_im()) / (t4.get_re() * t4.get_re() + t4.get_im() * t4.get_im()),((t4.get_re() * t3.get_im() - t3.get_re() * t4.get_im()) / (t4.get_re() * t4.get_re() + t4.get_im() * t4.get_im())));

    assert((t1 / t2) == t1_2);
    assert((t3 / t4) == t3_4);
    assert((t2 / t1) == t2_1);
    assert((t1 / n)  == t1_n);
    assert((n / t2)  == tn_2);
}

void assert_test_assignment_sum() {
    complex_number t1(3, 7);
    complex_number t2(11, -3);
    complex_number t3(-7, 5);
    complex_number t4(-1, -5);

    double n =7;
    complex_number t1_2(t1.get_re() + t2.get_re(), t1.get_im() + t2.get_im());
    complex_number t3_4(t3.get_re() + t4.get_re(), t3.get_im() + t4.get_im());
    complex_number t1_n(t1_2.get_re() + n, t1_2.get_im());
    complex_number t3_n(t3_4.get_re() + n, t3_4.get_im());

    assert((t1 += t2) == t1_2);
    assert((t3 += t4) == t3_4);
    assert((t1 += n)  == t1_n);
    assert((t3 += n)  == t3_n);
}

void assert_test_assignment_product() {
    complex_number t1(3, 7);
    complex_number t2(11, -3);
    complex_number t3(-7, 5);
    complex_number t4(-1, -5);

    double n = 7;
    complex_number t1_2(t1.get_re() * t2.get_re() - t1.get_im() * t2.get_im(), t1.get_re() * t2.get_im() + t1.get_im() * t2.get_re());
    complex_number t3_4(t3.get_re() * t4.get_re() - t3.get_im() * t4.get_im(), t3.get_re() * t4.get_im() + t3.get_im() * t4.get_re());
    complex_number t1_n(t1_2.get_re() * n, t1_2.get_im() * n);
    complex_number t3_n(t3_4.get_re() * n, t3_4.get_im() * n);

    assert((t1 *= t2) == t1_2);
    assert((t3 *= t4) == t3_4);
    assert((t1 *= n)  == t1_n);
    assert((t3 *= n)  == t3_n);
}

void assert_test_assignment_subtraction() {
    complex_number t1(3, 7);
    complex_number t2(11, -3);
    complex_number t3(-7, 5);
    complex_number t4(-1, -5);

    double n =7;
    complex_number t1_2(t1.get_re() - t2.get_re(), t1.get_im() - t2.get_im());
    complex_number t3_4(t3.get_re() - t4.get_re(), t3.get_im() - t4.get_im());
    complex_number t1_n(t1_2.get_re() - n, t1_2.get_im());
    complex_number t3_n(t3_4.get_re() - n, t3_4.get_im());

    assert((t1 -= t2) == t1_2);
    assert((t3 -= t4) == t3_4);
    assert((t1 -= n)  == t1_n);
    assert((t3 -= n)  == t3_n);
}

void assert_test_assignment_division() {
    complex_number t1(3, 7);
    complex_number t2(11, -3);
    complex_number t3(-7, 5);
    complex_number t4(-1, -5);

    double n =7;
    complex_number t1_2((t1.get_re() * t2.get_re() + t1.get_im() * t2.get_im()) / (t2.get_re() * t2.get_re() + t2.get_im() * t2.get_im()),((t2.get_re() * t1.get_im() - t1.get_re() * t2.get_im()) / (t2.get_re() * t2.get_re() + t2.get_im() * t2.get_im())));
    complex_number t3_4((t3.get_re() * t4.get_re() + t3.get_im() * t4.get_im()) / (t4.get_re() * t4.get_re() + t4.get_im() * t4.get_im()),((t4.get_re() * t3.get_im() - t3.get_re() * t4.get_im()) / (t4.get_re() * t4.get_re() + t4.get_im() * t4.get_im())));
    complex_number t1_n(t1_2.get_re() / n, t1_2.get_im() / n);
    complex_number t3_n(t3_4.get_re() / n, t3_4.get_im() / n);

    assert((t1 /= t2) == t1_2);
    assert((t3 /= t4) == t3_4);
    assert((t1 /= n) == t1_n);
    assert((t3 /= n) == t3_n);
}

void assert_test_abs() {
    complex_number t1(5, 7);
    complex_number t2(3, -3);
    complex_number t3(-3, 5);
    complex_number t4(-7, -11);

    assert (t1.c_abs() == sqrt(74));
    assert (t2.c_abs() == sqrt(18));
    assert (t3.c_abs() == sqrt(34));
    assert (t4.c_abs() == sqrt(170));
}

void assert_test_bool() {
    complex_number t1(5, 7);
    complex_number t_1(5, 7);
    complex_number t_1_(-5, -7);
    complex_number t2(3, -3);
    complex_number t_2(3, -3);
    complex_number t_2_(-3, 3);
    complex_number t3(-3, 5);
    complex_number t_3(-3, 5);
    complex_number t_3_(3, -5);
    complex_number t4(-7, -11);
    complex_number t_4(-7, -11);
    complex_number t_4_(7, 11);

    complex_number bt(3, 0);
    double t = 3;

    assert (t1 == t_1);
    assert (t2 == t_2);
    assert (t3 == t_3);
    assert (t4 == t_4);
    assert (bt ==   t);
    assert (t  ==  bt);

    assert (t1 != t_1_);
    assert (t2 != t_2_);
    assert (t3 != t_3_);
    assert (t4 != t_4_);
    assert (t1 != t);
    assert (t != t1);

    assert (t2 < t1);
    assert (t3 < t2);
    assert (t4 < t3);
    assert (t < t_1);

    assert (t2 <= t1);
    assert (t3 <= t2);
    assert (t4 <= t3);
    assert (bt <=   t);
    assert (t  <=  bt);
    assert (t <= t_1);

    assert ((t2 > t1) == 0);
    assert ((t3 > t2) == 0);
    assert ((t4 > t3) == 0);
    assert ((t > t_1) == 0);

    assert ((t2 >= t1) == 0);
    assert ((t3 >= t2) == 0);
    assert ((t4 >= t3) == 0);
    assert ((t >= t_1) == 0);
}

void assert_test_conjugate() {
    complex_number t1(5, 7);
    complex_number t2(3, -3);
    complex_number t3(-3, 5);
    complex_number t4(-7, -11);

    complex_number bb1(5, -7);
    complex_number bb2(3, 3);
    complex_number bb3(-3, -5);
    complex_number bb4(-7, 11);

    assert (t1.conjugate() == bb1);
    assert (t2.conjugate() == bb2);
    assert (t3.conjugate() == bb3);
    assert (t4.conjugate() == bb4);
}

void assert_test_unary() {
    complex_number t1(5, 7);
    complex_number t_1_(-5, -7);
    complex_number t2(3, -3);
    complex_number t_2_(-3, 3);
    complex_number t3(-3, 5);
    complex_number t_3_(3, -5);
    complex_number t4(-7, -11);
    complex_number t_4_(7, 11);

    assert ((-t1 == t_1_) == 1);
    assert ((-t2 == t_2_) == 1);
    assert ((-t3 == t_3_) == 1);
    assert ((-t4 == t_4_) == 1);

    assert (+t1 == t1);
    assert (+t2 == t2);
    assert (+t3 == t3);
    assert (+t4 == t4);
}

void assert_test_input() {
    complex_number k;
    std::istringstream in ("17 - 11i");
    in >> k;
    assert (k.get_re() == 17);
    assert (k.get_im() == -11);
}

void assert_test_output() {
    complex_number g(17, -11);
    std::ostringstream out;
    out << g;
    assert (out.str() == "17 - 11i");
}