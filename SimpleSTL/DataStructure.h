#pragma once
#include <iostream>
#include <cstdio>

#define OUTOFRANGE std::cerr << "Out Of Range" << std::endl

namespace simpleSTL
{
	/*队列*/
	//typedef double DequeItem;
	template <typename ItemType>
	class DequeNode
	{
	public:
		DequeNode *Next, *Last;
		ItemType Item;
		DequeNode() : Next(0), Last(0) {}
		ItemType &operator *() { return Item; }
		void Copy(const ItemType &item) { Item = item; }
	};

	template <typename DequeItem>
	class Deque
	{
	private:

		DequeNode<DequeItem> *DequeBase;
		size_t _Size;
		void Construct()
		{
			DequeBase = new DequeNode<DequeItem>();
			DequeBase->Last = DequeBase; DequeBase->Next = DequeBase;
			_Size = 0;
		}
		void _Clear()
		{
			DequeNode<DequeItem> *t = DequeBase->Next, *temp = t;
			for (; t != DequeBase; t = t->Next, delete temp, temp = t);
			DequeBase->Last = DequeBase; DequeBase->Next = DequeBase;
			_Size = 0;
		}
		void Copy(const Deque<DequeItem> &deque)
		{
			DequeNode<DequeItem> *t = deque.DequeBase->Last;
			for (size_t i = 0; i < deque.Size(); PushBack(t->Item), t = t->Last, ++i);
		}
	public:
		typedef DequeNode<DequeItem> Iterator;
		Deque()
		{
			Construct();
		}
		Deque(const Deque<DequeItem> &deque)
		{
			Construct();
			Copy(deque);
		}
		void PushFront(const DequeItem &item)
		{
			DequeNode<DequeItem> *temp = new DequeNode<DequeItem>();
			temp->Copy(item);
			temp->Next = DequeBase; temp->Last = DequeBase->Last;
			DequeBase->Last = temp; temp->Last->Next = temp;
			++_Size;
		}
		void PushBack(const DequeItem &item)
		{
			DequeNode<DequeItem> *temp = new DequeNode<DequeItem>();
			temp->Copy(item);
			temp->Last = DequeBase; temp->Next = DequeBase->Next;
			DequeBase->Next = temp; temp->Next->Last = temp;
			++_Size;
		}
		void PopFront()
		{
			if (0 != _Size)
			{
				DequeNode<DequeItem> *temp = DequeBase->Last;
				DequeBase->Last = temp->Last; DequeBase->Last->Next = DequeBase;
				delete temp;
				--_Size;
				return;
			}
			OUTOFRANGE;
		}
		void PopBack()
		{
			if (0 != _Size)
			{
				DequeNode<DequeItem> *temp = DequeBase->Next;
				DequeBase->Next = temp->Next; DequeBase->Next->Last = DequeBase;
				delete temp;
				--_Size;
				return;
			}
			OUTOFRANGE;
		}
		DequeNode<DequeItem> &Front()
		{
			if (0 != _Size)
				return *DequeBase->Last;
			OUTOFRANGE;
		}
		DequeNode<DequeItem> &Back()
		{
			if (0 != _Size)
				return *DequeBase->Next;
			OUTOFRANGE;
		}
		size_t Size() const
		{
			return _Size;
		}
		void Clear()
		{
			_Clear();
		}
		void operator = (const Deque<DequeItem> &Deque)
		{
			_Clear();
			Copy(Deque);
		}
		~Deque()
		{
			_Clear();
			delete DequeBase;
		}
	};

	/*栈*/
	template <typename StackItem>
	class Stack
	{
	private:
		typedef DequeNode<StackItem> StackNode;
		Deque<StackItem> _Deque;
		void Copy(const Stack<StackItem> &stack)
		{
			_Deque = stack._Deque;
		}
		void _Clear()
		{
			_Deque.Clear();
		}
	public:
		typedef StackNode Iterator;

		Stack() {}
		Stack(const Stack<StackItem> &stack) { Copy(stack); }
		void operator = (const Stack<StackItem> &stack) { Copy(stack); }
		void Push(const StackItem &item)
		{
			_Deque.PushBack(item);
		}
		void Pop()
		{
			_Deque.PopBack();
		}
		size_t Size()
		{
			return _Deque.Size();
		}
		StackItem &Top()
		{
			return _Deque.Back().Item;
		}
		void Clear()
		{
			_Clear();
		}
	};

	/*队列*/

	template <typename QueueItem>
	class Queue
	{
	private:
		Deque<QueueItem> _Deque;
		void Copy(const Queue<QueueItem> &queue)
		{
			_Deque = queue._Deque;
		}
		void _Clear()
		{
			_Deque.Clear();
		}
	public:
		Queue() {}
		Queue(const Queue<QueueItem> &queue) { Copy(queue); }
		void operator = (const Queue<QueueItem> &queue) { Copy(queue); }
		void PushFront(const QueueItem &item)
		{
			_Deque.PushFront(item);
		}
		void PopBack()
		{
			_Deque.PopBack();
		}
		size_t Size()
		{
			return _Deque.Size();
		}
		QueueItem &Back()
		{
			return _Deque.Back().Item;
		}
		void Clear()
		{
			_Clear();
		}
	};

	typedef double RBTItem;
	typedef double RBTItem;

#define RBT_RED false
#define RBT_BLACK true

	class RBTNode
	{
	public:
		RBTItem Item;
		size_t Rank;
		bool Flag;
		RBTNode *Left, *Right, *fa;
		RBTNode() : Rank(0), Flag(RBT_RED), Left(0), Right(0), fa(0) {}
		RBTItem &operator * () { return Item; }
		void Copy(const RBTItem &item) { Item = item; }
	};

	class RB_Tree
	{
	public:
		size_t _Size;
		RBTNode *Root;
		void BST_Insert(RBTNode **root, RBTNode *node)
		{
			RBTNode *t = *root, *temp = t;
			while (0 != t)
			{
				temp = t;
				if (t->Item > node->Item) { root = &(t->Left); t = t->Left;  }
				else { root = &(t->Right); t = t->Right; }
			}
			*root = node; node->fa = temp;
		}
		void _LeftRotate(RBTNode *node)
		{

		}
		void _RightRotate(RBTNode *node)
		{

		}
		void _RBT_InsertFixUp(RBTNode *node)
		{

		}
	public:
		RB_Tree() : _Size(0), Root(0){}
		void Insert(const RBTItem &item)
		{
			RBTNode *temp = new RBTNode();
			temp->Copy(item);
			BST_Insert(&Root, temp);
			_RBT_InsertFixUp(temp);
		}
		
	};
}