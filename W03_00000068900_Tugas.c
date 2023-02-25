#include <stdio.h>

typedef struct {
	int nim;
	union{
		struct {
			char name[30];
			char major[20];
		} student;

		struct {
			int tugas;
			int uts;
			int uas;
			float final;
			char grade[2];
		} score;
	} details;	
} data;

int main() {
	
	// open file and read to the struct variables 
	int i = 0;
	data Students[100];
	data Scores[100];

	// FILE *fD = fopen("dataMahasiswa.txt", "r");
	// while(!feof(fD)) {
	// 	data st;
	// 	fscanf(fD, "%d#%[^#]#%[^\n]", &st.nim, st.details.student.name, st.details.student.major);
	// 	Students[i] = st;
	// 	}

	i = 0;
	FILE *fN = fopen("nilaiMahasiswa.txt", "r");
	while(!feof(fN)) {
			data sc;
			fscanf(fN, "%d#%d#%d#%d#%f#%s", &sc.nim, &sc.details.score.tugas, &sc.details.score.uts, &sc.details.score.uas, &sc.details.score.final, sc.details.score.grade);
			Scores[i] = sc;
			i++;
		}		
	
	fclose(fD);
	fclose(fN);

	// menu
	int choice;
	do {
		printf("Welcome to simple student database (%d/100)\n", i);
		puts("1. Show all students");
		puts("2. Input new student");
		puts("3. Exit");
		printf("Choose: ");
		scanf("%d", &choice);
		printf("\n");
	} while(choice<1 || choice>3);

	int j;
	switch(choice) {
		case 1:
			printf("                                             List of Student Information                                             \n");
			printf("-----------------------------------------------------------------------------------------------------------------------\n");
			printf("| No. |     NIM     | Name                           | Major                | Tugas | UTS | UAS | Nilai Akhir | Grade |\n");
			printf("-----------------------------------------------------------------------------------------------------------------------\n");
			for(j = 0 ; j < i; j++){
				printf("| %-3d | 000000%5d | %-30s | %-20s |\n", j + 1,
				Students[j].nim, Students[j].details.student.name, Students[j].details.student.name);
				//  %3d | %3d | %3d | %5.1f | %-2s |
				// Scores[j].details.score.tugas, Scores[j].details.score.uts, Scores[j].details.score.uas,
				// Scores[j].details.score.final, Scores[j].details.score.grade);
			}
			break;
		case 2:
			// input();
			break;
		case 3:
			break;
	}

	return 0;
}