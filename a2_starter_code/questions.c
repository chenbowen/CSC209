#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "questions.h"

Node * get_list_from_file (char *input_file_name) {
	Node * head = NULL;
	Node * tail = NULL;
    //read lines and add to the list
    FILE *input_file=fopen(input_file_name, "r");
    if(input_file==NULL) {
    	fprintf(stderr, "Error opening file.\n");
    }
    char line[MAX_LINE];
    while(fgets(line, MAX_LINE, input_file)!=NULL) {
    	line[strcspn(line, "\r\n")] = '\0';
        Node * temp = malloc(sizeof(Node));
    	temp->str = malloc(sizeof(char)*(strlen(line) + 1));
    	strcpy(temp->str, line);
        temp->next = NULL;
        if(head == NULL) {
            head = temp;
            tail = temp;
        }
        else {
            tail->next = temp;
            tail = tail->next;
        }
    }
    int error = fclose(input_file);
    if(error == 1) {
    	fprintf(stderr, "Error closing file\n");
    }
	return head;
}

void print_list (Node *head) {
	Node *temp = head;
	while(temp != NULL) {
		printf("%s\n", temp->str);
        temp = temp->next;
	}
}

void free_list (Node *head) {
    if(head!=NULL) {
	   free_list(head->next);
	   free(head->str);
	   free(head);
    }
}