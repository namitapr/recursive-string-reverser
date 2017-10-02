#include <iostream>
#include <fstream>

int main (int argc, char* argv[]){

	std::ifstream infile(argv[1]);

	if(infile.fail()){
		std::cerr << "error opening file" << std::endl;
	}

	int numChars;
	infile >> numChars;

	char* original = new char[numChars+1];
	infile.ignore();
	infile.get(original, numChars+1);
	original[numChars] = '\0';

	char* reverse = new char[numChars+1];
	for(int i=0; i<numChars; i++){
		reverse[i] = original[numChars-1-i];
	}
	reverse[numChars] = '\0';

	for(int i=0; i<numChars; i++){
		std::cout << reverse[i];
	}
	std::cout << std::endl;

	delete [] original;
	delete [] reverse;

	return 0;
}