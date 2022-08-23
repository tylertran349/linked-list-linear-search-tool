#include <iostream>
using namespace std;

class Node {
	public:
		int value;
		Node* next;
};

void insertAtEnd(Node* head, int newValue) {
	Node* newNode = new Node();
	newNode->value = newValue;
	newNode->next = NULL;
	if(head == NULL) {
		head = newNode;
		return;
	}
	Node* currentLastNode = head;
	while(currentLastNode->next != NULL) {
		currentLastNode = currentLastNode->next;
	}
	currentLastNode->next = newNode;
}

void linearSearch(Node* n, int searchValue) {
	int index = 0;
	while(n != NULL) {
		if(n->value == searchValue) {
			cout << searchValue << " is linked list element #" << index << " (the first element is element #0)." << endl;
			return;
		} else {
			index++;
			n = n->next;
		}
	}
	cout << searchValue << " was not found in the linked list." << endl;
}

int main() {
	int newValue;
	string option;
	int searchValue;
	Node* head = new Node();
	cout << "Enter search value: ";
	cin >> searchValue;
	cout << "Write a list of integers separated by spaces below. Write a non-numeric character to end the list (e.g. 1 2 3 4 5 h): " << endl;
	cin >> newValue;
	head->value = newValue;
	while(cin >> newValue) {
		insertAtEnd(head, newValue);
	}
	linearSearch(head, searchValue);
}
