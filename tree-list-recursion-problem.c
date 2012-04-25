#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct node {
	int data;
	struct node *small;
	struct node *large;
};

typedef struct node * Node;

/*
Create a new node
*/

Node newnode(int data)
{
	Node node = (Node) malloc (sizeof(struct node));
	node->data = data;
	node->small = NULL;
	node->large = NULL;
	return node;
}

/*
Insert an element to the tree
*/
void treeinsert(Node *rootref, int data)
{
	Node root = *rootref;
	if (root == NULL) {
		*rootref = newnode(data);
	} else {
		if (data <= root->data) treeinsert(&(root->small), data);
		else treeinsert(&(root->large), data);
	}
}

/*
Print the tree in inorder 
*/

void printtree_inorder(Node node)
{
	if (node == NULL)
		return;

	printtree_inorder(node->small);
	printf("%d ", node->data);
	printtree_inorder(node->large);
}

/*
printing the list
*/
void printlist(Node head)
{
	Node cur = head;
	
	while (cur != NULL) {
		printf("%d ", cur->data);
		cur = cur->large;
		if (cur == head) break;
	}
	printf("\n");
}

/*
Given two nodes, say a and b, just join them
a->large = b;
b->small = a;
*/
void join(Node a, Node b)
{
	a->large = b;
	b->small = a;
}

/*
Given two circular doubly linked list, link the list 
and return the head of the new list

list #1: a->b->c->a
list #2: d->e->f->d

new list should be as follows:
a->b->c->d->e->f->a

algorithm:
1) if list #1 == NULL, return list #2
2) if list #2 == NULL, return list #1
3) find the last element of list #1 and list #2 and call them 
   alast and blast

   alast = a->small
   blast = b->small

4) Now, join alast with b and blast with a
   join(alast, b)
   join(blast, a)

*/
Node append(Node a, Node b)
{
	Node alast, blast;

	if (a == NULL) return b;
	if (b == NULL) return a;

	alast = a->small;
	blast = b->small;

	join(alast, b);
	join(blast, a);
	
	return a;
}

/*
Split the given node into three things
1. alist - a circular doubly linked list of all the 
		   left children
2. blist - a circular doubly linked list of all the
		   right children
3. node itself - left and right pointers point to the
				 node itself.

now join alist and node itself and then the node itself
and the blist
*/

Node treetolist(Node root)
{
	Node alist, blist;
	
	if (root == NULL)
		return NULL;

	alist = treetolist(root->small);
	blist = treetolist(root->large);

	root->small = root;
	root->large = root;

	alist = append(alist, root);
	blist = append(alist, blist);

	return alist;
}


Node getmid(Node head, Node tail)
{
	Node mid = head;
	int len = 1, m;

	assert (head!=NULL);
	assert (tail!=NULL);

	if (head == tail)
		return head;

	while (head != tail) {
		len++;
		head = head->large;
	}
	
	m = (len+1) / 2;
	m--;
	while (m--) {
		mid = mid->large;
	}
	
	return mid;
}

Node listtotree(Node head, Node tail)
{
	Node aroot, broot, mid;

	if (head == tail) {
		return head;
	}

	mid = getmid(head, tail);

	if (mid->small != NULL) {
		mid->small->large = NULL;
		mid->small = listtotree(head, mid->small);
	}

	if (mid->large != NULL) {
		mid->large->small = NULL;
		mid->large = listtotree(mid->large, tail);
	}

	return mid;
}

void printtree_postorder(Node n)
{
	if (n == NULL)
		return;

	printtree_postorder(n->small);
	printtree_postorder(n->large);
	printf("%d ", n->data);
}


int main()
{
	Node root = NULL;
	Node head = NULL;
	Node tail = NULL;

	treeinsert(&root, 20);
	treeinsert(&root, 10);
	treeinsert(&root, 30);
	treeinsert(&root, 5);
	treeinsert(&root, 15);
	treeinsert(&root, 25);
	treeinsert(&root, 35);
	treeinsert(&root, 40);

	/*
	treeinsert(&root, 4);
	treeinsert(&root, 2);
	treeinsert(&root, 1);
	treeinsert(&root, 3);
	treeinsert(&root, 5);
	*/

	printf("Printing tree inorder: \n");
	printtree_inorder(root);
	printf("\n");

	head = treetolist(root);	

	printf("Printing list: \n");
	printlist(head);


	/*
	To convert the list back to tree, make the 
	circular list to normal list..
 	*/
	tail = head->small;
	tail->large = NULL;
	head->small = NULL;

	root = listtotree(head, tail);
	printf("Printing tree inorder: \n");
	printtree_inorder(root);
	printf("\n");


	printf("Printing tree post order: \n");
	printtree_postorder(root);
	printf("\n");


	return 0;
}

