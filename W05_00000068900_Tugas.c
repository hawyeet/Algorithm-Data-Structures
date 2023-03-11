#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_CHARACTERS 100

typedef struct Song {
	char singer[MAX_CHARACTERS];
	char album[MAX_CHARACTERS];
	char title[MAX_CHARACTERS];
	int year;
	struct Song *next, *prev;
} Song;

Song *head = NULL;
Song *tail = NULL;
Song *node = NULL;

void printMenu();
Song *addNode(char *singer, char *album, char *title, int year, Song **tail);
void fscanfData();
void fprintfData();
void showData();
void inputData();
void eraseData();

int main(){

	int choice;

	do {
		printMenu();
		scanf("%d", &choice);
		printf("\n");

		switch (choice) {
		case 1:
			fscanfData();

			break;
		case 2:
			break;
		case 3:
			break;
		case 4:
			// free memory
			exit(0);
		}

	} while (choice >= 1 || choice <= 4);

	return 0;
}

void printMenu() {
	puts("Welcome to song database");
	puts("1. Show songs");
	puts("2. Add songs");
	puts("3. Erase last added song");
	puts("4. Exit");
	printf("Choice: ");
}

Song *addNode(char *singer, char *album, char *title, int year, Song **tail) {
	Song *newNode = (Song*) malloc(sizeof(Song*));

	strcpy(newNode->singer, singer);
	strcpy(newNode->album, album);
	strcpy(newNode->title, title);
	newNode->year = year;
	newNode->next = NULL;
	newNode->prev = (*tail)->prev;
	(*tail)->next = newNode;
	*tail = newNode;

	return newNode;
}

void fscanfData() {
	int i = 0;

	FILE *fP = fopen("playlist.txt", "r");
	while (!feof(fP)) {
		Song s;
		fscanf(fP, "%[^*]*%[^*]*%[^*]*%d\n", s.singer, s.album, s.title, &s.year);
		node = addNode(s.singer, s.album, s.title, s.year, &tail);

		if (head == NULL) {
			head = node;
		}
		else {
			Song *current = head;
			while(current->next != NULL) {
			current = current->next;
			}
			current->next = node;
		printf("%s %s %s %d\n", s.singer, s.album, s.title, s.year);
		}
	}

	fclose(fP);
}

void fprintfData(Song *head) {
	Song *temp;
	temp = head;
	// int j = 1;
	// while(temp != NULL) {
	// 	printf("Data ke %d\n", j);
	// 	printf("NIM     : %d\n", temp->nim);
	// 	printf("Nama    : %s\n", temp->nama);
	// 	printf("Jurusan : %s\n", temp->jurusan);
	// 	temp = temp->next;
	// 	j++;
	// }
}