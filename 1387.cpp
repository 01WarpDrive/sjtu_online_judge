// the construction of huffman
#include <iostream>
#include <limits.h>

using namespace std;

struct HuffmanNode
{
	int height = 0;
	long long weight = 0;;
	int parent = 0;;
	int left = 0, right = 0;
};

int minIndex(HuffmanNode Bt[], int k, int m)
{
	int i, min = 0;
	long long minWeight = LLONG_MAX;

	for (i = m - 1; i > k; i--)
	{
		if (Bt[i].parent == 0 && Bt[i].weight < minWeight)
		{
			min = i;
			minWeight = Bt[min].weight;
		}
	}

	return min;
}

HuffmanNode* BestBinaryTree(int* w, int n)
{
	HuffmanNode* BBTree;
	int first_min, second_min;
	int m = n * 2;
	int i, j;
	BBTree = new HuffmanNode[m];

	for (j = 0; j < n; j++)
	{
		i = m - 1 - j;
		BBTree[i].weight = w[j];
		BBTree[i].parent = 0;
		BBTree[i].left = 0;
		BBTree[i].right = 0;
	}


	i = n - 1;
	while (i != 0)
	{
		first_min = minIndex(BBTree, i, m);
		BBTree[first_min].parent = i;
		second_min = minIndex(BBTree, i, m);
		BBTree[second_min].parent = i;

		BBTree[i].weight = BBTree[first_min].weight + BBTree[second_min].weight;
		BBTree[i].parent = 0;
		BBTree[i].left = first_min;
		BBTree[i].right = second_min;
		i--;
	}

	for (int i = 1; i < n; i++)
	{
		int left = BBTree[i].left;
		int right = BBTree[i].right;

		BBTree[left].height = BBTree[i].height + 1;
		BBTree[right].height = BBTree[i].height + 1;
	}

	return BBTree;
}

int main()
{
	int N;
	cin >> N;
	int* list = new int[N];

	for (int i = 0; i < N; i++)
	{
		cin >> list[i];
	}


	HuffmanNode* BBtree = BestBinaryTree(list, N);

	long long sum = 0;
	for (int i = N; i < 2 * N; i++)
	{
		sum += BBtree[i].height * BBtree[i].weight;
	}
	cout << sum;

	delete[] list;
	return 0;
}