#include <iostream>
#include <cstring>

enum grades{ // za6to ne moje enum class
    DVE = 2,
    TRI,
    CHETRI,
    PET,
    shes
};

struct Grade{
    std::string predmet = "";
    double grade;
    Grade();
    Grade(std::string p, grades g);
};

Grade::Grade(){
}
Grade::Grade(std::string p, grades g){
    predmet = p;
    grade = g;
}


struct StudentskaKnijkaNaStudentSPishka{
    std::string name;
    std::string FN;
    int grades_count;
    Grade* ocenki = new Grade[grades_count];
    void addOcenkaToKnijka(Grade grade);
    StudentskaKnijkaNaStudentSPishka(std::string n, std::string fn, int gc);
    ~StudentskaKnijkaNaStudentSPishka();
    
};

void StudentskaKnijkaNaStudentSPishka :: addOcenkaToKnijka(Grade grade)
{

    for(int i =0;i<grades_count;i++){
        if(ocenki[i].predmet == "" || ocenki[i].predmet == grade.predmet)
        {
            ocenki[i].grade = grade.grade;
            break;    
        }
    }
}
StudentskaKnijkaNaStudentSPishka :: StudentskaKnijkaNaStudentSPishka(std::string n, std::string fn, int gc){
    name = n;
    FN=fn;
    grades_count=gc;
}
StudentskaKnijkaNaStudentSPishka :: ~StudentskaKnijkaNaStudentSPishka(){
    delete [] ocenki;
}

// int gradesToNumbers(grades grade){
//     switch (grade)
//     {
//     case DVE: return 2;
//     case TRI: return 3;
//     case CHETRI: return 4;
//     case PET: return 5;
//     case shes: return 6;
//     }
// }


int main()
{
    StudentskaKnijkaNaStudentSPishka* student1 = new StudentskaKnijkaNaStudentSPishka("Aleks","523525",3);
    Grade* grade1 = new Grade();
    grade1->predmet = "BEL";
    grade1->grade = 6.0;
    student1->addOcenkaToKnijka(*grade1);

    return 0;
}