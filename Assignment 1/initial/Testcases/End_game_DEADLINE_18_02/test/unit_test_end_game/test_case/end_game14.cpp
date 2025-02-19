#include "../unit_test_end_game.hpp"

bool UNIT_TEST_end_game::end_game14() {
  string name = "end_game14";
  //! data ------------------------------------
  string input_file("test/unit_test_end_game/test_case/input/input14");
  int LF1[17] = {0}, LF2[17] = {0}, EXP1 = 0, EXP2 = 0, T1 = 0, T2 = 0, E = 0;
  string code2_1 = "34Gia Lai47";
  string code2_2 = "Unhg Ft Manhm";
  int array_task4[10][10] = {
      {500, 500, 500, 500, 500, 500, 500, 500, 500, 500},
      {500, 500, 500, 500, 500, 500, 500000, 500, 500, 500},
      {500, 500, 500, 500, 500000, 500, 500, 500, 500, 500},
      {500, 500, 500, 500, 500, 500, 500, 500, 500, 500},
      {500, 500, 500, 500000, 500, 500, 500, 500, 500, 500},
      {500, 500, 500, 500, 500, 500, 500, 500, 500, 500},
      {500, 500, 500, 500, 500, 500, 500, 500, 500, 500},
      {500, 500, 500, 500, 500, 500, 500, 500, 500, 500},
      {500, 500, 500, 500, 500, 500, 500, 500, 500, 500},
      {500, 500, 500, 500, 500, 500, 500000, 500, 500, 500}};
  int array_task5[5][5] = {{453453, 886780, 145672, 345100, 270200},
                           {976534, 765867, 346889, 358923, 358656},
                           {75758, 9460, 157781, 34333, 43454},
                           {56655, 66776, 1790166, 8788, 57688},
                           {10, 20, 30, 40, 50}};

  //! expect ----------------------------------
  string expect =
      "----Input----\n"
      "LF1: 596 1000 1000 1000 534 486 264 338 326 1000 942 220 1000 1000 384 "
      "555 468 \n"
      "LF2: 1000 134 972 1000 1000 1000 368 278 626 244 1000 112 754 1000 1000 "
      "1000 758 \n"
      "EXP1: 234\n"
      "EXP2: 144\n"
      "T1: 840\n"
      "T2: 857\n"
      "E: 16\n\n"

      "----Check Task 1----\n"
      "gatherForces: 420016\n\n"
      "----Check Task 2----\n"
      "String code: 34Gia Lai47\n"
      "determineRightTarget: Duc Lap\n\n"
      "String Code: Unhg Ft Manhm\n"
      "decodeTarget: INVALID\n\n"

      "----Check Task 3----\n"
      "After manageLogistics: \n"
      "T1: 1640\n"
      "T2: 1657\n\n"

      "----Check Task 4----\n"
      "planAttack: -1790166\n\n"
      "----Check Task 5----\n"
      "resupply: 1790266\n\n"
      "Viet Nam Doc Lap\n";

  //! output ----------------------------------
  if (!readFile(input_file, LF1, LF2, EXP1, EXP2, T1, T2, E)) {
    return printResult("file fail", expect, name);
  }
  stringstream output;
  output << "----Input----" << endl;
  output << "LF1: ";
  for (int i = 0; i < 17; i++) {
    output << LF1[i] << " ";
  }
  output << "" << endl;

  output << "LF2: ";
  for (int i = 0; i < 17; i++) {
    output << LF2[i] << " ";
  }
  output << "" << endl;

  output << "EXP1: " << EXP1 << "" << endl;
  output << "EXP2: " << EXP2 << "" << endl;
  output << "T1: " << T1 << "" << endl;
  output << "T2: " << T2 << "" << endl;
  output << "E: " << E << "" << endl << endl;

  output << "----Check Task 1----" << endl;
  int result = gatherForces(LF1, LF2);
  output << "gatherForces: " << result << "" << endl << endl;

  output << "----Check Task 2----" << endl;
  output << "String code: " << code2_1 << "" << endl;
  string result2_1 = determineRightTarget(code2_1);
  output << "determineRightTarget: " << result2_1 << "" << endl << endl;

  output << "String Code: " << code2_2 << "" << endl;
  string result2_2 = decodeTarget(code2_2, EXP1, EXP2);
  output << "decodeTarget: " << result2_2 << "" << endl << endl;

  output << "----Check Task 3----" << endl;
  const int force_weights[17] = {1,  2,  3,  4,  5,  7,  8,  9, 10,
                                 12, 15, 18, 20, 30, 40, 50, 70};

  int SumLF1 = 0;
  int SumLF2 = 0;
  for (int i = 0; i < 17; i++) {
    SumLF1 += LF1[i] * force_weights[i];
    SumLF2 += LF2[i] * force_weights[i];
  }

  manageLogistics(SumLF1, SumLF2, EXP1, EXP2, T1, T2, E);
  output << "After manageLogistics: " << endl;
  output << "T1: " << T1 << "" << endl;
  output << "T2: " << T2 << "" << endl << endl;

  output << "----Check Task 4----" << endl;
  int plan = planAttack(SumLF1, SumLF2, EXP1, EXP2, T1, T2, array_task4);
  output << "planAttack: " << plan << "" << endl << endl;

  output << "----Check Task 5----" << endl;
  if (plan >= 0) {
    output << "Chien thang" << endl;
    output << "Viet Nam Doc Lap" << endl;
  } else {
    int supply = resupply(abs(plan), array_task5);
    output << "resupply: " << supply << "" << endl << endl;
    output << "Viet Nam Doc Lap" << endl;
  }
  //! remove data -----------------------------

  //! result ----------------------------------
  return printResult(output.str(), expect, name);
}