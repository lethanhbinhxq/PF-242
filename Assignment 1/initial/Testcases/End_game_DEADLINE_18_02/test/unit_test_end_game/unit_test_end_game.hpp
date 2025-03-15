#ifndef UNIT_TEST_end_game_HPP
#define UNIT_TEST_end_game_HPP

#include "tay_nguyen_campaign.h"
#include "unit_test.hpp"

// Macro to simplify test registration
#define REGISTER_TEST(func) registerTest(#func, [this]() { return func(); })

class UNIT_TEST_end_game : public UNIT_TEST {
 public:
  UNIT_TEST_end_game() { 
    REGISTER_TEST(end_game01); 
    REGISTER_TEST(end_game02);
    REGISTER_TEST(end_game03);
    REGISTER_TEST(end_game04);
    REGISTER_TEST(end_game05);
    REGISTER_TEST(end_game06);
    REGISTER_TEST(end_game07);
    REGISTER_TEST(end_game08);
    REGISTER_TEST(end_game09);
    REGISTER_TEST(end_game10);
    REGISTER_TEST(end_game11); 
    REGISTER_TEST(end_game12);
    REGISTER_TEST(end_game13);
    REGISTER_TEST(end_game14);
    REGISTER_TEST(end_game15);
    REGISTER_TEST(end_game16);
    REGISTER_TEST(end_game17);
    REGISTER_TEST(end_game18);
    REGISTER_TEST(end_game19);
    REGISTER_TEST(end_game20);
  }

 private:
  bool end_game01();
  bool end_game02();
  bool end_game03();
  bool end_game04();
  bool end_game05();
  bool end_game06();
  bool end_game07();
  bool end_game08();
  bool end_game09();
  bool end_game10();
  bool end_game11();
  bool end_game12();
  bool end_game13();
  bool end_game14();
  bool end_game15();
  bool end_game16();
  bool end_game17();
  bool end_game18();
  bool end_game19();
  bool end_game20();
};

#endif  // UNIT_TEST_end_game_HPP