//
/*
Author: Derek Ni
Course: CSCI-135
Instructor: Gennady Maryash
Assignment: Project 3 A

Description:
*/

#include <string>
#include "skill.hpp"
#ifndef PROFEMON_HPP
#define PROFEMON_HPP


enum Specialty{ML, SOFTWARE, HARDWARE};

class Profemon{
    private:
        std::string profemon_name;
        int profemon_level;
        int required_exp;
        int current_exp;
        double maximum_health;
        Specialty profemon_specialty;
        Skill skills[3];
    
    public: 
        Profemon();
        Profemon(std::string name, double max_health, Specialty specialty);
        std::string getName();
        Specialty getSpecialty();
        int getLevel();
        double getMaxHealth();
        void setName(std::string name);
        void levelUp(int exp);
        bool learnSkill(int slot, Skill skill);
        void printProfemon(bool print_skills);
};
#endif