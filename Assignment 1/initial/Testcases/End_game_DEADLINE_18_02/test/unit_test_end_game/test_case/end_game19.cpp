#include "../unit_test_end_game.hpp"

bool UNIT_TEST_end_game::end_game19() {
  string name = "end_game19";
  //! data ------------------------------------
  string input_file("test/unit_test_end_game/test_case/input/input19");
  int LF1[17] = {0}, LF2[17] = {0}, EXP1 = 0, EXP2 = 0, T1 = 0, T2 = 0, E = 0;
  string code2_1 = "90Pl93ei33ku35";
  string code2_2 = "Fysr Qe Xlysx";
  int array_task4[10][10] = {{1, 2, 3, 4000, 5, 6, 7000, 8, 9, 10},
                             {1, 2000, 3, 4, 5, 6, 7, 8, 9000, 10},
                             {1, 2, 3, 4, 5, 6, 7, 8, 9000, 10},
                             {1, 2, 3, 4000, 5, 6, 7, 8, 9, 10},
                             {1, 2000, 3, 4, 5, 6, 7, 8, 9, 10},
                             {1, 2, 3, 4, 5000, 6, 7, 8, 9, 10},
                             {1, 2, 3, 4, 5, 6, 7, 8, 9, 10},
                             {1, 2000, 3, 4, 5, 6, 7, 8000, 9, 10},
                             {1000, 2, 3, 4, 5, 6, 7000, 8, 9, 10},
                             {1, 2, 3000, 4, 5, 6, 7, 8000, 9, 10}};
  int array_task5[5][5] = {{1, 1, 1, 1, 1},
                           {1, 1, 1, 1, 1},
                           {1000, 1000, 1000, 1000, 1000},
                           {1, 1, 1, 1, 1},
                           {1, 1, 1, 1, 1}};

  //! expect ----------------------------------
  string expect =
      "----Input----\n"
      "LF1: 1000 474 364 1000 645 1000 1000 646 1000 1000 899 546 1000 944 "
      "1000 704 1000 \n"
      "LF2: 972 1000 958 1000 553 1000 854 1000 944 1000 396 959 367 1000 1000 "
      "732 578 \n"
      "EXP1: 301\n"
      "EXP2: 301\n"
      "T1: 1561\n"
      "T2: 1811\n"
      "E: 57\n\n"

      "----Check Task 1----\n"
      "gatherForces: 504397\n\n"
      "----Check Task 2----\n"
      "String code: 90Pl93ei33ku35\n"
      "determineRightTarget: INVALID\n\n"
      "String Code: Fysr Qe Xlysx\n"
      "decodeTarget: Buon Ma Thuot\n\n"

      "----Check Task 3----\n"
      "After manageLogistics: \n"
      "T1: 2006\n"
      "T2: 2018\n\n"

      "----Check Task 4----\n"
      "planAttack: 433441\n\n"
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