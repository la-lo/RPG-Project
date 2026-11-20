#include "Party.h"

bool Party::isPartyAlive(const Party& _party, int count)
{
    for(int i =0;i<count;i++)
    {
        if (_party.party[i].isAlive())return true;
    }
    return false;
}
