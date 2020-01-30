#include "heap.h"
#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	heap myHeap(100);

	int key;
	string user, opt;

	//OPENS INPUT FILE TO BE READ INTO PRIORITY QUEUE
	ifstream queueFile ("heapdata.txt");

	//CHECK FOR MISSING INPUT FILE
	if(!queueFile) {
		cout << "ERROR: INPUT FILE NOT FOUND";
		exit(1);
	}
	
	//READS EACH LINE OF FILE AND STORES VALUES IN VARIABLES
	while(!queueFile.eof()) {
		queueFile >> key;
		queueFile >> user >> opt;
		//CHECKS FOR OPT-IN THEN INSERTS IF YES
		if(opt == "Y") myHeap.insert(key, user);
	}

	//REMOVES FROM FRONT OF PRIORITY QUEUE AND OUTPUTS MEMBER AND PRIORITY NUMBER
	for(int i = 0; i < myHeap.size;) {
		node priority = myHeap.remove();
		cout << priority.key << " " << priority.data << endl;
	}
	
	return 0;
}