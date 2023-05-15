//
/*
Author: Derek Ni
Course: CSCI-135
Instructor: Gennady Maryash
Assignment: Project 3 B

Description:
*/
#pragma once
#include <iostream>
#include "profemon.hpp"
#include <vector>

class Trainer{
    private:
        std::vector<Profemon> profedex;
        Profemon current_team[3];
        Profemon *selected_profemon;
        Profemon name;
    
    public:
        Trainer();
        Trainer(std::vector <Profemon> profemons);
        bool contains(std::string name);
        bool addProfemon(Profemon profemon);
        bool removeProfemon(std::string name);
        void setTeamMember(int slot, std::string name);
        bool chooseProfemon(int slot);
        Profemon getCurrent();
        void printProfedex();
        void printTeam();
};