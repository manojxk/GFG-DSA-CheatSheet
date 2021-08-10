/* Program to implement a stack using
two queue */
#include <bits/stdc++.h>

using namespace std;

class Stack {
	// Two inbuilt queues
	queue<int> q1, q2;

	// To maintain current number of
	// elements
	int curr_size;

public:
	Stack()
	{
		curr_size = 0;
	}

	void push(int x)
	{
		curr_size++;

		// Push x first in empty q2
		q2.push(x);

		// Push all the remaining
		// elements in q1 to q2.
		while (!q1.empty()) {
			q2.push(q1.front());
			q1.pop();
		}

		// swap the names of two queues
		queue<int> q = q1;
		q1 = q2;
		q2 = q;
	}

	void pop()
	{

		// if no elements are there in q1
		if (q1.empty())
			return;
		q1.pop();
		curr_size--;
	}

	int top()
	{
		if (q1.empty())
			return -1;
		return q1.front();
	}

	int size()
	{
		return curr_size;
	}
};

// Driver code
int main()
{
	Stack s;
	s.push(1);
	s.push(2);
	s.push(3);

	cout << "current size: " << s.size()
		<< endl;
	cout << s.top() << endl;
	s.pop();
	cout << s.top() << endl;
	s.pop();
	cout << s.top() << endl;

	cout << "current size: " << s.size()
		<< endl;
	return 0;
}

/*

#include <bits/stdc++.h>
using namespace std;

class Stack {
	queue<int> q1, q2;
	int curr_size;

public:
	Stack()
	{
		curr_size = 0;
	}

	void pop()
	{
		if (q1.empty())
			return;

		// Leave one element in q1 and
		// push others in q2.
		while (q1.size() != 1) {
			q2.push(q1.front());
			q1.pop();
		}

		// Pop the only left element
		// from q1
		q1.pop();
		curr_size--;

		// swap the names of two queues
		queue<int> q = q1;
		q1 = q2;
		q2 = q;
	}

	void push(int x)
	{
		q1.push(x);
		curr_size++;
	}

	int top()
	{
		if (q1.empty())
			return -1;

		while (q1.size() != 1) {
			q2.push(q1.front());
			q1.pop();
		}

		// last pushed element
		int temp = q1.front();

		// to empty the auxiliary queue after
		// last operation
		q1.pop();

		// push last element to q2
		q2.push(temp);

		// swap the two queues names
		queue<int> q = q1;
		q1 = q2;
		q2 = q;
		return temp;
	}

	int size()
	{
		return curr_size;
	}
};

// Driver code
int main()
{
	Stack s;
	s.push(1);
	s.push(2);
	s.push(3);
	s.push(4);

	cout << "current size: " << s.size()
		<< endl;
	cout << s.top() << endl;
	s.pop();
	cout << s.top() << endl;
	s.pop();
	cout << s.top() << endl;
	cout << "current size: " << s.size()
		<< endl;
	return 0;
}
// This code is contributed by Chhavi

*/