#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    int pno;
    char name[40];
    int age;
    char dis[60];
} node;

int menu();
void addrecord();
void printlist();
void searchbyno();
void deleterecord();
void editrecord();

int main() {
    int ch;

    while (1) {
        ch = menu();
        switch (ch) {
            case 1:
                addrecord();
                break;
            case 2:
                printlist();
                break;
            case 3:
                searchbyno();
                break;
            case 4:
                deleterecord();
                break;
            case 5:
                editrecord();
                break;
            case 0:
				exit(0);            
            default:
                printf("Invalid option\n");
        }
    }
    return 0;
}
void addrecord() {
    int enter, i;
    FILE* p;
    node patient;
    if ((p = fopen("records.txt", "a+")) == NULL) {
        printf("File could not be opened\n");
        return;
    }

    printf("How many patients will you enter?\n");
    scanf("%d", &enter);

    for (i = 0; i < enter; i++) {
        printf("No: ");
        scanf("%d", &patient.pno);
        printf("Name: ");
        scanf("%s", patient.name);
        printf("Age: ");
        scanf("%d", &patient.age);
        printf("Disease: ");
        scanf("%s", patient.dis);
		printf("-----------------\n");
        fwrite(&patient, sizeof(node), 1, p);
    }
    fclose(p);
}

void printlist() {
	int pct=0;
    FILE* p;
    node patient;
    if ((p = fopen("records.txt", "r")) == NULL) {
        printf("File could not be opened\n");
        return;
    }
    fseek(p, 0, SEEK_SET);
    while (fread(&patient, sizeof(node), 1, p) == 1) {
        if (patient.pno > 0) {
        	printf("-----------------\n");
            printf("No: %d\n", patient.pno);
            printf("Name: %s\n", patient.name);
            printf("Age: %d\n", patient.age);
            printf("Disease: %s\n", patient.dis);
            printf("-----------------\n");
            pct++;
        }	
    }
    if((pct == 0)){
    		printf("-----------------\n");
        	printf("Not found any records \n");
        	printf("-----------------\n");
        	return;
    pct = 0;
    fclose(p);
	}
}

void searchbyno() {
    FILE* p;
    int sno;
    node patient;
    int found = 0;

    if ((p = fopen("records.txt", "r")) == NULL) {
        printf("File could not be opened\n");
        return;
    }

    printf("Enter the patient code you want to search: ");
    scanf("%d", &sno);

    while (fread(&patient, sizeof(node), 1, p) == 1) {
        if (patient.pno == sno) {
            printf("-----------------\n");
            printf("Name: %s\n", patient.name);
            printf("Age: %d\n", patient.age);
            printf("Disease: %s\n", patient.dis);
            printf("-----------------\n");
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("-----------------\n");
        printf("No patient found with that number\n");
        printf("-----------------\n");
    }

    fclose(p);
}

void deleterecord() {
    FILE* p;
    int dno;
    node patient;
    int found = 0;

    if ((p = fopen("records.txt", "r+")) == NULL) {
        printf("File could not be opened\n");
        return;
    }

    printf("Enter the patient number you want to delete: ");
    scanf("%d", &dno);

    while (fread(&patient, sizeof(node), 1, p) == 1) {
        if (patient.pno == dno) {
            node empty = {0};
            fseek(p, -sizeof(node), SEEK_CUR);
            fwrite(&empty, sizeof(node), 1, p);
            found = 1;
            break;
        }
    }

    if (found) {
        printf("-----------------\n");
        printf("Successfully deleted\n");
        printf("-----------------\n");
    } else {
        printf("-----------------\n");
        printf("No patient found with that number\n");
        printf("-----------------\n");
    }

    fclose(p);
}

void editrecord() {
    FILE* p;
    int eno, editchoice;
    node patient;
    node newp;
    int found = 0;

    if ((p = fopen("records.txt", "r+")) == NULL) {
        printf("File could not be opened\n");
        return;
    }

    printf("Enter the patient number you want to edit: ");
    scanf("%d", &eno);

    while (fread(&patient, sizeof(node), 1, p) == 1) {
        if (patient.pno == eno) {
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("-----------------\n");
        printf("No patient found with that number\n");
        printf("-----------------\n");
        fclose(p);
        return;
    }

    printf("Patient found\n");
    printf("-----------------\n");
    printf("No: %d\n", patient.pno);
    printf("Name: %s\n", patient.name);
    printf("Age: %d\n", patient.age);
    printf("Disease: %s\n", patient.dis);
    printf("-----------------\n");

    printf("1-Edit name\n");
    printf("2-Edit patient number\n");
    printf("3-Edit age\n");
    printf("4-Edit disease\n");
    printf("0-Cancel edit\n");
    printf("-----------------\n");
    scanf("%d", &editchoice);

    newp = patient;

    switch (editchoice) {
        case 1:
            printf("Enter new name: ");
            scanf("%s", newp.name);
            break;
        case 2:
            printf("Enter new patient number: ");
            scanf("%d", &newp.pno);
            break;
        case 3:
            printf("Enter new age: ");
            scanf("%d", &newp.age);
            break;
        case 4:
            printf("Enter new disease: ");
            scanf("%s", newp.dis);
            break;
        case 0:
            fclose(p);
            return;
        default:
            printf("Invalid option\n");
            fclose(p);
            return;
    }

    fseek(p, -sizeof(node), SEEK_CUR);
    fwrite(&newp, sizeof(node), 1, p);
    printf("-----------------\n");
    printf("Patient record edited successfully\n");
    printf("-----------------\n");

    fclose(p);
}

int menu() {
    int s;
    printf("Add patient               [1]\n"
           "Show all records          [2]\n"
           "Search                    [3]\n"
           "Delete                    [4]\n"
           "Edit                      [5]\n\n"
           "Exit                      [0]\n\n");
    printf("----------------------\n");

    scanf("%d", &s);
    printf("----------------------\n");
    return s;
}
