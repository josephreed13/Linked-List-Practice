// Joseph Reed
// student.cpp
// class member function definitions

#include "student.h"
using namespace std;

Student::Student() {
	head = NULL;
}

Student::~Student() {}

void Student::insertNode(int studentId, string studentName, string studentAddress, double studentGpa) {
	studentNode *newNode;
	studentNode *nodePtr;
	studentNode *previousNode = NULL;

	newNode = new studentNode;
	newNode->id = studentId;
	newNode->name = studentName;
	newNode->address = studentAddress;
	newNode->gpa = studentGpa;

	if(!head) {
		head = newNode;
		newNode->next = NULL;
	}
	else {
		nodePtr = head;
		previousNode = NULL;

		while(nodePtr != NULL && nodePtr->id < studentId) {
			previousNode = nodePtr;
			nodePtr = nodePtr->next;
		}

		if(previousNode == NULL) {
			head = newNode;
			newNode->next = nodePtr;
		}
		else {
			previousNode->next = newNode;
			newNode->next = nodePtr;
		}
	}
}

void Student::deleteNode(int studentId) {
	studentNode *nodePtr; //moves through list
	studentNode *previousNode;

	if(!head)
		return;

	if (head->id == studentId) {
		nodePtr = head->next;
		delete head;
		head = nodePtr;
	}
	else {
		nodePtr = head;

		while(nodePtr != NULL && nodePtr->id != studentId) {
			previousNode = nodePtr;
			nodePtr = nodePtr->next;
		}

		if(nodePtr) {
			previousNode->next = nodePtr->next;
			delete nodePtr;
		}
	}
}

void Student::appendNode(int studentId, string studentName, string studentAddress, double studentGpa) {
	studentNode *newNode; //points to new node
	studentNode *nodePtr; //moves through list

	// allocate new node and set values
	newNode = new studentNode;
	newNode->id = studentId;
	newNode->name = studentName;
	newNode->address = studentAddress;
	newNode->gpa = studentGpa;
	newNode->next = NULL;

	if (!head)
		head = newNode;
	else {
		nodePtr = head;

		while(nodePtr->next)
			nodePtr = nodePtr->next;

		nodePtr->next = newNode;
	}
}

void Student::displayList() {
	studentNode *nodePtr; // moves through the list

	nodePtr = head;

	while(nodePtr) {
		cout << nodePtr->id << " ";
		cout << nodePtr->name << " ";
		cout << nodePtr->address << " ";
		cout << nodePtr->gpa << endl;
		
		nodePtr = nodePtr->next;
	}
}

void Student::getRecord(int studentId, int &i, string &n, string &a, double &g) {
	studentNode *nodePtr; //moves through list
	
	if(!head)
		return;

	if (head->id == studentId) {
		i = head->id;
		n = head->name;
		a = head->address;
		g = head->gpa;
	}
	else {
		nodePtr = head;
		while(nodePtr->next) {
			nodePtr = nodePtr->next;
			if(nodePtr->id == studentId) {
				i = nodePtr->id;
				n = nodePtr->name;
				a = nodePtr->address;
				g = nodePtr->gpa;
			}
		}
	}
}


DynIntStack::~DynIntStack() {
	StackNode *nodePtr = NULL, *nextNode = NULL;
	nodePtr = top;

	while(nodePtr != NULL) {
		nextNode = nodePtr->next;
		delete nodePtr;
		nodePtr = nextNode;
	}
}


void DynIntStack::push(int studentId, string studentName, string studentAddress, double studentGpa) {
	StackNode *newNode = NULL;

	newNode = new StackNode;
	newNode->idNum = studentId;
	newNode->sName = studentName;
	newNode->sAddress = studentAddress;
	newNode->sGrade = studentGpa;


	if(isEmpty()) {
		top = newNode;
		newNode->next = NULL;
	} 
	else {
		newNode->next = top;
		top = newNode;
	}
}

void DynIntStack::pop(int &num, string &name, string &address, double &grade) {
	StackNode *temp = NULL; //temporary pointer

	if(isEmpty()) {
		cout << "the stack is empty\n";
	}
	else {
		num = top->idNum;
		name = top->sName;
		address = top->sAddress;
		grade = top->sGrade;
		temp = top->next;
		delete top;
		top = temp;
	}
}

bool DynIntStack::isEmpty() {
	bool status;
	if (!top)
		status = true;
	else 
		status = false;

	return status;
}