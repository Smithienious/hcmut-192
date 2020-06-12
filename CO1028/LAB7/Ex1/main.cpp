#include <iostream>
#include <fstream>
using namespace std;

ifstream ifs;

struct node
{
	int data;
	node *next;
};

node *createLinkList(int n)
{
	node *head = new node;
	node *current = head;
	int dat = 0;

	for (int i = 0; i < n; i += 1)
	{
		ifs >> dat;
		current->data = dat;
		if (i != n - 1)
		{
			node *next = new node;
			current->next = next;
			current = next;
		}
		else
			current->next = nullptr;
	}

	return head;
}

void print(node *head)
{
	while (head != nullptr)
	{
		cout << head->data << endl;
		head = head->next;
	}
}

int main(int argc, char **argv)
{
	ifs.open(argv[1]);

	int n = 0;
	ifs >> n;
	if (n > 0)
	{
		node *head = createLinkList(n);
		print(head);
	}
	else
	{
		cout << "Invalid n" << endl;
	}

	ifs.close();
	return 0;
}
