#include "human.h"
#include <list>

class Space {   //ABSTRACT χώρος.

protected:
    list <Student*> students;
public:

    virtual void enter(Student& )=0;
    virtual Student* exit()=0;
    virtual ~Space(){
        return;
    };
};

class Trasplace{     //μεταβατικος abstract χωρος, ανηκουν εκει το σχολειο και το floor

public:
    virtual void operate(int hours) = 0;  
    virtual void enter(Student& ) = 0;
    virtual void place(Teacher& ) = 0;
    virtual void print() = 0;
    virtual ~Trasplace(){
        return;
    };
};


class Classroom: public Trasplace{

private:
    unsigned int Cclass; //ποσοι μαθητες χωρανε συνολικα
    unsigned int floorId;    //αριθμος οροφου
    unsigned int classId;    //αριθμος ταξης
    Teacher* teacher;   //Δεικτης για να αποθηκευει τον δάσκαλο της τάξης.
    list < Student* > students; //Λιστα που κρατάει τους μαθητές.

public:
    Classroom(int C, int floorId, int classId): 
    Cclass(C),
    floorId(floorId),
    classId(classId),
    teacher(NULL) {
        cout<<"A new Classroom has been created!"<<endl;
    }

    void enter(Student&);   
    void place(Teacher&);
    void operate(int);
    void print() ;
    bool available_space(){
        return ((this->students.size()==this->Cclass)? false : true );    
    }

    ~Classroom(){ cout<<"A Classroom to be destroyed!"<<endl; }    
};


class Corridor: public Space{   //αφου αποθηκευει μαθητες και εχει ΚΑΙ exit ΚΑΙ enter είναι ένας space

public:
    Corridor(){ cout<<"A new Corridor has been constructed"<<endl; }
    void enter(Student&);
    Student* exit();
    ~Corridor(){ cout<<"A Corridor to be destroyed!"<<endl; }
};

class Floor: public Trasplace {

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
    void print()  ;
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


class School: public Trasplace {  

private:
    Schoolyard schoolyard;
    Stairs stairs;
    Floor* floors[3];

public:
    School(int Cclass);
    void enter(Student&);
    void place(Teacher& );
    void operate(int);
    void print() ;
    ~School();
};















