#include "Visitor.h"
#include "Printvisitor.h"
#include "Node.h"
#include "Group.h"
#include "Employee.h"



PrintVisitor::PrintVisitor(const PrintVisitor& rhs)
{
    _tab = rhs.get_tab();
}


PrintVisitor & PrintVisitor::operator= (const PrintVisitor& rhs)
{
    if(this != &rhs)
    {
        _tab = rhs.get_tab();
    }
    return *this;
}



void PrintVisitor::visitGroup(Group* g) {
  
  //*NON TERMINAL CASE*
  //group contains: a vector of children, its own data (name)
  
  //A string of tabs are used to maintain the current level of indentation in the tree.
  //Preorder: increase indentation, going down a branch will increase indentation
  //Postorder: decrease indentation, restores indentation moving back upwards
  //coming back up a branch and then going back down will preserve indentation.
  g->print_data();
  _tab+="\t";

  for(int i=0; i < g->get_children_size(); i++)
  {
      cout<<_tab;
      g->get_child(i)->Accept(this);
  }
  _tab.pop_back();
  //iterate through members of group
  //selectively do some operation
}
void PrintVisitor::visitEmployee(Employee* e) {
  //*TERMINAL CASE*
  // employee contains: its own data
  //print the data of the employee
  e->print_data();
}
void PrintVisitor::Reset() {
  
  //empty implementation
  
}
