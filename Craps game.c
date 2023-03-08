#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main (){
	printf("2 dice are thrown throughout the game and the results are summed\n");
	int n,s,d=1;
	srand(time(NULL));
	n = 2 + rand() %11;
	
	if ((n == 7) || (n == 11)){
		printf("Your score is %d\n" ,n);
		printf("You Won");
		return 0;
	}
	else{
		if ((n == 2) || (n == 3) || (n == 12)){
			printf("Your score is %d\n" ,n);
			printf("You Lose");
			return 0;
		}
		else {
			s=n;
			printf("Your score is %d.\n" ,s);
			printf("Now you need to keep your score.\n");
		}
	}
		
	while (d == 1){
	
	printf("Press 1 to roll two dice\n");
	scanf("%d" ,&d);
	
	int n2;
	srand(time(NULL));
	n2 = 2 + rand() %11;
	
	if (n2 == s){
		printf("Your Current Score is %d\n" ,n2);
		printf("Your Old Score is %d\n" ,s);
		printf("You Won Game is Over");
		return 0;
	}
	else{
		if (n2 == 7){
			printf("Your current score is %d\n" ,n2);
			printf("You Lose Game is Over");
			
			return 0;
		}
		else{
			printf("Your Current Score is %d\n" ,n2);
			printf("Your Old Score is %d\n" ,s);
			printf("You are Failed please try again.\n");
			
		}
	}
	
	}

	return 0;
}
