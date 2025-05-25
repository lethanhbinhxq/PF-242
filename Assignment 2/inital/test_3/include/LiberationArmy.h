#ifndef _H_LIBERATIONARMY_H_
#define _H_LIBERATIONARMY_H_

#include "Army.h"

class LiberationArmy : public Army {
public:
    LiberationArmy(Unit **unitArray, int size, string name);
    void fight(Army* enemy, bool defense = false);
    bool getBattleFlag();
    string str() const;
private:
    vector<Unit*> findMinCombination(vector<Unit*>& units, int targetValue);
};

#endif