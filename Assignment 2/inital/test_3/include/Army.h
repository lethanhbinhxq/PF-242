#ifndef _H_ARMY_H_
#define _H_ARMY_H_

class BattleField; // Forward declaration

#include "UnitList.h"
#include "BattleField.h"
using namespace std;

//!-----------------------------------------------------
//! CLASS Army 
//!-----------------------------------------------------
/* 
   * Army: 
   *  LF được tính bằng tổng điểm tấn công của các phương tiện.
   *  EXP được tính bằng tổng điểm tấn công của các lực lượng bộ binh.
   *  Capacity của UnitList được tính dựa vào S = LF + EXP.
   *(Các thao tác thêm vào danh sách đơn vị được thực hiện trong Army constructor.)
*/
class Army {
protected:
    int LF;        // * Tổng điểm từ các phương tiện (Vehicle)
    int EXP;       // * Tổng điểm từ các lực lượng bộ binh (Infantry)
    string name;
    BattleField* battleField;
    void normalizeArmyData();
    
public:
    UnitList *unitList;     // * Danh sách đơn vị quân sự
    Army(Unit **unitArray, int size, string name, BattleField *battleField);
    virtual ~Army();
    virtual void fight(Army *enemy, bool defense = false) = 0;
    virtual string str() const = 0;
    int getLF();
    int getEXP();
    UnitList* getUnitList() const;
    void setLF(int LF);
    void setEXP(int EXP);
    void updateScores();
    void removeUnit(vector<Unit*> infantryList = {}, vector<Unit*> vehicleList = {});
    void confiscate(Army* winner, Army* loser);
    bool getBattleFlag();
};

#endif
