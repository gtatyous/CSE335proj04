#include "Node.h"

Employee::Employee(const Employee &e) : Node(e.get_name())
{
  //_name = e->get_name(); //put this in initialization list somehow?
  set_name(e.get_name());
  _last_name = e.get_last_name();
  _title = e.get_title();
}


Employee &Employee::operator=(const Employee &e)
{
if(this != &e)
  {
    set_name(e.get_name());
    _last_name = e.get_last_name();
    _title = e.get_title();
  }
  return *this;
}
