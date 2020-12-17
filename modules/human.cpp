#include <human.h>

void Junior::attend(int hours){
    for(int i=0;i<hours;i++)
            this->fatigue = this->fatigue + this->Lfatigue;
}

void Senior::attend(int hours){
    for(int i=0;i<hours;i++)
            this->fatigue = this->fatigue + this->Lfatigue;
}

void Teacher::teach(int hours){
    for(int i=0;i<hours;i++)
        this->fatigue = this->fatigue + this->Lfatigue; 
}