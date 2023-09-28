#include <iostream>
#include "complex_header.h"
#include "unit_test_header.h"

int main() {
    assert_get_part();
    assert_test_assignment();
    assert_test_sum();
    assert_test_product();
    assert_test_subtraction();
    assert_test_division();
    assert_test_assignment_sum();
    assert_test_assignment_product();
    assert_test_assignment_subtraction();
    assert_test_assignment_division();
    assert_test_abs();
    assert_test_bool();
    assert_test_unary();
    assert_test_conjugate();
    assert_test_input();
    assert_test_output();
    return 0;
}
