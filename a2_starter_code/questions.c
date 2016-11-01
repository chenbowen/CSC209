#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "questions.h"

#define N 129
Node * get_list_from_file (char *input_file_name) {
	Node * head = NULL;
	
    //read lines and add to the list
    File *input_file=fopen(input_file_name, "r");
    if(input_file==NULL) {
    	fprintf(stderr, "Error opening file.\n");
    }
    head = malloc(sizeof(Node));
    Node * tail = head;
    char line[N];
    while(fgets(line, N, input_file)!=NULL) {
    	line[strcspn(line, "\r\n")] = '\0';
    	tail->str = malloc(sizeof(char)*(strlen(line) + 1));
    	tail->str = line;
    	tail->next = malloc(sizeof(Node));
    	tail = tail->next;
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
	}
}

void free_list (Node *head) {
	free_list(head->next);
	free(head->str);
	free(head);
}