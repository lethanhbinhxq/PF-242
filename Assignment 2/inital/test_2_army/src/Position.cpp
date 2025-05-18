#include "Position.h"

//!----------------------------------------------
//! Lớp Position
//!----------------------------------------------
Position::Position(int r, int c) : r(r), c(c) {}
Position::Position(const string &str_pos) {
    stringstream ss(str_pos);
    char ignoreChar;
    int row, column;
    ss >> ignoreChar >> row >> ignoreChar >> column;
    this->r = row;
    this->c = column;
}

int Position::getRow() const {
    return this->r;
}

int Position::getCol() const {
    return this->c;
}

void Position::setRow(int r) {
    this->r = r;
}

void Position::setCol(int c) {
    this->c = c;
}

string Position::str() const {
    string positionStr = "(";
    positionStr += to_string(this->r) + ",";
    positionStr += to_string(this->c) + ")";
    return positionStr;
}

double Position::calculateDistance(Position a, Position b) {
    double dx = pow(a.r - b.r, 2);
    double dy = pow(a.c - b.c, 2);
    return sqrt(dx + dy);
}
