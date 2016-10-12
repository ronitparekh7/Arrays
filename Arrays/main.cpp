#include <iostream>
#include <string>
#include <sstream>
#include <fstream>

int main(){
	//load the text file and put it into a single string:
	std::ifstream in("d:\\output.dat");
	std::stringstream buffer;
	buffer << in.rdbuf();
	std::string test = buffer.str();
	std::cout << test << std::endl << std::endl;

	//create variables that will act as "cursors". we'll take everything between them.
	size_t pos1 = 0;
	size_t pos2;

	//create the array to store the strings.
	std::string str[4];

	for (int x = 0; x <= 3; x++){
		pos2 = test.find("|", pos1); //search for the bar "|". pos2 will be where the bar was found.
		str[x] = test.substr(pos1, (pos2 - pos1)); //make a substring, wich is nothing more 
		//than a copy of a fragment of the big string.
		std::cout << str[x] << std::endl;
		std::cout << "pos1:" << pos1 << ", pos2:" << pos2 << std::endl;
		pos1 = pos2 + 1; // sets pos1 to the next character after pos2. 
		//so, it can start searching the next bar |.
	}
	system("PAUSE");
		
}