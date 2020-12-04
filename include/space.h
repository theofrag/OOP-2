#include "human.h"
#include <list>

class Space {

protected:
    list <Student*> students;

public:

    virtual void enter(Student& )=0;

};


class Classroom: public Space{

private:
    int Cclass; //ποσοι μαθητες χωρανε συνολικα
    int capacity; //ποσοι μαθητες εχουν μπει μεχρι τωρα
    Teacher* teacher;

public:
    Classroom(int C): Cclass(C), capacity(0){ cout<<"A new Classroom has been created!"<<endl;}
    void enter(Student&);
    void place(Teacher&);
    void operate(int hours){
        //attend τους μαθητες
    }
    
};

class Corridor: public Space{


public:
    Corridor(){
        cout<<"A new Corridor has been constructed"<<endl;
    }
    void enter(Student&);
    
    Student& exit();

};

class Floor: public Space{

private:
    Classroom* classrooms[6];
    Corridor corridor;

public:
    Floor(int Cclass){
        for(int i=0;i<6;i++)
            classrooms[i]= new Classroom(Cclass);
    
    }
    void enter(Student&);
    void place(Teacher&);
    void operate(int hours){
        for(int i=0;i<6;i++)
            this->classrooms[i]->operate(hours);
    }

};

class Stairs: public Space{

public:
    Stairs(){
        cout<<"A new Stairs has been constructed"<<endl;

    }
    void enter(Student&);
    Student& exit();
};

class Schoolyard: public Space{

public:
    Schoolyard(){
        cout<<"A new Schoolyard has been constructed"<<endl;

    }
    void enter(Student&);
    Student& exit();

};

class School: public Space {

private:
    Schoolyard schoolyard;
    Stairs stairs;
    Floor* floors[3];

public:
    School(int Cclass){
        for(int i=0;i<3;i++)
            floors[i]=new Floor(Cclass);
        
        cout<<"A new School has been constructed"<<endl;

    }
    void enter(Student&);
    void place(Teacher& );
    void operate(int hours){
        for(int i=0;i<3;i++)
            this->floors[i]->operate(hours);
    }

};















