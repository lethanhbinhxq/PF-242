#include "TASK2.h"

////////////////////////////////////////////////////////////////////////
/// STUDENT'S ANSWER BEGINS HERE
/// Complete the following functions
/// DO NOT modify any parameters in the functions.
////////////////////////////////////////////////////////////////////////

const int MAX_LINES = 5;
const int MAX_LINE_LENGTH = 100;

// Task 2
const string ACTUAL_TARGET[5] = {"Buon Ma Thuot", "Duc Lap", "Dak Lak", "National Route 21", "National Route 14"};

bool isMatchedTarget(const string &decodedMessage)
{
    for(int i = 0; i < 5; i++)
    {
        if(decodedMessage == ACTUAL_TARGET[i]) return true;
    }

    return false;
}

string toLowerCase(const string &s)
{
    string lowerCaseString = s;

    for(int i = 0; i < lowerCaseString.length(); i++)
    {
        if(lowerCaseString[i] >= 'A' && lowerCaseString[i] <= 'Z')
        {
            lowerCaseString[i] = lowerCaseString[i] + 32;
        }
    }

    return lowerCaseString;
}

string CaesarCipherMethod(const string &message, int shift)
{
    string decodedMessage = "";

    for(int i = 0; i < message.length(); i++)
    {
        char ch = message[i];

        if(ch >= 'A' && ch <= 'Z')
        {
            decodedMessage += char(((ch - 'A' + shift) % 26) + 'A');
        }
        else if(ch >= 'a' && ch <= 'z')
        {
            decodedMessage += char(((ch - 'a' + shift) % 26) + 'a');
        }
        else if(ch == ' ')
        {
            decodedMessage += ch;
        }
        else
        {
            return "INVALID"; // if character is not A-Z, a-z, ' '
        }
    }

    return decodedMessage;
}

string reversedStringMethod(const string &message)
{
    string reversed = message;
    int len = reversed.length();

    for(int i = 0; i < len/2; i++)
    {
        char temp = reversed[i];
        reversed[i] = reversed[len - i - 1];
        reversed[len - i - 1] = temp;
    }

    return reversed;
}

string decodeTarget(const string &message, int EXP1, int EXP2)
{
    // TODO: Implement this function
    if(EXP1 > 600) EXP1 = 600;
    if(EXP1 < 0) EXP1 = 0;

    if(EXP2 > 600) EXP2 = 600;
    if(EXP2 < 0) EXP2 = 0;

    string decodedMessage;

    if(EXP1 >= 300 && EXP2 >= 300)
    {
        int shift = (EXP1 + EXP2) % 26;
        decodedMessage = CaesarCipherMethod(message, shift);
        
        if(isMatchedTarget(decodedMessage) == true) return decodedMessage;
    }
    if(EXP1 < 300 || EXP2 < 300)
    {
        decodedMessage = reversedStringMethod(message);

        for(int i = 0; i < 5; i++)
        {
            if(toLowerCase(decodedMessage) == toLowerCase(ACTUAL_TARGET[i]))
            {
                return ACTUAL_TARGET[i];
            }
        }
    }

    return "INVALID";
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////