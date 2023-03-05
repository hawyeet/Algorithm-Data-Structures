#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Mahasiswa {
	char nama[100];
	char jurusan[30];
	int nim;
	struct Mahasiswa *next;
}	Mahasiswa;

Mahasiswa *head = NULL;

void inputStudent();
void showStudent();
void deleteAll();
void deleteFirst();
void deleteNIM(int a);

int main() {
	
	int choice, a;
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
				inputStudent();
				printf("\n");
				break;
			case 2:
				showStudent();
				printf("\n");
				break;
			case 3:
				deleteAll();
				printf("\n");
				break;
			case 4:
				deleteFirst();
				printf("\n");
				break;
			case 5:
				printf("Enter NIM to delete : ");
				scanf("%d", &a);
				deleteNIM(a);
				printf("\n");
				break;
			case 6:
				exit(0);
		}
		choice = 0;
	} while(choice<1 || choice>5);
	
	return 0;
}

void inputStudent() {
	Mahasiswa *newNode = (Mahasiswa*) malloc(sizeof(Mahasiswa*));
	
	puts("Insert student information.");
	printf("NIM     : ");
	scanf("%d", &newNode->nim);
	getchar();
	printf("Nama    : ");
	scanf("%[^\n]s", newNode->nama);
	getchar();
	printf("Jurusan : ");
	scanf("%[^\n]s", newNode->jurusan);
	getchar();
	newNode->next = NULL;
	
	if (head == NULL) {
		head = newNode;
	}
	else {
		Mahasiswa *current = head;
		while(current->next != NULL) {
			current = current->next;
		}
		current->next = newNode;
	}
	
}

void showStudent() {
	if (head == NULL) {
		printf("There is no student information.\n");
		return;
	}
	else {
		Mahasiswa *current = head;
		int i = 1;
		while (current != NULL) {
			printf("Data ke %d\n", i);
			printf("NIM      : %d\n", current->nim);
			printf("Nama     : %s\n", current->nama);
			printf("Jurusan  : %s\n\n", current->jurusan);
			current = current->next;
			i++;
		}
	}
}

void deleteAll() {
	while (head != NULL) {
		Mahasiswa *trash = head;
		head = head->next;
		free(trash);
	}
}

void deleteFirst() {
	if (head == NULL) {
        return;
    }
    
    Mahasiswa *trash = head;
    head = head->next;
    free(trash);
}

void deleteNIM(int a) {
	Mahasiswa *trash, *current;
	
	if (head == NULL) {
		printf("There is no student information.\n");
		return;
	}
	else if (head->nim == a) {
		trash = head;
	}
	else {
		while(head->next->nim != a) {
			head->next = head->next->next;
		}
		trash = head->next;
	}
	
	head = head->next;
    free(trash);

}
