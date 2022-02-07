#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

void bit_print();

void parse(char* comStr);
void MOV(char* par1, char* par2);
void REV();
void SH(char* num);
void SET(char* par1, char* par2);

unsigned char t = 0;
int t1 = 0;
typedef unsigned char byte;

int main()
{
    //instruction
    printf("Usage: -256 >= number <= 255\n\n");
    printf("command: MOV [-L] || [-R] [n]\n \t MOV - bit shift\n \t -L - shift to the left\n \t -R - shift to the right\n \t n - number of shift bits\n\n");
    printf("command: REV - reverse all bits\n\n");
    printf("command: SET [n] 1||0\n \t SET - set bit\n \t n - bit order (from 0)\n \t set to 0 or 1\n\n");
    printf("command: SH [n]\n \t SH - show bit state\n \t [n] - bit order (from 0)\n\n");

    printf("Enter the number: ");
    scanf("%d", &t1);

    if (t1 > 255)
    {
        printf("The number is outside the char type, MAX = 255\n");
        t1 = 255;
    }

    t = t1;

    bit_print();

    char command_string[50];
    gets(command_string);
    memset(command_string, ' ', 50);

    while (true)
    {
        gets(command_string);
        if (*command_string == 'q')
        {
            printf("exit\n");
            return 0;
        }
        
        parse(command_string);
        memset(command_string, ' ', 50);
    }
}

void parse(char* comStr)
{
    //Initialize the list of commands
    char COMMAND[][10] = {"MOV", "REV", "SH", "SET"};

    //Initialize the list of parameters
    char PARAMETER[4][10] = {" "};
    
    char* sep;
    bool valid_command = false;
    int i = 0;

    //parsing input string (strtok), separation command and arguments
    sep = strtok(comStr, " ");      
    while (sep != NULL)             
    {                               
        strcpy(PARAMETER[i], sep);  
	    sep = strtok(NULL, " ");    
        i++;
    }

    // determining of the command
    if(strcmp(PARAMETER[0], COMMAND[0]) == 0)
    {
        valid_command = true;
        MOV(PARAMETER[1], PARAMETER[2]);
    }

    if(strcmp(PARAMETER[0], COMMAND[1]) == 0)
    {
        valid_command = true;
        REV();
    }

    if(strcmp(PARAMETER[0], COMMAND[2]) == 0)
    {
        valid_command = true;
        SH(PARAMETER[1]);
    }

    if(strcmp(PARAMETER[0], COMMAND[3]) == 0)
    {
        valid_command = true;
        SET(PARAMETER[1], PARAMETER[2]);
    }

    //if entered data is incorrect
    if(valid_command == false)
    {
        printf("Command not valid\n");
    }

    valid_command = false;
}

//output a sequence of bits to the stream
void bit_print()
{
    byte num = t;
    byte control = 128;

    for (int i = 0; i < sizeof(char) * 8; i++)
    {
        (control >> i) & num ? printf("1") : printf("0");  
    }
    printf("\n");
}

//implementation of the MOV command
void MOV(char* par1, char* par2)
{
    if (strcmp(par1, "-L") == 0) t <<= atoi(par2);
    if (strcmp(par1, "-R") == 0) t >>= atoi(par2);

    bit_print();
}

//implementation of the REV command
void REV()
{
    t = ~t;
    bit_print();
}

//implementation of the SH command
void SH(char* num)
{
    (t & (128 >> atoi(num))) ? printf("1\n") : printf("0\n");
}

// implementation of the SET command
void SET(char* par1, char* par2)
{
    if (strcmp(par1, "-ALL") == 0)
    {
        if (*par2 == '1') t = 255;
        if (*par2 == '0') t = 0;
    }
    else
    {
        t = t ^ (128 >> atoi(par1));
    }
    bit_print();
}