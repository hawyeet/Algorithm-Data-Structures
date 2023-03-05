#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// #include <malloc.h>

typedef struct Mahasiswa {
	char nama[100];
	char jurusan[30];
	int nim;
	struct Mahasiswa *next;
}	Mahasiswa;

Mahasiswa *createNewNode(int nim, char *nama, char *jurusan);
void printLinkedlist(Mahasiswa *head);
void deleteAllData(Mahasiswa *head);
void deleteFirstData(Mahasiswa *head);
void deleteByNim(Mahasiswa *head, int a);

int main() {
	int choice, b;
	Mahasiswa *head, *node, *a;
	head = NULL;
	a = node = (Mahasiswa*) malloc(sizeof(Mahasiswa));
	
	node = createNewNode(14026, "James Christian Wira", "Informatika");
	head = node;

	Mahasiswa *tail;
	tail = node;

	node = createNewNode(17492, "Matthew Evans", "Informatika");
	tail->next = node;
	tail = node;

	node = createNewNode(13633, "Justin Susanto", "Informatika");
	node->next = head;
	head = node;

	do {
		puts("Welcome to simple student database");
		puts("1. Input new student");
		puts("2. Show all students");
		puts("3. Delete all students");
		puts("4. Delete first student");
		puts("5. Delete student by NIM");
		printf("Choose: ");
		scanf("%d", &choice);
		printf("\n");
		
		switch(choice) {
			case 1:
				puts("Insert student information");
				printf("NIM       : ");
				scanf("%d", &a->nim);
				printf("Nama      : ");
				scanf("%s", a->nama);
				printf("Jurusan   : ");
				scanf("%s", a->jurusan);
				
				if (head != NULL) {
					node = createNewNode(a->nim, a->nama, a->jurusan);
					tail->next = node;
					tail = node;
				}
				else {
					node = createNewNode(a->nim, a->nama, a->jurusan);
					head = node;
					tail = node;
				}
				
				printf("\n");
				break;
			case 2:
				printLinkedlist(head);
				printf("\n");
				break;
			case 3:
				deleteAllData(head);
				printf("\n");
				break;
			case 4:
				deleteFirstData(head);
				printf("\n");
				break;
			case 5:
				printf("Enter NIM of student to delete: ");
				scanf("%d", &b);
				deleteByNim(head, b);
				break;
			case 6:
				exit(0);
		}
		choice = 0;
	} while(choice<1 || choice>5);

	// printf("Data SEBELUM di hapus\n");
	// printLinkedlist(head);

	// Mahasiswa *trash, *temp;
	// trash = head;
	// while(strcmp(trash->next->nama, "James Christian Wira") == 1){
	// 	printf("%s\n", trash->nama);
	// 	trash = trash->next;
	// }
	// if (trash->nim == head->nim) printf("true\n");
	// else printf("false\n");
	// temp = trash;
	// trash = trash->next;
	// temp->next = trash->next;
	// tail->next = NULL;
	// free(trash);

	// printf("Data SETELAH di hapus\n");
	// printLinkedlist(head);

	return 0;
}

Mahasiswa *createNewNode(int nim, char *nama, char *jurusan) {
	Mahasiswa *newNode = (Mahasiswa*)malloc(sizeof(Mahasiswa));
	newNode->nim = nim;
	strcpy(newNode->nama, nama);
	strcpy(newNode->jurusan, jurusan);
	newNode->next = NULL;
	return newNode;
}

void printLinkedlist(Mahasiswa *head) {
	Mahasiswa *temp;
	temp = head;
	int i = 1;
	while(temp != NULL) {
		printf("Data ke %d\n", i);
		printf("NIM      : %d\n", temp->nim);
		printf("Nama     : %s\n", temp->nama);
		printf("Jurusan  : %s\n\n", temp->jurusan);
		temp = temp->next;
		i++;
	}
}

void deleteAllData(Mahasiswa *head) {
	Mahasiswa *trash;
	while(head != NULL) {
		trash = head;
		free(head);
		head = head->next;	
	}
}

void deleteFirstData(Mahasiswa *head) {
	Mahasiswa *trash;
	trash = head;
	head = head->next;
	free(trash);
	}

void deleteByNim(Mahasiswa *head, int b) {
	Mahasiswa *trash, *temp;
	trash = head;
	while(trash->nim != b) {
		trash = trash->next;
	}

	temp = trash;
	trash = trash->next;
	temp->next = trash->next;
	trash->next = NULL;
	free(trash);
}