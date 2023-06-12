//
//  Class_Student.h
//  DB_Of_Students
//
//  Created by Daniil Vilchinskiy on 15.05.2023.
//

#pragma once
#include <string>
#include <iostream>
#include <fstream>

#include "Class_Edit_Data.h"
#include "Class_Menu.h"

using namespace std;



struct ExamRecords {
    string name;
    string mark;
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
    char Sex[10];
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
        strcpy(st.Sex, "Men");
        for( int i = 0; i < 9; i++ )
            for( int j = 0; j < 10; j++ ){
                st.ExamsRecordsData[i][j].name = "Предмет";
                st.ExamsRecordsData[i][j].mark = "Оценка";
            }
    }
    
    void PrintData(Student_Data data){
        cout << endl << " Информация о студенте " << endl;
        cout << "ФИО: " << data.Sur_Name << " " << data.Name << " " << data.Mid_Name << endl;
        cout << "Учится в " << data.Institute << " институт " << data.Departament << " группа " << data.Group << endl;
        cout << "Номер зачетной книжки: " << data.Credit_Book << ". Дата рождения: " <<
            data.Birthday << endl;
        cout << "Пол: " << data.Sex << endl;
        cout << "Оценки: " << endl;
        for (int i = 0; i < 9; i++) {
            cout << "\nСеместр: " << i+1 << endl;
            for (int j = 0; j < 10; j++) {
                cout << data.ExamsRecordsData[i][j].name << " - " << data.ExamsRecordsData[i][j].mark << ";";
            }
        }
        cout << endl;
    }
    
    void deleteStudent(){
        Student_Data ReadStudents[10];
        
        ifstream data_f;
        data_f.open("Data.txt");
        for (int i = 0; i < 10; i++){
            data_f >> ReadStudents[i].Name;
            data_f >> ReadStudents[i].Mid_Name;
            data_f >> ReadStudents[i].Sur_Name;
            data_f >> ReadStudents[i].Institute;
            data_f >> ReadStudents[i].Departament;
            data_f >> ReadStudents[i].Group;
            data_f >> ReadStudents[i].Credit_Book;
            data_f >> ReadStudents[i].Birthday;
            data_f >> ReadStudents[i].Sex;
        }
        data_f.close();
        
        int ident;
        int boolean;
        
        getAllInfoFromFile();
        cout << "\nВыберите студента" << endl;
        cin >> ident;
        ident -= 1;
        PrintData(ReadStudents[ident]);
        
        cout << "Вы уверены, что хотите удалить этого студента?(0 - Нет / 1 - Да)" << endl;
        cin >> boolean;
        switch (boolean) {
            case 0:
                break;
            case 1:
                strcpy(ReadStudents[ident].Name, "");
                strcpy(ReadStudents[ident].Mid_Name, "");
                strcpy(ReadStudents[ident].Sur_Name, "");
                strcpy(ReadStudents[ident].Institute, "");
                strcpy(ReadStudents[ident].Departament, "");
                strcpy(ReadStudents[ident].Group, "");
                strcpy(ReadStudents[ident].Credit_Book, "");
                strcpy(ReadStudents[ident].Birthday, "");
                strcpy(ReadStudents[ident].Sex, "");
                for(int i = 0; i < 9; i++){
                    for(int j = 0; j < 10; j++){
                        ReadStudents[ident].ExamsRecordsData[i][j].isEmpty = true;
                    }
                }
                
            default:
                break;
        }

        ofstream data_file_out;
        data_file_out.open("Data.txt", ios::out);
        for (int i = 0; i < 10; i ++) {
            data_file_out << ReadStudents[i].Name << endl;
            data_file_out << ReadStudents[i].Mid_Name << endl;
            data_file_out << ReadStudents[i].Sur_Name << endl;
            data_file_out << ReadStudents[i].Institute << endl;
            data_file_out << ReadStudents[i].Departament << endl;
            data_file_out << ReadStudents[i].Group << endl;
            data_file_out << ReadStudents[i].Credit_Book << endl;
            data_file_out << ReadStudents[i].Birthday << endl;
            data_file_out << ReadStudents[i].Sex << endl;
        }
        data_file_out.close();
        
        
    }
    
    void editExistStudent(){
        
        Student_Data ReadStudents[10];
        
        ifstream data_f;
        data_f.open("Data.txt");
        for (int i = 0; i < 10; i++){
            data_f >> ReadStudents[i].Name;
            data_f >> ReadStudents[i].Mid_Name;
            data_f >> ReadStudents[i].Sur_Name;
            data_f >> ReadStudents[i].Institute;
            data_f >> ReadStudents[i].Departament;
            data_f >> ReadStudents[i].Group;
            data_f >> ReadStudents[i].Credit_Book;
            data_f >> ReadStudents[i].Birthday;
            data_f >> ReadStudents[i].Sex;
            for(int j = 0; j < 9; j++){
                for(int k = 0; k < 10; k++){
                    data_f >> ReadStudents[i].ExamsRecordsData[j][k].name;
                    data_f >> ReadStudents[i].ExamsRecordsData[j][k].mark;
                }
            }
        }
        data_f.close();
        
        int ident;
        
        getAllInfoFromFile();
        cout << "\nВыберите студента" << endl;
        cin >> ident;
        ident -= 1;
        PrintData(ReadStudents[ident]);
        
        
        ClassMenu* studMenu = new ClassMenu("Изменение данных о студенте");
        
        studMenu->addMenuItem("Выход"); // 0
        studMenu->addMenuItem("Имя"); // 1
        studMenu->addMenuItem("Отчество"); // 2
        studMenu->addMenuItem("Фамилия"); // 3
        studMenu->addMenuItem("Университет"); // 4
        studMenu->addMenuItem("Интитут"); // 5
        studMenu->addMenuItem("Группа"); // 6
        studMenu->addMenuItem("Зачетная книжка"); // 7
        studMenu->addMenuItem("Дата рождения"); // 8
        studMenu->addMenuItem("Пол"); // 9
        
        int selectedItem = -1;
        
        char str[30];
        while (selectedItem != 0) {
            selectedItem = studMenu->run();
            switch (selectedItem)
            {
                case 1:
                    cout << ("Введите имя: "); cin >> str ;
                    strcpy(ReadStudents[ident].Name, str);
                    strcpy(str, "");
                    break;
                case 2:
                    cout << ("Введите отчество: "); cin >> str ;
                    strcpy(ReadStudents[ident].Mid_Name, str);
                    strcpy(str, "");
                    break;
                case 3:
                    cout << ("Введите фамилию: "); cin >> str ;
                    strcpy(ReadStudents[ident].Sur_Name, str);
                    strcpy(str, "");
                    break;
                case 4:
                    cout << ("Введите университет: "); cin >> str ;
                    strcpy(ReadStudents[ident].Institute, str);
                    strcpy(str, "");
                    break;
                case 5:
                    cout << ("Введите институт: "); cin >> str ;
                    strcpy(ReadStudents[ident].Departament, str);
                    strcpy(str, "");
                    break;
                case 6:
                    cout << ("Введите группа: "); cin >> str ;
                    strcpy(ReadStudents[ident].Group, str);
                    strcpy(str, "");
                    break;
                
                case 7:
                    cout << ("Введите номер зачетной книжки: "); cin >> str ;
                    strcpy(ReadStudents[ident].Credit_Book, str);
                    strcpy(str, "");
                    break;
                    
                case 8:
                    cout << ("Введите дату рождению: "); cin >> str ;
                    strcpy(ReadStudents[ident].Birthday, str);
                    strcpy(str, "");
                    break;
                    
                case 9:
                    cout << ("Введите пол: "); cin >> str ;
                    strcpy(ReadStudents[ident].Sex, str);
                    strcpy(str, "");
                    break;

                
                deafault:
                    break;
            }
        }
        
        PrintData(ReadStudents[ident]);
        
        ofstream data_file_out;
        data_file_out.open("Data.txt", ios::out);
        for (int i = 0; i < 10; i ++) {
            data_file_out << ReadStudents[i].Name << endl;
            data_file_out << ReadStudents[i].Mid_Name << endl;
            data_file_out << ReadStudents[i].Sur_Name << endl;
            data_file_out << ReadStudents[i].Institute << endl;
            data_file_out << ReadStudents[i].Departament << endl;
            data_file_out << ReadStudents[i].Group << endl;
            data_file_out << ReadStudents[i].Credit_Book << endl;
            data_file_out << ReadStudents[i].Birthday << endl;
            data_file_out << ReadStudents[i].Sex << endl;
            for(int j = 0; j < 9; j++){
                for(int k = 0; k < 10; k++){
                    data_file_out << ReadStudents[i].ExamsRecordsData[j][k].name << endl;
                    data_file_out << ReadStudents[i].ExamsRecordsData[j][k].mark << endl;
                }
            }
        }
        data_file_out.close();
        
        delete studMenu;
    }
    
    void createNewStudent(){
        cout << "Создание студента" << endl;
        char str[30];
        
        cout << ("Введите имя: "); cin >> str ;
        strcpy(st.Name, str);
        strcpy(str, "");
        
        cout << ("Введите отчество: "); cin >> str ;
        strcpy(st.Mid_Name, str);
        strcpy(str, "");
        
        cout << ("Введите фамилию: "); cin >> str ;
        strcpy(st.Sur_Name, str);
        strcpy(str, "");
        
        cout << ("Введите университет: "); cin >> str ;
        strcpy(st.Institute, str);
        strcpy(str, "");
        
        cout << ("Введите институт: "); cin >> str ;
        strcpy(st.Departament, str);
        strcpy(str, "");
        
        cout << ("Введите группа: "); cin >> str ;
        strcpy(st.Group, str);
        strcpy(str, "");
        
        cout << ("Введите номер зачетной книжки: "); cin >> str ;
        strcpy(st.Credit_Book, str);
        strcpy(str, "");
        
        cout << ("Введите дату рождению: "); cin >> str ;
        strcpy(st.Birthday, str);
        strcpy(str, "");
        
        cout << ("Введите пол: "); cin >> str ;
        strcpy(st.Sex, str);
        strcpy(str, "");
        
        for (int i = 0; i < 9; i++) {
            cout << "Семестр" << i << endl;
            for (int j = 0; j < 10; j++) {
                cout << ("Введите предмет: "); cin >> str ;
                st.ExamsRecordsData[i][j].name += str;
                strcpy(str, "");
                cout << ("Введите оценку: "); cin >> str ;
                st.ExamsRecordsData[i][j].mark += str;
                strcpy(str, "");
            }
        }
    }
    
    void addSt2File() {
        Student_Data WriteTextStudents;
        ofstream data_f;
        data_f.open("Data.txt", ios::app);
        strcpy(WriteTextStudents.Name, st.Name);
        strcpy(WriteTextStudents.Mid_Name, st.Mid_Name);
        strcpy(WriteTextStudents.Sur_Name, st.Sur_Name);
        strcpy(WriteTextStudents.Institute, st.Institute);
        strcpy(WriteTextStudents.Departament, st.Departament);
        strcpy(WriteTextStudents.Group, st.Group);
        strcpy(WriteTextStudents.Credit_Book, st.Credit_Book);
        strcpy(WriteTextStudents.Birthday, st.Birthday);
        strcpy(WriteTextStudents.Sex,st.Sex);
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 10; j++) {
                WriteTextStudents.ExamsRecordsData[i][j].name = st.ExamsRecordsData[i][j].name;
                WriteTextStudents.ExamsRecordsData[i][j].mark = st.ExamsRecordsData[i][j].mark;
            }
        }
        data_f << WriteTextStudents.Name << endl;
        data_f << WriteTextStudents.Mid_Name << endl;
        data_f << WriteTextStudents.Sur_Name << endl;
        data_f << WriteTextStudents.Institute << endl;
        data_f << WriteTextStudents.Departament << endl;
        data_f << WriteTextStudents.Group << endl;
        data_f << WriteTextStudents.Credit_Book << endl;
        data_f << WriteTextStudents.Birthday << endl;
        data_f << WriteTextStudents.Sex << endl;
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 10; j++) {
                data_f << WriteTextStudents.ExamsRecordsData[i][j].name << endl;
                data_f << WriteTextStudents.ExamsRecordsData[i][j].mark << endl;
            }
        }
        data_f.close();
    }
    
    void getAllInfoFromFile(){
        Student_Data ReadTextStudents[10];
        ifstream data_f;
        data_f.open("Data.txt");
        for (int i = 0; i < 10; i++){
            data_f >> ReadTextStudents[i].Name;
            data_f >> ReadTextStudents[i].Mid_Name;
            data_f >> ReadTextStudents[i].Sur_Name;
            data_f >> ReadTextStudents[i].Institute;
            data_f >> ReadTextStudents[i].Departament;
            data_f >> ReadTextStudents[i].Group;
            data_f >> ReadTextStudents[i].Credit_Book;
            data_f >> ReadTextStudents[i].Birthday;
            data_f >> ReadTextStudents[i].Sex;
            for(int j = 0; j < 9; j++){
                for(int k = 0; k < 10 ; k++){
                    data_f >> ReadTextStudents[i].ExamsRecordsData[j][k].name;
                    data_f >> ReadTextStudents[i].ExamsRecordsData[j][k].mark;
                }
            }
            PrintData(ReadTextStudents[i]);
        }
        
        data_f.close();
    }
    
    void filterStudents(){
        Student_Data Students4Filter[10];
        ifstream data_4_filter;
        data_4_filter.open("Data.txt");
        
        for(int i = 0; i < 10; i++){
            data_4_filter >> Students4Filter[i].Name;
            data_4_filter >> Students4Filter[i].Mid_Name;
            data_4_filter >> Students4Filter[i].Sur_Name;
            data_4_filter >> Students4Filter[i].Institute;
            data_4_filter >> Students4Filter[i].Departament;
            data_4_filter >> Students4Filter[i].Group;
            data_4_filter >> Students4Filter[i].Credit_Book;
            data_4_filter >> Students4Filter[i].Birthday;
            data_4_filter >> Students4Filter[i].Sex;
            for(int j = 0; j < 9; j++){
                for(int k = 0; k < 10 ; k++){
                    data_4_filter >> Students4Filter[i].ExamsRecordsData[j][k].name;
                    data_4_filter >> Students4Filter[i].ExamsRecordsData[j][k].mark;
                }
            }
        }
        
        data_4_filter.close();
        
        string marks;
        int count = 0;
        int count_4_plus = 0;
        int count_4_min = 0;
        
        cout << "Группы:" << endl;
        cout << "Группа 50%:" << endl;
        
        for(int i = 0; i < 10; i++){
            for(int j = 0; j < 9; j++){
                for(int k = 0; k < 10; k++){
                    marks += Students4Filter[i].ExamsRecordsData[j][k].mark;
                }
            }
            
            for(int b = 0; b < 90; b++){
                if(marks[b] == '5' || marks[b] == '4'){
                    count_4_plus++;
                } else {
                    count_4_min++;
                }
            }
            
            
            if(count_4_plus == count_4_min){
                cout << i;
            } else {
                count += i;
            }
            
            
            marks = "";
            int count_4_plus = 0;
            int count_4_min = 0;
        }
        if(count == 45){
            cout << "Нет таких студентов!" << endl;
            cout << "Оставшиеся: " << endl;
            cout << "1 2 3 4 5 6 7 8 9 10" << endl;
        }
    }
    
    void Marks(){
        SetDefaultData();
        
        string mark0 = "5";
        string mark1 = "4";
        string mark2 = "3";
        
        string name0 = "English";
        string name1 = "Math";
        string name2 = "Rus";
        
        ofstream data_4_filter;
        data_4_filter.open("Data.txt");
        
        for(int i = 0; i < 10; i++){
            data_4_filter << st.Name << endl;
            data_4_filter << st.Mid_Name << endl;
            data_4_filter << st.Sur_Name << endl;
            data_4_filter << st.Institute << endl;
            data_4_filter << st.Departament << endl;
            data_4_filter << st.Group << endl;
            data_4_filter << st.Credit_Book << endl;
            data_4_filter << st.Birthday << endl;
            data_4_filter << st.Sex << endl;
            
            for(int j = 0; j < 9; j++){
                if(j % 2 == 0){
                    for(int k = 0; k < 10 ; k++){
                        if (k % 2 == 0) {
                            data_4_filter << name0 << endl;
                            data_4_filter << mark1 << endl;
                        }
                        else if (k % 3 == 0){
                            data_4_filter << name1 << endl;
                            data_4_filter << mark0 << endl;
                        }
                        else {
                            data_4_filter << name2 << endl;
                            data_4_filter << mark2 << endl;
                        }
                    }
                }
                else if ( j % 3 == 0){
                    for(int k = 0; k < 10 ; k++){
                        if (k % 2 == 0) {
                            data_4_filter << name2 << endl;
                            data_4_filter << mark0 << endl;
                        }
                        else if (k % 3 == 0){
                            data_4_filter << name1 << endl;
                            data_4_filter << mark2 << endl;
                        }
                        else {
                            data_4_filter << name2 << endl;
                            data_4_filter << mark2 << endl;
                        }
                    }
                }
                else if ( j % 5 == 0 ){
                    for(int k = 0; k < 10 ; k++){
                        if (k % 2 == 0) {
                            data_4_filter << name2 << endl;
                            data_4_filter << mark2 << endl;
                        }
                        else if (k % 3 == 0){
                            data_4_filter << name1 << endl;
                            data_4_filter << mark1 << endl;
                        }
                        else {
                            data_4_filter << name0 << endl;
                            data_4_filter << mark0 << endl;
                        }
                    }
                }
                else {
                    for(int k = 0; k < 10 ; k++){
                        if (k % 2 == 0) {
                            data_4_filter << name2 << endl;
                            data_4_filter << mark0 << endl;
                        }
                        else if (k % 3 == 0){
                            data_4_filter << name1 << endl;
                            data_4_filter << mark2 << endl;
                        }
                        else {
                            data_4_filter << name2 << endl;
                            data_4_filter << mark2 << endl;
                        }
                    }
                }
                
                /*                if(j % 2 == 0){
                    for(int k = 0; k < 10 ; k++){
                        if(k % 2 == 0){
                            data_4_filter << name1 << endl;
                            data_4_filter << mark1 << endl;
                        }
                        else if (k % 3 == 0 ){
                            for(int k = 0; k < 10 ; k++){
                                data_4_filter << name0 << endl;
                                data_4_filter << mark0 << endl;
                            }
                        }
                        else {
                            for(int k = 0; k < 10 ; k++){
                                data_4_filter << name0 << endl;
                                data_4_filter << mark0 << endl;
                            }
                        }
                    }
                }
                else if(j % 3 == 0) {
                    for(int k = 0; k < 10 ; k++){
                        if(k % 2 == 0){
                            data_4_filter << name1 << endl;
                            data_4_filter << mark1 << endl;
                        }
                        else if ( k % 3 == 0 ){
                            for(int k = 0; k < 10 ; k++){
                                data_4_filter << name0 << endl;
                                data_4_filter << mark0 << endl;
                            }
                        }
                        else {
                            for(int k = 0; k < 10 ; k++){
                                data_4_filter << name2 << endl;
                                data_4_filter << mark2 << endl;
                            }
                        }
                    }
                }
                else if (j % 5 == 0){
                    for(int k = 0; k < 10 ; k++){
                        if(k % 2 == 0){
                            data_4_filter << name0 << endl;
                            data_4_filter << mark0 << endl;
                        }
                        else if ( k % 3 == 0 ){
                            for(int k = 0; k < 10 ; k++){
                                data_4_filter << name1 << endl;
                                data_4_filter << mark1 << endl;
                            }
                        }
                        else {
                            for(int k = 0; k < 10 ; k++){
                                data_4_filter << name2 << endl;
                                data_4_filter << mark2 << endl;
                            }
                        }
                    }
                }
                else {
                    for(int k = 0; k < 10 ; k++){
                        if(k % 2 == 0){
                            data_4_filter << name2 << endl;
                            data_4_filter << mark2 << endl;
                        }
                        else if ( k % 3 == 0 ){
                            for(int k = 0; k < 10 ; k++){
                                data_4_filter << name1 << endl;
                                data_4_filter << mark2 << endl;
                            }
                        }
                        else {
                            for(int k = 0; k < 10 ; k++){
                                data_4_filter << name0 << endl;
                                data_4_filter << mark2 << endl;
                            }
                        }
                    }
                }*/
            }
        }
        
        data_4_filter.close();
        
        
    }
};
