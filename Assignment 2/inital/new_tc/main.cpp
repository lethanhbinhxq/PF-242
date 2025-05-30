#include "hcmcampaign.h"
using namespace std;

void tc3() {
    cout << "----- Triet's test 3 -----" << endl;
    HCMCampaign *campaign = new HCMCampaign("tests/my_cf3.txt");
    cout << "** Before the fight" << endl;
    cout << campaign->printResult() << endl;
    cout << "** After the fight" << endl;
    campaign->run();
    cout << campaign->printResult() << endl;
    delete campaign;
}

void tc4() {
    cout << "----- Triet's test 4 -----" << endl;
    HCMCampaign *campaign = new HCMCampaign("tests/my_cf4.txt");
    cout << "** Before the fight" << endl;
    cout << campaign->printResult() << endl;
    cout << "** After the fight" << endl;
    campaign->run();
    cout << campaign->printResult() << endl;
    delete campaign;
}

int main()
{
    tc3();
    tc4();
    return 0;
}