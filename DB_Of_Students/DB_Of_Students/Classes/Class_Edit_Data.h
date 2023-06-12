//
//  Class_Edit_Data.h
//  DB_Of_Students
//
//  Created by Daniil Vilchinskiy on 15.05.2023.
//

#pragma once
#include <iostream>
#include <string.h>

using namespace std;

enum class editType : char { onlyDigit, onlyAlpha, all };


class ClassEditData
{
private:
    string label;
    string data;
public:
    ClassEditData() {
        label = "";
        data = "";
    }
    void setLabel(string _label="Поле") {
        if (_label.length() > 1)
            this->label = _label;
        else
            label = "";
    }
    bool isDigit(char ch) {
        if (ch >= 48 and ch <= 57)
            return true;
        else
            return false;
    }
    bool isStringDigit(string _str) {
        for (int i = 0; i < _str.length(); i++)
            if (not isDigit(_str[i]))
                return false;
        if (_str.length()==0)
            return false;
        return true;
    }
    bool isAlpha(int ch) {
        if (ch >= 65 and ch <= 90)
            return true;
        if (ch >= 97 and ch <= 122)
            return true;
        if (ch >= -200 and ch <= -1)
            return true;
        return false;
    }
    bool isSpace(char ch) {
        if (ch == 32)
            return true;
        else
            return false;
    }
    bool isSpec(char ch) {
        if (ch >= 33 and ch <= 47)
            return true;
        else
            return false;
    }
    void clear(string _data = "") {
        for (int i = 0; i < 100; i++) {
            cout << " " << endl;
        }
        data = _data;
    }
    
    string getData(enum editType et){
        char ch;
        cout << label << endl << data;
        
        ch = getchar();
        
        if (et == editType::onlyDigit){
            if(isDigit(ch)){
                cout << ch;
                data = data + ch;
            }
        }
        
        if (et == editType::onlyAlpha){
            if(isAlpha(ch)){
                cout << ch;
                data = data + ch;
            }
        }
        
        if (et == editType::all){
            cout << ch;
            data = data + ch;
            
        }
        
        return data;
    }
    
    int getData(enum editType et, int min, int max) {
        if (et == editType::onlyDigit){
            getData(et);
            int num = max + 1;
            if (isStringDigit(data)) num = atoi(data.c_str());
            if (not (num >= min and num < max)){
                cout << endl << " Диапазон (" << min << "; " << max-1 << ") " << endl;
                getData(et, min, max);
            }
            if (isStringDigit(data)) num = atoi(data.c_str());
            return num;
        } else {
            return NULL;
        }
    }

    string getData(enum editType et, int len) {
        if (et == editType::onlyAlpha or et == editType::all) {
            getData(et);
            if (data.length() > len) {
                cout << endl << "Возможные символы: " << data.length() - 1 << " Введите число в диапазоне: " << len << " " << endl;
                getData(et, len);
            }
            return data;
        }
        else {
           return NULL;
       }
    }
};
