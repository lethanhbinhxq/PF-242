#include "Position.h"

Position::Position(int r, int c) : r(r), c(c)
{
    // TODO: implement
}

Position::Position(const string &str_pos)
{
    // TODO: implement
    stringstream ss(str_pos);
    char ignoreChar;
    int row, column;
    ss >> ignoreChar >> row >> ignoreChar >> column;
    this->r = row;
    this->c = column;
}

int Position::getRow() const { return r; }

int Position::getCol() const { return c; }

void Position::setRow(int r)
{ // TODO: implement
    this->r = r;
}

void Position::setCol(int c)
{
    // TODO: implement
    this->c = c;
}

string Position::str() const
{
    // TODO: implement
    string positionStr = "(";
    positionStr += to_string(this->r) + ",";
    positionStr += to_string(this->c) + ")";
    return positionStr;
}