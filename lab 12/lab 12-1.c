#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
	int sno;
	char name[20];
	int midg;
	int final;
} node;

void createfle() {
	FILE *f;
	if ((f = fopen("data.txt", "w")) == NULL) {
		printf("File cannot be opened\n");
		return;
	}
	fclose(f);
}

void addrecord() {
	FILE *f;
	node std;
	if ((f = fopen("data.txt", "a")) == NULL) {
		printf("File cannot be opened\n");
		return;
	} else {
		printf("Student ID: ");
		scanf("%d", &std.sno);
		printf("Student Name: ");
		scanf("%s", std.name);
		printf("Student Midterm Grade: ");
		scanf("%d", &std.midg);
		printf("Student Final Grade: ");
		scanf("%d", &std.final);

		fprintf(f, "%d %s %d %d\n", std.sno, std.name, std.midg, std.final);
	}
	fclose(f);
}

void listrecords() {
	FILE *f;
	node std;
	if ((f = fopen("data.txt", "r")) == NULL) {
		printf("File cannot be opened\n");
		return;
	} else {
		printf("Student ID  |  Student Name  |  Midterm Grade  |  Final Grade\n");
		printf("------------------------------------------------------------\n");
		while (fscanf(f, "%d %s %d %d", &std.sno, std.name, &std.midg, &std.final) != EOF) {
			printf("%-11d | %-14s | %-15d | %-12d\n", std.sno, std.name, std.midg, std.final);
		}
		printf("------------------------------------------------------------\n");
	}
	fclose(f);
}

void researchbyname() {
	char sn[20];
	int ret;
	FILE *f;
	node std;
	printf("Enter a name for information: ");
	scanf("%s", sn);
	
	if ((f = fopen("data.txt", "r")) == NULL) {
		printf("File cannot be opened\n");
		return;
	} else {
		printf("Student ID  |  Student Name  |  Midterm Grade  |  Final Grade\n");
		printf("------------------------------------------------------------\n");
		while (fscanf(f, "%d %s %d %d", &std.sno, std.name, &std.midg, &std.final) != EOF) {
			ret = strcmp(sn, std.name);
			if (ret == 0) {
				printf("%-11d | %-14s | %-15d | %-12d\n", std.sno, std.name, std.midg, std.final);
				fclose(f);
				return;
			}
		}
		printf("Student not found.\n");
	}
	fclose(f);
}

int main() {
	char c;
	while (1) {
		printf("**************************************\n");
		printf("1 - Create a File\n");
		printf("2 - Add Record\n");
		printf("3 - List Records\n");
		printf("4 - Research by Name\n");
		printf("**************************************\n");
		printf("Enter your choice: ");
		scanf(" %c", &c);
		printf("**************************************\n");

		switch (c) {
			case '1':
				createfle();
				break;
			case '2':
				addrecord();
				break;
			case '3':
				listrecords();
				break;
			case '4':
				researchbyname();
				break;
			default:
				printf("Invalid option selected\n");
				exit(0);
		}
	}
	return 0;
}

