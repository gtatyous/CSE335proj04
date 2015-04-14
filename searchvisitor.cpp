#include "Visitor.h"
#include "Node.h"
#include "SearchVisitor.h"



SearchVisitor::SearchVisitor(const SearchVisitor& rhs)
{
    _search_stack = rhs.get_search_stack();
    _search_query = rhs.get_query();
}


SearchVisitor & SearchVisitor::operator= (const SearchVisitor& rhs)
{
    if(this != &rhs)
    {
        _search_stack = rhs.get_search_stack();
        _search_query = rhs.get_query();
    }
    return *this;
}

void SearchVisitor::visitGroup(Group* g)
{

  //If there is a match, push the first layer of children onto the search stack
//  (s1.find(s2_a) != string::npos && s1.find(s2_b)!= string::npos) || (s1==s2_a || s1==s2_b) )
  if((get_query().find(g->get_name()) != string::npos) || get_query() == g->get_name() )
  {
    for(int i=0; i < g->get_children_size(); i++)
    {
      push_stack(g->get_child(i));
    }
    push_stack(g);
  }
  else{
    //If there is no match, continue searching through the children to arbitrary depth 
    for(int i=0; i < g->get_children_size(); i++)
    {
      g->get_child(i)->Accept(this);
    }
  }
  
}
void SearchVisitor::visitEmployee(Employee* e)
{
  //  (s1.find(s2_a) != string::npos && s1.find(s2_b)!= string::npos) || (s1==s2_a || s1==s2_b) )
  if( (get_query().find(e->get_name())!= string::npos || get_query().find(e->get_last_name()) != string::npos) || \
  ( get_query() == e->get_name() || get_query() == e->get_last_name() ) )
   // _search_query == e->get_name() || _search_query == e->get_last_name())
  {
    push_stack(e);
  } //else do nothing
}

void SearchVisitor::PrintResults()
{
  stack<Node*> copy_stack = _search_stack;
  int results_size = copy_stack.size();
  if(results_size == 0)
    cout << "No results for " << get_query() << "." << endl;
  else
  {
    cout << results_size << " results for query " << get_query() << ":" << endl;
    while(!copy_stack.empty())
    {
      copy_stack.top()->print_data();;
      copy_stack.pop(); 
      
    }
  }
  cout << endl;
}
void SearchVisitor::Reset()
{
  _search_query = "";
  while(!_search_stack.empty())
  {
    _search_stack.pop();
  }
  
}

void SearchVisitor::setQuery(string s)
{ 
  
  if(get_stack_size()) //not greater than 1
    cout << "Warning: results of previous search for " << get_query() << " have not been cleared." << endl;
  _search_query = s;
 
}

Node* SearchVisitor::pop_stack() 
{ 
  
  Node* ret= _search_stack.top();
  _search_stack.pop(); 
  return ret;
}
