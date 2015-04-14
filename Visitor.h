#ifndef __VISITOR__
#define __VISITOR__
#include <stack>
#include <vector>
using namespace std;

class Group;
class Employee;
class Visitor
{
  public:
    Visitor() {}
    virtual ~Visitor() =default;
  
    //Visits terminal nodes. These are the "base cases" of the recursive call to accept and visit.
    virtual void visitEmployee(Employee*)=0; //terminal visit
    
    //Visits non-terminal nodes, calls Accept from their children nodes. Accept(this) passes in an abstract visitor, not
    // a group visitor. The accept call inside of a node calls either visit group or visit employee. So this will either
    // lead to a recursive call of visit group, or a call to visit employee depending on the terminality of the node.
    virtual void visitGroup(Group*)=0; //nonterminal visit
    
    virtual void Reset()=0;
};



#endif
