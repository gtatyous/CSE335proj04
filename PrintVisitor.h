#ifndef __PRINTVISITOR__
#define __PRINTVISITOR__
#include "Visitor.h"
#include <string>
#include <iostream>
using namespace std;

class PrintVisitor : public Visitor 
{
  private:
    string _tab;
  public:
    PrintVisitor() : Visitor() {string _tab = "";}
    virtual ~PrintVisitor()=default;
     
    PrintVisitor(const PrintVisitor&);
    PrintVisitor &operator=(const PrintVisitor&);
    std::string get_tab() const {return _tab;}
    
    virtual void visitEmployee(Employee*); //terminal visit
    virtual void visitGroup(Group*); //nonterminal visit
    virtual void Reset();
};

#endif
