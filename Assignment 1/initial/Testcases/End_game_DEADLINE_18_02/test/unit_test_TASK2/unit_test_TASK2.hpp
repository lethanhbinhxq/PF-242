#ifndef UNIT_TEST_TASK2_HPP
#define UNIT_TEST_TASK2_HPP

#include "tay_nguyen_campaign.h"
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
    REGISTER_TEST(TASK206);
    REGISTER_TEST(TASK207);
    REGISTER_TEST(TASK208);
    REGISTER_TEST(TASK209);
    REGISTER_TEST(TASK210);
    REGISTER_TEST(TASK211);
    REGISTER_TEST(TASK212);
    REGISTER_TEST(TASK213);
    REGISTER_TEST(TASK214);
    REGISTER_TEST(TASK215);
    REGISTER_TEST(TASK216);
    REGISTER_TEST(TASK217);
    REGISTER_TEST(TASK218);
    REGISTER_TEST(TASK219);
    REGISTER_TEST(TASK220);
    REGISTER_TEST(TASK221);
    // TODO
  }

 private:
  bool TASK201();
  bool TASK202();
  bool TASK203();
  bool TASK204();
  bool TASK205();
  bool TASK206();
  bool TASK207();
  bool TASK208();
  bool TASK209();
  bool TASK210();
  bool TASK211();
  bool TASK212();
  bool TASK213();
  bool TASK214();
  bool TASK215();
  bool TASK216();
  bool TASK217();
  bool TASK218();
  bool TASK219();
  bool TASK220();
  bool TASK221();
  // TODO
};

#endif  // UNIT_TEST_TASK2_HPP