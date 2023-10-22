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
   char wordbuffer[256];
   int rnum;
   int line_number;
   int word_length;
   int lives;
   char ch;
   int offset_character[];
}data;
void menu();
int search(int len,char character);
void highscore();
void hangman_brand();
void game_logic();
void hangman_1();
void hangman_2();
void hangman_3();
void hangman_4();
void line_fetch(int);
void number_sort();
void game();
void rand_offset_characters();
void printer(int);
void tutorial();
//MAIN FUNCTION
int main(){
	srand(time(NULL));
	data.line_number =  rand() % 2500;
	line_fetch(data.line_number);
	strcpy(data.wordbuffer,data.buffer);
	data.line_number = HLINE;
	line_fetch(data.line_number);
	data.lives = LIFE_LIMIT;
	data.word_length = strlen(data.wordbuffer);
	rand_offset_characters(); 
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
    printf("      _______\n");
    printf("     |/      |\n");
    printf("     |          \n");
    printf("     |          \n");
    printf("     |          \n");
    printf("     |          \n");
    printf("     |          \n");
    printf("     |__________________\n");
}

//DISPLAYS THE SECOND HANGMAN ANIMATION
void hangman_2()
{
    printf("      ________ \n");
    printf("     |/      | \n");
    printf("     |      (_)\n");
    printf("     |         \n");
    printf("     |         \n");
    printf("     |         \n");
    printf("     |         \n");
    printf("     |__________________\n"); 
}

//DISPLAYS THE THIRD HANGMAN ANIMATION
void hangman_3(){

    printf("      _______    \n");
    printf("     |/      |   \n");
    printf("     |      (_)  \n");
    printf("     |      \\|/ \n");
    printf("     |          \n");
    printf("     |          \n");
    printf("     |          \n");
    printf("     |__________________\n");
}

//DISPLAYS THE FOURTH HANGMAN ANIMATION
void hangman_4()
{
    printf("      _______   \n");
    printf("     |/      |  \n");
    printf("     |      (_) \n");
    printf("     |      \\|/ \n");
    printf("     |       |  \n");
    printf("     |          \n");
    printf("     |          \n");
    printf("     |__________________\n");
}

//DISPLAYS THE FIFTH HANGMAN ANIMATION
void hangman_5()
{
    printf("      _______   \n");
    printf("     |/      |  \n");
    printf("     |      (_) \n");
    printf("     |      \\|/ \n");
    printf("     |       |  \n");
    printf("     |      / \\\n");
    printf("     |          \n");
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
{
	for(int i=0;i<data.word_length;i++)
	{
		data.offset_character[i] = rand() % 2;
	}
}
//FETCHING THE WORD FROM THE EXTERNAL WORDLIST <COMPLETE>
void line_fetch(int line_number)
{
	FILE *file_ptr;
	file_ptr = fopen("wordlist.txt","r+");
	int present_line = 1;
	while(fgets(data.buffer,sizeof(data.buffer),file_ptr) != NULL)
	{
		if(present_line == line_number)
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
	sleep(2);
	printf("%d",data.hscore);
}

//SORTS THE ARRAY OF RANDOM CHARACTER INDEXES <INCOMPLETE>
void number_sort()
{
int temp=0;
for(int i=0;i<data.word_length;i++)
{
	for(int j=0;j<data.word_length;j++)
	{
       if(data.offset_character[i]<data.offset_character[j])
       {
       	temp = data.offset_character[i];
       	data.offset_character[i] = data.offset_character[j];
       	data.offset_character[j] = temp;
       }
	}
}
}
//PRINTS CHARACTER ARRAY
void printer(int len)
{
	for(int i=0;i<len;i++)
{
		if(data.offset_character[i] == 1){

			printf("%c\t",data.wordbuffer[i]);
		}
		else {
			printf("_\t");
		}
	}

}
//SEARCH A ARRAY FOR A CHARACTER
int search(int len,char letter)
{
     for(int i=0;i<len;i++)
	{	
	if(data.wordbuffer[i] == letter){
		return i;
	}
	
}
return -1;	
}
//GAME LOGIC FOR THE GAME TO RUN OFF OF <INCOMPLETE>
void game_logic()
{
	system("clear");
	fflush(stdout);
	for(int i = 0;i<LIFE_LIMIT;i++)
	{
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
		else {
			hangman_6();
		}
		printer(data.word_length);
		scanf("%c",&data.ch);
		if (search(data.word_length,data.ch) == -1)
		{
			data.lives = data.lives - 1;
			system("clear");
			printf("WRONG");
			usleep(500000);
		}
		else{
			data.offset_character[search(data.word_length,data.ch)] = 1;
			number_sort();
			system("clear");
			printf("RIGHT");
			usleep(500000);
		}


	}
}








