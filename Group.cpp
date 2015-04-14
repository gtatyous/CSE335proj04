#include "Node.h"
#include "Group.h"


Group::~Group()
{
    while(!_node_vector.empty())
    {
        delete _node_vector.back();
        _node_vector.pop_back();
    }
}


Group::Group (const Group &g) : Node(g.get_name())
{

  set_name(g.get_name());
  for(int index=0; index<g.get_children_size();index++)
  {
    AddChild(g.get_child(index));
  }
}


Group & Group::operator= (const Group &g)
{
  if(this != &g)
  {
    set_name(g.get_name());
    for(int index=0;index<g.get_children_size();index++)
    {
      AddChild(g.get_child(index));
    }
  }
  return *this;
}
