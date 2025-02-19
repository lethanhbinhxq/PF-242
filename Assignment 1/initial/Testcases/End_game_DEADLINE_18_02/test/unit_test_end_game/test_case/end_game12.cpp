#include "../unit_test_end_game.hpp"

bool UNIT_TEST_end_game::end_game12() {
  string name = "end_game12";
  //! data ------------------------------------
  string input_file("test/unit_test_end_game/test_case/input/input12");
  int LF1[17] = {0}, LF2[17] = {0}, EXP1 = 0, EXP2 = 0, T1 = 0, T2 = 0, E = 0;
  string code2_1 = "Ple0iku";
  string code2_2 = "Unhg Ft Manhm";
  int array_task4[10][10] = {{0, 1, 2, 3, 4, 5, 6, 7, 8, 9},
                             {10, 11, 12, 13, 14, 15, 16, 17, 18, 19},
                             {20, 21, 22, 23, 24, 25, 26, 27, 28, 29},
                             {30, 31, 32, 33, 34, 35, 36, 37, 38, 39},
                             {40, 41, 42, 43, 44, 45, 46, 47, 48, 49},
                             {50, 51, 52, 53, 54, 55, 56, 57, 58, 59},
                             {60, 61, 62, 63, 64, 65, 66, 67, 68, 69},
                             {70, 71, 72, 73, 74, 75, 76, 77, 78, 79},
                             {80, 81, 82, 83, 84, 85, 86, 87, 88, 89},
                             {90, 91, 92, 93, 94, 95, 96, 97, 98, 99}};
  int array_task5[5][5] = {{1, 2, 3, 4, 5},
                           {1, 2, 3, 4, 5},
                           {1, 2, 3, 4, 5},
                           {1, 2, 3, 4, 5},
                           {1, 2, 3, 4, 5}};

  //! expect ----------------------------------
  string expect =
      "----Input----\n"
      "LF1: 1000 885 1000 1000 1000 522 107 1000 964 579 1000 65 223 258 954 "
      "718 651 \n"
      "LF2: 264 958 677 1000 393 1000 290 575 1000 592 650 924 817 1000 516 "
      "953 1000 \n"
      "EXP1: 354\n"
      "EXP2: 360\n"
      "T1: 3000\n"
      "T2: 508\n"
      "E: 38\n\n"

      "----Check Task 1----\n"
      "gatherForces: 445655\n\n"
      "----Check Task 2----\n"
      "String code: Ple0iku\n"
      "determineRightTarget: DECOY\n\n"
      "String Code: Unhg Ft Manhm\n"
      "decodeTarget: INVALID\n\n"

      "----Check Task 3----\n"
      "After manageLogistics: \n"
      "T1: 3000\n"
      "T2: 547\n\n"

      "----Check Task 4----\n"
      "planAttack: 450749\n\n"
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