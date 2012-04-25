#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct node {
	int data;
	struct node *prev;
	struct node *next;
}NODE;

NODE *head = NULL, *tail = NULL;

/*
void addfront(int data);
void addrear(int data);
void addafter(int data, int after);
void addbefore(int data, int before);
void addnth(int data, int nth);

void deletefront();
void deleterear();
void deleteafter(int after);
void deletebefore(int before);
void deletenth(int nth);
void deleteelement(int data);

void deletelist();

int length();
void display();
*/

int length()
{
	int len = 0;
	NODE *cur = head;
	while(cur != NULL) {
		len++;
		cur = cur->next;
	}
	return len;
}

void display(){
	printf("%s: ", __FUNCTION__);
	NODE *cur = head;
	if (head == NULL) {
		assert(tail == NULL);
		printf("Empty list \n");
		return;
	}
	while(cur != NULL) {
		printf("%d ", cur->data);
		cur = cur->next;
	}
	printf("\n");
	return;
}

void display_backwards()
{
	printf("%s: ", __FUNCTION__);
	NODE *cur = tail;
	if (tail == NULL) {
		assert(head == NULL);
		printf("Empty list \n");
		return;
	}
	while(cur != NULL) {
		printf("%d ", cur->data);
		cur = cur->prev;
	}
	printf("\n");
	return;
}

void addfront(int data)
{
	printf("%s: %d ", __FUNCTION__, data);
	NODE *newnode; 

	if (newnode = (NODE *) malloc(sizeof (NODE))) {
		newnode->data = data;
		newnode->next = NULL;
		newnode->prev = NULL;
	} else {
		printf("unable to allocate memory \n");
		return;
	}

	if (head == NULL) {
		assert (tail == NULL);
		head = tail = newnode;
	} else {
		newnode->next = head;
		head->prev = newnode;
		head = newnode;
	}

	printf("added \n");
	return;
}

void addrear(int data)
{
	printf("%s: %d ", __FUNCTION__, data);
	NODE *newnode; 

	if (newnode = (NODE *) malloc(sizeof (NODE))) {
		newnode->data = data;
		newnode->next = NULL;
		newnode->prev = NULL;
	} else {
		printf("unable to allocate memory \n");
		return;
	}
		
	if (tail == NULL) {
		assert (tail == NULL);
		head = tail = newnode;
	} else {
		newnode->prev = tail;
		tail->next = newnode;
		tail = newnode;
	}
	
	printf("added \n");
	return;
}

void addafter(int data, int after)
{
	printf("%s: %d %d ", __FUNCTION__, data, after);
	NODE *newnode; 
	NODE *cur = head; 

	if (newnode = (NODE *) malloc(sizeof (NODE))) {
		newnode->data = data;
		newnode->next = NULL;
		newnode->prev = NULL;
	} else {
		printf("unable to allocate memory \n");
		return;
	}

	if (head == NULL) {
		assert(tail == NULL);
		printf("Empty list \n");	
		return;
	}

	if (tail->data == after) {
		tail->next = newnode;
		newnode->prev = tail;	
		tail = newnode;
		printf("added \n");
		return;	
	}	

	while (cur != NULL) {
		if (cur->data == after) {
			newnode->prev = cur;
			newnode->next = cur->next;
			cur->next->prev = newnode;
			cur->next = newnode;
			printf("added \n");
			return;
		}		
		cur = cur->next;
	}

	free(newnode);

	printf("%d not found\n", after);
	return;
}

void addbefore(int data, int before)
{
	printf("%s: %d %d ", __FUNCTION__, data, before);
	NODE *newnode; 
	NODE *cur = head; 

	if (newnode = (NODE *) malloc(sizeof (NODE))) {
		newnode->data = data;
		newnode->next = NULL;
		newnode->prev = NULL;
	} else {
		printf("unable to allocate memory \n");
		return;
	}
	
	if (head->data == before) {
		newnode->next = head;
		head->prev = newnode;
		head = newnode;
		printf("added \n");
		return;
	}

	while (cur != NULL) {
		if (cur->data == before) {
			newnode->next = cur;
			newnode->prev = cur->prev;
			cur->prev->next = newnode;
			cur->prev = newnode;
			printf("added \n");
			return;
		}
		cur = cur->next;
	}

	free(newnode);

	printf("%d not found\n", before);
	return;
}

void addnth(int data, int nth)
{
	printf("%s: %d %d ", __FUNCTION__, data, nth);
	NODE *newnode; 
	NODE *cur = head; 
	int l = length();

	if (nth <= 0 || nth > l+1) { 
		printf("Invalid nth \n");
		return;
	}

	if (newnode = (NODE *) malloc(sizeof (NODE))) {
		newnode->data = data;
		newnode->next = NULL;
		newnode->prev = NULL;
	} else {
		printf("unable to allocate memory \n");
		return;
	}

	if (nth == 1) {
		// If list is empty and nth is position #1
		if (head == NULL) {
			assert (tail == NULL);
			head = tail = newnode;
			printf("added \n");
			return;
		}
		// The list is not empty but attempting to 
		// add the element in the head's position
		newnode->next = head;
		head->prev = newnode;
		head = newnode;	
		printf("added \n");
		return;
	}

	// Adding just after the tail node.. ie. when 
	// nth == len+1	
	if (nth == l+1) { 
		tail->next = newnode;
		newnode->prev = tail;
		tail = newnode;
		printf("added \n");
		return;
	}

	// All the other cases
	--nth;
	while (--nth) {
		cur = cur->next;
	}
	newnode->prev = cur;
	newnode->next = cur->next;
	cur->next->prev = newnode;
	cur->next = newnode;
	printf("added \n");

	return;
}

void deletefront()
{
	printf("%s: ", __FUNCTION__);
	NODE *temp = head;

	if (head == NULL) {
		assert(tail == NULL);
		printf("Empty list\n");
		return;
	}

	if (head == tail) {
		head = tail = NULL;
	} else {
		head = head->next;
		head->prev = NULL;
	}
	
	printf("%d deleted \n", temp->data);
	free(temp);
	
	return;
}

void deleterear()
{
	printf("%s: ", __FUNCTION__);
	NODE *temp = tail;

	if (head == NULL) {
		assert(tail == NULL);
		printf("Empty list\n");
		return;
	}

	if (head == tail) {
		head = tail = NULL;
	} else {
		tail = tail->prev;
		tail->next = NULL;
	}
	
	printf("%d deleted \n", temp->data);
	free(temp);
	
	return;
}

void deleteafter(int after)
{
	printf("%s: %d - ", __FUNCTION__, after);
	NODE *cur = head;
	NODE *temp = NULL;

	if (head == NULL) {
		assert(tail == NULL);
		printf("Empty list\n");
		return;
	}

	while (cur != NULL) {
		if (cur->data == after) {
			if (cur == tail) {
				printf("nothing to delete \n");
				return;
			}
			
			temp = cur->next;

			// if we are deleting tail node then
			// reset the tail pointer
			if (cur->next == tail) {
				tail = cur; 
				tail->next = NULL;				
			} else {
				cur->next = cur->next->next;
				cur->next->prev = cur;
			}
		
			printf("%d deleted \n", temp->data);
			free(temp);
			return;
		}	
		cur = cur->next;
	}
		
	printf("%d not found \n", after);
	return;
}

void deletebefore(int before)
{
	printf("%s: %d - ", __FUNCTION__, before);
	NODE *cur = head;
	NODE *temp = NULL;

	if (head == NULL) {
		assert(tail == NULL);
		printf("Empty list\n");
		return;
	}

	while (cur != NULL) {
		if (cur->data == before) {
			if (cur == head) {
				printf("nothing to delete \n");
				return;
			}
			
			temp = cur->prev;

			// if we are deleting head node then
			// reset the head pointer
			if (cur->prev == head) {
				head = cur;
				head->prev = NULL;
			} else {
				cur->prev = cur->prev->prev;
				cur->prev->next = cur;
			}
		
			printf("%d deleted \n", temp->data);
			free(temp);
			return;
		}	
		cur = cur->next;
	}
		
	printf("%d not found \n", before);
	return;

}

void deletenth(int nth)
{
	printf("%s: %d - ", __FUNCTION__, nth);
	NODE *cur = head;
	NODE *temp = cur;
	int l = length();

	if (head == NULL) {
		assert(tail == NULL);
		printf("Empty list \n");
		return;
	}

	if ( nth <= 0 || nth > l) {
		printf("%d Invalid nth \n", nth);
		return;
	}
	
	if (nth == 1) {
		// there is only one node available in this list
		//  and we're deleting that
		if (head == tail) {
			head = tail = NULL;
			printf(" %d deleted \n", temp->data);
			free(temp);
			return;
		}
		head = head->next;
		head->prev = NULL;
		printf(" %d deleted \n", temp->data);
		free(temp);
		return;
	}

	// If nth is the last node, then delete that
	// and adjust the tail pointer
	if (nth == l) {
		if (head == tail) {
			head = tail = NULL;
			printf(" %d deleted \n", temp->data);
			free(temp);
			return;
		}
		temp = tail;
		tail = tail->prev;	
		tail->next = NULL;
		printf(" %d deleted \n", temp->data);
		free(temp);
		return;
	}
	
	--nth;	
	while (--nth) 
		cur = cur->next;

	temp = cur->next;
	cur->next = cur->next->next;
	cur->next->prev = cur;
	printf(" %d deleted \n", temp->data);
	free(temp);
	
	return;
}

void deleteitem(int data)
{
	printf("%s: %d - ", __FUNCTION__, data);
	NODE *cur = head;
	NODE *temp = NULL;

	if (head == NULL) {
		assert(tail == NULL);
		printf("empty list \n");
		return;
	}

	if (head->data == data) {
		temp = head;
		// One node list
		if (head == tail) {
			head = tail = NULL;
			printf("%d deleted\n", temp->data);
			free(temp);
			return;
		}			
		head = head->next;
		head->prev = NULL;	
		printf("%d deleted\n", temp->data);
		free(temp);
		return;
	}	

	while (cur != NULL) {
		if (cur->data == data) {
			temp = cur;
			if (cur == tail) {
				tail = tail->prev;
				tail->next = NULL;
			} else {
				cur->prev->next = cur->next;
				cur->next->prev = cur->prev;
			}
			
			printf("%d deleted\n", temp->data);
			free(temp);
			return;
		}
		cur = cur->next;
	}
	
	printf("%d not present \n", data);

	return;
}

void deletelist()
{
	printf("%s: ", __FUNCTION__);
	NODE *cur = head;
	NODE *temp;
	
	while (cur != NULL) {
		temp = cur;
		cur = cur->next;
		free(temp);
	}
	
	head = tail = NULL;
	
	printf(" done \n");

	return;
}


int main()
{
	addfront(1); display();
	addfront(2); display();
	addfront(3); display();
	addfront(4); display();

	addrear(5); display();
	addrear(6); display();
	addrear(7); display();
	addrear(8); display();
	addrear(9); display();

	deletelist(); display();
	deletelist(); display();

	/*
	addafter(10, 5); display();
	addafter(20,10); display();
	addafter(20, 9); display();
	addafter(21, 20); display();
	addrear(22); display();

	addbefore(30, 3); display();
	addbefore(31, 4); display();
	addbefore(32, 5); display();
	addbefore(33, 299); display();

	addnth(40, 10); display();
	addnth(41, 0); display();
	addnth(42, 1); display();
	addnth(43, length()); display();
	addnth(44, length()+1); display();
	*/

	return 0;
}
