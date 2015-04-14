# CSE335proj4

Everything works. However, the provided input file was created on Windows. Windows OS adds return character (\r) and a new line character (\n) at the end of each input line. These hidden different character across different platform might cause the code to run incorrectly. Therefore, I have re-written the input file again, which looks exactly like the old one. Please run it on input.txt (the new one) but you could check how the oldinput.txt will cause errors in the code if you are curious.

To build this program, log onto a CSE machine and unzip the all of the source files. Put them all in the same directory. Type "make" to generate an executable. The executable is called “out” to run it type "out" or “./out” in the terminal. This code was tested on a mac as well as on arctic.cse.msu.edu

Name, NetID, responsibility
  + Yousef Gtat (gtatyous): Drew the UML diagram for the project, wrote the whole project of this version. My partner Ian Bacus has his own implementation and we will submit two versions to see which one will get better grade.

Parser takes the input file and reads all line of the input file and calls the correct commands to the builder object. If the input file cannot be open, parser will return false and will not call any commands on the builder object. 

CompanyBuilder has three main functions, addNode, removeNode, and disbandNode. The first functions has two versions; overloaded function, to accommodate wether Employee obj or Group obj should be allocated. The second removes a Node and all of its children from the company hierarchy which is a private Group object stored inside the CompanyBuilder object. Disband functions, on the other hand, will delete only the group specified not its children. All of the children will be passed to the nearest group object in the company hierarchy.

