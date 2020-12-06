#include<iostream>
#include <string>

using namespace std;

class Human{        //base class, ειναι abstract class

protected:
    string name;    //το ονομα του ανθρωπου
    int fatigue;    // Ακεραιος που μετραει την κουραση καθε ανθρωπου
    int Lfatigue;   //Καθε ανθρωπος χαρακτηριζεται απο εναν βαθμο κουρασης

public:
    Human(string name, int L): name(name), fatigue(0), Lfatigue(L) {}
    string get_name(){return this->name;}
    virtual void print()=0;

};

class Academic: public Human{   //εξειδικευση το human

protected:
    int floorId, classId;   //αριθμος οροφου, αριθμος αιθουσας
    bool inClassroom;   //αν ο μαθητης ειναι στην ταξη του == true
public:
    Academic(string name,int floorId,int classId,int L):Human(name,L),floorId(floorId),classId(classId), inClassroom(false) {}

};

class Student: public Academic {   //Abstract class και αυτη

public:
    Student(string name,int floorId,int classId,int L):Academic(name,floorId,classId,L) {
        cout<<"A new Student has been created! "<<endl;
    };
    void print(){cout<<"Student's name is: "<<this->name<<" and students fatigue is: "<<this->fatigue<<endl;}
    virtual void attend(int hours)=0;
    int get_floor_id(){return this->floorId;}
    int get_class_id(){return this->classId;}

};


class Junior: public Student {  //Subclass of student

public:
    Junior(string name,int floorId,int classId,int Lj):Student(name,floorId,classId,Lj){};
    void attend(int hours){
        for(int i=0;i<hours;i++)
            this->fatigue = this->fatigue + this->Lfatigue;
    }

};


class Senior: public Student {  //Subclass of student

public:
    Senior(string name,int floorId,int classId,int Ls):Student(name,floorId,classId,Ls){};
    void attend(int hours){
        for(int i=0;i<hours;i++)
            this->fatigue = this->fatigue + this->Lfatigue; 
    }

};

class Teacher: public Academic {

public:
    Teacher(string name,int floorId,int classId,int Lt):Academic(name,floorId,classId,Lt){
        cout<<this->name<<endl;
    }
    void attend(){this->fatigue = this->fatigue + this->fatigue; }
    int get_floor_id(){return this->floorId;}
    int get_class_id(){return this->classId;}
    void print(){cout<<"Teacher's name is: "<<this->name<<" and teacher's fatigue is: "<<this->fatigue<<endl;}
    void attend(int hours){
        for(int i=0;i<hours;i++)
            this->fatigue = this->fatigue + this->Lfatigue; 
    }

};
