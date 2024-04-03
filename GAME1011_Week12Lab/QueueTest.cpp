#include <iostream>
#include "QueueArray.h"
using namespace std;

//int main()
//{
//	cout << "Queue using QueueArray Class" << endl << endl;
//
//	Queue<int> qQueue(5);
//
//	qQueue.push(101);
//	qQueue.push(501);
//	qQueue.push(201);
//	qQueue.push(301);
//	qQueue.push(401);
//	qQueue.push(901); // should call expand here
//	qQueue.pop();
//	qQueue.pop();
//	// final queue 201, 301, 401, 901
//
//	cout << "Contents of the Queue: ";
//	while (!qQueue.isEmpty())
//	{
//		cout << " " << qQueue.front();
//		qQueue.pop();
//	}
//	cout << endl << endl;
//}