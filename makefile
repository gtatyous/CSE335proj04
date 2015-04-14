EXE = out
SOURCES = samplemain.cpp searchvisitor.cpp printvisitor.cpp countvisitor.cpp Group.cpp Employee.cpp CompanyBuilder.cpp parser.cpp
OBJECTS := $(SOURCES:%.cpp=%.o)
CXXFLAGS = -Wall -std=c++11
CXX = g++
$(EXE) : $(OBJECTS) 
	$(CXX) $^ -o $@
clean:
	rm -rf *o $(EXE)
