#ifndef _H_ARVN_H_
#define _H_ARVN_H_

#include "Army.h"

class ARVN : public Army {
public:
    ARVN(Unit **unitArray, int size, string name);
    void fight(Army* enemy, bool defense = false);
    string str() const;
};

#endif