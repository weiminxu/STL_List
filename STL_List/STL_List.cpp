//list is double linked list
//insert, delete data from begin, middle and end
//sort and re-sort
//only use iterator, do not use index, list is linked list, it is not array.
//vector and deque are array

#include <iostream>
#include <list>

using namespace std;

void PrintListContents(const list<int>& listInput);

int main()
{
	list<int> a;
	list<int> b;

	b.push_back(0);
	b.push_back(1);
	b.push_back(2);
	b.push_back(3);

	PrintListContents(b);

	a.push_front(10);
	a.push_front(2001);
	a.push_front(1);
	a.push_front(9999);

	a.push_back(-1);
	a.push_back(-2);
	a.push_back(-3);
	a.push_back(-4);
	
	a.insert(a.begin(), 1000000);
	a.insert(a.end(), 4, -10000);

	std::list<int>::iterator iter1 = a.begin();
	++iter1;
	a.insert(iter1, 0);
	++iter1;
	a.insert(iter1, 0);

	std::list<int>::iterator iter;

	for (iter = a.begin(); iter != a.end(); ++iter)
	{
		size_t offset = distance(a.begin(), iter);
		cout <<"a["<<offset<<"]= "<< *iter << endl;
	}

	list<int>::iterator iElementValueTwo;
	iElementValueTwo = a.insert(a.begin(), b.begin(), b.end());
	//a.insert(iter, ++b.begin(), --b.end());
	PrintListContents(a);
	cout << endl << endl;

	//a.erase(a.begin(), iElementValueTwo);//from [0~iElementValueTwo) all were delete
	a.erase(iElementValueTwo, a.end());//from [iEmentValueTwo, a.end) all were delete
	//a.erase(iElementValueTwo);//only iElementValueTwo was delete
	cout << "result: ";
	PrintListContents(a);


}

void PrintListContents(const list<int>& listInput)
{
	std::list<int>::const_iterator iter;

	for (iter = listInput.begin(); iter != listInput.end(); ++iter)
	{
		cout << *iter << endl;
	}

}