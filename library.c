// Imports
//---------------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//---------------------------------------------
// Definitions
//---------------------------------------------
#define MAX_STRING_LENGTH 50
//---------------------------------------------
// Type definitions to make the code more readable
//---------------------------------------------
typedef struct node {
    char *name;
    char *author;
    struct node * next;
} Node;
//---------------------------------------------
// Global Variable
//---------------------------------------------
Node* head = NULL;
//---------------------------------------------
// Function protoypes
//---------------------------------------------
void insert(char *q, char *r);
void print_the_list();
void bsort();
void search();
void omit();
//---------------------------------------------
// Main Function :
// Ask the user to insert some books then
// print the list of books
// normally or sorted by book name
//---------------------------------------------
int main() {
    head = NULL; //Initially head is null

    char *book_name, *book_author;

    int n,i; // Number of book that the user want to enter
    printf("How many books you want to enter?: \n");
    scanf("%d", &n);

    for (i = 1; i <= n; i++){ // Loop iterate the number of times we have books in quantity.
        // To clear buffer memory
        fflush(stdin);
        printf("Enter a Book name: ");
        fflush(stdin); // To clear buffer memory
        book_name = (char*) malloc(MAX_STRING_LENGTH*sizeof(char));
        gets(book_name); // Same as scanf
        printf("Author: ");
        book_author = (char*) malloc(MAX_STRING_LENGTH*sizeof(char));
        gets(book_author);

        // add it to the list
        insert(book_name, book_author);
        }

    print_the_list();
    char d;
    printf("Do you want to sort the data in ascending order?(y/n): \n\t");
    scanf("%c", &d);
    if (d == 'y') {
        printf("Sorting the list!");
        bsort();
    } else
        printf("alright!");

    print_the_list();
    omit();
    printf("Printing the modified list");
    print_the_list();
    search();
    return 0;
}
//---------------------------------------------
// insert(name of the book, authro of the book):
// O(n_of_element_in_the_list)
// append the new book the global list
//---------------------------------------------
void insert(char* name, char* author){ //Adding items at the end of linked list
    // create and initialize the new node
    Node* new_node = (Node* ) malloc(sizeof(Node));
    new_node->author = author;
    new_node->name   = name;
    new_node->next   = NULL; // Since we are adding a node to the end, we are linking it to NULL.

    // if the list is empty then add the node as the head of the list
    if (head == NULL) {
        head = new_node;
    }
    else {
        Node * temp = head;
        // Traverse the list till the end
        while (temp->next != NULL)
            temp = temp->next;
        // add the new node as the successor of the last node
        temp->next = new_node;
    }
}

//---------------------------------------------
// print_the_list():
// O(n_of_element_in_the_list)
// print the whole content of the global list
//---------------------------------------------
void print_the_list() //Traversing
{
    printf("\n");
    printf("The Library data is as follows: \n");
    Node* temp=head;
    printf("\n");
    while(temp!=NULL)
    {
        printf("%25s",temp->name);
        printf("%25s",temp->author);
        temp=temp->next;
        printf("\n");
    }
}

//---------------------------------------------
// sort():
// O(n_of_element_in_the_list^2)
// sort the whole list by name in Ascending Order
//---------------------------------------------
void bsort(){ //Bubble Sort Algorithm to arrange Library data in Ascending Order
    char *swap_ptr_name, *swap_ptr_author;
    // for each node of the list
    Node* current_minimum;
    Node* current_node;
    for (current_minimum = head; current_minimum != NULL; current_minimum = current_minimum->next) {
        // for each node after the current_minimum
        for (current_node = current_minimum->next; current_node != NULL;  current_node = current_node->next) {
            // if the current_node is less than the current_minimum swap them
            if (strcmp(current_node->name,current_minimum->name) < 0) {
                // Save the name and author of the current_minimum
                swap_ptr_name   = current_minimum->name;
                swap_ptr_author = current_minimum->author;

                // Place the current node as the minimum
                current_minimum->name   = current_node->name;
                current_minimum->author = current_node->author;

                // Place the old minimum in the place of the current_node
                current_node->name   = swap_ptr_name;
                current_node->author = swap_ptr_author;
            }
        }
    }
}

void search()
{
    char *keyword;
    Node* current=head;
    printf("Enter a book name or author name to search: ");
    fflush(stdin);
    keyword=(char*) malloc(MAX_STRING_LENGTH*sizeof(char));
    gets(keyword);
    for (current=head;current!=NULL;current=current->next)
    {
        if ((strcmp(current->name,keyword)==0) || (strcmp(current->author,keyword)==0)) {//||(strcmp(current->author,keyword))==0) {
            puts(current->name);
            puts(current->author);
        }
    }
}


void omit()
{
    char *keyword;
    char d;
    Node* current=head;
    Node* temp;
    printf("Enter a book name or author name to delete: ");
    fflush(stdin);
    keyword=(char*) malloc(MAX_STRING_LENGTH*sizeof(char));
    gets(keyword);
    for (current=head;current!=NULL;current=current->next)
    {
        if ((strcmp(current->name,keyword)==0) || (strcmp(current->author,keyword)==0)) {//||(strcmp(current->author,keyword))==0) {
            puts(current->name);
            puts(current->author);
            printf("Are you sure you want to delete[y/n]: ");
            fflush(stdin);
            scanf("%c",&d);
            if (d=='y') {
                if (current==head)
                {
                    head=current->next;
                    free(current);
                }
                else
                {
                    temp->next=current;
                    temp->next=current->next;
                    free(current);
                }
            }
        }
    }
}
