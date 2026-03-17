#include <stdio.h> //---> standard input printf scanf just the essentials
#include <stdlib.h> // dynamic memory functions like malloc and free which we need
#include <string.h> // str functions for string manipulation
typedef struct node {
	char *question;
	struct node *no;
	struct node *yes;
} node; // created a node struct which has a char pointer and two struct pointers yes and no, giving an idea that theres going to be a question and its answer is yes/no depending on that the two struct pointers will point to a struct



int yes_no(char *question){
	char answer[3];
	printf("%s? (y/n): ", question);
	fgets(answer, 3, stdin);
	return answer[0] == 'y';
}
//created a function, give it the pointer to question array (decay), create an answer array ask the question to user. and expect answer in y/n. using fgets we take the answer and return if answer's 0th index is char y so itll return 0 or 1 based on comaprison answer

node* create(char *question){
	node *n = malloc(sizeof(node));
	n->question = strdup(question);
	n->no = NULL;
	n->yes = NULL;
	return n;
}
// next up is the function that creates the actual nodes in the heap memory and returns the ptr since question is being taken from an array in the stack we need to duplicate it with strdup so that a copy of it will exist inside the heap and the node will use that, then since we dont know the answer to the question is yes or no we just keep it NULL and finally we return n i.e. the address. 
//NOTE: we have to free the heap allocation of the question field first before node or the way to access it will be lost


void release(node *n){
	if (n) {
		if (n->no)
			release(n->no);
		if (n->yes)
			release(n->yes);
		if (n->question)
			free(n->question);
		free(n);
	}
} //heres the free function that i was talking about, first pass it the pointer to the node, then if its not NULL then check if n->no is not NULL, if true then recursively call the function for that so now n->no is a ptr gets send back to release as *n since it has no subfields itll get freed at the end by free(n), similarly for n->yes. next for n->question since we used strdup just free it using free. cant pass it to release because it expects a node pointer and question is a char ptr

int main(){
	char question[80]; // initialise two arrays one for question and one for
	char suspect[20]; // supposedly suspect name
	node *start_node = create("Does suspect have a mustache"); //create a node (first node) and give the question, i.e. string literal to the create function and hence pointer to D will be passed to create(), it will do its work and initialise the field values and return the ptr
	start_node->no = create("Loretta Barnsworth"); // then using that ptr we set the no field with a pointer to another node with the question field as Loretta
	start_node->yes = create("Vinny the Spoon"); // similarly for yes, basically if no moustache then someone and if yes then someone else

	node *current;  // declare a node pointer called current. since we havent initialised it, it contains random address
	do {
		current = start_node;  // a do while loop so it will run atleast once before checking the condition. now current is pointing to the same address as start_node
		while (1) { // keep running infinitely
			if (yes_no(current->question)){    //from the selected node(currently start_node, ask the question by passing it to the yesno fun, record the answer and if answer is yes, move inside the if block, next check if the value of start_node's yes ptr field is not NULL, if true current will point to current->yes which means current will point to start_node->yes, which is the address to the node which contains vinny the spoon
				if (current->yes) {
					current = current->yes;
				} else {
					printf("SUSPECT IDENTIFIED\n");
					break;
				}
			} else if (current->no) {
				current = current->no;
			} else {
				/* make the yes-node the new suspect name*/
				printf("Who's the suspect? ");
				fgets(suspect, 20, stdin);
				node *yes_node = create(suspect);
				current->yes = yes_node;
				
				/* make the no-node a copy of this question*/
				node *no_node = create(current->question);
				current->no = no_node;
				
				/*Then replace this question with the new question*/
				printf("give me a question that is TRUE for %s but not for %s? ", suspect, current->question);
				fgets(question, 80, stdin);
				current->question = strdup(question);
				break;
			}
		}
	} while(yes_no("Run again"));
	release(start_node);
	return 0;
}
		
				
			
			
			
			
			
			
