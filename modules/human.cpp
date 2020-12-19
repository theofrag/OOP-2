#include <human.h>

void Junior::attend(int hours){
    for(int i=0;i<hours;i++)
            this->fatigue = this->fatigue + this->Lj;
}

void Senior::attend(int hours){
    for(int i=0;i<hours;i++)
            this->fatigue = this->fatigue + this->Ls;
}

void Teacher::teach(int hours){
    for(int i=0;i<hours;i++)
        this->fatigue = this->fatigue + this->Lt; 
}