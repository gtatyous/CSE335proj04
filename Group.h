
#ifndef __GROUP__
#define __GROUP__

#include "Node.h"
#include "Visitor.h"
#include <iostream>
#include <vector>
#include <string>


class Group : public Node
{
private:
  vector<Node*> _node_vector;
public:
  
  Group(string n) : Node(n) {}
  Group(const Group &g);
  Group & operator= (const Group &g);
  virtual ~Group(); //implemented to delete all Nodes in _node_vector

  virtual void print_data() const {cout << "+Team "  << this->get_name() << endl;}
  virtual void Accept(Visitor* v) {v->visitGroup(this);}
  
  Node* get_child(int i) const {return _node_vector[i];}
  int get_children_size() const {return _node_vector.size();}
  
  void AddChild(Node* c) {_node_vector.push_back(c);}    
  void RemoveChild(Node* c){_node_vector.erase ( (std::find(_node_vector.begin(),_node_vector.end(),c)) );}
  void ClearNodeVec() {_node_vector.clear();}
};

#endif
