#include <iostream>
using namespace std;

struct Node
{
	int data;
	Node* next;
};

struct Queue
{
	Node* front;
	Node* back;
	int size;
	void init()
	{
		front = nullptr;
		back = nullptr;
		size = 0;
	}
};

void push(Queue*& queue, int data)
{
	Node* tmp = new Node;
	tmp->data = data;
	tmp->next = nullptr;
	if (queue->size == 0)
	{
		queue->front = tmp;
		queue->back = tmp;
	}
	else
	{
		queue->back->next = tmp;
		queue->back = tmp;
	}
	queue->size++;
}

void pop(Queue*& queue)
{
	if (queue->size == 0)
	{
		return;
	}
	queue->front = queue->front->next;
	queue->size--;
}
void insert_element(Queue*& queue, int pos, int data)
{
	Queue* tmp = new Queue;
	tmp->init();
	for (int i = 1; i < pos; i++)
	{
		push(tmp, queue->front->data);
		pop(queue);
	}
	push(tmp, data);
	int init_size = queue->size;
	for (int i = 0; i < init_size; i++)
	{
		push(tmp, queue->front->data);
		pop(queue);
	}
	queue=tmp;
}
void insert_elements(Queue*& queue, int pos, int k)
{
	Queue* tmp = new Queue;
	tmp->init();
	int data;
	cout << "Ââåäèòå ýëåìåíòû, êîòîðûå õîòèòå äîáàâèòü: ";
	for (int i = 1; i < pos; i++)
	{
		push(tmp, queue->front->data);
		pop(queue);
	}
	for (int i = 0; i < k; i++)
	{
		cin >> data;
		push(tmp, data);
	}
	int init_size = queue->size;
	for (int i = 0; i < init_size; i++)
	{
		push(tmp, queue->front->data);
		pop(queue);
	}
	queue=tmp;
}
void delete_element(Queue*& queue, int pos)
{
	Queue* tmp = new Queue;
	tmp->init();
	for (int i = 1; i < pos; i++)
	{
		push(tmp, queue->front->data);
		pop(queue);
	}
	pop(queue);
	int init_size = queue->size;
	for (int i = 0; i < init_size; i++)
	{
		push(tmp, queue->front->data);
		pop(queue);
	}
	queue=tmp;
}

void delete_elements(Queue*& queue, int pos, int k)
{
	Queue* tmp = new Queue;
	tmp->init();
	for (int i = 1; i < pos; i++)
	{
		push(tmp, queue->front->data);
		pop(queue);
	}
	for (int i = 0; i < k; i++)
	{
		pop(queue);
	}
	int init_size = queue->size;
	for (int i = 0; i < init_size; i++)
	{
		push(tmp, queue->front->data);
		pop(queue);
	}
	queue=tmp;
}

void search_element(Queue*& queue, int element)
{
	Queue* curr = new Queue;
	curr->init();
	while (queue->front != nullptr && queue->back !=nullptr)
	{
		if (queue->front->data == element)
		{
			cout << "Ýëåìåíò íàéäåí" << endl;
			return;
		}
		else
		{
			push(curr, queue->front->data);
			pop(queue);
		}
	}
	cout << "Ýëåìåíò íå íàéäåí" << endl;
}

Queue* createQueue(int n)
{
	Queue* queue = new Queue;
	queue->init();
	int data;
	for (int i = 0; i < n; i++)
	{
		cin >> data;
		push(queue, data);
	}
	return queue;
}

void printQueue(Queue*& queue)
{
	Node* curr = new Node;
	curr = queue->front;
	for (int i = 0; i < queue->size; i++)
	{
		cout << curr->data << ' ';
		curr = curr->next;
	}
	cout << endl;
}

int main()
{
	setlocale(LC_ALL, "RUS");
	int size, data, pos, k, element;
	cout << "Ââåäèòå ðàçìåð î÷åðåäè: ";
	cin >> size;
	cout << "Ââåäèòå ýëåìåíòû î÷åðåäè" << endl;
	Queue* queue = createQueue(size);
	cout << "Âûâîä î÷åðåäè" << endl;
	printQueue(queue);
	cout << "Ââåäèòå ýëåìåíò, êîòîðûé õîòèòå äîáàâèòü: ";
	cin >> data;
	push(queue, data);
	cout << "Âûâîä î÷åðåäè" << endl;
	printQueue(queue);
	pop(queue);
	cout << "Âûâîä î÷åðåäè" << endl;
	printQueue(queue);
	cout << "Ââåäèòå ýëåìåíò è ïîçèöèþ êóäà õîòèòå äîáàâèòü ýòîò ýëåìåíò: ";
	cin >> data;
	cin >> pos;
	insert_element(queue, pos, data);
	cout << "Âûâîä î÷åðåäè" << endl;
	printQueue(queue);
	cout << "Ââåäèòå êîëè÷åñòâî ýëåìåíòîâ è ïîçèöèþ, êóäà õîòèòå äîáàâèòü: ";
	cin >> k;
	cin >> pos;
	insert_elements(queue, pos, k);
	cout << "Âûâîä î÷åðåäè" << endl;
	printQueue(queue);
	cout << "Ââåäèòå ïîçèöèþ îòêóäà õîòèòå óäàëèòü ýëåìåíò: ";
	cin >> pos;
	delete_element(queue, pos);
	cout << "Âûâîä î÷åðåäè" << endl;
	printQueue(queue);
	cout << "Ââåäèòå êîëè÷åñòâî ýëåìåíòîâ è ïîçèöèþ, îòêóäà õîòèòå óäàëèòü: ";
	cin >> k;
	cin >> pos;
	delete_elements(queue, pos, k);
	cout << "Âûâîä î÷åðåäè" << endl;
	printQueue(queue);
	cout << "Ââåäèòå ýëåìåíò, êîòîðûé õîòèòå íàéòè: ";
	cin >> element;
	search_element(queue, element);
	return 0;
}