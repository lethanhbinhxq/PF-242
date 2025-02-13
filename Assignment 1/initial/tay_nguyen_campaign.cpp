#include "tay_nguyen_campaign.h"

////////////////////////////////////////////////////////////////////////
/// STUDENT'S ANSWER BEGINS HERE
/// Complete the following functions
/// DO NOT modify any parameters in the functions.
////////////////////////////////////////////////////////////////////////

const int MAX_LINES = 5;
const int MAX_LINE_LENGTH = 100;

// Task 0: Read input file
void convertArray(int arr[], stringstream &ss)
{
  char split;
  int number;
  ss >> split;
  int index = 0;
  while (ss >> number)
  {
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
  int numSoldiers = 17;
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
    }
    else if (i == 3)
    {
      ss >> T1 >> T2;
    }
    else
    {
      ss >> E;
    }
  }

  return true;
}

// Task 1
int gatherForces(int LF1[], int LF2[])
{
  // TODO: Implement this function
  int force = 0;
  int numSoldiers = 17;
  int weight[numSoldiers] = {1, 2, 3, 4, 5, 7, 8, 9, 10, 12, 15, 18, 20, 30, 40, 50, 70};
  for (int i = 0; i < numSoldiers; i++)
  {
    force += (LF1[i] + LF2[i]) * weight[i];
  }
  return force;
}

// Task 2
string determineRightTarget(const string &target)
{
  // TODO: Implement this function
  int numbers[3];
  int maxNum = 3;
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
    else if (!numString.empty())
    {
      if (numCount < maxNum)
      {
        numbers[numCount] = stoi(numString);
        numString.clear();
      }
      numCount++;
    }
  }
  
  if (!numString.empty())
  {
    if (numCount < maxNum) {
      numbers[numCount] = stoi(numString);
    }
    numCount++;
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

  if (id == 3)
  {
    return "Buon Ma Thuot";
  }
  if (id == 4)
  {
    return "Duc Lap";
  }
  if (id == 5)
  {
    return "Dak Lak";
  }
  if (id == 6)
  {
    return "National Route 21";
  }
  if (id == 7)
  {
    return "National Route 14";
  }
  return "INVALID";
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
    if (tolower(l1[i]) != tolower(l2[i]))
    {
      return false;
    }
  }
  return true;
}

string decodeTarget(const string &message, int EXP1, int EXP2)
{
  // TODO: Implement this function
  string target = "";
  string location[] = {"Buon Ma Thuot", "Duc Lap", "Dak Lak", "National Route 21", "National Route 14"};

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
        c = (c - begin - shift + 26) % 26 + begin;
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

  for (int i = 0; i < 5; i++)
  {
    if (compareLocation(target, location[i]))
    {
      return location[i];
    }
  }
  return "INVALID";
}

// Task 3
void manageLogistics(int LF1, int LF2, int EXP1, int EXP2, int &T1, int &T2, int E)
{
  // TODO: Implement this function
  const int minT = 0;
  const int maxT = 3000;

  if (E == 0)
  {
    int delta_T1 = (LF1 / (LF1 + LF2) * (T1 + T2)) * (1 + (EXP1 - EXP2));
    int delta_T2 = (T1 + T2) - delta_T1;

    T1 += delta_T1;
    T2 += delta_T2;
  }
  else if (E >= 1 && E <= 9)
  {
    T1 -= T1 * E / 100;
    T2 -= T2 * E * 0.5 / 100;
  }
  else if (E >= 10 && E <= 29)
  {
    T1 += E * 50;
    T2 += E * 50;
  }
  else if (E >= 30 && E <= 59)
  {
    T1 += T1 * E * 0.5 / 100;
    T2 += T2 * E * 0.2 / 100;
  }

  T1 = round(T1);
  if (T1 < minT)
    T1 = minT;
  else if (T1 > maxT)
    T1 = maxT;

  T2 = round(T2);
  if (T2 < minT)
    T2 = minT;
  else if (T2 > maxT)
    T2 = maxT;
}

// Task 4
int planAttack(int LF1, int LF2, int EXP1, int EXP2, int T1, int T2, int battleField[10][10])
{
  // TODO: Implement this function
  double S = (LF1 + LF2) + (EXP1 + EXP2) * 5 + (T1 + T2) * 2;
  int sumOdd = 0;
  int sumEven = 0;

  // for (int i = 0; i < 10; i++) {
  //   for (int j = 0; j < 10; j++) {
  //     if (i % 2 == 0) {
  //       S = S - battleField[i][j] * 2 / 3;
  //     }
  //     else {
  //       S = S - battleField[i][j] * 3 / 2;
  //     }
  //   }
  // }

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

  return round(S);
}

// Task 5
int resupply(int shortfall, int supply[5][5])
{
  // TODO: Implement this function
  int totalSupply = shortfall;
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

            if (sum >= totalSupply) {
              totalSupply = min(totalSupply, sum);
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
