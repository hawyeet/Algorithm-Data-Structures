#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_CHARACTERS 20

typedef struct Song {
	char singer[MAX_CHARACTERS];
	char album[MAX_CHARACTERS];
	char title[MAX_CHARACTERS];
	int year;
	struct Song *next, *prev;
} Song;

Song *head = NULL;
Song *node = NULL;
Song *current = NULL;

void printMenu();
Song *addNode(Song *head, char *singer, char *album, char *title, int year);
void fscanfData();
void fprintfData();
void showData();
void inputData();
void eraseData();
void freeMemory();

int main() {

	int choice;
	fscanfData();
	do {
		printMenu();
		scanf("%d", &choice);
		printf("\n");

		switch (choice) {
		case 1:
			showData();
			current = head;
			break;
		case 2:
			inputData();
			fprintfData();
			break;
		case 3:
			current = head;
			eraseData();
			fprintfData();
			break;
		case 4:
			freeMemory();
			exit(0);
		}
	} while (choice >= 1 && choice <= 4);

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

Song *addNode(Song *head, char *singer, char *album, char *title, int year) {
    Song *newNode = (Song*) malloc(sizeof(Song));

    if (newNode == NULL) {
        fprintf(stderr, "Error: failed to allocate memory for new node.\n");
        return NULL;
    }

    strcpy(newNode->singer, singer);
    strcpy(newNode->album, album);
    strcpy(newNode->title, title);
    newNode->year = year;
    newNode->next = NULL;
    newNode->prev = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        Song *lastNode = head;
        while (lastNode->next != NULL) {
            lastNode = lastNode->next;
        }
        lastNode->next = newNode;
        newNode->prev = lastNode;
    }

    return newNode;
}

void fscanfData() {
    Song s;
    Song *current = NULL;
    FILE *fP = fopen("playlist.txt", "r");
    
    if (fP == NULL) {
        printf("Error opening file.\n");
        return;
    }
    
    while (fscanf(fP, "%[^*]*%[^*]*%[^*]*%d\n", s.singer, s.album, s.title, &s.year) == 4) {
        Song *newNode = addNode(head, s.singer, s.album, s.title, s.year);
        
        if (head == NULL) {
            head = newNode;
            current = head;
        } else {
            current->next = newNode;
            newNode->prev = current;
            current = current->next;
        }
    }
    
    fclose(fP);
}
	
void fprintfData() {
	Song *current = head;
    FILE *fP = fopen("playlist.txt", "w");
    
    if (fP == NULL) {
        printf("Error opening file.\n");
        return;
    }
    
    while (current != NULL) {
        fprintf(fP, "%s*%s*%s*%d\n", current->singer, current->album, current->title, current->year);
        current = current->next;
    }
    
    fclose(fP);
}
	
void showData() {
    Song *current = head;

    printf("%-20s %-30s %-20s %-10s\n", "Singer", "Song Title", "Album", "Released Date");
    printf("--------------------------------------------------------------------------------------\n");

    while (current != NULL) {
        printf("%-20s %-30s %-20s %-10d\n", current->singer, current->title, current->album, current->year);
        current = current->next;
    }

    printf("\n");
}

void inputData() {
	
    Song *input = (Song*) malloc(sizeof(Song));
    if (input == NULL) {
        fprintf(stderr, "Error: failed to allocate memory for input.\n");
        return;
    }

    printf("Input Singer     : ");
    scanf("%s", input->singer);
    printf("Album            : ");
    scanf("%s", input->album);
    printf("Title            : ");
    scanf("%s", input->title);
    printf("Released Year    : ");
    scanf("%d", &input->year);
    printf("Data berhasil ditambahkan!\n\n");

    Song *inputNode = addNode(head, input->singer, input->album, input->title, input->year);
    if (head == NULL) {
        head = inputNode;
        current = head;
        printf("%s", current->album);
    } else {
        current = inputNode;
        current->next = NULL;
        inputNode->prev = current;
        current->prev = inputNode->prev;
    }
    
    while (current->next != NULL) {
        current = current->next;
    }
}

void eraseData() {
    if (head == NULL) {
        return;
    }

    Song *temp = head;
    if (temp->next == NULL) {
        head = NULL;
        free(temp);
        return;
    }

    while (temp->next->next != NULL) {
        temp = temp->next;
    }

    Song *trash = temp->next;
    temp->next = NULL;
    free(trash);
}

void freeMemory() {
    Song *temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}
