#include "Employee.h"
#include "Group.h"
#include "PrintVisitor.h"
#include "SearchVisitor.h"
#include "CountVisitor.h"
#include <string>
#include "CompanyBuilder.h"
#include "Parser.h"
#include "Node.h"

#include <iostream>
using namespace std;

int main(int argc, char** argv)
{
    if (argc!=2) {
        cout <<"need argument for filename" << endl;
        return 0;
    }
        Parser parser(argv[1]);
	CompanyBuilder cb;
	bool success = parser.Parse(&cb);
        Node* AppleCo= cb.getResult();
       
	return 0;
}
