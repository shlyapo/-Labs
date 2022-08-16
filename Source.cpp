#ifndef DEK_H_INCLUDED
#define DEK_H_INCLUDED
#include  <iostream>
#include "Vector.h"

using namespace std;

class Dek : public Vector {
public:
    // Конструктор класса Student
    student(
        std::string last_name,
        std::string name,
        std::string second_name,
        std::vector<int> scores
    ) : human(
        last_name,
        name,
        second_name
    ) {
        this->scores = scores;
    }
    #endef;