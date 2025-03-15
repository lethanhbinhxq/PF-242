#include "../unit_test_end_game.hpp"

bool UNIT_TEST_end_game::end_game16() {
  string name = "end_game16";
  //! data ------------------------------------
  string input_file("test/unit_test_end_game/test_case/input/input16");
  int LF1[17] = {0}, LF2[17] = {0}, EXP1 = 0, EXP2 = 0, T1 = 0, T2 = 0, E = 0;
  string code2_1 = "K100on Tum";
  string code2_2 = "12 eTuOR LANOitan";
  int array_task4[10][10] = {
      {1000, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 1000, 0, 0, 0, 0, 0, 0, 0, 0},
      {0, 0, 1000, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 1000, 0, 0, 0, 0, 0, 0},
      {0, 0, 0, 0, 1000, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 1000, 0, 0, 0, 0},
      {0, 0, 0, 0, 0, 0, 1000, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 1000, 0, 0},
      {0, 0, 0, 0, 0, 0, 0, 0, 1000, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 1000}};
  int array_task5[5][5] = {{1, 2, 4, 8, 16},
                           {32, 64, 128, 256, 512},
                           {1, 2, 4, 8, 16},
                           {32, 64, 128, 256, 512},
                           {1, 2, 4, 8, 16}};

  //! expect ----------------------------------
  string expect =
      "----Input----\n"
      "LF1: 416 571 844 926 1000 1000 914 1000 314 624 797 480 807 268 854 "
      "1000 1000 \n"
      "LF2: 1000 1000 525 379 1000 393 964 561 1000 524 599 1000 1000 1000 "
      "1000 562 546 \n"
      "EXP1: 0\n"
      "EXP2: 600\n"
      "T1: 2266\n"
      "T2: 1560\n"
      "E: 65\n\n"

      "----Check Task 1----\n"
      "gatherForces: 471865\n\n"
      "----Check Task 2----\n"
      "String code: K100on Tum\n"
      "determineRightTarget: INVALID\n\n"
      "String Code: 12 eTuOR LANOitan\n"
      "decodeTarget: National Route 21\n\n"

      "----Check Task 3----\n"
      "After manageLogistics: \n"
      "T1: 2266\n"
      "T2: 1560\n\n"

      "----Check Task 4----\n"
      "planAttack: 471684\n\n"
      "----Check Task 5----\n"
      "Chien thang\n"
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