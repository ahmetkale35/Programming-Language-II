//. Write C program to store data in structures dynamically. (In this example, you should to store the 
//information entered by the user using dynamic memory allocation.


#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char name[50];
	char Surname[50];
    int age;
} Person;

int main() {
    int numPersons,i;
    printf("Enter the number of persons: ");
    scanf("%d", &numPersons);

 
    Person* persons = (Person*)malloc(numPersons * sizeof(Person));

    if (persons == NULL) {
        printf("Memory allocation failed. Exiting...");
        return 1;
    }

    for (i = 0; i < numPersons; i++) {
        printf("\nEnter details for Person %d:\n", i + 1);

        printf("Enter name: ");
        scanf("%s", persons[i].name);
        
        printf("Enter Surname: ");
        scanf("%s", persons[i].Surname);

        printf("Enter age: ");
        scanf("%d", &(persons[i].age));
    }

  
    printf("\nData entered by the user:\n");
    for (i = 0; i < numPersons; i++) {
        printf("Person %d:\n", i + 1);
        printf("Name: %s\n", persons[i].name);
        printf("SurName: %s\n", persons[i].Surname);
        printf("Age: %d\n", persons[i].age);
        printf("\n");
    }

    free(persons);

    return 0;
}

