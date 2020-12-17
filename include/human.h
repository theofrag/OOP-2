#include<iostream>
#include <string>

using namespace std;


//base class, ειναι abstract class, αναπαριστα μια αφηρημενη οντοτητα ανθρωπου
//Καθε ανθρωπος χαρακτηριζεται απο το ονομα του και την κουραση του
class Human{        

protected:
    string name;    //το ονομα του ανθρωπου
    int fatigue;    // Ακεραιος που μετραει την κουραση καθε ανθρωπου
    int Lfatigue;   //η κουραση αυξανεται κατα Lfatigue οσο περναει η ωρα.
public:
    Human(string name, int L): name(name), fatigue(0), Lfatigue(L) {}
    string get_name(){return this->name;}
    virtual void print() const=0;
    virtual ~Human(){ return;}
};


//υποκλαση του human, ABSTRACT και αυτη.
//Υποδηλωνει εναν ανθρωπο που εργάζεται ή ειναι μαθητης σε σχολειο.
//Για αυτο και χαρακτηρίζεται απο την τάξη του και μια ενδειξη για το αν είναι μέσα.
class Academic: public Human{ 

protected:
    int floorId, classId;   //αριθμος οροφου, αριθμος αιθουσας
    bool inClassroom;   //αν ειναι στην ταξη του == true
public:
    Academic(string name,int floorId,int classId,int L):Human(name,L),floorId(floorId),classId(classId), inClassroom(false) {}
    void set_inClass(bool b){ //Αν b=true ==> μεσα στην ταξη.
        this->inClassroom=b; 
    }

    int get_floor_id(){
        return this->floorId;
    }

    int get_class_id(){
        return this->classId;
    }
    
    virtual ~Academic(){
        return;
    }

};

//Abstract class και αυτη, δηλώνει έναν μαθητή. Ομως κάθε μαθητής χωρίζεται σε 
//senior ή junior.
class Student: public Academic {   

public:
    Student(string name,int floorId,int classId,int L) : Academic(name,floorId,classId,L) {
        cout<<"A new Student has been created! "<<endl;
    };

    void print() const{
        cout<<"Student's name is: "<<this->name
        <<" and students fatigue is: "<<this->fatigue<<endl;
    }

    virtual void attend(int hours)=0;   //pure virtual
    virtual ~Student(){
        cout<<"A Student to be destroyed!"<<endl;
    }     
};


class Junior: public Student {  //Subclass of student

public:
    Junior(string name,int floorId,int classId,int Lj=1):Student(name,floorId,classId,Lj){};
    void attend(int);
    ~Junior(){ cout<<"A JStudent to be destroyed!"<<endl; }
};


class Senior: public Student {  //Subclass of student

public:
    Senior(string name,int floorId,int classId,int Ls=1):Student(name,floorId,classId,Ls){};
    void attend(int);
    ~Senior(){ cout<<"A S-Student to be destroyed!"<<endl; }
};


class Teacher: public Academic {

public:
    Teacher(string name,int floorId,int classId,int Lt=1):Academic(name,floorId,classId,Lt){
        cout<<"A New Teacher has been created!"<<endl;
    }

    void print() const {
        cout<<"Teacher's name is: "<<this->name<<" and teacher's fatigue is: "<<this->fatigue<<endl;    
    }

    void teach(int hours);

    ~Teacher(){
        cout<<"A Teacher to be destroyed!"<<endl;
    }

};
