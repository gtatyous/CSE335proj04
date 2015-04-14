#ifndef __SEARCHVISITOR__
#define __SEARCHVISITOR__

#include "Visitor.h"
#include "Node.h"


class SearchVisitor : public Visitor 
{
  private:
    stack<Node*> _search_stack ;//not sure if this is necessary
    string _search_query;
  public:
    
    SearchVisitor()=default;
    virtual ~SearchVisitor() = default;
    virtual void visitEmployee(Employee*); //terminal visit
    virtual void visitGroup(Group*); //nonterminal visit 
    virtual void Reset();
    
    SearchVisitor (const SearchVisitor&);
    SearchVisitor & operator= (const SearchVisitor&);

    void PrintResults(); //should this leave the stack intact?
    
    int get_stack_size() const {return _search_stack.size();}
    string get_query() const {return _search_query;}
    
    stack<Node*> get_search_stack() const {return _search_stack;}
    string get_search_query() const {return _search_query;}
    Node* pop_stack();
    void push_stack(Node* n) { _search_stack.push(n); }
    void setQuery(string s);
};

#endif
