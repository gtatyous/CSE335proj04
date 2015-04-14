#ifndef __NODE__
#define __NODE__

#include <iostream>
#include <vector>
#include <string>
#include "Visitor.h"

using namespace std;

class Node
{
  private:
    string _name;
  public:
    Node(string n) : _name(n) {}
    virtual ~Node(){};
  
    virtual void Accept(Visitor* v)=0;
    virtual void print_data() const=0;
    string get_name() const {return _name;}     
    void set_name(string s) {_name = s;}
};

#endif
