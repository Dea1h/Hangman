#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#define HLINE 1001 
#define LIFE_LIMIT 6
struct data
{
   int hscore;
   char buffer[256];
   char character;
   int line_number;
   size_t word_length;
   int lives;
   char ch;
   char * wordbuffer;
   int offset_character[];
}data;
void menu();
int search();
void highscore();
void hangman_brand();
void game_logic();
void hangman_1();
void hangman_2();
void hangman_3();
void hangman_4();
void line_fetch();
void game();
void rand_offset_characters();
void printer();
void tutorial();
//BACKEND FUNCTION
void backend()
{
	srand(time(NULL));
	data.line_number = rand() % 1825;
	line_fetch();
	data.word_length = strcspn(data.buffer,"\n");
	data.wordbuffer = (char *)malloc(data.word_length + 1);
	if(data.wordbuffer == NULL)
	{
		system("clear");
		printf("Memory Allocation Failed: BUFFER returned NULL when alocating");
		free(data.wordbuffer);
		exit(0);
	}
	strncpy(data.wordbuffer,data.buffer,data.word_length);
	data.wordbuffer[data.word_length] = '\0';
	data.lives = LIFE_LIMIT;
	data.word_length = strlen(data.wordbuffer);
	rand_offset_characters();
}
//MAIN FUNCTION
int main(){ 
	menu();
}
//MAIN MENU FOR THE HANGMAN GAME 
void menu()
{       int a;
	top:
	fflush(stdout);
	system("clear");
	hangman_brand();
	printf("*******Start Game***********\n");
	printf("*******High Score***********\n");
	printf("********Tutorial************\n");
	printf("*********Exit***************\n");
	printf("\n\n\t\t\t");
	scanf("%d",&a);
	system("clear");
	switch (a)
	{
	case 1:
	game_logic();
	goto top;
	break;
	case 2:
	highscore();
	goto top;
	break;	
	case 3:
	tutorial();
	goto top;
	break;
	case 4:
	exit(0);
	break;
	default:
	goto top;
	break;
	}
}

//DISPLAYS THE HANGMAN LOGO
void hangman_brand()
{
    printf(" _\n");
    printf("| |\n");
    printf("| |__   __ _ _ __   __ _ _ __ ___   __ _ _ __  \n");
    printf("| '_ \\ / _` | '_ \\ / _` | '_ ` _ \\ / _` | '_ \\ \n");
    printf("| | | | (_| | | | | (_| | | | | | | (_| | | | |\n");
    printf("|_| |_|\\__,_|_| |_|\\__, |_| |_| |_|\\__,_|_| |_|\n");
    printf("                    __/ |                      \n");
    printf("                   |___/                       \n");

}

//DISPLAYS THE FIRST HANGMAN ANIMATION
void hangman_1()
{
    printf("      ________   \n");
    printf("     |/      |   \n");
    printf("     |           \n");
    printf("     |           \n");
    printf("     |           \n");
    printf("     |           \n");
    printf("     |           \n");
    printf("     |__________________\n");
}

//DISPLAYS THE SECOND HANGMAN ANIMATION
void hangman_2()
{
    printf("      ________   \n");
    printf("     |/      |   \n");
    printf("     |      (_)  \n");
    printf("     |           \n");
    printf("     |           \n");
    printf("     |           \n");
    printf("     |           \n");
    printf("     |__________________\n"); 
}

//DISPLAYS THE THIRD HANGMAN ANIMATION
void hangman_3(){

    printf("      _______    \n");
    printf("     |/      |   \n");
    printf("     |      (_)  \n");
    printf("     |      \\|/ \n");
    printf("     |           \n");
    printf("     |           \n");
    printf("     |           \n");
    printf("     |__________________\n");
}

//DISPLAYS THE FOURTH HANGMAN ANIMATION
void hangman_4()
{
    printf("      _______    \n");
    printf("     |/      |   \n");
    printf("     |      (_)  \n");
    printf("     |      \\|/ \n");
    printf("     |       |   \n");
    printf("     |           \n");
    printf("     |           \n");
    printf("     |__________________\n");
}

//DISPLAYS THE FIFTH HANGMAN ANIMATION
void hangman_5()
{
    printf("      _______    \n");
    printf("     |/      |   \n");
    printf("     |      (_)  \n");
    printf("     |      \\|/ \n");
    printf("     |       |   \n");
    printf("     |      / \\ \n");
    printf("     |           \n");
    printf("     |__________________\n");
}

//DISPLAYS THE SIXTH HANGMAN ANIMATION OR FINAL ANIMATION
void hangman_6()
{
    printf(" ___________.._______\n");
    printf("| .__________))______|\n");
    printf("| | / /      ||\n");
    printf("| |/ /       ||\n");
    printf("| | /        ||.-''.\n");
    printf("| |/         |/  _  \\\n");
    printf("| |          ||  `/,|\n");
    printf("| |          (\\\\`_.'\n");
    printf("| |         .-`--'.\n");
    printf("| |        /Y . . Y\\\n");
    printf("| |       // |   | \\\\\n");
    printf("| |      //  | . |  \\\\\n");
    printf("| |     ')   |   |   (`\n");
    printf("| |          || ||\n");
    printf("| |          || ||\n");
    printf("| |          || ||\n");
    printf("| |          || ||\n");
    printf("| |         / | | \\\n");
    printf("\"\"\"\"\"\"\"\"\"\"|_`-' `-' |\"\"\"\"\n");
    printf("|\"|\"\"\"\"\"\"\\ \\       '\"|\"|\"|\n");
    printf("| |        \\ \\        | |\n");
    printf(": :         \\ \\       : :\n");
    printf(". .          `'       . .\n");


}
//TUTORIAL
void tutorial()
{
	system("clear");
	printf("YOU KNOW HOW TO PLAY SO GO PLAY");
	sleep(1);
}
//INITIALIZING ARRAT(offset_characters) WITH RANDOM 1 AND 0
void rand_offset_characters()
{int count = 0;
	for(int i=0;i<data.word_length;i++)
	{
		data.offset_character[i] = rand() % 2;
		if(data.offset_character[i] == 1)
		{
			count++;
			if (count == LIFE_LIMIT)
			break;
		}
	}
}
//FETCHING THE WORD FROM THE EXTERNAL WORDLIST <COMPLETE>
void line_fetch()
{
	FILE *file_ptr;
	file_ptr = fopen("wordlist.txt","r");
	int present_line = 1;
	while(fgets(data.buffer,sizeof(data.buffer),file_ptr) != NULL)
	{
		if(present_line == data.line_number)
		{
			break;
		}
		present_line++;
	}


}
//DISPLAYS THE HIGHSCORE OF THE PRIVIOUS RUNS <INCOMPLETE>
void highscore()
{
	system("clear");
	printf("HIGHSCORE\n");
	printf("%d",data.hscore);
	sleep(2);
}
//PRINTS CHARACTER ARRAY
void printer()
{
	for(int i=0;i<data.word_length;i++)
{
		if(data.offset_character[i] == 1){

			printf("%c ",data.wordbuffer[i]);
		}
		else {
			printf("_ ");
		}
	}

}
//SEARCH A ARRAY FOR A CHARACTER
int search()
{
     for(int i=0;i<data.word_length;i++)
	{
		if(data.wordbuffer[i] == data.ch && data.offset_character[i] != 1)
		{
			return i;
			break;
		}
	}
	return 400;
}
//GAME LOGIC FOR THE GAME TO RUN OFF OF <INCOMPLETE>
void game_logic()
{
	backend();
	for(int i = 0;i<LIFE_LIMIT;i++)
	{
		fflush(stdout);
		system("clear");
		if(data.lives == LIFE_LIMIT){
			hangman_1();
		}
		else if (data.lives + 1 == LIFE_LIMIT) {
			hangman_2();
		}
		else if (data.lives + 2 == LIFE_LIMIT) {
			hangman_3();
		}
		else if (data.lives + 3 == LIFE_LIMIT) {
			hangman_4();
		}
		else if (data.lives + 4 == LIFE_LIMIT) {
			hangman_5();
		}
		else if (data.lives + 5 == LIFE_LIMIT) {
		        hangman_5();
		}
		else if (data.lives + 6 == LIFE_LIMIT){
                        hangman_6();
			printf("\n\n");
			printf("GAME OVER");
			sleep(1);
			break;
		}
		printf("\n\n");
		printer();
		scanf("%s",&data.ch);
		if (search() != 400)
		{
			printf("\n");
			printf("RIGHT GUESS");
			data.offset_character[search()] = 1;
			sleep(1);
		}
		else{
			data.lives--;
			printf("\n");
			printf("WRONG GUESS");
			sleep(1);
		}


	}
	free(data.wordbuffer);

}
