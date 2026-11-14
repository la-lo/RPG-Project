#pragma once
#include"Battle.h"
#include "character.h"
#include "enemy.h"
#include  "Party.h"
 void InBAttle(character& player, enemy& _cpu);
 void DisplayHPMP(character player, enemy _cpu);
 void InPBAttle(Party _party, enemy& _cpu);
 void DisplayHPMP(Party _party, enemy _cpu);