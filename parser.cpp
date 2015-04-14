#include "Parser.h"
#include <fstream>
#include <string>
#include <iostream>
#include <sstream>

Parser::Parser(const Parser &p)
{
    _fileName = p.getFileName();
    _parent = p.getParentMap();
}


Parser &Parser::operator=(const Parser &p)
{
    if(this != &p)
    {
        _fileName = p.getFileName();
        _parent = p.getParentMap();
    }
    return *this;
}

bool Parser::Parse(CompanyBuilder* cb){
    /*
     Apple
     1,1,Cook,Tim,CEO,Apple
     1,2,VP,Apple
     1,1,Federighi,Craig,VP of Engineering,VP
     1,1,Schiller,Phillip,VP of Marketing,VP
     1,2,Smartwatch,VP
     1,2,iPad,VP
     1,1,Smith,Bob,iPad Designer,iPad
     1,2,Smartwatch,Chefs
     2,iPad
     3,VP
     */
    
    ifstream infile;
    infile.open(_fileName);
    
    if(!infile.is_open()){
        cout << "***  Error: could not open file  ***" <<endl;
        return false;
    }
    
    string company_name;
    getline(infile, company_name);
    cb->establishCompany(company_name); //Acts like a constructor
    
    string line;
    while(getline(infile, line)){
        std::stringstream ss(line);
        string num1;
        getline(ss, num1, ',');
        int i = std::stoi (num1);
        if(i == 1)
        {
            string num2;
            getline(ss, num2, ',');
            int j = std::stoi (num2);
            if (j==1)
            {
                string last, first, title, team_name;
                getline(ss, last, ',');
                getline(ss, first, ',');
                getline(ss, title, ',');
                getline(ss, team_name); //inputfile had \r char at the end? should be \n
                cb->addNode(first, last, title, team_name); //overloaded function
            }
            else
            {
                string team_name, supervisor;
                getline(ss, team_name, ',');
                getline(ss, supervisor);//inputfile had \r char at the end? should be \n
                _parent[team_name] = supervisor; //save supervisor of each team
                cb->addNode(team_name, supervisor); //overloaded function
            }
        }
        else if (i == 2)
        {
            string team_name, supervisor;
            getline(ss, team_name);//inputfile had \r char at the end? should be \n
            auto search = _parent.find(team_name);
            if (search != _parent.end()) //checks if the team is there?
            {
                supervisor = search->second;
            }
            else { supervisor ="None";}
            cb->removeNode(team_name, supervisor);
        }
        else if (i ==3)
        {
            string team_name, supervisor;
            getline(ss, team_name);//inputfile had \r char at the end? should be \n
            auto search = _parent.find(team_name);
            if (search != _parent.end()) //checks if the team is there?
            {
                supervisor = search->second;
            }
            else { supervisor = "None";}
            cb->disbandNode(team_name, supervisor);
        }
    }
    infile.close();
    return true;
}

