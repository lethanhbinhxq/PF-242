#include "../unit_test_end_game.hpp"

bool UNIT_TEST_end_game::end_game17() {
  string name = "end_game17";
  //! data ------------------------------------
  string input_file("test/unit_test_end_game/test_case/input/input17");
  int LF1[17] = {0}, LF2[17] = {0}, EXP1 = 0, EXP2 = 0, T1 = 0, T2 = 0, E = 0;
  string code2_1 = "P3leiku18";
  string code2_2 = "NaTiOnAl RoUtE 14";
  int array_task4[10][10] = {{2, 3, 5, 7, 11, 13, 17, 10009, 2, 3},
                             {5, 7, 11, 10003, 17, 19, 2, 3, 5, 7},
                             {11, 13, 17, 10009, 2, 3, 5, 7, 11, 13},
                             {17, 19000, 2, 3, 5, 7, 11, 13, 17, 19},
                             {2, 3, 5, 7, 11, 13, 17, 19, 2, 3},
                             {5, 7, 11000, 13, 17, 19, 2, 3, 5, 7},
                             {11, 13, 17, 19, 2, 3, 5, 7, 11, 13},
                             {17, 19, 2, 3, 5, 7, 10001, 13, 17, 19},
                             {2, 3, 5, 7, 11, 13, 17, 19, 2, 3},
                             {5, 7, 10001, 13, 17, 19, 2, 3, 5, 7}};
  int array_task5[5][5] = {{10, 20, 10, 20, 10},
                           {10, 20, 10, 20, 10},
                           {10, 20, 10, 20, 10},
                           {10, 20, 10, 20, 10},
                           {10, 20, 10, 20, 10}};

  //! expect ----------------------------------
  string expect =
      "----Input----\n"
      "LF1: 1000 448 397 671 380 1000 381 375 467 533 976 552 443 630 255 301 "
      "449 \n"
      "LF2: 220 1000 420 409 1000 828 325 1000 623 631 736 389 548 1000 598 "
      "1000 661 \n"
      "EXP1: 596\n"
      "EXP2: 600\n"
      "T1: 2273\n"
      "T2: 3000\n"
      "E: 86\n\n"

      "----Check Task 1----\n"
      "gatherForces: 361682\n\n"
      "----Check Task 2----\n"
      "String code: P3leiku18\n"
      "determineRightTarget: Duc Lap\n\n"
      "String Code: NaTiOnAl RoUtE 14\n"
      "decodeTarget: INVALID\n\n"

      "----Check Task 3----\n"
      "After manageLogistics: \n"
      "T1: 2273\n"
      "T2: 3000\n\n"

      "----Check Task 4----\n"
      "planAttack: 273940\n\n"
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