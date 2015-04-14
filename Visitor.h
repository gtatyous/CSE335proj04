#ifndef __VISITOR__
#define __VISITOR__

#include <stack>
#include <vector>
#include "Group.h"
#include "Employee.h"
using namespace std;

class Visitor
{
  public:
    Visitor() {}
    virtual ~Visitor() =default;
  
    virtual void visitEmployee(Employee*)=0;
    virtual void visitGroup(Group*)=0;
    virtual void Reset()=0;
};

#endif
