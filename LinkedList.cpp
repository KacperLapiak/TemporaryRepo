#include <iostream>
#include <string>

using namespace std;

struct Element
{
public:
	int key_ = NULL;
	string data_ = "";
	Element* next_ = nullptr;

	Element() { }
	explicit Element(int key)
	{
		key_ = key;
		data_ = "key= " + to_string(key_);
		next_ = nullptr;
	}
};

class LinkedList
{
private:
	Element* head_;

public:
	~LinkedList()
	{
		delete head_;
	}

	void Insert(int key)
	{
		Element* element = new Element(key);
		element->next_ = head_;
		head_ = element;
	}
	Element* Search(int key)
	{
		Element* temp = head_;
		while (temp->next_ && temp->key_ != key)
		{
			temp = temp->next_;
		}

		return temp;
	}
	Element* SearchPrevious(int key)
	{
		Element* temp = head_;
		Element* tempPrev = nullptr;
		if (head_->key_ != key)
		{
			while (temp->next_ && temp->key_ != key)
			{
				tempPrev = temp;
				temp = temp->next_;
			}

			return tempPrev;
		}
		else
		{
			tempPrev = head_;
			return tempPrev;
		}
	}
	void Delete(int key)
	{
		Element* tempCurr = Search(key);
		Element* tempPrev = SearchPrevious(key);
		if (tempPrev->key_ == head_->key_)
		{
			Element* temp = head_;
			head_ = head_->next_;
			delete temp;
		}
		else
		{
			tempPrev->next_ = tempCurr->next_;
			delete tempCurr;
		}
	}
	void ShowList()
	{
		Element* temp = head_;
		while (temp->next_)
		{
			cout << temp->key_ << " " << temp->data_ << " | ";
			temp = temp->next_;
		}
		cout << temp->key_ << " " << temp->data_ << " | ";
	}
};

int main()
{
	LinkedList list;
	list.Insert(1);
	list.Insert(2);
	list.Insert(3);
	list.Insert(4);
	list.Insert(5);
	list.ShowList();

	Element* elOne = list.Search(5);
	cout << "\n\nkey: " << elOne->key_ << "\ndata: " << elOne->data_;

	Element* elTwo = list.Search(2);
	cout << "\n\nkey: " << elTwo->key_ << "\ndata: " << elTwo->data_ << "\n\n";

	list.Delete(5);
	list.ShowList();

	cin.get();
}