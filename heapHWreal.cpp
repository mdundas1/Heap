#include <iostream>
#include <string>
#include <stdlib.h>    // srand, rand 
#include <time.h>      // time 
using namespace std;
#define HEAP_SIZE 100

///////////////////This Program is for a min-heap (smallest node in root)

struct node {
	
	int priority;
	string name;
};

void reHeapUp(node heap[], int loc) {   //int loc = our location in the tree
	
	if (loc != 0) {  //we are not at the root
		
		int parent = (loc - 1)/2;
		if (heap[parent].priority > heap[loc].priority) {   //when parent is larger than its child
			
			node temp = heap[parent];
			heap[parent] = heap[loc];  //swapping heap[parent] with heap[loc]
			heap[loc] = temp;
			reHeapUp(heap, parent);  // reheap up the child node
		}
	}
}

void reheapDown(node heap[], int loc, int last) {
	
	node hold, leftKey, rightKey, largestKey;
	int largestIndex;
	
	//check for left child
	if (2*loc + 1 <= last) {
		
		leftKey = heap[2*loc + 1];  //left child
		
		if (2*loc + 2 <= last) {
			
			rightKey = heap[2*loc + 2];
			
		} else {
			
			rightKey = leftKey;  //right key always smaller than left key
			rightKey.priority = leftKey.priority + 1;
			
		}
		
		if (rightKey.priority < leftKey.priority) {
			
			largestKey = rightKey;
			largestIndex = 2*loc + 2;

		} else {
			
			largestKey = leftKey;
			largestIndex = 2*loc + 1;
			
		}
		
		if (heap[loc].priority > heap[largestIndex].priority) {
			
			hold = heap[loc];
			heap[loc] = heap[largestIndex];
			heap[largestIndex] = hold;
			
			reheapDown(heap, largestIndex, last);   //bring the new, smaller node up the heap
			
		}
		
	}
	
}

bool insertHeap(node heap[], int& last, node newNode) {
	
	if (last == HEAP_SIZE - 1) {
		
		return false;
		
	} 
	
	last++;
	heap[last] = newNode;
	reHeapUp(heap, last);
	return true;
}


bool deleteHeap(node heap[], int& last, node& dataOut) {
	
	if (last < 0) {  //empty heap
		
		cout << "Heap is empty" << endl;
		return false;
	}	
	
		dataOut = heap[0];
		heap[0] = heap[last];   //root is now equal to last index value
		last--;
		reheapDown(heap, 0, last);  //bring the parent down the heap
		return true;
}


int main() {
	
	node heap[HEAP_SIZE];
	int last =  -1;  //starting at -1 means we have an empty heap
	node temp;
	
	srand(time(NULL));
	
	while (1) {
		
	temp.priority = rand()%(4 + 1) + 1;

	
		if (temp.priority == 1) {
			
			//temp.priority = 1;
			temp.name = "Run BIOS Command";
			insertHeap(heap, last, temp);
//			deleteHeap(heap, last, temp);
			cout << temp.priority << ". " << temp.name << endl;
		
		} else if (temp.priority == 2) {
		
			//temp.priority = 2;
			temp.name = "Run OS Command";
			insertHeap(heap, last, temp);
//			deleteHeap(heap, last, temp);
			cout << temp.priority << ". " << temp.name << endl;

		} else if (temp.priority == 3) {
			
			//temp.priority = 3;
			temp.name = "Run prioritized App command";
			insertHeap(heap, last, temp);
//			deleteHeap(heap, last, temp);
			cout << temp.priority << ". " << temp.name << endl;

		} else if (temp.priority == 4) {

			//temp.priority = 4;
			temp.name = "Run standard App command";
			insertHeap(heap, last, temp);
//			deleteHeap(heap, last, temp);
			cout << temp.priority << ". " << temp.name << endl;

		} else {

			//temp.priority = 5;
			temp.name = "Run background command";
			insertHeap(heap, last, temp);
//			deleteHeap(heap, last, temp);
			cout << temp.priority << ". " << temp.name << endl;
			
		}
		
		int choice = 0;
		cout << endl << "An operating system operation has been randomly selected above. Please choose one of the following commands: " <<
		endl << endl << "1. Execute an instruction" << endl << "2. Continue holding" 
		<< endl << "3. Send an interrupt service routine" << endl; 
		
		cin >> choice;
		
		if (choice == 1) {
			
			deleteHeap(heap, last, temp);
			cout << temp.priority << ". " << temp.name << endl;
			cout << "You have just added a command to the list, adding a new node to the heap: " << endl;
			
		} else if (choice == 2) {
			
			cout << endl << "You have chosen to hold. The next randomly generated operation is below: " << endl;
		
		} else {
			
			temp.priority = 0;
			temp.name = "Send an interrupt service routine";
		    insertHeap(heap, last, temp);
			cout << temp.name << endl;
			cout << endl << "These are the commands (nodes) you added to the heap after selecting option 1: " << endl;

			while (last >= 0) {    //iterate through the array and delete the whole heap at the root
				
				deleteHeap(heap, last, temp);
				cout << temp.priority << ". " << temp.name << endl;
				
			} 
			cout << endl << "Thank you for making your choices. End of program." << endl;
			return 0;
		}
		
	}

	return 0;
}