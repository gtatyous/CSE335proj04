#ifndef __COUNTVISITOR__
#define __COUNTVISITOR__

#include "Visitor.h"
#include "Node.h"
#include "Group.h"
#include "Employee.h"

class CountVisitor : public Visitor 
{
  private:
    int _Employee_count;
    int _Group_count;

  public:
    CountVisitor() : _Employee_count(0),_Group_count(0) {}
    int get_numEmp() const {return _Employee_count;}
    int get_numGroups() const {return _Group_count;}
    
    CountVisitor (const CountVisitor&);
    CountVisitor & operator= (const CountVisitor&);
    
    virtual ~CountVisitor() = default;
    virtual void visitEmployee(Employee*);
    virtual void visitGroup(Group*);
    virtual void Reset();
    void PrintResults();
};

#endif
