#include "space.h"


void Schoolyard::enter(Student& s){

    this->students.push_front(&s);
    cout<<s.get_name()<<" enter schoolyard!"<<endl;
}

Student& Schoolyard :: exit(){
    Student* temp = this->students.front();
    cout<<temp->get_name()<<" exits schoolyard!"<<endl;
    this->students.pop_front();
    return *temp;
}


void Stairs::enter(Student& s){

    this->students.push_front(&s);
    cout<<s.get_name()<<" enter Stairs!"<<endl;
}



Student& Stairs :: exit(){
    Student* temp = this->students.front();
    cout<<temp->get_name()<<" exits Stairs!"<<endl;
    this->students.pop_front();
    return *temp;
}



void Corridor::enter(Student& s){

    this->students.push_front(&s);
    cout<<s.get_name()<<" enter Corridor!"<<endl;
}

Student& Corridor :: exit(){
    Student* temp = this->students.front();
    cout<<temp->get_name()<<" exits Corridor!"<<endl;
    this->students.pop_front();
    return *temp;

}



void School::enter(Student& s){
    
    cout<<s.get_name()<<" enter School!"<<endl;
    this->schoolyard.enter(s);
    this->stairs.enter(this->schoolyard.exit());
    Student& temp=this->stairs.exit();
    this->floors[temp.get_floor_id()]->enter(temp);
    
}
void School::place(Teacher& t){

    this->floors[t.get_floor_id()]->place(t);
}


void Floor::enter(Student& s){

    cout<<s.get_name()<<" enter Floor!"<<endl;
    this->corridor.enter(s);
    Student& temp=this->corridor.exit();
    this->classrooms[temp.get_class_id()]->enter(temp);
}

void Floor::place(Teacher& t){
    this->classrooms[t.get_class_id()]->place(t);
}


void Classroom::enter(Student& s){

    this->students.push_front(&s);
    //prepei na kano to bool tou mathiti true
    cout<<s.get_name()<<" enter Classroom!"<<endl;
}

void Classroom::place(Teacher& t){
    if(this->teacher==NULL)
        this->teacher=& t;

    return;

}

