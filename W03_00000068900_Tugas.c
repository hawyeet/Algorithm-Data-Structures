#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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

float finalGrade(int a, int b, int c);

int main() {
	
	// open file and read to the struct variables 
	int i = 0;
	data Students[100];
	data Scores[100];

	FILE *fD = fopen("dataMahasiswa.txt", "r");
	while(!feof(fD)) {
	 	data st;
	 	fscanf(fD, "%d#%[^#]#%[^\n]\n", &st.nim, st.details.student.name, st.details.student.major);
	 	Students[i] = st;
	 	i++;
	}

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
	int choice, j, x, y, z;
	float w;
	do {
		printf("Welcome to simple student database (%d/100)\n", i);
		puts("1. Show all students");
		puts("2. Input new student");
		puts("3. Exit");
		printf("Choose: ");
		scanf("%d", &choice);
		printf("\n");
		
		switch(choice) {
		case 1:
			printf("                                             List of Student Information                                             \n");
			printf("-----------------------------------------------------------------------------------------------------------------------\n");
			printf("| No. |     NIM     | Name                           | Major                | Tugas | UTS | UAS | Nilai Akhir | Grade |\n");
			printf("-----------------------------------------------------------------------------------------------------------------------\n");
			for(j = 0 ; j < i; j++){
				printf("| %-3d | 000000%5d | %-30s | %-20s |  %3d  | %3d | %3d |    %5.1f    |   %-2s  |\n", j + 1,
				Students[j].nim, Students[j].details.student.name, Students[j].details.student.major,
				Scores[j].details.score.tugas, Scores[j].details.score.uts, Scores[j].details.score.uas,
				Scores[j].details.score.final, Scores[j].details.score.grade);
			}
			printf("Press any key to continue");
			getchar();
			printf("\n\n");
			break;
		case 2:
			if(i<100){
				// inserting info
				puts("  Insert Student Information");
				puts("------------------------------");
				printf("NIM	: ");
				scanf("%d", &Students[i].nim);
				Scores[i].nim = Students[i].nim;
				fflush(stdin);
				printf("Name	: ");
				scanf("%[^\n]", Students[i].details.student.name);
				fflush(stdin);
				printf("Major	: ");
				scanf("%[^\n]", Students[i].details.student.major);
				fflush(stdin);
				printf("Tugas	: ");
				scanf("%d", &Scores[i].details.score.tugas);
				x = Scores[i].details.score.tugas;
				fflush(stdin);
				printf("UTS	: ");
				scanf("%d", &Scores[i].details.score.uts);
				y = Scores[i].details.score.uts;
				fflush(stdin);
				printf("UAS	: ");
				scanf("%d", &Scores[i].details.score.uas);
				z = Scores[i].details.score.uas;
				fflush(stdin);
				w = Scores[i].details.score.final = finalGrade(x, y, z);
				
				// calculating grade
				if(w >= 95 && w <= 100){
					strcpy(Scores[i].details.score.grade, "A+");
				}
				else if(w >= 85 && w <= 94.99){
					strcpy(Scores[i].details.score.grade, "A");
				}
				else if(w >= 75 && w <= 79.99){
					strcpy(Scores[i].details.score.grade, "B+");
				}
				else if(w >= 70 && w <= 74.99){
					strcpy(Scores[i].details.score.grade, "B");
				}
				else if(w >= 65 && w <= 69.99){
					strcpy(Scores[i].details.score.grade, "C");
				}
				else if(w >= 60 && w <= 64.99){
					strcpy(Scores[i].details.score.grade, "C-");
				}
				else if(w >= 55 && w <= 59.99){
					strcpy(Scores[i].details.score.grade, "D");
				}
				else if(w >= 0 && w <= 54.99){
					strcpy(Scores[i].details.score.grade, "E");
				}
				
				// fprintf
				int k;
				fD = fopen("dataMahasiswa.txt", "w");
				for(k = 0; k <= i; k++) {
				 	fprintf(fD, "000000%d#%s#%s\n", Students[k].nim, Students[k].details.student.name, Students[k].details.student.major);
				}
			
				k = 0;
				fN = fopen("nilaiMahasiswa.txt", "w");
				for(k = 0; k <= i; k++) {
					fprintf(fN, "000000%d#%d#%d#%d#%.2f#%s\n", Scores[k].nim, Scores[k].details.score.tugas, Scores[k].details.score.uts, Scores[k].details.score.uas, Scores[k].details.score.final, Scores[k].details.score.grade);
				}	
				
				fclose(fD);
				fclose(fN);	
					
				i++;
				printf("Inserting data\nNew student added\nPress any key to continue");
				getchar();
				printf("\n\n");
				break;
			}
			else {
				printf("Database is full\nPress any key to continue\n");
				getchar();
				printf("\n");
				break;
			}
		case 3:
			exit(1);
		}
		choice = 0;
	} while(choice<1 || choice>2);

	return 0;
}

float finalGrade(int a, int b, int c)
{
	float x = (a*0.3 + b*0.3 + c*0.4);
	return x;
}
