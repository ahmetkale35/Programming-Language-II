#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

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
    	system("cls");
        ch = menu();
        switch (ch) {
            case '1':
                addrecord();
                break;
            case '2':
                printlist();
                break;
            case '3':
                searchbyno();
                break;
            case '4':
                deleterecord();
                break;
            case '5':
                editrecord();
                break;
            case '0':
            	system("cls");
				exit(0);            
            default:
                printf("Invalid option\n");
        }
    }
    return 0;
}
void addrecord() {
	system("cls");
    int enter, i;
    FILE* p;
    node patient;
    if ((p = fopen("records.txt", "a+")) == NULL) {
        printf("File could not be opened\n");
        getch();
        return;
    }

    printf("How many patients will you enter?\n");
    scanf("%d", &enter);
	system("cls");
	
    for (i = 0; i < enter; i++) {
    	printf("-----------------\n");
    	printf("%d . Patient\n" ,i+1);
    	printf("-----------------\n");
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
    printf("%d New patient added " ,enter);
    getch();
    fclose(p);
}

void printlist() {
	system("cls");
	int pct=0;
    FILE* p;
    node patient;
    if ((p = fopen("records.txt", "r")) == NULL) {
        printf("Not found any records\n");
        getch();
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
        	getch();
        	return;
    pct = 0;
	}
	getch();
	fclose(p);
}

void searchbyno() {
    FILE* p;
    int sno;
    node patient;
    int found = 0;
	system("cls");
    if ((p = fopen("records.txt", "r")) == NULL) {
        printf("File could not be opened\n");
        return;
    }

    printf("Enter the patient code you want to search: ");
    scanf("%d", &sno);
	system("cls");
	
    while (fread(&patient, sizeof(node), 1, p) == 1) {
        if (patient.pno == sno) {
            printf("-----------------\n");
            printf("No: %d\n", patient.pno);
            printf("Name: %s\n", patient.name);
            printf("Age: %d\n", patient.age);
            printf("Disease: %s\n", patient.dis);
            printf("-----------------\n");
            found = 1;
            break;
        }
    }

    if (!found) {
    	system("cls");
        printf("-----------------\n");
        printf("No patient found with that number\n");
        printf("-----------------\n");
    }
	getch();
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
	system("cls");
	
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
    	system("cls");
        printf("-----------------\n");
        printf("Successfully deleted\n");
        printf("-----------------\n");
    } else {
    	system("cls");
        printf("-----------------\n");
        printf("No patient found with that number\n");
        printf("-----------------\n");
    }

    fclose(p);
    getch();
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
	system("cls");
    printf("Enter the patient number you want to edit: ");
    scanf("%d", &eno);
	system("cls");
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
        getch();
        fclose(p);
        return;
    }
	system("cls");
    printf("Patient found\n");
    printf("-----------------\n");
    printf("No: %d\n", patient.pno);
    printf("Name: %s\n", patient.name);
    printf("Age: %d\n", patient.age);
    printf("Disease: %s\n", patient.dis);
    printf("-----------------\n");

	printf("1-Edit patient number\n");
    printf("2-Edit name\n");
    printf("3-Edit age\n");
    printf("4-Edit disease\n");
    printf("0-Cancel edit\n");
    printf("-----------------\n");
    editchoice = getch();

    newp = patient;

    switch (editchoice) {
        case '2':
            printf("Enter new name: ");
            scanf("%s", newp.name);
            break;
        case '1':
            printf("Enter new patient number: ");
            scanf("%d", &newp.pno);
            break;
        case '3':
            printf("Enter new age: ");
            scanf("%d", &newp.age);
            break;
        case '4':
            printf("Enter new disease: ");
            scanf("%s", newp.dis);
            break;
        case '0':
        	system("cls");
            fclose(p);
            return;
        default:
            printf("Invalid option\n");
            fclose(p);
            return;
    }

    fseek(p, -sizeof(node), SEEK_CUR);
    fwrite(&newp, sizeof(node), 1, p);
    system("cls");
    printf("-----------------\n");
    printf("Patient record edited successfully\n");
    printf("-----------------\n");
	
	printf("-----------------\n");
    printf("No: %d\n", newp.pno);
    printf("Name: %s\n", newp.name);
    printf("Age: %d\n", patient.age);
    printf("Disease: %s\n", newp.dis);
	printf("-----------------\n");
	     
	getch();
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
    s = getch();
    printf("----------------------\n");
    return s;
}
