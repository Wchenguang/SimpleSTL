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
		void BST_Insert(RBTNode **root, RBTNode *node)
		{
			RBTNode *t = *root, *temp = t;
			while (0 != t)
			{
				temp = t;
				if (node->Item < t->Item ) { root = &(t->Left); t = t->Left;  }
				else { root = &(t->Right); t = t->Right; }
			}
			*root = node; node->fa = temp;
		}
		void _LeftRotate(RBTNode *y)
		{
			RBTNode *x = y->fa, *yl = y->Left, *yr = y->Right;
			x->Right = y->Left; if (yl) yl->fa = x;
			y->fa = x->fa;
			if (0 == x->fa)
				Root = y;
			else if (x->fa->Right == x)
				x->fa->Right = y;
			else
				x->fa->Left = y;
			y->Left = x; x->fa = y;
		}
		void _RightRotate(RBTNode *y)
		{
			RBTNode *x = y->fa, *yl = y->Left, *yr = y->Right;
			x->Left = y->Right; if (yr) yr->fa = x;
			y->fa = x->fa;
			if (0 == x->fa)
				Root = y;
			else if (x->fa->Right == x)
				x->fa->Right = y;
			else
				x->fa->Left = y;
			y->Right = x; x->fa = y;
		}
		void _RBT_InsertFixUp(RBTNode *node)
		{
			while (0 != node->fa && RBT_RED == node->fa->Flag)
			{
				if (node->fa->fa->Left == node->fa)
				{
					RBTNode *u = node->fa->fa->Right;
					if (RBT_RED == u->Flag)
					{
						node->fa->Flag = RBT_BLACK;
						u->Flag = RBT_BLACK;
						node->fa->fa->Flag = RBT_RED;
						node = node->fa->fa;
					}
					else if (node == node->fa->Right)
					{
						node = node->fa;
						_LeftRotate(node);
					}
					else
					{
						node->fa->Flag = RBT_BLACK;
						node->fa->fa->Flag = RBT_RED;
						_RightRotate(node->fa->fa);
					}
				}
				else
				{
					RBTNode *u = node->fa->fa->Left;
					if (RBT_RED == u->Flag)
					{
						u->Flag = RBT_BLACK;
						node->fa->Flag = RBT_BLACK;
						node->fa->fa->Flag = RBT_RED;
						node = node->fa->fa;
					}
					else if (node == node->fa->Left)
					{
						node = node->fa;
						_RightRotate(node);
					}
					else
					{
						node->fa->fa->Flag = RBT_RED;
						node->fa->Flag = RBT_BLACK;
						_LeftRotate(node->fa->fa);
					}
				}
			}
			Root->Flag = RBT_BLACK;
		}
		void _Clear(RBTNode *root)
		{
			if (root)
			{
				_Clear(root->Left);
				_Clear(root->Right);
				delete root;
			}
		}
		RBTNode *_Search(const RBTItem &item)
		{
			RBTNode *t;
			for (t = Root; t != 0;)
				if (item == t->Item)
					break;
				else if (item < t->Item)
					t = t->Left;
				else
					t = t->Right;
			return t;
		}
	public:
		typedef RBTNode Iterator;
		RBTNode *Root;
		RB_Tree() : _Size(0), Root(0){}
		~RB_Tree() { _Clear(Root); }
		RBTNode &Insert(const RBTItem &item)
		{
			RBTNode *temp = new RBTNode();
			temp->Copy(item);
			BST_Insert(&Root, temp);
			_RBT_InsertFixUp(temp);
			++_Size;
			return *temp;
		}
		RBTNode &Search(const RBTItem &item)
		{
			RBTNode *temp;
			if (0 == (temp = _Search(item)))
				std::cerr << "not found" << std::endl;
			else
				return *temp;
		}
		void Delete(const RBTItem &item)
		{
			RBTNode *temp = _Search(item);
			if (temp)
			{

				return;
			}
			std::cerr<< "not found" << std::endl;
		}
		size_t Size()
		{
			return _Size;
		}
	};
}