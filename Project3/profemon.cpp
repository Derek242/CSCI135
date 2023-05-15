//
/*
Author: Derek Ni
Course: CSCI-135
Instructor: Gennady Maryash
Assignment: Project 3 A

Description:
*/


#include <iostream>
#include "profemon.hpp"
#include <string>

Profemon::Profemon(){
    profemon_name = "Undefined";
}

Profemon::Profemon(std::string name, double max_health, Specialty specialty){
    profemon_name = name;
    maximum_health = max_health;
    profemon_specialty = specialty;
    required_exp = 50;
    current_exp = 0;
    profemon_level = 0;
}

std::string Profemon::getName(){
    return profemon_name;
}
Specialty Profemon::getSpecialty(){
    return profemon_specialty;
}
int Profemon::getLevel(){
    return profemon_level;
}

double Profemon::getMaxHealth(){
    return maximum_health;
}
void Profemon::setName(std::string name){
    profemon_name = name;
}
void Profemon::levelUp(int exp){
    current_exp += exp;

    while(current_exp >= required_exp){
        current_exp -= required_exp;

        if(profemon_specialty == ML){
            required_exp += 10;
        } else if (profemon_specialty == SOFTWARE){
            required_exp += 15;
        } else if (profemon_specialty == HARDWARE){
            required_exp += 20;
        }

        profemon_level++;
    }

}
bool Profemon::learnSkill(int slot, Skill skill){
    if ((slot == 1 || slot == 2 || slot == 0) && skill.getSpecialty() == profemon_specialty){
        skills[slot] = skill;
        return true;
    } else {
        return false;
    }
}

void Profemon::printProfemon(bool print_skills){
    std::cout << Profemon::getName() << " [";

    if (profemon_specialty == 0){
        std::cout << "ML";
    } else if(profemon_specialty == 1){
        std::cout << "SOFTWARE";
    } else if(profemon_specialty == 2){
        std::cout << "HARDWARE";
    }

    std::cout << "] | lvl " << profemon_level << " | exp " << current_exp << "/" << required_exp << " | hp " << maximum_health << std::endl;
    
    if(print_skills == true){
        for (int i = 0; i < 3; i++){
            if (skills[i].getName() != "Undefined"){
                std::cout << "    " << skills[i].getName() << " [" << skills[i].getTotalUses() << "] : " << skills[i].getDescription() << std::endl;

            }
        }
    }
}

