#include <iostream>
#include "Datastructure.h"

using namespace std;
using namespace simpleSTL;

class aa
{
public:
	int a;
};

int main()
{
	/*Stack<aa*> s;
	s.Push(new aa());
	s.Push(new aa());
	s.Clear();
	Stack<aa*> ss = s;
	cout << ss.Size();
	ss.Push(new aa());
	cout << ss.Top()->a;
	ss.Clear();*/

	/*Stack s;
	s.Push(3);
	s.Pop();
	s.Push(4);
	s.Push(5);
	cout << s.Size() << endl;
	s.Clear();
	s.Push(44);

	cout << s.Top();

	Stack ss = s;
	Stack sss;
	sss = s;

	sss.Push(444);

	cout << sss.Size();

	sss.Clear();*/


	/*Deque<aa*> l;
	l.PushBack(new aa());
	l.PushFront(new aa());
	cout << (*l.Back())->a << endl;
	cout << (*l.Front())->a << endl;
	cout << l.Size() << endl;

	Deque<aa*> ll = l;

	Deque<aa*> lll;
	lll = l;

	cout << (*ll.Back())->a << endl;
	cout << ll.Size() << endl;

	cout << (*lll.Front())->a << endl;
	cout << lll.Size();

	lll.Clear();
	ll.Clear();
	l.Clear();

	getchar();

	Stack<aa*> s;
	s.Push(new aa());
	cout << s.Top()->a << endl;
	cout << s.Size() << endl;
	s.Pop();
	cout << s.Size() << endl;
	cout << s.Top()->a;

	s.Clear();

	s.Push(new aa());
	cout << s.Top()->a << endl;
	cout << s.Size() << endl;
	s.Pop();
	cout << s.Size() << endl;
	cout << s.Top()->a;

	getchar();
	Queue<aa*> q;
	q.PushFront(new aa());
	q.PushFront(new aa());
	cout << q.Back()->a << endl;
	cout << q.Size() << endl;
	q.PopBack();
	cout << q.Back()->a << endl;
	cout << q.Size() << endl;

	q.Clear();

	q.PushFront(new aa());
	q.PushFront(new aa());
	cout << q.Back()->a << endl;
	cout << q.Size() << endl;
	q.PopBack();
	cout << q.Back()->a << endl;
	cout << q.Size() << endl;*/

	RB_Tree t;
	t.Insert(1);
	t.Insert(2);

	cout << **(t.Root) << endl;
	cout << **(t.Root->Right) << endl;

	getchar();
	return 0;
}