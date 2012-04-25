#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>


/*

void addnode(int data);
void deletenode(int data);
int count();
int maxvalue();
int minvalue();
int maxdepth();
int mindepth();

void display();
void inorder();
void preorder();
void postorder();

void haspathsum();
void printpaths();
void mirror();

copytree() and deletetree()

int isbst();
*/

typedef struct node {
	int data;
	struct node *left;
	struct node *right;
} NODE;

NODE *root = NULL;

NODE *q[50];
int qhead = 0, qtail = 0;

/* ---- (minimal) stack (without error checkings -------- */

typedef struct s {
	NODE *data[100];
	int stkptr;
} stack;

void push(stack * s, NODE * node)
{
	s->data[++s->stkptr] = node;
	//	printf("%s - %d \n", __FUNCTION__, node->data);
	return;
}

NODE * pop(stack *s)
{
	if (s->stkptr == -1) {
		printf("empty stack \n");
		return;
	}
	//printf("%s \n", __FUNCTION__);
	return s->data[s->stkptr--];
}

int isempty(stack *s) {
	return (s->stkptr == -1);
}

/*  ---- end stack ------ */

NODE * newnode (int data) 
{
	NODE * n = NULL;
	if (n = (NODE *) malloc (sizeof (NODE))) {
		n->data = data;
		n->right = n->left = NULL;
	} else {
		printf("%d - %d - unalbe to create new node \n", __LINE__, data);
	}

	return n;
}

// This insert is wrong.. 
// the new node must be created only when incoming node is null
// else there will be a memory leak
//
// the below code has a memory leak
//
NODE * insert (NODE * node, int data)
{
	// printf("%s: %d ", __FUNCTION__, data);
	NODE * n = newnode(data);
	assert(n!=NULL);

	if (node == NULL) 
		return (n);

	if (data <= node->data) 
		node->left = insert(node->left, data);
	else 
		node->right = insert(node->right, data);

	return node;
}

// for iterative versions of traversals, please refer below
// http://web.cs.wpi.edu/~cs2005/common/iterative.inorder
//

void preorder(NODE * node)
{
	if (node == NULL) 
		return;

	printf("%d ", node->data);
	preorder(node->left);
	preorder(node->right);
	return;
}

void inorder(NODE * node)
{
	if (node == NULL) 
		return;

	inorder(node->left);
	printf("%d ", node->data);
	inorder(node->right);
	return;
}

void postorder(NODE * node)
{
	if (node == NULL) 
		return;

	postorder(node->left);
	postorder(node->right);
	printf("%d ", node->data);

	return;
}

/*
Iterative inorder traversal

use stack.

inorder:
step-1:	push all the left child to the stack
step-2:	when there is no left child to push to the stack
	if the stack is not empty
		pop the element and print it
		go to the right child and go to step-1
	else if the stack is empty
		you're done

*/

void iterative_inorder(NODE *node)
{
	stack s1;
	s1.stkptr = -1;
	int done = 0;

	while (!done) {
		if(node) {
			push(&s1, node);
			node = node->left;
		} else {
			if (!isempty(&s1)) {
				node = pop(&s1);
				printf("%d ", node->data);
				node = node->right;
			} else {
				done = 1;
			}
		}
	}
	return;
}


/*

The following functions are used in levelorder traversal

void enqueue(NODE * n)
NODE * dequeue() 
int qempty()
void printq()

*/

void enqueue(NODE * n)
{
	if (qhead < 50) {
		// printf("%d %s - %d \n", __LINE__, __FUNCTION__, n->data);
		q[qhead++] = n;
	} else {
		printf("%d - qhead > queue limit \n", __LINE__);
	}
}

NODE * dequeue() 
{
	NODE * n; 
	if (qtail >= 0 && qtail < 50) {
		n = q[qtail++];
		// printf("%d %s - %d \n", __LINE__, __FUNCTION__, n->data);
		return n;
	} else {
		printf("%d - dequeing an empty queue \n", __LINE__);
		return NULL;
	}
}

int qempty()
{
	return (qhead == qtail);
}

void printq()
{
	int i;

	for(i=qtail ; i<qhead; i++)
		printf("%d ", q[i]->data);
	printf("\n");
	return;
}

void levelorder(NODE * node)
{
	NODE *a;

	enqueue(node);
	while (!qempty()) {
		a = dequeue();
		printf("%d ", a->data);
		if (a->left) enqueue(a->left);
		if (a->right) enqueue(a->right);

	}
	printf("\n");
}

int size(NODE * n)
{
	if (n == NULL) 
		return 0;
	else
		return (1 + size(n->left) + size(n->right));
}

int maxdepth(NODE * n)
{
    int ldepth, rdepth;
    
    if ( n == NULL)
        return 0;

    ldepth = maxdepth(n->left);
    rdepth = maxdepth(n->right);
    
    if (ldepth < rdepth) 
        return rdepth + 1;
    else 
        return ldepth + 1;
}

int mindepth(NODE * n)
{
	int ldepth, rdepth;
	
	if (n == NULL)
		return 0;

	ldepth = mindepth(n->left);
	rdepth = mindepth(n->right);
	
	if (ldepth < rdepth) 
		return ldepth + 1;
	else 
		return rdepth + 1;
}

int minvalue(NODE * n)
{
    while (n->left != NULL)
        n = n->left;

    return n->data;
}

int maxvalue(NODE * n)
{
    while (n->right != NULL)
        n = n->right;

    return n->data;
}

int haspathsum(NODE *n, int sum)
{
    int subsum = 0;

    if (n == NULL)
        return (sum == 0);

    subsum = sum - n->data;
    return (haspathsum(n->left, subsum) || 
            haspathsum(n->right, subsum));    

}


/*
 * printarray() and printpathrecursive() are helper functions
 * for printpaths()
 */

void printarray(int a[], int len)
{
    int i;
    for (i=0;i<len;i++)
        printf("%d ", a[i]);
    printf("\n");
}

void printpathrecursive(NODE *n, int path[], int pathlen)
{
    if (n == NULL)
        return;

    path[pathlen++] = n->data;

    if (n->left == NULL && n->right == NULL) {
        printarray(path, pathlen);
        return;
    }

    printpathrecursive(n->left, path, pathlen);
    printpathrecursive(n->right, path, pathlen);
}

void printpaths(NODE * n)
{
    int path[100] = {0};
    printpathrecursive(n, path, 0);
}

void mirror(NODE * n)
{
    NODE * temp;

    if (n == NULL) 
        return;
    
    temp = n->left;
    n->left = n->right;
    n->right = temp;

    mirror(n->left);
    mirror(n->right);
}

NODE * copytree(NODE * from)
{
	NODE * n = NULL;
	
	if (from != NULL) {
		n = newnode(from->data);
		n->left = copytree(from->left);
		n->right = copytree(from->right);
	}

	return n;
}


NODE * deletetree(NODE * from)
{
	if (from != NULL) {
		deletetree(from->left);
		deletetree(from->right);
		printf("deleting %d \n", from->data);
		free(from);
	}
	return NULL;
}

int isBST(NODE * n)
{
	if (n == NULL)
		return 1;

	if (n->left && minvalue(n->left) > n->data) 
		return 0;

	if (n->right && maxvalue(n->right) <= n->data)
		return 0;

	if (!isBST(n->left) || !isBST(n->right))
		return 0;

	return 1;
}


int isBST2(NODE * n)
{
	return isBSTv2(n, INT_MIN, INT_MAX);
}

int isBSTv2(NODE * n, int min, int max)
{
	if (n == NULL)
		return 1;

	if (n->data < min || n->data > max) 
		return 0;
	
	if (isBSTv2(n->left, min, n->data) &&
		isBSTv2(n->right, n->data, max))
		return 1;

	return 0;
}


NODE * getnode(NODE * n, int data)
{
	if (n == NULL)
		return NULL;

	if (n->data == data) 
		return n;

	if (data < n->data)	{
		return getnode (n->left, data);
	}

	if (data > n->data) {
		return getnode (n->right, data);
	}

	return NULL;
}

/*

#1.	Traverse through the list and check whether the element is
	present in the tree or not
	-> 	if the element is present, then 'node' will point to 
		that element
	-> 	if the element is present, then 'parent' will point to 
		that elements parent
	-->	if the parent == NULL then you're attempting to delete
		the root node (special case).
	--->	if the element to be deleted is not present in the 
			list then 'node' pointer will be NULL, so quit in 
			this case. Nothing to delete.

After #1, node will point to the node to be deleted and parent 
will point to its parent. 

#2. if the node-to-be-deleted is the leaf node, i.e. left and 
	right pointers are NULL, then, delete it and return root.
	--> (special case) - if the node-to-be-deleted is a leaf node 
		and if it is the only node in the tree (i.e. root), then
		delete that node and return null. update root pointer. 


#3. node-to-be-deleted has only one child (it could be root also)
	->	node-to-be-deleted has left child and no right child
	->	node-to-be-deleted has right child and no left child
		
#4. node-to-be-deleted has both left and right child
	(conside root also)
	-> 	temp = node->left->right 
	-> 	node->left->right = node->right
	-> 	go to the left most link on the right sub tree and 
		insert temp there

*/

NODE * deletenode(NODE * n, int data)
{
	NODE *root = n;
	NODE *temp = NULL;
	NODE *newroot = NULL;
	NODE *temp2 = NULL; // to hold the right sub tree for case #3
	NODE *parent = NULL, *node = n;

	if (n == NULL) {
		//printf("Its an empty binary search tree \n");
		return root;
	}

	while (node != NULL) {
		if (node->data == data)
			break;
		parent = node;
		if (data < node->data)
			node = node->left;
		else 
			node = node->right;
	}

	if (node == NULL) {
		printf("Element: %d not found \n", data);
		return root;
	}

	if (parent == NULL) {
		printf("deleting root node \n");
		printf("Node : %d \n", node->data);
	} else {
		printf("Node : %d & parent : %d \n", node->data, parent->data);
	}

	// Attempting to delete a leaf node.
	if (node->left == NULL && node->right == NULL) {
		// the root is the only node available in the tree
		// and we are attempting to delete it
		if (parent == NULL) {
			printf("Deleting %d - root leaf node! \n", node->data);
			free(node);
			return NULL;	
		}
		
		// we are attempting to delete a leaf node which
		// is not root
		if (node == parent->left)
			parent->left = NULL;
		else 
			parent->right = NULL;
		printf("Deleting %d - leaf node! \n", node->data);
		free(node);
		return root;
	}
	
	// Attempting to delete a node with only one child
	
	// if the node-to-be-deleted have only left child
	// i.e. no right subtree, then, 
	//
	// node->parent->left = node->left 
	// (connect parent and left sub tree)
	// 
	// then, delete the node

	if (node->left != NULL && node->right == NULL) {

		// node-to-be-deleted is root node	
		if (parent == NULL) {
			temp = node->left;	
			printf("Deleting %d - left not null and right null - root\n", node->data);
			free(node);
			return temp;
		}

		// node to be deleted is non root node
		//printf("node-to-be-deleted : %d - left child: %d - " \
		//	   "right child: NULL - parent: %d \n", 
		//		node->data, node->left->data, parent->data);
		parent->left = node->left;
		printf("Deleting %d - left not null and right null \n", node->data);
		free(node);		
		return root;
	}	

	if (node->left == NULL && node->right != NULL) {

		// attempting to delete the root node
		if (parent == NULL) {
			temp = node->right;
			printf("Deleting %d - left null and right not null - root\n", node->data);
			free(node);
			return temp;
		}

		// node to be deleted is non root node
		//printf("node-to-be-deleted : %d - left child: NULL - " \
		//	   "right child: %d - parent: %d \n", 
		//		node->data, node->right->data, parent->data);
		parent->right = node->right;
		printf("Deleting %d - left not null and right null \n", node->data);
		free(node);		
		return root;
	}


	if (node->left != NULL && node->right != NULL) {
		
		temp = node; 
		newroot = node->left;
		temp2 = node->left->right;
		
		node->left->right = node->right;
		if (temp2 != NULL) {
			node = node->right;
			while(node->left != NULL) 
				node = node->left;
			node->left = temp2;
		}
	
		
		if (parent != NULL) {	
			if (temp == parent->left)
				parent->left = temp->left;
			else
				parent->right = temp->left;
		}
		
		printf("Deleting %d - both valid child \n", temp->data);
		free(temp);
		
		if (parent == NULL)
			return newroot;
		else 
			return root;
	}
}


int main()
{
    int sum = 35;
    NODE * root1 = NULL;

	root = insert(root, 20); //printf("\n");
	root = insert(root, 10); //printf("\n");
	root = insert(root, 30); //printf("\n");
	root = insert(root, 25); //printf("\n");
	root = insert(root, 15); //printf("\n");
	root = insert(root, 5); //printf("\n");
	root = insert(root, 35); //printf("\n");
	root = insert(root, 40); //printf("\n");
	root = insert(root, 23); //printf("\n");
	root = insert(root, 21); //printf("\n");
	root = insert(root, 24); //printf("\n");

	printf("preorder: "); preorder(root);	printf("\n");
	printf("inorder: "); inorder(root);	printf("\n");
	printf("postorder: "); postorder(root);	printf("\n");

	printf("iterative inorder traversal \n");
	iterative_inorder(root); 
	printf("\n");

	printf("levelorder: "); levelorder(root); 
	printf("size: %d \n", size(root));
    printf("maxdepth: %d \n", maxdepth(root));
    printf("mindepth: %d \n", mindepth(root));

	if (maxdepth(root) - mindepth(root) <= 1)
		printf("this tree is balanced\n");
	else
		printf("this tree is not balanced - skewed\n");

    printf("minvalue: %d \n", minvalue(root));
    printf("maxvalue: %d \n", maxvalue(root));
    printf("haspathsum: %d - %d \n", sum, haspathsum(root, sum));
    
    printpaths(root);
    mirror(root);
	printf("levelorder: "); levelorder(root); 

    root1 = copytree(root);
	printf("new tree: "); inorder(root1); printf("\n");
	printf("mirror: "); mirror(root1); inorder(root1); printf("\n");

	root1 = deletetree(root1);
	printf("delete tree: "); inorder(root1); printf("\n");

	printf("old tree: "); inorder(root); printf("\n");
    mirror(root);
	printf("mirror: "); inorder(root); printf("\n");

	printf("isbst: %s \n", (isBST(root) ? "yes" : "no"));
	printf("isbstv2: %s \n", (isBST2(root) ? "yes" : "no"));


	int search = 40;
	NODE * temp = getnode(root, search);
	if (temp)
		printf("getnode: %d : %d\n", search, temp->data);
	else 
		printf("getnode: %d : no node found\n", search);
	
	int delelement = 20; 
	root = deletenode(root, delelement); inorder(root); printf("\n");  


	return 0;

}
