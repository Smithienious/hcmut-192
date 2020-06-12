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

node *insertNode(node *head, node *newNode, int position)
{
	if (position < 1)
	{
	}
	else if (position == 1)
	{
		newNode->next = head;
		head = newNode;
	}
	else
	{
		node *current = head;
		node *prev = current;
		int i = 1;
		while (1)
		{
			if (i == position)
			{
				prev->next = newNode;
				newNode->next = current;
				break;
			}
			if (current->next == nullptr)
			{
				newNode->next = nullptr;
				current->next = newNode;
				break;
			}

			prev = current;
			current = current->next;
			i += 1;
		}
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

		node *newNode = new node();
		ifs >> newNode->data;
		int position = 0;
		ifs >> position;
		head = insertNode(head, newNode, position);

		print(head);
	}
	else
	{
		cout << "Invalid n" << endl;
	}

	ifs.close();
	return 0;
}
