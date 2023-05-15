//
/*
Author: Derek Ni
Course: CSCI-135
Instructor: Gennady Maryash
Assignment: Project 3 A

Description:
*/

#include <iostream>
#include "skill.hpp"
#include <string>

Skill::Skill(){
    skill_name = "Undefined";
    skill_description = "Undefined";
    skill_count = -1;
    skill_specialty = -1;
}


Skill::Skill(std::string name, std::string description, int specialty, int uses){
    skill_name = name;
    skill_description = description;
    skill_count = uses;
    skill_specialty = specialty;   
}

std::string Skill::getName(){
    return skill_name;
}

std::string Skill::getDescription(){
    return skill_description;
}

int Skill::getTotalUses(){
    return skill_count;
}

int Skill::getSpecialty(){
    return skill_specialty;
}

void Skill::setName(std::string name){
    skill_name = name;
}

void Skill::setDescription(std::string description){
    skill_description = description;
}

void Skill::setTotalUses(int uses){
    skill_count = uses;
}

bool Skill::setSpecialty(int specialty){
    if(specialty == 0 || specialty == 1 || specialty == 2){
        skill_specialty = specialty;
        return true;
    } else {
        return false;
    }
}