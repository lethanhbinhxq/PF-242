#include "../unit_test_end_game.hpp"

bool UNIT_TEST_end_game::end_game08() {
  string name = "end_game08";
  //! data ------------------------------------
  string input_file("test/unit_test_end_game/test_case/input/input8");
  int LF1[17] = {0}, LF2[17] = {0}, EXP1 = 0, EXP2 = 0, T1 = 0, T2 = 0, E = 0;
  string code2_1 = "78Gia55 L5ai";
  string code2_2 = "Angvbany Ebhgr 14";
  int array_task4[10][10] = {{0, 0, 0, 10, 0, 0, 0, 10, 0, 0},
                             {15, 15, 15, 21, 21, 21, 19, 19, 19, 19},
                             {0, 10, 0, 10, 0, 10, 0, 10, 0, 10},
                             {31, 11, 21, 41, 18, 13, 15, 17, 19, 1},
                             {0, 10, 0, 30, 0, 0, 50, 0, 80, 0},
                             {18, 31, 11, 15, 16, 17, 18, 19, 12, 15},
                             {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                             {31, 41, 51, 61, 71, 18, 19, 10, 11, 12},
                             {23, 24, 0, 0, 0, 0, 29, 100, 0, 0},
                             {1, 1, 0, 0, 1, 1010, 0, 0, 1, 1}};
  int array_task5[5][5] = {{10, 100, 10, 100, 10},
                           {100, 10, 100, 10, 100},
                           {10, 100, 10, 100, 10},
                           {100, 10, 100, 10, 100},
                           {10, 100, 10, 100, 10}};

  //! expect ----------------------------------
  string expect =
      "----Input----\n"
      "LF1: 1000 498 812 637 516 434 413 1000 252 582 1000 1000 1000 530 523 "
      "972 926 \n"
      "LF2: 548 1000 994 1000 337 707 1000 1000 378 1000 1000 381 419 1000 688 "
      "569 729 \n"
      "EXP1: 350\n"
      "EXP2: 380\n"
      "T1: 1234\n"
      "T2: 3000\n"
      "E: 9\n\n"

      "----Check Task 1----\n"
      "gatherForces: 453828\n\n"
      "----Check Task 2----\n"
      "String code: 78Gia55 L5ai\n"
      "determineRightTarget: National Route 21\n\n"
      "String Code: Angvbany Ebhgr 14\n"
      "decodeTarget: INVALID\n\n"

      "----Check Task 3----\n"
      "After manageLogistics: \n"
      "T1: 1123\n"
      "T2: 2865\n\n"

      "----Check Task 4----\n"
      "planAttack: 462353\n\n"
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