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

bool isEqual(node *head1, node *head2)
{
	node *current1 = head1, *current2 = head2;
	int result = 1, num1 = 0, num2 = 0;

	while (current1 != nullptr)
	{
		num1 += 1;
		current1 = current1->next;
	}
	while (current2 != nullptr)
	{
		num2 += 1;
		current2 = current2->next;
	}

	if (num1 != num2)
		result = 0;

	current1 = head1;
	current2 = head2;
	while (result && current1 != nullptr && current2 != nullptr)
	{
		if (current1->data != current2->data)
			result = 0;

		current1 = current1->next;
		current2 = current2->next;
	}

	return result;
}

int main(int argc, char **argv)
{
	ifs.open(argv[1]);

	int n = 0;
	ifs >> n;
	if (n <= 0)
	{
		cout << "Invalid n" << endl;
		return 0;
	}
	node *head1 = createLinkList(n);

	int m = 0;
	ifs >> m;
	if (m <= 0)
	{
		cout << "Invalid m" << endl;
		return 0;
	}
	node *head2 = createLinkList(m);

	cout << isEqual(head1, head2) << endl;

	ifs.close();
	return 0;
}
