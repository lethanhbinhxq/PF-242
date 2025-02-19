#include "tay_nguyen_campaign.h"

////////////////////////////////////////////////////////////////////////
/// STUDENT'S ANSWER BEGINS HERE
/// Complete the following functions
/// DO NOT modify any parameters in the functions.
////////////////////////////////////////////////////////////////////////

const int MAX_LINES = 5;
const int MAX_LINE_LENGTH = 100;

const int MIN_VALUE = 0;
const int MAX_LF = 1000;
const int MAX_EXP = 600;
const int MAX_T = 3000;
const int MAX_E = 99;

const int FLAG_NORM_LF = 0;
const int FLAG_NORM_EXP = 1;
const int FLAG_NORM_T = 2;
const int FLAG_NORM_E = 3;
const int FLAG_NORM = 4;

const int NUM_SOLDIERS = 17;

const int MAX_ENCODED_NUMBERS = 3;
const int MAX_ENCODED_VALUE = 100;

const string INVALID = "INVALID";
const string CAPTURED_TARGET[] = {
  "DECOY",
  "DECOY",
  "DECOY",
  "Buon Ma Thuot",
  "Duc Lap",
  "Dak Lak",
  "National Route 21",
  "National Route 14"
};

const int MAX_TARGET_ID = 7;
const int START_TARGET_ID = 3;

void normalizeData(int &data, int flagNorm = FLAG_NORM) {
  data = max(MIN_VALUE, data);
  if (flagNorm == FLAG_NORM_LF) {
    data = min(MAX_LF, data);
  }
  else if (flagNorm == FLAG_NORM_EXP) {
    data = min(MAX_EXP, data);
  }
  else if (flagNorm == FLAG_NORM_T) {
    data = min(MAX_T, data);
  }
  else if (flagNorm == FLAG_NORM_E) {
    data = min(MAX_E, data);
  }
}

// Task 0: Read input file
void convertArray(int arr[], stringstream &ss)
{
  char split;
  int number;
  ss >> split;
  int index = 0;

  while (ss >> number)
  {
    normalizeData(number, FLAG_NORM_LF);
    arr[index] = number;
    index++;
    ss >> split;
  }
}

bool readFile(
    const string &filename,
    int LF1[], int LF2[],
    int &EXP1, int &EXP2,
    int &T1, int &T2, int &E)
{
  char data[MAX_LINES][MAX_LINE_LENGTH];
  int numLines = 0;

  ifstream ifs(filename);
  if (!ifs.is_open())
  {
    return false;
  }

  while (numLines < MAX_LINES && ifs.getline(data[numLines], MAX_LINE_LENGTH))
  {
    numLines++;
  }
  ifs.close();

  if (numLines < MAX_LINES)
  {
    return false;
  }

  // TODO: Extract values from the `data` array and store them in respective variables
  
  for (int i = 0; i < numLines; i++)
  {
    stringstream ss(data[i]);
    if (i == 0)
    {
      convertArray(LF1, ss);
    }
    else if (i == 1)
    {
      convertArray(LF2, ss);
    }
    else if (i == 2)
    {
      ss >> EXP1 >> EXP2;
      normalizeData(EXP1, FLAG_NORM_EXP);
      normalizeData(EXP2, FLAG_NORM_EXP);
    }
    else if (i == 3)
    {
      ss >> T1 >> T2;
      normalizeData(T1, FLAG_NORM_T);
      normalizeData(T2, FLAG_NORM_T);
    }
    else
    {
      ss >> E;
      normalizeData(E, FLAG_NORM_E);
    }
  }

  return true;
}

// Task 1
int gatherForces(int LF1[], int LF2[])
{
  // TODO: Implement this function
  int force = 0;
  int weight[NUM_SOLDIERS] = {1, 2, 3, 4, 5, 7, 8, 9, 10, 12, 15, 18, 20, 30, 40, 50, 70};
  for (int i = 0; i < NUM_SOLDIERS; i++)
  {
    normalizeData(LF1[i], FLAG_NORM_LF);
    normalizeData(LF2[i], FLAG_NORM_LF);
    force += (LF1[i] + LF2[i]) * weight[i];
  }
  return force;
}

// Task 2
bool convertToNumber(string& numString, int& numCount, const int& maxNum, int numbers[]) {
  bool validFlag = true;
  if (!numString.empty()) {
    if (numCount < maxNum) {
      int convertedNumber = stoi(numString);

      if (convertedNumber <= MAX_ENCODED_VALUE) {
        numbers[numCount] = convertedNumber;
      }
      else {
        validFlag = false;
      }
      
      numString.clear();
    }
    numCount++;
  }
  return validFlag;
}

string determineRightTarget(const string &target)
{
  // TODO: Implement this function
  int numbers[MAX_ENCODED_NUMBERS];
  int numCount = 0;
  int id = -1;
  string numString = "";

  for (int i = 0; i < (int)(target.length()); i++)
  {
    char c = target[i];
    if (isdigit(c))
    {
      numString += c;
    }

    else {
      if (!convertToNumber(numString, numCount, MAX_ENCODED_NUMBERS, numbers)) {
        return INVALID;
      }
    }
  }

  if (!convertToNumber(numString, numCount, MAX_ENCODED_NUMBERS, numbers)) {
    return INVALID;
  }

  if (numCount == 1)
  {
    id = numbers[0];
  }
  else if (numCount == 2)
  {
    id = (numbers[0] + numbers[1]) % 5 + 3;
  }
  else if (numCount == 3)
  {
    id = numbers[0];
    if (numbers[1] > id)
    {
      id = numbers[1];
    }
    if (numbers[2] > id)
    {
      id = numbers[2];
    }
    id = id % 5 + 3;
  }

  if (id >= MIN_VALUE && id <= MAX_TARGET_ID) {
    return CAPTURED_TARGET[id];
  }
  return INVALID;
}

bool compareLocation(const string &l1, const string &l2)
{
  int length1 = l1.length();
  int length2 = l2.length();
  if (length1 != length2)
  {
    return false;
  }

  for (int i = 0; i < length1; i++)
  {
    if (isalpha(l1[i]) && isalpha(l2[i])) {
      if (tolower(l1[i]) != tolower(l2[i])) {
        return false;
      }
    }

    else {
      if (l1[i] != l2[i]) {
        return false;
      }
    }
  }
  return true;
}

string decodeTarget(const string &message, int EXP1, int EXP2)
{
  // TODO: Implement this function
  string target = "";

  if (EXP1 >= 300 && EXP2 >= 300)
  {
    // Caesar Cipher
    int shift = (EXP1 + EXP2) % 26;
    for (int i = 0; i < (int)(message.length()); i++)
    {
      char c = message[i];

      if (isalpha(c))
      {
        char begin = islower(c) ? 'a' : 'A';
        c = (c - begin + shift) % 26 + begin;
      }
      
      else if (!isdigit(c) && c != ' ') {
        return INVALID;
      }

      target += c;
    }
  }
  else
  {
    // String Reversal
    for (int i = (int)(message.length()) - 1; i >= 0; i--)
    {
      target += message[i];
    }
  }

  for (int i = START_TARGET_ID; i <= MAX_TARGET_ID; i++)
  {
    if (compareLocation(target, CAPTURED_TARGET[i]))
    {
      return CAPTURED_TARGET[i];
    }
  }
  return INVALID;
}

// Task 3
void manageLogistics(int LF1, int LF2, int EXP1, int EXP2, int &T1, int &T2, int E)
{
  // TODO: Implement this function
  double dT1;
  double dT2;
  normalizeData(LF1, FLAG_NORM);
  normalizeData(LF2, FLAG_NORM);
  normalizeData(EXP1, FLAG_NORM_EXP);
  normalizeData(EXP2, FLAG_NORM_EXP);
  normalizeData(T1, FLAG_NORM_T);
  normalizeData(T2, FLAG_NORM_T);
  normalizeData(E, FLAG_NORM_E);

  if (E == 0)
  {
    double delta_T1 = (LF1 / (double)(LF1 + LF2)) * (double)(T1 + T2) * (1 + (double)(EXP1 - EXP2) / 100);
    double delta_T2 = (T1 + T2) - delta_T1;

    dT1 = T1 + delta_T1;
    dT2 = T2 + delta_T2;
  }
  else if (E >= 1 && E <= 9)
  {
    dT1 = T1 - T1 * E / 100;
    dT2 = T2 - T2 * E * 0.5 / 100;
  }
  else if (E >= 10 && E <= 29)
  {
    dT1 = T1 + E * 50;
    dT2 = T2 + E * 50;
  }
  else if (E >= 30 && E <= 59)
  {
    dT1 = T1 + T1 * E * 0.5 / 100;
    dT2 = T2 + T2 * E * 0.2 / 100;
  }
  else {
    dT1 = T1;
    dT2 = T2;
  }

  T1 = ceil(dT1);
  T2 = ceil(dT2);
  
  normalizeData(T1, FLAG_NORM_T);
  normalizeData(T2, FLAG_NORM_T);
}

// Task 4
int planAttack(int LF1, int LF2, int EXP1, int EXP2, int T1, int T2, int battleField[10][10])
{
  // TODO: Implement this function
  normalizeData(LF1, FLAG_NORM);
  normalizeData(LF2, FLAG_NORM);
  normalizeData(EXP1, FLAG_NORM_EXP);
  normalizeData(EXP2, FLAG_NORM_EXP);
  normalizeData(T1, FLAG_NORM_T);
  normalizeData(T2, FLAG_NORM_T);

  double S = (LF1 + LF2) + (EXP1 + EXP2) * 5 + (T1 + T2) * 2;
  double sumOdd = 0;
  double sumEven = 0;

  for (int i = 0; i < 10; i += 2) {
    for (int j = 0; j < 10; j++) {
      sumEven += battleField[i][j];
    }
  }

  for (int i = 1; i < 10; i += 2) {
    for (int j = 0; j < 10; j++) {
      sumOdd += battleField[i][j];
    }
  }

  S = S - (sumOdd * 3 / 2) - (sumEven * 2 / 3);
  return ceil(S);
}

// Task 5
int resupply(int shortfall, int supply[5][5])
{
  // TODO: Implement this function
  int totalSupply = -1;
  const int size = 25;
  int fSupply[size];
  int index = 0;
  
  for (int i = 0; i < 5; i++)
  {
    for (int j = 0; j < 5; j++)
    {
      fSupply[index] = supply[i][j];
      index++;
    }
  }

  for (int x1 = 0; x1 < size - 4; x1++) {
    for (int x2 = x1 + 1; x2 < size - 3; x2++) {
      for (int x3 = x2 + 1; x3 < size - 2; x3++) {
        for (int x4 = x3 + 1; x4 < size - 1; x4++) {
          for (int x5 = x4 + 1; x5 < size; x5++) {

            int sum = fSupply[x1] + fSupply[x2] + fSupply[x3] + fSupply[x4] + fSupply[x5];

            if (sum >= shortfall) {
              if (totalSupply == -1) {
                totalSupply = sum;
              }
              else totalSupply = min(totalSupply, sum);
            }
          }
        }
      }
    }
  }

  return totalSupply;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////
