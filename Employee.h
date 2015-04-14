#ifndef __EMPLOYEE__
#define __EMPLOYEE__

#include "Visitor.h"
#include "Node.h"
#include <string>
#include <iostream>
using namespace std;


class Employee : public Node
{
  private:
    string _last_name;
    string _title;

  public:
  
    Employee(string n, string l, string t) : Node(n), _last_name(l), _title(t) {}
    virtual ~Employee() = default;
    string get_last_name() const {return _last_name;}
    string get_title() const {return _title;}
    
    Employee(const Employee &);
    Employee &operator=(const Employee &);
    
    virtual void print_data() const {cout << _title << ": " << this->get_name() << " " << _last_name  << endl;}
    virtual void Accept(Visitor* v) {v->visitEmployee(this);}
    
};

#endif
