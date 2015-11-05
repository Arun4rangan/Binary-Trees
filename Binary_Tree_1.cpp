//	Binary Tree  
//
//	Binary tree that stores the numbers within array. Then it prints each stem. 
// 
//
//	ALGORITHM
//	========== 
//	Takes the number from the array and compares it node values, if node value is greater then the program sets node pointer to node->bigger	
//	and if the node->bigger is null, then new node is created. If is a smaller value than the node value then, it checks node->smaller 
//	to see if its available, if its not null, then node is set to node->smaller, and the function is repeated. Once a null pointer is found that 
//	matches the condition, it creates a new node at that point. 
//
//
//
// Parameters  - Main               
// ==========                
//	  paths			Initalize array to print stems
// array_numbers[]	Numbers that get appended to the binary tree
// a,len,check,tru	Iterative values
//	 *root			To keep the root of the binary tree 
//	 *node			Memorry allocated vaiable to store root value 
//	  
//
// Parameters  - make_newnode            
// ==========     
//   *new_node     Memory allocated variable to store the new node information
//
// Parameters  - print_tree          
// ==========     
//    b     		Iterative variable 
//


#include<stdlib.h>
#include <stdio.h>
#include <string.h>

// binary node structure to store value
struct numbers{
	struct numbers *bigger;
	struct numbers *smaller;
	int value;
};

// declaring make_newnode function 
void make_newnode(struct numbers *ptr, int val);

// declaring print_tree function 
void print_tree(struct numbers *node, int path[], int len);

// global declared stucture used to allocate memory 
struct numbers first;

int main(){
	//initalizing iterative values 
	int a = 0;
	int len = -1;
	int check = 0;
	int tru = 0;
	
	//initalizing iterative arrays
	int paths[30] = {'\0'};
	int array_numbers[] = {1,5,7,9,34,-1,48,9,14,15,11,12,'\0'};
	
	// FUTURE ADDITION: MAKE USER ADD TO array_numbers VARIABLE 
	
	//created a root pointer 
	struct numbers *root;
	
	//memory allocated to the root pointer and added value to the root value
	struct numbers *node = (numbers*)malloc(sizeof(first));
	root = node;
	node->value = 10;
	node->bigger = NULL;
	node->smaller = NULL;
	
	//Algorithum to seperate numbers into binary trees
	while( array_numbers[a]!= '\0'){
		node = root;
		while(tru == 0){
			if(array_numbers[a]>node->value){
				if(node->bigger == NULL){
					make_newnode(node,array_numbers[a]);
					tru = 1;
				}else{
					node = node->bigger;
				}
			}else{
				if(node->smaller == NULL){
					make_newnode(node,array_numbers[a]);
					tru = 1;
				}else{
					node = node->smaller;
				}
			}
		}
		tru =0;
		a++;
	}
	
	//setting node to the root node to print stems within tree
	node = root;
	
	//passing root node to print_tree function, along with stem array and variable that checks the length of node
	print_tree(node, paths, len);
	
	
	//FUTURE ADDITION: A ALGORITHM TO FREE ALL THE NODES WITHIN TREE
	
	return 0;
};

void make_newnode(struct numbers *ptr, int val){
	//Allocates memory to new_node variable
	struct numbers *new_node = (numbers*)malloc(sizeof(first));
	
	//sets value to the node->value and all the pointer variables to NULL
	new_node->value = val;
	new_node->bigger = NULL;
	new_node->smaller = NULL;
	
	// depending on the head node, new_node will be added to correct pointer.
	if(ptr->value >= val){
		ptr->smaller = new_node;
	}else{
		ptr->bigger = new_node;
	}
	
};

void print_tree(struct numbers *node, int path[] , int len){
	//Increase the length of the path 
	len ++;
	
	//Checks if there is a node that has both bigger and smaller pointers active
	//if so, it sends both memory to this function again after appending the value found in the path
	//Creates two different paths by sending two seperate path to the function again  
	if (node->smaller != NULL && node->bigger != NULL){
		path[len]= node->value;
		print_tree(node->smaller,path,len);
		print_tree(node->bigger,path,len);
		return;
	}
	else{
		//checks if smaller pointer is active and does recursive algorithum 
		if(node->smaller != NULL){
			path[len]= node->value;
			node = node->smaller;
			print_tree(node, path, len);
			return;
		}
		//checks if bigger pointer is active and does recursive algorithum 
		if(node->bigger != NULL){
			path[len]= node->value;
			node = node->bigger;
			print_tree(node, path,len);
			return;
		}
		//if poth pointers in a node is NULL then it prints the path up to that node
		if(node->smaller == NULL & node->bigger == NULL){		
			int b = 0;
			while(b < len){
				printf("%d",path[b]);
				printf(" -> ");
				b++;
			}
			b++;
			printf("%d",node->value);	
			printf("\n");
			return;
		}
	}
}
