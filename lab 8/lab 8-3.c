//Write C program to store information of students using structure. (In this example, you should store the 
//information of 5 students by using an array of structures.)


#include <stdio.h>
#include <string.h>


int main(){
	int i;
	typedef struct info{
		char Name[40];
		char Surname[40];
		int number;
		float Grade;
	};
	struct info students[5];
	
	 for(i=0 ; i<3 ; i++){
        printf("Student %d\n", i+1);
        printf("Enter name: "); 
        scanf("%s", students[i].Name);
        printf("Enter surname: "); 
        scanf("%s", students[i].Surname);
        printf("Enter student number: ");
        scanf("%s", &students[i].number);
        printf("Enter midterm grade: ");
        scanf("%f", &students[i].Grade);
        printf("\n");
    }
	
	 for(i=0 ; i<3 ; i++)
        printf("Student %d\n"
               "Name and surname: %s %s\n"
               "Student number: %s\n"
               "grade: %.2f\n\n", i+1,
                                        students[i].Name,
                                        students[i].Surname,
                                        students[i].number,
                                        students[i].Grade);
	
	
	return 0;
}
