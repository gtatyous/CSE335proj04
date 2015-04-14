#ifndef __COMPANYBUILDER__
#define __COMPANYBUILDER__

#include "Node.h"
#include "Group.h"
#include "PrintVisitor.h"
#include "SearchVisitor.h"
#include <string>


/*class AbstractBuilder
{
  public:
    virtual ~AbstractBuilder(){};
  protected:
    AbstractBuilder();
};*/


class CompanyBuilder //: public AbstractBuilder
{
  private:
    Group* _company;
    SearchVisitor* _sVisitor;
    PrintVisitor* _pVisitor;
    
    //Tools
    bool _parsed = false;
    Node* getNode(string);
    Group* getTeam(string);
    void print();

  public:
    
    //Constructor & Destructor
    CompanyBuilder()=default;
    virtual ~CompanyBuilder(); //all allocated memeory is deleted
    
    //Copy constructor & Assignment operator
    CompanyBuilder(const CompanyBuilder &);
    CompanyBuilder &operator=(const CompanyBuilder &);

    //Accessors
    Group* getCompany() const {return _company;}
    SearchVisitor* getSVisitor() const {return _sVisitor;}
    PrintVisitor* getPVisitor() const {return _pVisitor;}
    
    //Builder main functions
    void establishCompany(string);
    void addNode(string first, string last, string title, string team_name);
    void addNode(string team_name, string supervisor); //overloaded
    void removeNode(string, string);
    void disbandNode(string, string);
    Node* getResult();
};

#endif
