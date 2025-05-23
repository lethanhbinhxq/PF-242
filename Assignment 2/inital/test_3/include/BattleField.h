#ifndef _H_BATTLEFIELD_H_
#define _H_BATTLEFIELD_H_

#include "main.h"
#include "Position.h"
#include "Army.h"
class TerrainElement; // Forward declaration
#include "TerrainElement.h"

//!-----------------------------------------------------
//! CLASS BattleField
//!-----------------------------------------------------
class BattleField
{
private:
    int n_rows, n_cols;
    // TODO
    vector<TerrainElement*>* terrain;
    void setTerrain(vector<Position *> posList = vector<Position*>(), TerrainType type = ROAD);
public:
    BattleField(int n_rows, int n_cols, vector<Position *> arrayForest,
                vector<Position *> arrayRiver, vector<Position *> arrayFortification,
                vector<Position *> arrayUrban, vector<Position *> arraySpecialZone);
    ~BattleField();
    string str();
};

#endif