#ifndef __PARSER__
#define __PARSER__

#include "CompanyBuilder.h"
#include <map>
#include <string>

/*
class AbstractParser{
  public:
    virtual ~AbstractParser(){};
  protected:
    AbstractParser();
};
*/
class Parser //:public AbstractParser
{
  private:
    string _fileName;
    map<string, string> _parent; //str1 is team, str2 is supervisor
  public:
    Parser(string f) : _fileName(f) {}
    ~Parser()=default;
    Parser(const Parser &);
    Parser &operator=(const Parser &);
    string getFileName() const {return _fileName;}
    map<string, string> getParentMap() const {return _parent;}
    bool Parse(CompanyBuilder*);
};

#endif
