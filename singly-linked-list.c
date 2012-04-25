#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

/*

head - points to the first element of the list
tail - points to the last element of the list
--> In case of empty list, both head and tail
	pointers points to NULL
--> In case of one-element-list, both head and tail
	pointers points to the same element

int length();
int display();

void addfront(int data);
void addrear(int data);
void addafter(int after, int data);
void addbefore(int before, int data);
void addnth(int nth, int data)
void deletefront();
void deleterear();
void deleteafter(int after);
void deletebefore(int before);
void deletenth(int nth); 
void deleteitem(int data);

void deletelist();
void recursivedeletelist();

void reverselist();
void recursivereverse();

void makeloop();
int looped();
void fixloop();
	
void deletenode(NODE *n);
void deletenthfromtail(int nth);

void removeduplicates();

*/


typedef struct node {
	int data;
	struct node *next;
}NODE;

NODE *head = NULL;
NODE *tail = NULL;

NODE *head1 = NULL;
NODE *head2 = NULL;

void display()
{
	printf("%s: ", __FUNCTION__);
	NODE * current = head;

	if (current == NULL) {
		assert(head == tail && head == NULL && tail == NULL);	
		printf("Empty list \n");
		return;
	}

	while(current != NULL) {
		printf("%d ", current->data);
		current = current->next;
	}

	printf("\n");
	return;
}

int length()
{
	int len = 0;
	NODE *n = head;

	while (n != NULL) {
		len++;
		n = n->next;
	}
	
	return len;
}


/*
(1) - empty list
head and tail pointers are pointing to NULL.
Add a new element, make head and tail point to the 
newly added element

(2) - list with more than one element
Add a new element and adjust the head to point to the
newly added element. No change in the tail element.
*/
void addfront(int data)
{
	printf("%s: %d\n", __FUNCTION__, data);
	NODE *newnode = NULL;

	if ((newnode = (NODE *) malloc(sizeof(NODE))) != NULL) {
		newnode->data = data;
		newnode->next = NULL;	
	} else {
		printf("Couldn't allocate space for new element \n");
		return;
	}	

	if (head == NULL) {
		// empty list
		head = newnode;	
		tail = newnode;
	} else {
		newnode->next = head;
		head = newnode;
	}
	
	return;
}

/*
(1) empty list 
Can't delete anything. assert on head and tail pointers if they
are not pointing to NULL.

(2) list with one element (head == tail)
delete element and update head and tail to NULL

(3) list with more than 2 elements
just delete the first element and update head pointer. No change in
tail pointer
*/
void deletefront()
{
	printf("%s: ", __FUNCTION__);
	
	if (head == NULL) {
		assert(head == tail && head == NULL && tail == NULL);
		printf("Empty list\n");
	} else if (head == tail) {
		printf("%d \n", head->data);
		free(head);
		head = tail = NULL;
	} else {
		NODE *n = head;
		head = head->next;
		printf("%d \n", n->data);
		free(n);
	}
		
	return;
}

/*
(1) Empty list
this is the case where head = tail = NULL. So add
a new element and set the head and tail pointers

(2) List with one or more elements
Add the new element and adjust the tail pointer.
The head pointer need not be touched in this case..
*/
void addrear(int data)
{
	printf("%s: %d\n", __FUNCTION__, data);
	NODE * newnode = NULL;

	if ((newnode = (NODE *) malloc(sizeof(NODE))) != NULL) {
		newnode->data = data;
		newnode->next = NULL;
	} else {
		printf("unalbe to allocate memory to the new element - %d \n", data);
		return;
	}

	if (tail == NULL) {
		assert(head == NULL && tail == NULL);
		head = tail = newnode;
	} else {
		tail->next = newnode;
		tail = newnode;
	}

	return;
}

/*
(1) Empty list
Do nothing.. both head and tail pointers are NULL

(2) List with one element
Delete the element and set the head and tail 
pointers to NULL

(3) List with more than one element
Delete the rear element and adjust the tail pointer
No changes in the head pointer

-> How do we do this operation in constant time?!
   (i.e. w/o traversing through the whole list)

Implemented solution:
O(n) - Start from head and traverse through the list
till we find the tail pointer. Keep a prev pointer 
which points to the previous element to the tail

*/
void deleterear()
{
	printf("%s: ", __FUNCTION__);	

	if (head == NULL) {
		printf("Empty list \n");
		assert(head == NULL && tail == NULL);
	} else if (head == tail) {
		printf("%d \n", tail->data);
		free(tail);
		head = tail = NULL;
	} else {
		NODE *n = head; 

		while (n->next->next != NULL)
			n = n->next;		
		n->next = NULL;

		printf("%d \n", tail->data);
		free(tail);
		tail = n;
	}	

	return;
}


/*
(1) Empty list
Do nothing as the 'after' element is not present
head and tail pointer must be NULL.

(2) List with one or more elements
- If the 'after' element is found in the list, then
	- If the 'after' element is the tail element, then
	  add the element and adjust the tail pointer.
	- add the incoming element to the 'after' element.

--> pointer to the 'after' element is needed to 
	add the new element

*/
void addafter(int after, int data)
{
	printf("%s: %d %d ", __FUNCTION__, after, data);	
	NODE *n = head;
	NODE *newnode = NULL;
	
	while (n != NULL) {
		if (n->data == after) {
			if ((newnode = (NODE *) malloc(sizeof(NODE))) != NULL) {
				newnode->data = data;
				newnode->next = NULL;
			} else {	
				printf("- unalbe to allocate memory \n");
				return;
			}	
			newnode->next = n->next;
			n->next = newnode;
			if (n == tail)
				tail = newnode;	
			printf("\n");
			return;
		}	
		n = n->next;
	}

	printf("- %d not found \n", after);
	return;
}


/*
(1) Empty list
Do nothing..

(2) List with one or more elements
- If the 'after' element is found, then
	- If the 'after' element is the tail, then
	  do nothing. 
	- If the 'after' element is not tail, then
	  delete the element and adjust the pointers

*/

void deleteafter(int after)
{
	printf("%s: %d ", __FUNCTION__, after);
	NODE *n = head;
	NODE *temp = NULL;

	while (n != NULL) {
		if (n->data == after) {
			if (n == tail) {
				assert(n->next == NULL);
				printf("- %d is tail .. nothing to delete \n", after);
				return;
			}
			temp = n->next;
			printf("- %d deleted \n", temp->data);
			free(temp);
			
			// adjust pointers
			n->next = n->next->next;
			return;
		}
		n = n->next;
	}
	
	printf("- %d not found \n", after);
	return;
}

/*
(1) Empty list
Do nothing

(2) List with one or more elements
If the 'before' element is found in the list, then
	- If the 'before' element is the head, then
	  add the element and adjust the head pointer
	- If the 'before' element is not the head, then
	  add the element and adjust the pointers accordingly.

--> Keep a pointer to the previous node (to the 'before' node)

*/
void addbefore(int before, int data)
{
	printf("%s: %d %d ", __FUNCTION__, before, data);
	NODE *n = head;
	NODE *newnode = NULL;
	NODE *prev = head;

	while (n != NULL) {
		if (n->data == before) {

			if ((newnode = (NODE *) malloc(sizeof(NODE))) != NULL) {
				newnode->data = data;
				newnode->next = NULL;
			} else {	
				printf("- unalbe to allocate memory \n");
				return;
			}	

			if (n == head) {
				newnode->next = head; 
				head = newnode; 
				printf("\n");
				return;
			}

			newnode->next = prev->next;
			prev->next = newnode;
			printf("\n");
			return;
		}
		prev = n;
		n = n->next;
	}

	printf("- %d not found \n", before);
	return;
}

/*
(1) empty list 
Do nothing..

(2) List has only one element
head and tail must be pointing to the same element..
Do nothing..

(3) List has only two elements
head is pointing to first element
tail is pointing to second element
If 'before' element is tail, then delete head and 
adjust the head pointer

(4) List has more than two elements
In this case, the following housekeeping pointers points
to the folloing elements:
 - 'prev' pointer points to head
 - 'del' pointer points to element-next-to-head
 - 'cur' pointer points to the current element (Initialized 
	to the third element in the list)

	prev (head) -> del (next-to-head) -> cur ('before') -> ...,

	If 'cur' is the element mentioned in the 'before' pointer
	then, do the following:
	prev->next = cur;
	free(del)


--> The problem for the above complicated way is because of the
	inability to traverse backwards in a singly linked list..
	Is there any better way?! 

*/

void deletebefore(int before)
{
	printf("%s: %d -", __FUNCTION__, before);
	NODE *prev = NULL;
	NODE *del = NULL;
	NODE *cur = NULL;
	
	// empty list case
	if (head == NULL) {
		assert(head == tail && head == NULL && tail == NULL);
		printf("Empty list\n");
		return;
	}
	
	// if 'before' is head .. nothing to do.. 
	if (head->data == before) {
		printf(" %d is head.. nothing to delete\n", before);
		return;
	}
	
	// if 'before' is element-next-to-head
	if (head->next != NULL && head->next->data == before) {
		del = head;
		printf(" %d deleted \n", del->data);
		head = head->next;
		free(del);
		return;
	}	

	// 'before' is not the first two elements of the list
	// the list has more than 2 items.. 
	// start the iteration form third element and traverse further
	prev = head; 
	del = head->next;
	cur = head->next->next;

	while( cur != NULL ) {
		if (cur->data == before) {
			prev->next = cur;
			printf(" %d deleted \n", del->data);
			free(del);
			return;
		}
		prev = del;
		del = cur; 
		cur = cur->next;
	}
	
	printf(" %d not found\n", before);
	return;
}

/*
Check whether the given 'nth' is a valid length
If invalid 'nth' then do nothing and return error

--> valid nth is anywhere between 1 to length+1

(1) nth == 1
	1.1 If nth == 1 and If list is empty
		then add the element and update head an tail pointers
	1.2 If nth == 1 and If list is not empty
		then add the element and update the head pointer

(2) nth == length + 1
	then, add the element and update the tail pointer

(3) for all other lengths
	goto nth-1 position and add the element and 
	adjust the pointers.
*/
void addnth(int nth, int data) 
{
	printf("%s: %d %d - ", __FUNCTION__, nth, data);
	NODE *cur = head;
	int len = length();
	NODE *newnode = NULL;
	int nminus1;

	if (nth <= 0 || nth > (len+1)) {
		printf("invalid nth! \n");
		return;
	}		

	if ((newnode = (NODE *) malloc(sizeof(NODE))) != NULL) {
		newnode->data = data;
		newnode->next = NULL;
	} else {	
		printf(" unalbe to allocate memory \n");
		return;
	}
	
	printf(" \n");

	// special case - when adding to the head 
	if (nth == 1) {
		// empty list
		if (head == NULL) {
			assert (head == NULL && tail == NULL);
		 	head = newnode;
			tail = newnode;
			return;	
		}
		// non-empty list but adding new element
		// at the head
		newnode->next = head;
		head = newnode;	
		return;
	}

	// special case - when adding after the tail 
	// 1->2->3->4->5 .. length of the list is 5
	// if nth is 6, then this is a valid case
	// add the incoming element next to 5 and adjust
	// the tail pointer
	// nth == length+1;	
	if (nth == len+1) {
		tail->next = newnode;
		tail = newnode;
		return;
	}

	// All the other cases
	// i.e. nth is not head and nth is not tail 
	// but somewhere between head and tail
	// Traverse to nth-1 element and add the new element
	// and adjust the pointers

	nminus1 = nth-1;
	while (--nminus1) {
		cur = cur->next;
	}
	newnode->next = cur->next;
	cur->next = newnode;

	return;
}

/*
Valid nth in this case - 
1 > nth > length

(1) nth == 1
	1.1 length of the list == 1
		then, delete the head and adjust the
		head and tail pointers
	1.2 length of the list > 1
		then, delete the head and adjust the
		head pointer

(2) nth == length 
	delete the tail node and adjust the tail 
	pointer

(3) all the other cases
	traverse the list and hold the
	previous-to-nth-pointer, delete the element
	and adjust the pointers
*/
void deletenth(int nth)
{
	printf("%s: %d - ", __FUNCTION__, nth);
	int len = length();
	NODE *temp = NULL;
	NODE *cur = head;
	int nthminus1 = 0;	

	if (nth <= 0 || nth > len) {
		printf("Invalid length \n");	
		return;
	}
		
	if (nth == 1) {
		if (head == tail && head != NULL) {
			printf("%d \n", head->data);
			free(head);	
			head = tail = NULL;
			return;
		}
		
		temp = head;
		head = head->next;
		printf("%d \n", temp->data);
		free(temp);	
		return;
	}	
	
	nthminus1 = nth-1;
	while (--nthminus1) {
		cur = cur->next;
	}
	
	if (cur->next == tail) {
		cur->next = NULL;
		printf("%d \n", tail->data);
		free(tail);
		tail = cur;
		return;
	}
	
	temp = cur->next;
	cur->next = cur->next->next;
	printf("%d \n", temp->data);
	free(temp);

	return;
}

/*
(1) deleting head 
	delete element and adjust head pointer

(2) deleting tail
	delete element and adjust tail pointer

(3) one element list
	if data is the data for the only element
	then delete the list and set head and tail
	pointers to NULL

(4) all the other cases
	traverse through the list and hold the
	previous pointer. delete element and adjust
	the next pointers. 

(5) if not the above cases, then element not
	present.. do nothing..

*/
void deleteitem(int data)
{
	printf("%s: %d - ", __FUNCTION__, data);
	NODE *cur = head;
	NODE *prev = cur;
	NODE *temp = NULL;

	if (head == NULL) {
		assert (tail == NULL);
		printf("Empty list \n");
		return;
	}

	if (head->data == data) {
		temp = head;

		// one element list
		if (head == tail)
			head = tail = NULL;
		else 
			// list has more than one element
			head = head->next;

		printf("%d \n", temp->data);	
		free(temp);
		return;
	}	
	
	while (cur != NULL) {
		if (cur->data == data) {
			if (cur == tail) {
				tail = prev;
			}
			prev->next = cur->next;
			printf(" %d deleted\n", cur->data);
			free(cur);
			assert(tail->next == NULL);
			return;
		}
		prev =cur;
		cur = cur->next;
	}
	
	printf(" %d not found\n", data);
	return;
}

/*
Conventional list deletion

- Traverse the list, store the node to a temp node
- Advance to the next node and delete the temp node
*/
void deletelist()
{
	printf("%s: ", __FUNCTION__);
	NODE *cur = head;
	NODE *prev = cur;

	while (cur != NULL) {
		prev = cur; 
		cur = cur->next;
		printf(" --%d", prev->data);
		free(prev);
	}
	
	printf("\n");
	head = tail = NULL;
	return;
}

void recursivedeletelist()
{
	if (head == NULL && tail == NULL)
		return;

	NODE * temp = head;
	head = head->next;
	free(temp);
	
	if (head == NULL) {
		tail = NULL;
		return;
	}
	
	return recursivedeletelist();
}

/*
(1) Empty list and list with one element
nothing to do.. no need to adjust head and
tail pointers.

(2) list with two or more elements
traverse the old list and construct the new list
*/
void reverselist()
{
	printf("%s: \n", __FUNCTION__);
	NODE *newtail, *newcur, *cur, *temp;

	if (head == tail) 
		return;
	
	cur = head->next;
	newtail = head;
	newtail->next = NULL;
	newcur = newtail;

	while (cur != NULL) {
		temp = cur;
		cur = cur->next;
		temp->next = newcur;
		newcur = temp;
	}
	
	tail = newtail;
	head = newcur;

	return;
}


/*
tail->next will not be set by this recursive funtion
So added a helper function to set the same
*/
NODE * recursivereverse(NODE * cur)
{
	if (cur->next != NULL) {
		recursivereverse(cur->next);
		cur->next->next = cur;
		return cur;		
	} else {
		head = cur;
	}
}

void recursivereverselist()
{
	tail = recursivereverse(head);
	tail->next = NULL;
}

/*
Warning - There is no way to set 'tail' pointer in the 
		  below method.

Do not use the same
*/
NODE * recrev(NODE *cur, NODE *next)
{
	NODE *ret = NULL;

	if (cur == NULL)
		return NULL;

	if (cur->next != NULL) 
		ret = recrev(cur->next, cur);
	else
		ret = cur;

	cur->next = next;
	return ret;
}

void display25()
{
	printf("%s: ", __FUNCTION__);
	NODE * current = head;
	int times = 50;

	if (current == NULL) {
		assert(head == tail && head == NULL && tail == NULL);	
		printf("Empty list \n");
		return;
	}

	while(--times && current != NULL) {
		printf("%d ", current->data);
		current = current->next;
	}

	printf("\n");
	return;
}

void makeloop()
{
	printf("%s: \n", __FUNCTION__);
	int mid = length()/7;
	NODE *cur = head;

	while(--mid) {
		cur = cur->next;
	}
	
	tail->next = cur;	
}

/*
slow - travels one element at a time
fast - travels two element at a time

If there is a loop, then slow will meet fast!
*/

NODE * looped()
{
	printf("%s: ", __FUNCTION__);

	if (head == NULL) {
		assert (tail == NULL);
		printf("Empty List\n");
		return NULL;
	}

	NODE *slow = head;
	NODE *fast = slow->next;

	while (slow != NULL && fast != NULL) {
		if (slow == fast) {
			printf("Loop detected %d - %d\n", slow->data, fast->data);
			return slow; 
		}
	
		slow = slow->next; 
		if (fast->next != NULL)
			fast = fast->next->next;
		else { 
			printf("Not looped \n");
			return NULL;
		}
	}
	
	printf("Not looped \n");
	return NULL;
}

/*
Identify whether there is a loop or not. If there is a loop, then
follow the below instructions.
- find a node inside a loop - say N
- find the length of the loop - from N to N - say L
- Now, from start, go ahead of L elements in the list - say T1
- Now, take another pointer, say T2 which points to head
- Now, move T2 and T1 one node at a time, if T1 = T2 then you're in 
  the starting of the loop
- Now, take T1 or T2 and move L nodes, and thats the tail node
- set tail nodes next to NULL

O(n) - time 
O(1) - space

*/
void fixloop()
{
	printf("%s: \n", __FUNCTION__);
	NODE *N = looped();
	int L = 1, t, s;
	NODE *T1 = head, *T2 = head;
	NODE *temp = N->next;


	// Find the length of the loop	
	// Start from N and stop at N
	while (temp != N) {
		L++;
		temp = temp->next;
	} 
	
	s = t = L;
	// Now, move T1 L times
	while (L--)
		T1 = T1->next;

	// move T1 and T2 one node at a time 
	// When they meet, they meet at the start of the loop
	while (T2 != T1) {
		T2 = T2->next;
		T1 = T1->next;
	}
	
	// move len-1 times, that will point to the tail node
	while (--t)
		T2 = T2->next;

	T2->next = NULL;
	tail = T2;	
	return;
}

NODE * getrandomnodeaddress()
{
	printf("%s: ", __FUNCTION__);
	NODE * n = head;
	NODE *prev = head;

	/*
	int i = length() / 15;
	while (i--)
		n = n->next;
	*/
	while(n->next != NULL) {
		prev = n;
		n = n->next;
	}

	printf("%d \n", prev->next->data);
	return prev->next;
} 

/*
(1) If the given node is the last node, then 
	start from the head and traverse the list to 
	change last-1's next pointer
	O(n) time
(2) If the given node is not the last node, then 
	copy the contents of the next node to this node
	and delete the next node
	O(1) time
*/
void deletenode(NODE * n) 
{
	printf("%s: ", __FUNCTION__);
	NODE * i = head;
	NODE * temp; 
	int data = n->data;

	// check whether the given node is the tail node
	if (n->next == NULL) {
		while (i->next != n) 
			i = i->next;
		temp = i->next;
		i->next = NULL;
		tail = i;
		printf(" %d deleted\n", temp->data);
		free(temp);
		return;
	}
	
	// copy the content of the next node to this
	// node and delete this node
	temp = n->next;
	n->data = n->next->data;
	n->next = n->next->next;
	printf(" %d deleted \n", data);
	free(temp);
	return;
}

/*
Goto nth-1 node to delete nth node

nth must be > 0 and <= length of the list

(1) if nth == lenght, then delete the head node
(2) if nth == 1 then delete the tail node
(3) else goto nth-1 node and delete nth node	

Two pointers, 
P1 - starts from the head
P2 - nth-1 nodes ahead of P1
advance the pointer till P2 reaches the end, P1->next 
will be the nth from the tail, .. delete it

*/

void deletenthfromtail(int nth)
{
	printf("%s: %d ", __FUNCTION__, nth);
	int len = length();
	NODE *P1, *P2, *temp;
	if (nth <= 0 || nth > len) {
		printf("Invalid nth \n");
		return;
	}
	
	if (nth == len) {
		deletefront();
		return;
	}

	if (nth == 1) {
		deleterear();
		return;
	}

	P2 = P1 = head;
	while (nth--)
		P2 = P2->next;
	
	while (P2->next != NULL) {
		P1 = P1->next;
		P2 = P2->next;
	}
	
	temp = P1->next;
	P1->next = P1->next->next;
	printf("- %d deleted\n", temp->data);
	free(temp);	

	return;
}


/*
current pointer runs from first to last element of the list

newcurrent runs from the fisrt element to the last 
element (i.e current pointer) of the unique list

*/
void removeduplicates()
{
	// empty list
	if (head == NULL) return;

	// element with one list .. nothing to remove
	if (head == tail) return;

	NODE * previous = head;
	NODE * current = head->next;
	NODE * newcurrent = head;
	NODE * temp;
	
	while (current != NULL) {

		newcurrent = head;

		while (newcurrent != current) {
			if (newcurrent->data == current->data) {
				temp = current;
				previous->next = current->next;
				current = current->next;
				printf("Deleting %d \n", temp->data);
				free(temp);
				break;
			}	
			
			newcurrent = newcurrent->next;
		}	

		if (newcurrent == current) {
			previous = current;
			current = current->next;
		}
	}

	tail = previous;
}

/*
addfront_and_return_head() and display_list() are used as 
helper functions for add_list()

the following should be output:

5 4 3 2 9 				=> list1
9 9 8 5 9 				=> list2
4 4 2 8 8 1 			=> list3 = list1 + list2

*/
NODE * addfront_and_return_head(NODE *head, int data)
{
	NODE * newnode = (NODE *) malloc(sizeof(NODE));
	newnode->data = data;
	newnode->next = head;
	
	head = newnode;
	return head;
}

void display_list(NODE *head)
{	
	while(head) {
		printf("%d ", head->data);
		head = head->next;
	}
	printf("\n");
		
}

NODE * add_list(NODE *l1, NODE *l2, int carry)
{
	int result = 0;
	if (carry && l1 == NULL && l2 == NULL) {
		NODE * newnode = (NODE *) malloc(sizeof(NODE));
		newnode->data = carry;
		newnode->next = NULL;
		return newnode;
	} else if (l1 == NULL && l2 == NULL) {
		return NULL;
	}

	if (l1 != NULL)
		result = result + l1->data;

	if (l2 != NULL)
		result = result + l2->data;
	
	result = result + carry;

	if (result >= 10) carry = 1;
	else carry = 0;

	result = result % 10;

	NODE * newnode = (NODE *) malloc (sizeof(NODE));
	newnode->data = result;
	newnode->next = add_list(l1->next ? l1->next : NULL,
							 l2->next ? l2->next : NULL, 
							 carry);

	return newnode;
}


int main()
{
	NODE * head1 = NULL;	
	NODE * head2 = NULL;
	NODE * head3 = NULL;

	head1 = addfront_and_return_head(head1, 9);	
	head1 = addfront_and_return_head(head1, 2);	
	head1 = addfront_and_return_head(head1, 3);	
	head1 = addfront_and_return_head(head1, 4);	
	head1 = addfront_and_return_head(head1, 5);	
	display_list(head1);

	head2 = addfront_and_return_head(head2, 9);	
	head2 = addfront_and_return_head(head2, 5);	
	head2 = addfront_and_return_head(head2, 8);	
	head2 = addfront_and_return_head(head2, 9);	
	head2 = addfront_and_return_head(head2, 9);	
	display_list(head2);

	
	head3 = add_list(head1, head2, 0);
	display_list(head3);

	/*
	
	*/

	

	/*
	addfront(1); display();
	addfront(2); display();
	addfront(3); display();
	addfront(4); display();
	addfront(5); display();
	addfront(6); display();
	addfront(7); display();
	addfront(8); display();
	addfront(9); display();
	addfront(10); display();
	addfront(1); display();
	addfront(2); display();
	addfront(3); display();
	addfront(4); display();
	addfront(5); display();
	addfront(6); display();
	addfront(7); display();
	addfront(8); display();
	addfront(9); display();
	addfront(10); display();
	addfront(10); display();
	addfront(10); display();
	addfront(10); display();
	addfront(10); display();
	addfront(10); display();
	addfront(10); display();
	

	removeduplicates();	display();
	addfront(10); display();
	addfront(10); display();
	addfront(10); display();
	addfront(10); display();
	addfront(10); display();
	addfront(10); display();
	addrear(1); display();
	addrear(1); display();
	addrear(1); display();
	addrear(1); display();
	addrear(1); display();
	addrear(1); display();
	removeduplicates();	display();

	makeloop(); display25();
	looped();
	fixloop(); display();

	deletenode(getrandomnodeaddress());	display();
	
	reverselist(); display();
	*/

	/*
	deletenthfromtail(1); display();
	deletenthfromtail(2); display();
	deletenthfromtail(3); display();
	deletenthfromtail(4); display();
	deletenthfromtail(5); display();
	*/

	/*
	deletefront(); display();
	deletefront(); display();
	deletefront(); display();
	deletefront(); display();
	deletefront(); display();
	deletefront(); display();
	deletefront(); display();
	deletefront(); display();
	deletefront(); display();
	addfront(1); display();
	addfront(2); display();
	addfront(3); display();
	addrear(4);  display();
	addrear(5);  display();
	addrear(6);  display();
	addbefore(3, 23); display();
	addbefore(2, 21); display();
		
	deleteafter(23); display();

	deletefront(); display();
	deletefront(); display();

	deletebefore(3); display();
	deletebefore(2); display();
	deletebefore(1); display();
	deletebefore(6); display();
	deletebefore(6); display();
	deletebefore(6); display();
	deleterear(); display();
	*/

	return 0;
}	




