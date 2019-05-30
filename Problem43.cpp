/*
Problem 43
Implement a stack that has the following methods:
push(val), which pushes an element onto the stack
pop(), which pops off and returns the topmost element of the stack. If there are no elements in the stack, then it should throw an error or return null.
max(), which returns the maximum value in the stack currently. If there are no elements in the stack, then it should throw an error or return null.
Each method should run in constant time.
*/

class stack{
	private:
	int arr[];
	int maxa[];
	int top;
	
	public:
	stack()
	{
		top=0;
	}
	
	void push(int val)
	{
		arr[top]=val;
		if(top>0)
			maxa[top]=max(maxa[top-1],val);
		else
			maxa[top]=val;
		top++;		
	}
	
	int pop()
	{
		top--;
		return arr[top];
	}
	
	int max()
	{
		return maxa[top];
	}
};

