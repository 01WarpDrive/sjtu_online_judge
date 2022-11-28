//11051
#include<iostream>
#include<unordered_map>
#include<string>
#include<vector>


using namespace std;

struct LinkNode
{
	string value = "";
	LinkNode* next = nullptr;
};

void Clear(LinkNode* head)
{
	LinkNode* temp;
	while (head->next)
	{
		temp = head->next;
		head->next = temp->next;
		delete temp;
	}
	delete head;
}


int main()
{
	int n;
	string num;
	cin >> n;
	unordered_map<string, int> hash;
	for (int i = 0; i < n; i++)
	{
		cin >> num;
		if (hash[num])
		{
			continue;
		}
		hash[num] = i + 1;
	}

	int m;
	int count = 0;
	int index = 0;

	LinkNode *head, *p, *q;
	head = new LinkNode;
	q = head;

	cin >> m;
	for (int j = 0; j < m; j++)
	{
		cin >> num;
		if (hash[num]) {
			index = hash[num];
		}
		else {
			count += n;
			continue;
		}
		
		if (index < 0)
		{
			q = head;
			count += 1;
			while (q->next->value != num)
			{
				count += 1;
				q = q->next;
			}

			p = q->next;
			q->next = p->next;
			p->next = head->next;
			head->next = p;
		}
		else
		{
			q = head;
			while (q->next)
			{
				q = q->next;
				if (abs(hash[q->value]) > index)
				{
					count += 1;
				}
			}
			count += index;

			p = new LinkNode;
			p->value = num;
			p->next = head->next;
			head->next = p;

			hash[num] = -index;
		}
	}

	Clear(head);
	cout << count << endl;

	return 0;
}