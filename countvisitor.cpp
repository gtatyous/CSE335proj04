#include "Visitor.h"
#include "Countvisitor.h"

CountVisitor::CountVisitor(const CountVisitor& rhs)
{
    _Group_count = rhs.get_numGroups();
    _Employee_count = rhs.get_numEmp();
}


CountVisitor & CountVisitor::operator= (const CountVisitor& rhs)
{
    if(this != &rhs)
    {
        _Group_count = rhs.get_numGroups();
        _Employee_count = rhs.get_numEmp();
    }
    return *this;
}

void CountVisitor::visitGroup(Group* g) {
    //Iterate through all of the children and call the appropriate visit from the accept function of the child.
    //Increment the group count by 1 for visiting a group node
    _Group_count++;
    for(int i=0; i < g->get_children_size(); i++)
    {
      g->get_child(i)->Accept(this);
    }
}
void CountVisitor::visitEmployee(Employee* e) {
  //Terminal case: increment the count of employees for visiting employee nodes
  _Employee_count++;
  
}
void CountVisitor::Reset() {
  //Only the counters need to be reset for this visitor class
  _Group_count=0;
  _Employee_count=0;
}
void CountVisitor::PrintResults() {
  cout << "Groups:" << _Group_count << endl;
  cout << "Employees:"<< _Employee_count << endl;
}

