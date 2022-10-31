#include<iostream>
#include<assert.h>
#include<queue>
#include<vector>
using namespace std;
//Worker id, name, surname, age, pageCount
//WorkerQueue
//Printer workerQueue
//start - 
//Printer clasinin ichinde workerQueue saxlanilmalidir
//ve printer in start methodu chagrilan kimi
//novbede olan ishchilerin kagizlari ksersks olsun
//kserks emeliyyati bitenden sonra ishci siradan dequeue olunsun
//novbe boshalana qeder bu proses davam etmelidir

//Worker
//WorkerQueue = >
//Printer = > WorkerQueue obj.start()

class Student {
public:
	string name; 
	string surname; 
	double avg;
	Student() {
		name = "";
		avg = 0;
	}
	Student(string name, double avg) {
		this->name = name;
		this->avg = avg;
	}

	//operator >
	bool operator>(const Student& obj) {
		return avg > obj.avg;
	}
	//operator<<
	friend ostream& operator<<(ostream& out, const Student& obj) {
		out << obj.name << " " << obj.avg << endl;
		return out;
	}
};
template<class T>
class PriorityQueue {
	T* arr;
	int capacity;
	int count;
	int rear;

	int GetMaxIndex() {
		int maxIndex = 0;
		for (int i = 0; i < count; i++)
		{
			if (arr[i] > arr[maxIndex]) {
				maxIndex = i;
			}
		}
		return maxIndex;
	}
	public:
		PriorityQueue(int size) {
			arr = new T[size];
			capacity = size;
			count = 0;
			rear = -1;
		}

		bool IsFull()const { return capacity == count; }
		bool IsEmpty()const { return 0 == count; }

		void Push(T value) {
			assert(!IsFull());
			arr[++rear] = value;
			count++;
		}

		void Pop() {
			assert(!IsEmpty());
			int index = GetMaxIndex();

			for (int i = 0; i < count - 1; i++)
			{
				arr[i] = arr[i + 1];
			}count--;
		}

		void Print() {
			for (int i = 0; i < count; i++)
			{
				cout << arr[i] << " ";
			}cout << endl;
		}

		~PriorityQueue() {
			delete[]arr;
		}
};

void main() {
	PriorityQueue<Student>pq(4);
	pq.Push(Student("Madina", 3));
	pq.Push(Student("Nargiz", 3.6));
	pq.Push(Student("Cahangir",9));
	pq.Push(Student("Yasemen", 5.6));

	pq.Print();
	cout << "***********************\n";
	pq.Pop();
	pq.Print();
	cout << "***********************\n";
	pq.Pop();
	pq.Print();
	cout << "***********************\n";
}




















