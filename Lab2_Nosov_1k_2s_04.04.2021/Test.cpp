#define BOOST_TEST_MODULE mytests
#define ITEMS_COUNT 10
#include <boost/test/included/unit_test.hpp>

#include "DynamicArray.h"
#include "ArraySequence.h"
#include "LinkedListSequence.h"
#include "Queque.h"
#include "MyComplex.h"

complex mupFuncComplex(complex a)
{
	return a * a;
}

bool whereFunc(complex a)
{
	return (a * a == a / a);
}
BOOST_AUTO_TEST_CASE(testDynamicArray)
{
	char arr[ITEMS_COUNT] = { 0 };

	for (int i = 0; i < ITEMS_COUNT; i++)
	{
		arr[i] = i+40;
	}
	DynamicArray<char> DynArr1(arr, ITEMS_COUNT);
	DynamicArray<char> DynArr2(ITEMS_COUNT);
	DynamicArray<char> DynArr3(DynArr1);
	// Test for ResizeRight
	DynArr1.ResizeRight(11);
	BOOST_CHECK(DynArr1.GetSize()==11);
	BOOST_CHECK(DynArr1.Get(0) == 0);
	int elemSum1 = 0;
	int elemSum2 = 0;
	for (int i = 0; i < 11; i++)
	{
		elemSum1 += DynArr1.Get(i);
	}
	for (int i = 1; i < 11; i++)
	{
		elemSum2 += DynArr1.Get(i);
	}
	BOOST_CHECK(elemSum1 == elemSum2);
}

BOOST_AUTO_TEST_CASE(testArraySequence)
{
	complex complexArr[ITEMS_COUNT];
	complex endIndex(ITEMS_COUNT, ITEMS_COUNT);
	complex add(1, 1);
	int counterJ = 0;
	for (complex i(0, 0); i < endIndex; i += add, counterJ++)
	{
		complexArr[counterJ] = i;
	}
	// ���� ArraySequence()
	ArraySequence<complex>* arrSeq1 = new ArraySequence<complex>;
	ArraySequence<complex>* arrSeq2 = new ArraySequence<complex>;
	// ���� ArraySequence(T* arr, int count)
	ArraySequence<complex>* arrSeq3 = new ArraySequence<complex>(complexArr, ITEMS_COUNT);
	for (int i = 0; i < ITEMS_COUNT; i++)
	{
		BOOST_CHECK(arrSeq3->Get(i) == complexArr[i]);
	}
	// ���� ArraySequence(ArraySequence <T>& list)
	ArraySequence<complex>* arrSeq4 = new ArraySequence<complex>(*arrSeq3);
	for (int i = 0; i < ITEMS_COUNT; i++)
	{
		BOOST_CHECK(arrSeq4->Get(i) == arrSeq3->Get(i));
	}
	// ���� T GetFirst()
	BOOST_CHECK(arrSeq4->GetFirst() == complexArr[0]);
	// ���� T GetLast()
	BOOST_CHECK(arrSeq4->GetLast() == complexArr[ITEMS_COUNT-1]);
	// ���� T Get(int index)
	for (int i = 0; i < ITEMS_COUNT; i++)
	{
		BOOST_CHECK(arrSeq4->Get(i) == arrSeq3->Get(i));
	}
	// ���� ArraySequence<T>* GetSubsequence(int startIndex, int endIndex)
	delete arrSeq1;
	int indexOne = 1;
	int indexTwo = (arrSeq3->GetLength() )/ 2;
	int difOneTwo = indexTwo - indexOne;
	arrSeq1 = arrSeq3->GetSubsequence(indexOne, indexTwo);
	for (int i = 0; i < difOneTwo; i++)
	{
		BOOST_CHECK(arrSeq1->Get(i) == arrSeq3->Get(i+ indexOne));
	}
	// ���� GetLength()
	BOOST_CHECK(arrSeq3->GetLength() == ITEMS_COUNT);
	// ���� Set(int index, T value)
	arrSeq3->Set(0, arrSeq3->GetLast());
	BOOST_CHECK(arrSeq3->GetFirst() == arrSeq3->GetLast());
	// ���� void Append(T item)
	arrSeq3->Append(arrSeq3->GetFirst());
	BOOST_CHECK(arrSeq3->Get(ITEMS_COUNT) == arrSeq3->GetFirst());
	// ���� Prepend(T item)
	arrSeq3->Prepend(arrSeq3->GetFirst());
	BOOST_CHECK(arrSeq3->Get(0) == arrSeq3->GetFirst());
	// ���� void InsertAt(T item, int index)
	int lenghtInsert = arrSeq3->GetLength();
	complex elemInsert = arrSeq3->GetLast() + arrSeq3->GetFirst();
	complex elem0 = arrSeq3->GetFirst();
	complex elem1 = arrSeq3->Get(1);
	arrSeq3->InsertAt(elemInsert, 0);
	BOOST_CHECK(lenghtInsert + 1 == arrSeq3->GetLength());
	BOOST_CHECK(arrSeq3->GetFirst() == elem0);
	BOOST_CHECK(arrSeq3->Get(1) == elemInsert);
	BOOST_CHECK(arrSeq3->Get(2) == elem1);
	// ���� 

	// ���� 

	// ���� 

	// ���� 
}

BOOST_AUTO_TEST_CASE(testLinkedListSequence)
{
	LinkedListSequence<complex>* LinListSeq1 = new LinkedListSequence<complex>;
}

BOOST_AUTO_TEST_CASE(testQueue)
{
	complex complexArr[ITEMS_COUNT];
	complex endIndex(ITEMS_COUNT, ITEMS_COUNT);
	complex add(1, 1);
	int counterJ = 0;
	for (complex i(0,0); i<endIndex; i+=add, counterJ++)
	{
		complexArr[counterJ] = i;
	}
	// Queue()
	// �������� 5 que � ������ �������������
	Queue<complex>* que1 = new Queue<complex>;
	Queue<complex>* que2 = new Queue<complex>;
	Queue<complex>* que3 = new Queue<complex>;
	Queue<complex>* que4 = new Queue<complex>;
	Queue<complex>* que5 = new Queue<complex>;
	// ������������� que1 �������� push
	for (int i = 0; i < ITEMS_COUNT; i++)
	{
		que1->push(complexArr[i]);
	}
	for (int i = 0; i < ITEMS_COUNT; i++)
	{
		BOOST_CHECK(que1->Peek(i) == complexArr[i]);
	}
	// �������� que6 �� ������������ �����������
	Queue<complex>* que6 = new Queue<complex>(*que1);
	for (int i = 0; i < ITEMS_COUNT; i++)
	{
		BOOST_CHECK(que6->Peek(i) == que1->Peek(i));
	}
	// �������� Peek()
	for (int i = 0; i < ITEMS_COUNT; i++)
	{
		BOOST_CHECK(que1->Peek(i) == complexArr[i]);
	}
	// �������� Pop()
	BOOST_CHECK(que1->pop() == complexArr[0]);
	BOOST_CHECK(que1->Peek(0) == complexArr[1]);
	// �������� Size()
	BOOST_CHECK(que1->Size()==ITEMS_COUNT-1);
	// �������� isEmpty()
	BOOST_CHECK(que2->isEmpty());
	BOOST_CHECK(!(que1->isEmpty()));
	// �������� map(T mupFunc(T arg))
	que6->map(mupFuncComplex);
	for (int i = 0; i < ITEMS_COUNT; i++)
	{
		BOOST_CHECK(que6->Peek(i) == complexArr[i]* complexArr[i]);
	}
	// �������� wwhere(bool(*whereFunc)(T))
	int countRetTrueData = 0;
	for (int i = 0; i < ITEMS_COUNT; i++)
	{
		if (whereFunc(que6->Peek(i))) countRetTrueData++;
	}
	que6->wwhere(whereFunc);
	BOOST_CHECK(que6->Size() == countRetTrueData);
	// �������� Concat(Queue<T>& que2)
	int sizeQ1PlusQ6 = que1->Size() + que6->Size();
	que1 = que1->Concat(*que6);
	BOOST_CHECK(que1->Size() == sizeQ1PlusQ6);
	// �������� GetSubsequence(int startIndex, int endIndex)
	int startIndexInt = 1;
	int endIndexInt = (que1->Size()) / 2;
	que2 = que1->GetSubsequence(startIndexInt, endIndexInt);
	for (int i = 0; i < endIndexInt - startIndexInt; i++)
	{
		BOOST_CHECK(que2->Peek(i) == que1->Peek(i+ startIndexInt));
	}
	// �������� SubSequenceSearch(Queue<T>& que)
	BOOST_CHECK(que1->SubSequenceSearch(*que2));
}