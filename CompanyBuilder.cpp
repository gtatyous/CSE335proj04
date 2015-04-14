#include "CompanyBuilder.h"
#include "Group.h"
#include "PrintVisitor.h"
#include "SearchVisitor.h"
#include "Node.h"
#include <iostream>
#include <unistd.h>
#include <cstdlib>


//////////////////      Tools      //////////////////

Node* constructEmp(string first, string last, string title)
{
    Node* emp = new Employee(first, last, title);
    return emp;
}


Node* constructGrp(string team_name)
{
    Node* grp = new Group(team_name);
    return grp;
}

void printErrorMessage(string cmd, string team_name)
{
    cout<<("----------------------------------------------------------")<<endl;
    std::cout << "Error: Cannot " << cmd << " group " << team_name << \
    " because it does not exist!" << " Omitting this entry." << std::endl;
    cout<<("----------------------------------------------------------")<<endl;
    usleep(3000000);
}


void CompanyBuilder::print()
{
    system("clear");
    cout<<("----------------------------------------------------------")<<endl;
    _company->Accept(_pVisitor);
    cout<<("----------------------------------------------------------")<<endl;
    usleep(3000000);
}


Node* CompanyBuilder::getNode(string team_name) {
    _sVisitor->setQuery(team_name);
    _company->Accept(_sVisitor);
    if (_sVisitor->get_stack_size() == 0)
    {
        return nullptr;
    }
    Node* result = _sVisitor->pop_stack();;
    _sVisitor->Reset();
    return result;
}


Group* CompanyBuilder::getTeam(string team_name) {
    _sVisitor->setQuery(team_name);
    _company->Accept(_sVisitor);
    if (_sVisitor->get_stack_size() == 0)
    {
        return nullptr;
    }
    Node* result = _sVisitor->pop_stack();;
    _sVisitor->Reset();
    return (Group*) result;
}



//////////////////   Copy constructor & Assignment operator   //////////////////

CompanyBuilder::CompanyBuilder(const CompanyBuilder &cb)
{
    _company = cb.getCompany();
    _sVisitor = cb.getSVisitor();
    _pVisitor = cb.getPVisitor();
}


CompanyBuilder &CompanyBuilder::operator=(const CompanyBuilder &cb)
{
    if(this != &cb)
    {
        _company = cb.getCompany();
        _sVisitor = cb.getSVisitor();
        _pVisitor = cb.getPVisitor();
    }
    return *this;
}



//////////////////      Destructor      //////////////////

CompanyBuilder::~CompanyBuilder()
{
    delete _company; //Group destructor will delete all children
    delete _sVisitor;
    delete _pVisitor;
}



//////////////////      Builder main functions      //////////////////


void CompanyBuilder::establishCompany(string company_name)
{
    _company = new Group(company_name);
    _sVisitor = new SearchVisitor();
    _pVisitor = new PrintVisitor();
    _parsed = true;
    print();
    
}


void CompanyBuilder::addNode(string first, string last, string title, string team_name)
{
    Node* emp = constructEmp(first, last, title);
    Group* team = getTeam(team_name);
    if (team != nullptr) {
        team->AddChild(emp);
        print();
    } else {printErrorMessage("find", team_name);}
}


void CompanyBuilder::addNode(string team_name, string supervisor)
{
    Node* grp = constructGrp(team_name);
    Group* super = getTeam(supervisor);
    if (super != nullptr) {
        super->AddChild(grp);
        print();
    }else {printErrorMessage("find", supervisor);}
}


void CompanyBuilder::removeNode(string team_name , string supervisor)
{
    if (supervisor == "None") { printErrorMessage("remove", team_name); return;}
    Node* team = getNode(team_name);
    Group* super = getTeam(supervisor);
    super->RemoveChild(team); //remove team's pointer from super's vector
    delete team; //deletes team and all of its children
    print();
}


void CompanyBuilder::disbandNode(string team_name , string supervisor) 
{
    if (supervisor == "None") { printErrorMessage("disband", team_name); return;}
    Node* team = getNode(team_name);
    Group* teamGrp = getTeam(team_name);
    Group* super = getTeam(supervisor);
    super->RemoveChild(team); //remove team's pointer from super's vector
    for (int i=0; i < teamGrp->get_children_size(); i++)
    {
        super->AddChild(teamGrp->get_child(i));
    }
    teamGrp->ClearNodeVec(); //prevent team from deleting its children when destructor called
    delete teamGrp;
    print();
}


Node* CompanyBuilder::getResult()
{
    if (_parsed)
    {
        print();
    }
    return _company;
}





