/*1) Write a C program that can perform various operations on the number, name, 
midterm grade and final grade information of students in a class. The features of 
the program are given below:
a) Program will have a main menu with options below: 
1- Add New Record 
2- List Records 
3- Update Record 
4- Calculate Class Average 
5- Show Best Student Record According to Average 
b) Your program should consume as minimum memory space as it can. To achieve 
this, perform dynamic memory management. 
c) Listing records can be according to student number or grade. User should be 
able to list students according to upper or lower limits applied to midterm or final 
grades. 
d) Updating records will be carried out according to student number */


#include <stdio.h>
#include <stdlib.h>


typedef struct student {
    char* name;
    int midterm;
    int final;
    int no;
    struct student* next;
} node;

node* head;

node* addnewrecord() {
    int n, k;
    node* p = NULL;
    printf("How many records do you want to add: ");
    scanf("%d", &n);

    for (k = 0; k < n; k++) {
        if (k == 0) {
            head = (node*)malloc(sizeof(node));
            p = head;
        }
        else {
            p->next = (node*)malloc(sizeof(node));
            p = p->next;
        }
        printf("Enter name of %d. student: ", k + 1);
        p->name = (char*)malloc(50 * sizeof(char));
        scanf("%s", p->name);

        printf("Enter midterm grade of %d. student: ", k + 1);
        scanf("%d", &p->midterm);

        printf("Enter final grade of %d. student: ", k + 1);
        scanf("%d", &p->final);

        printf("Enter number of %d. student: ", k + 1);
        scanf("%d", &p->no);

        p->next = NULL;
    }
    return head;
}

void liststudents() {
    node* p;
    double semesterGrade = 0;
    p = head;
    while (p != NULL) {
        printf("\n *** **** \n");
        printf("Student No: %d\t", p->no);
        printf("Student Name: %s\t", p->name);
        printf("Student Midterm Grade: %d\t", p->midterm);
        printf("Student Final Grade: %d\t", p->final);
        semesterGrade = p->midterm * 0.4 + p->final * 0.6;
        printf("Semester Grade: %.2f\t", semesterGrade);
        p = p->next;
    }
}

void updaterecords() {
    int stdnum, upd;
    printf("Enter the student number to update: ");
    scanf("%d", &stdnum);

    node* p;
    p = head;
    while (p != NULL) {
        if (p->no == stdnum) {
            printf("Which record do you want to update:\n");
            printf("1-Name\n");
            printf("2-Number\n");
            printf("3-Midterm Grade\n");
            printf("4-Final Grade\n");
            printf("Press 0 to go back\n");
            scanf("%d", &upd);

            switch (upd) {
                case 1:
                    printf("Enter the new name: ");
                    scanf("%s", p->name);
                    printf("New Name: %s\n", p->name);
                    break;
                case 2:
                    printf("Enter the new number: ");
                    scanf("%d", &p->no);
                    printf("New Number: %d\n", p->no);
                    break;
                case 3:
                    printf("Enter the new midterm grade: ");
                    scanf("%d", &p->midterm);
                    printf("New Midterm Grade: %d\n", p->midterm);
                    break;
                case 4:
                    printf("Enter the new final grade: ");
                    scanf("%d", &p->final);
                    printf("New Final Grade: %d\n", p->final);
                    break;
                case 0:
                    return;
                default:
                    printf("Invalid option\n");
            }
        }
        else {
            printf("The student you are looking for could not be found\n");
        }
        p = p->next;
    }
}

void calculateaverage(){
	int ct=0;
	float total, average;
	node* p;
    p = head;
	while(p!=NULL){
		float semesterGrade = p->midterm * 0.4 + p->final * 0.6;
		total = total + semesterGrade;
		ct++;
		
		p = p->next;
	}
	average = total / ct;
	printf("\nClass Average: %f" ,average);
}

void best(){
	node* ch = NULL;
	node* p;
	p = head;
	float b=0.0;
	
	while(p!=NULL){
		float semesterGrade = (p->midterm * 0.4) + (p->final * 0.6);
		if(semesterGrade > b){
			ch = p;
			b = semesterGrade;
		}
		p = p->next;
	}
	printf(" v Information of the Best Student v\n");
	printf("Name: %s\n" ,ch->name);
	printf("Midterm Grade: %d\n" ,ch->midterm);
	printf("Final Grade: %d\n" ,ch->final);
	printf("Average: %f\n" ,b);
}

int main() {
    int c;

    while (1) {
        printf("Please select an option\n");
        printf("1-Add new record\n");
        printf("2-List records\n");
        printf("3-Update record\n");
        printf("4-Calculate average\n");
        printf("5-Show best student\n");
        printf("0-Exit\n");
        scanf("%d", &c);

        switch (c) {
            case 1:
                head = addnewrecord();
                break;
            case 2:
                liststudents();
                break;
            case 3:
                updaterecords();
                break;
            case 4:
            	calculateaverage();
            	break;
            case 5:
            	best();
            	break;
            case 0:
                exit(0);
            default:
                printf("Invalid option\n");
        }
    }

    return 0;
}

