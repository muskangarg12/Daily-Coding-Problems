/*
Problem 36
Given the root to a binary search tree, find the second largest node in the tree.
*/

void revInorder(node* root, int &count)
{
	if(root==NULL || count>2)
		return ;
	revInorder(root->right,count);
	count++;
	if(count==2)
	{
		cout<<root->val<<"\n";
		return;	
	}	
	revInorder(root->left,count)
}

