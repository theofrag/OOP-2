#include "human.h"
#include <list>

class Space {   //ABSTRACT χώρος.

protected:
    list <Student*> students;

public:

    virtual void enter(Student& )=0;
    virtual ~Space(){
        return;
    };
};


class Classroom: public Space{  //Η classroom αφου αποθηκευει μαθητες είναι ένας χώρος

private:
    int Cclass; //ποσοι μαθητες χωρανε συνολικα
    int floorId;
    int classId;
    Teacher* teacher;       //ενδεχεται καποιος να θελει να βαλει περισσοτερους απο εναν δασκαλους

public:
    Classroom(int C,int floorId,int classId): Cclass(C),floorId(floorId),classId(classId),teacher(NULL){
        cout<<"A new Classroom has been created!"<<endl;
    }

    void enter(Student&);   
    void place(Teacher&);
    void operate(int);
    void print();

    ~Classroom(){
        cout<<"A Classroom to be destroyed!"<<endl;
    }    
};


class Corridor: public Space{   //O corridor αφου αποθηκευει μαθητες είναι ένας χώρος


public:
    Corridor(){
        cout<<"A new Corridor has been constructed"<<endl;
    }
    void enter(Student&);
    Student* exit();
    ~Corridor(){
        cout<<"A Corridor to be destroyed!"<<endl;

    }
};

class Floor {

private:
    Classroom* classrooms[6];
    Corridor corridor;
    int floorId;
    

public:
    Floor(int Cclass,int floorId): floorId(floorId){
        for(int i=0;i<6;i++)
            classrooms[i]= new Classroom(Cclass,floorId,i);
    
    }
    void enter(Student&);
    void place(Teacher&);
    void operate(int hours);
    void print() const ;
    ~Floor(){
        for(int i=0;i<6;i++)
            delete classrooms[i];
        cout<<"A Floor to be destroyed!"<<endl;

    }
};

class Stairs: public Space{

public:
    Stairs(){
        cout<<"A new Stairs has been constructed"<<endl;

    }
    void enter(Student&);
    Student* exit();
};

class Schoolyard: public Space{

public:
    Schoolyard(){
        cout<<"A new Schoolyard has been constructed"<<endl;

    }
    void enter(Student&);
    Student* exit();

};




class School {  

private:
    Schoolyard schoolyard;
    Stairs stairs;
    Floor* floors[3];

public:
    School(int Cclass){
        for(int i=0;i<3;i++)
            floors[i]=new Floor(Cclass,i);
        cout<<"A new School has been constructed"<<endl;
    }
    void enter(Student&);
    void place(Teacher& );
    void operate(int);
    void print() const;
    ~School(){
        for(int i=0;i<3;i++)
            delete floors[i];
        cout<<"A School to be destroyed!"<<endl;
    }
};















