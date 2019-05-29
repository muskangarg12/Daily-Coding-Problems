/*
Problem 24
Implement locking in a binary tree. A binary tree node can be locked or unlocked only if all of its descendants or ancestors are not locked.
Design a binary tree node class with the following methods:
is_locked, which returns whether the node is locked
lock, which attempts to lock the node. If it cannot be locked, then it should return false. Otherwise, it should lock it and return true.
unlock, which unlocks the node. If it cannot be unlocked, then it should return false. Otherwise, it should unlock it and return true.
You may augment the node to add parent pointers or any other property you would like. You may assume the class is used in a single-threaded program, so there is no need for actual locks or mutexes. Each method should run in O(h), where h is the height of the tree.
*/

class node{
	private:
	int val;
	node *left, *right;
	node* parent;
	bool locked;
	int numLockedDes ;
	
	public:
	node(int x, node* par)
	{
		val = x;
		left = right = NULL;
		parent = par;
		locked = 0; 
		numLockedDes = 0;
	}
	
	bool is_locked()
		return locked;
		
	bool lock()
	{
		if(numLockedDes>0 || locked)
			return 0;
		for(node* curr = parent ; curr!=NULL; curr=curr->parent)
			if(is_locked(curr))
				return 0;
		for(node* curr = parent ; curr!=NULL; curr=curr->parent)
			curr->numLockedDes++;
		return 1;			
	}
	
	bool unlock()
	{
		if(locked)
		{
			locked=1;
			for(node* curr = parent ; curr!=NULL; curr=curr->parent)
				curr->numLockedDes--;
			return 1;
		}
		return 0;
	}	
};
