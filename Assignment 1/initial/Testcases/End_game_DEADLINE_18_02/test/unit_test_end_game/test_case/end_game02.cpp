#include "../unit_test_end_game.hpp"

bool UNIT_TEST_end_game::end_game02() {
  string name = "end_game02";
  //! data ------------------------------------
  string input_file("test/unit_test_end_game/test_case/input/input2");
  int LF1[17] = {0}, LF2[17] = {0}, EXP1 = 0, EXP2 = 0, T1 = 0, T2 = 0, E = 0;
  string code2_1 = "Pleiku7A6";
  string code2_2 = "touhT aM nouB";
  int array_task4[10][10] = {
      {100, 100, 100, 100, 100, 100, 100, 100, 100, 100},
      {100, 100, 1000, 100, 100, 100, 100, 100, 100, 100},
      {14, 21, 280, 35, 452, 49, 56, 63, 70, 77},
      {162, 240, 323, 404, 484, 60, 40, 72, 80, 88},
      {181, 270, 36, 52, 543, 63, 72, 81, 90, 99},
      {5, 300, 40, 501, 602, 70, 80, 90, 100, 110},
      {1000, 100, 1000, 1000, 100, 100, 100, 1000, 1000, 100},
      {1000, 100, 1000, 1000, 100, 100, 100, 1000, 1000, 100},
      {264, 39, 525, 65, 78, 91, 104, 700, 130, 143},
      {28, 42, 56, 50, 84, 98, 125, 1206, 140, 154}};
  int array_task5[5][5] = {{10, 20, 30, 40, 50},
                           {60, 70, 80, 90, 10},
                           {110, 102, 103, 104, 105},
                           {160, 107, 108, 109, 020},
                           {210, 220, 230, 204, 205}};

  //! expect ----------------------------------
  string expect =
      "----Input----\n"
      "LF1: 1000 1000 1000 251 219 193 402 1000 22 0 0 0 0 0 0 0 0 \n"
      "LF2: 1 2 3 4 5 10 20 30 40 50 0 0 0 0 0 0 0 \n"
      "EXP1: 0\n"
      "EXP2: 600\n"
      "T1: 105\n"
      "T2: 0\n"
      "E: 54\n\n"

      "----Check Task 1----\n"
      "gatherForces: 23441\n\n"
      "----Check Task 2----\n"
      "String code: Pleiku7A6\n"
      "determineRightTarget: National Route 21\n\n"
      "String Code: touhT aM nouB\n"
      "decodeTarget: Buon Ma Thuot\n\n"

      "----Check Task 3----\n"
      "After manageLogistics: \n"
      "T1: 134\n"
      "T2: 0\n\n"

      "----Check Task 4----\n"
      "planAttack: -637\n\n"
      "----Check Task 5----\n"
      "resupply: 637\n\n"
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
  cout << "SumLF1: " << SumLF1 << endl;
  cout << "SumLF2: " << SumLF2 << endl;
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