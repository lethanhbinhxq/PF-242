#ifndef UNIT_TEST_TASK2_HPP
#define UNIT_TEST_TASK2_HPP

#include "TASK2.h"
#include "unit_test.hpp"

// Macro to simplify test registration
#define REGISTER_TEST(func) registerTest(#func, [this]() { return func(); })

class UNIT_TEST_TASK2 : public UNIT_TEST {
 public:
  UNIT_TEST_TASK2() {
    REGISTER_TEST(TASK201);
    REGISTER_TEST(TASK202);
    REGISTER_TEST(TASK203);
    REGISTER_TEST(TASK204);
    REGISTER_TEST(TASK205);
    // TODO
  }

 private:
  bool TASK201();
  bool TASK202();
  bool TASK203();
  bool TASK204();
  bool TASK205();
  // TODO
};

#endif  // UNIT_TEST_TASK2_HPP