#include "human.h"


Human::Human(Human& copy){
    this->name=copy.name;
    this->fatigue=copy.fatigue;
    this->Lfatigue=copy.Lfatigue;
}