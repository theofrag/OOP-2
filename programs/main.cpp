#include "space.h"
#include <cstdlib>  

int main(int argc, char** argv){
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

 for(int i=0;i<Cclass*N;i++)
    cout<<"&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&::::::::::"<<stud[i]->get_name()<<endl;


    int end=Cclass*N;
    int div=18;
    int temp=0;
    int counter=0;
    int i=0;
    Student* s;

    while(end!=0){

        temp=rand()%(Cclass*N);                 //επιλεγω τυχαιο αριθμο που θα μπουνε στο yar
        

        for(int k=0;k<temp;k++){
            if(counter+Cclass*N==0)             //Αν μπήκαν όλοι οι μαθητες, αυτο θα είναι 0
                break;
            
            i=rand()%(Cclass*N + counter);        //αριθμος μαθητων συνολικος επιλεγω εναν μαθητη
           
                 s=stud[i];
                stud[i]=stud[Cclass*N-1+counter];    //τον βαζω στο τελος για να μην τον ξαναπαρω
                stud[Cclass*N-1+counter]=s;
                counter--;                      //Για κάθε νέο μαθητή που βάζω, το μειώνω
                school.enter(*s);               //βαζω στο yard τον μαθητη αν χωραει
                end--;
        }

        // if(div==0)      //Αν εχουν μπει όλοι οι καθηγητες στην τάξη τους, πρέπει να ελένξουμε και τους μαθητές
        //     continue;

        //     int times=rand()%div;
        //     for(int k=0;k<=times;k++){
        //         i=rand()%div;
        //         school.place(*(teachers[i]));
        //         Teacher* temp= teachers[i];
        //         teachers[i]=teachers[div-1];
        //         teachers[div-1]=temp;
        //         div--; 
        //     }
        
    }
    





    

    return 0;
}