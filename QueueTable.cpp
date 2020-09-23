#include <iostream>

using namespace std;

class QueueTable
{
private:
	int queue_[5]{};
	int head_ = 0;
	int tail_ = 0;
	int size_ = 0;

public:
	int Size() 
	{ 
		return size_; 
	}
	void Enqueue(int value)
	{
		if (head_ == tail_ + 1 || (head_ == 0 && tail_ == size(queue_) - 1))
		{
			cout << "queue is full" << endl;
			return;
		}

		queue_[tail_] = value;
		if (tail_ == size(queue_)-1)
		{
			tail_ = 0;
		}
		else
		{
			tail_++;
		}

		size_++;
	}
	int Dequeue()
	{
		if (head_ == tail_)
		{
			cout << "queue is empty" << endl;
			return 0;
		}
		else
		{
			int buffer = queue_[head_];
			if (head_ == size(queue_) - 1)
			{
				head_ = 0;
			}
			else
			{
				head_++;
			}

			size_--;
			return buffer;
		}
	}
};

int main()
{
	QueueTable queue;

	queue.Enqueue(1);
	queue.Enqueue(2);
	queue.Enqueue(3);
	queue.Enqueue(4);
	queue.Enqueue(5); // overflow error
	cout << "size: " << queue.Size() << "\n";

	cout << queue.Dequeue() << "\n";
	cout << queue.Dequeue() << "\n";
	queue.Enqueue(6);
	queue.Enqueue(7);
	cout << queue.Dequeue() << "\n";
	cout << queue.Dequeue() << "\n";
	cout << queue.Dequeue() << "\n";
	cout << queue.Dequeue() << "\n";
	cout << queue.Dequeue() << "\n"; // underflow error
	cout << "size: " << queue.Size() << "\n";

	cin.get();
}