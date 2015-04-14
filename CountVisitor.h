#ifndef __COUNTVISITOR__
#define __COUNTVISITOR__
#include "Visitor.h"
#include "CountVisitor.h"
#include "Node.h"

class CountVisitor : public Visitor 
{
  private:
    int _Employee_count;
    int _Group_count;
//    stack<int> _counter_stack;
  public:
    CountVisitor() : _Employee_count(0),_Group_count(0) {}
    int get_numEmp() const {return _Employee_count;}
    int get_numGroups() const {return _Group_count;}
    
    
    CountVisitor (const CountVisitor&);
    CountVisitor & operator= (const CountVisitor&);
    
    
    virtual ~CountVisitor() = default;
    virtual void visitEmployee(Employee*); //terminal visit
    virtual void visitGroup(Group*); //nonterminal visit 
    virtual void Reset();
    void PrintResults();
};

#endif
