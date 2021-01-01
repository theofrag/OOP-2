#include "space.h"
#include <cstdlib>  

int main(int argc, char** argv){
    srand(time(NULL));
    const int N=18;
    int Cclass=atoi(argv[1]); 
    int Lj=atoi(argv[2]); 
    int Ls=atoi(argv[3]); 
    int Lt=atoi(argv[4]); 



    School school(Cclass);

    Teacher* teachers[18];
    Student* stud[N*Cclass];                        //create an array to keep students

    int count=0, count2=0, count1=0;
    for(int i=0;i<Cclass;i++){                      // create students and save them to an array

        for(int j=0;j<3;j++){
            for(int k=0;k<3;k++){
                stud[count]=new Senior("Senior "+ to_string(count1),j,k,Ls);
                count1++;
                count++;

            }
            for(int k=3;k<6;k++){
                stud[count]=new Junior("Junior "+ to_string(count2),j,k,Lj);
                count2++;
                count++;

            }
            
        }
    }
    count=0;
    for(int j=0;j<3;j++){   //φτιαχνω 18 δασκαλους
        for(int k=0;k<6;k++){
            teachers[count]=new Teacher("Teacher "+ to_string(count),j,k,Lt);
            count++;
        }
    }

    int end=Cclass*N;
    int div=18;
    int temp=0;
    int counter=0;
    int i=0;
    Student* s;

    while(1){
        
        temp=rand()%(end+1);                 //επιλεγω τυχαιο αριθμο που θα μπουνε στο yar

        for(int k=0;k<temp;k++){
            if(end==0)             //Αν μπήκαν όλοι οι μαθητες, αυτο θα είναι 0
                break;
            
            i=rand()%end;        //αριθμος μαθητων συνολικος επιλεγω εναν μαθητη
           
                 s=stud[i];
                stud[i]=stud[end-1];    //τον βαζω στο τελος για να μην τον ξαναπαρω
                stud[end-1]=s;
                end--;                      //Για κάθε νέο μαθητή που βάζω, το μειώνω
                school.enter(*s);               //βαζω στο yard τον μαθητη αν χωραει
        }

            int times=rand()%(div+1);
            for(int k=0;k<times;k++){
                if(div==0)
                    break;
                i=rand()%div;
                school.place(*(teachers[i]));
                Teacher* temp= teachers[i];
                teachers[i]=teachers[div-1];
                teachers[div-1]=temp;
                div--; 
            }
        if(end==0 && div==0)
            break;
        
    }
    school.operate(10);
    school.print();

    for(int i=0;i<N*Cclass;i++)
        delete stud[i];

    for(int i=0;i<N;i++){
        if(teachers[i]->get_inClassroom()==false)
            cout<<teachers[i]->get_name()<<endl;
        delete teachers[i];}
    

    return 0;
}