//
//  Class_Student.h
//  DB_Of_Students
//
//  Created by Daniil Vilchinskiy on 15.05.2023.
//

#pragma once
#include <string>
using namespace std;

enum class Sex : char { Women, Men, Any };
enum class Mark : char { Fail, Pass, Excllent, Good, Standart, Bad };

struct ExamRecords {
    string name;
    enum class Mark;
    bool isEmpty;
};

struct Student_Data {
    char Name[30];
    char Mid_Name[30];
    char Sur_Name[30];
    char Institute[30];
    char Departament[30];
    char Group[30];
    char Credit_Book[30];
    char Birthday[15];
    enum Sex sex;
    ExamRecords ExamsRecordsData[9][10];
    
};

class Student {
    
private:
    string filename;
    Student_Data st;

public:
    Student() {
        filename = "data.txt";
    }
    
    void SetDefaultData(){
        strcpy(st.Name, "Name");
        strcpy(st.Mid_Name, "Mid_Name");
        strcpy(st.Sur_Name, "Sur_Name");
        strcpy(st.Institute, "Institute");
        strcpy(st.Departament, "Departament");
        strcpy(st.Group, "Group");
        strcpy(st.Credit_Book, "Credit_Book");
        strcpy(st.Birthday, "Birthday");
        st.sex = Sex::Men;
        for( int i = 0; i < 9; i++ )
            for( int j = 0; j < 10; j++ ){
                st.ExamsRecordsData[i][j].isEmpty = true;
            }
    }
    
    void PrintInfo(){
        cout << endl << " Информация о студенте " << endl;
        cout << "ФИО: " << st.Name << " " << st.Mid_Name << " " << st.Sur_Name << endl;
        cout << "" << st.Institute << "" << st.Departament << "" << st.Group << endl;
        cout << "" << st.Credit_Book << "" << st.Birthday << endl;
        cout << "";
        if ( st.sex == Sex::Men ) { cout << ""; }
        if ( st.sex == Sex::Women ) { cout << ""; }
        if ( st.sex == Sex::Any ) { cout << ""; }
        
    }
};
