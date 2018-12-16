
#include <iostream>
#include <string>

using namespace std;

struct Student
{
	int id;
	string name;
	float avg;
};


struct Node {
	Student student;
	Node *next;
};

Node* createLinkedListFromArray(Student studentList[], int size)
{
	Node *head = NULL;
	Node *tail = NULL;
	Node *node = NULL;

	for (int i=0; i < size; i++)
	{
		node = new Node;
		node->student = studentList[i];
		node->next = NULL;

		if (head == NULL)
		{
			head = node;
			tail = node;
		}
		else
		{
			tail->next = node;
			tail = tail->next;
		}
	}
	return head;
}

void showLinkedList(Node* head)
{
	Student st;
	cout << "link list: " << endl;
	while (head != NULL)
	{
		st = head->student;
		cout << "id: " << st.id << "\t\t name:" << st.name << "\t\tavg: " << st.avg << endl;
		head = head->next;
	}
}

struct Stack {
	Student student;
	Stack *prev;
};

Stack* createStackFromArray(Student studentList[], int size)
{
	Stack *lastNode = NULL;
	Stack *node = NULL;

	for (int i=0; i < size; i++)
	{
		node = new Stack;
		node->student = studentList[i];
		node->prev = NULL;

		if (lastNode == NULL)
		{
			lastNode = node;
			//tail = node;
		}
		else
		{
			node->prev = lastNode;
			lastNode = node;
		}
	}
	return lastNode;
}

void showStack(Stack* lastNode)
{
	Student st;
	cout << "Stack list: " << endl;
	while (lastNode != NULL)
	{
		st = lastNode->student;
		cout << "id: " << st.id << "\t\t name:" << st.name << "\t\tavg: " << st.avg << endl;
		lastNode = lastNode->prev;
	}
}

int main()
{

	Student studentList[3];

	studentList[0].id = 1;
	studentList[0].name = "ali";
	studentList[0].avg = 17;

	studentList[1].id = 2;
	studentList[1].name = "hasan";
	studentList[1].avg = 14;

	studentList[2].id = 3;
	studentList[2].name = "mehdi";
	studentList[2].avg = 19;

	cout << "0 for link list and 1 for stack: ";
	int n;
	cin >> n;
	if (n == 0)
	{
		Node* head = createLinkedListFromArray(studentList, 3);
		showLinkedList(head);
	}
	else 
	{
		Stack* last = createStackFromArray(studentList, 3);
		showStack(last);
	}

	return 0;
}