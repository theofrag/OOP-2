#include "space.h"


void Schoolyard::enter(Student& s){

    this->students.push_front(&s);  //προσθεσε τον μαθητη στην λιστα
    cout<<s.get_name()<<" enter schoolyard!"<<endl; 
}

Student* Schoolyard :: exit(){
    Student* temp = this->students.front();
    cout<<temp->get_name()<<" exits schoolyard!"<<endl;
    this->students.pop_front(); //παρε τον μαθητη απο την λιστα
    return temp;
}

//---------------------------------------------------------------------
void Stairs::enter(Student& s){
    this->students.push_front(&s);
    cout<<s.get_name()<<" enter Stairs!"<<endl;
}



Student* Stairs :: exit(){
    Student* temp = this->students.front();
    cout<<temp->get_name()<<" exits Stairs!"<<endl;
    this->students.pop_front();
    return temp;
}


//---------------------------------------------------------------------

void Corridor::enter(Student& s){

    this->students.push_front(&s);
    cout<<s.get_name()<<" enter Corridor!"<<endl;
}

Student* Corridor :: exit(){
    Student* temp = this->students.front();
    cout<<temp->get_name()<<" exits Corridor!"<<endl;
    this->students.pop_front();
    return temp;

}


//---------------------------------------------------------------------


School::School(int Cclass){
    for(int i=0;i<3;i++)
        floors[i]=new Floor(Cclass,i);
    cout<<"A new School has been constructed"<<endl;
}

void School::enter(Student& s){
    
    cout<<s.get_name()<<" enter School!"<<endl;
    this->schoolyard.enter(s);
    this->stairs.enter(*(this->schoolyard.exit()));
    Student* temp=this->stairs.exit();
    this->floors[temp->get_floor_id()]->enter(*temp);
    
}
void School::place(Teacher& t){

    this->floors[t.get_floor_id()]->place(t);
}

void School::operate(int hours){
    for(int i=0;i<3;i++)
            this->floors[i]->operate(hours);
}

void School::print() {
    cout<<"School life consist of: "<<endl;
        for (int i=0;i<3;i++)
            this->floors[i]->print();
}

School::~School(){
    for(int i=0;i<3;i++)
        delete floors[i];
    cout<<"A School to be destroyed!"<<endl;
}

//---------------------------------------------------------------------

void Floor::enter(Student& s){

    cout<<s.get_name()<<" enter Floor!"<<endl;
    this->corridor.enter(s);
    //TODO ελεγχος αν χωραει ο μαθητης
    Student* temp=this->corridor.exit();
    this->classrooms[temp->get_class_id()]->enter(*temp);
}

void Floor::place(Teacher& t){
    this->classrooms[t.get_class_id()]->place(t);
}
void Floor::operate(int hours){
    for(int i=0;i<6;i++)
            this->classrooms[i]->operate(hours);
}

void Floor::print()  {
    cout<<"Floor number "<<this->floorId <<" contains: "<<endl;
        for(int i=0;i<6;i++)
            this->classrooms[i]->print();
}
//---------------------------------------------------------------------

void Classroom::enter(Student& s){

    if(this->students.size()==Cclass){
        cout<<"eeee"<<endl;
    }

    this->students.push_front(&s);
    s.set_inClass(true);
    cout<<s.get_name()<<" enter Classroom!"<<endl;
        
}


void Classroom::place(Teacher& t){
    if(this->teacher==NULL){
        this->teacher=& t;
        t.set_inClass(true);
    }

}

void Classroom::operate(int hours){
    for(list<Student*>::iterator it= this->students.begin();it != this->students.end();++it)
            (*it)->attend(hours);
        if(this->teacher!=NULL)
            teacher->teach(hours);
}

void Classroom::print(){
    cout<<"People in class "<<this->floorId<<"."<<this->classId<<" are: "<<endl;
        for(list<Student*>::iterator it= this->students.begin();it != this->students.end();++it)
            (*it)->print();
        cout<<"The teacher is:  "<<endl;
        if(this->teacher!=NULL)
            teacher->print();
}

//---------------------------------------------------------------------
