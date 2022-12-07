#include <stdio.h>
#include <math.h>
#include "CuTest.h"
#include "functions.h"


double sum_of_sides(double p1_x, double p1_y, double p2_x, double p2_y, double p3_x, double p3_y){
  double side1, side2, side3, sum;

  /* Calculate side 1 */
  side1 = calc_side(p1_x, p1_y, p2_x, p2_y);

  /* Calculate side 2 */
  side2 = calc_side(p2_x, p2_y, p3_x, p3_y);

  /* Calculate side 3 */
  side3 = calc_side(p1_x, p1_y, p3_x, p3_y);

  /* Calculate sum */
  sum = side1 + side2 + side3;

  
  return sum;
}

double calc_side(double p1_x, double p1_y, double p2_x, double p2_y){
  double x_difference;
  double y_difference;
  double side;

  x_difference = p1_x - p2_x;
  y_difference = p1_y - p2_y;

  side = sqrt(x_difference * x_difference + y_difference * y_difference);

  return side;
}

void print_sum(double sum){
  printf("The sum is %f\n", sum);
}

void test_calc_side0010(CuTest *tc){
  double actual = calc_side(0,0,1,0);
  double expected = 1;

  CuAssertDblEquals(tc, expected, actual, 0.00001);
}

void test_calc_side0011(CuTest *tc){
  double actual = calc_side(0,0,1,1);
  double expected = 1.41421356237;

  CuAssertDblEquals(tc, expected, actual, 0.00001);
}

CuSuite *calc_sideGetSuite() {
  CuSuite *suite = CuSuiteNew();
  SUITE_ADD_TEST(suite, test_calc_side0010);
  SUITE_ADD_TEST(suite, test_calc_side0011);
  //TODO: Add more tests

  return suite;
}



