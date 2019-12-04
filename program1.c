/**********************************************************************/
/*                                                                    */
/* Program Name: program1 - Add sequential numbers in a range         */
/* Author:       Ian McPherson                                        */
/* Installation: Pansacola Christian College                          */
/* Course:       CS277, Data Structures and Algorithms                */
/* Date Written: September 2, 2019                                    */
/*                                                                    */
/**********************************************************************/

/**********************************************************************/
/*                                                                    */
/* I pledge this assignment is my own first time work.                */
/* I pledge I did not copy or try to copy any work from the Internet. */
/* I pledge the only person I asked for help from was my teacher.     */
/* I pledge I did not attempt to help any student on this assignment. */
/* I understand if I violate this pledge I will receive a 0 grade.    */
/*                                                                    */
/*                                                                    */
/*                      Signed: _____________________________________ */
/*                                           (signature)              */
/*                                                                    */
/*                                                                    */
/**********************************************************************/

/**********************************************************************/
/*                                                                    */
/* This program asks the user for two different numbers and then      */
/* sequentially adds them from the range of numbers provided.  It     */
/* then prints the final sum to the user.                             */
/*                                                                    */
/**********************************************************************/
#include <stdio.h> /* scanf, printf                                   */

/**********************************************************************/
/*                        Symbolic Constants                          */
/**********************************************************************/
#define COURSE_NUMBER  "CS227"
#define PROGRAM_NUMBER 1
#define USER_NAME      "McPherson"

/**********************************************************************/
/*                        Function Prototypes                         */
/**********************************************************************/
void printHeading();
int  get_number_range(int *p_lowEnd, int *p_highEnd);
int  sum_number_range(int lowNumber, int highNumber);

/**********************************************************************/
/*                          Main Function                             */
/**********************************************************************/
int main()
{
   int lowNumber,  /* This is for the small number in the range       */
       highNumber, /* This is for the high number in the range        */
       *p_lowEnd,  /* This is the pointer for low end range           */
       *p_highEnd; /* This is the pointer for the high range          */

   /* Print the program heading                                       */
   printf("\n\n\n\n\n\n");
   printHeading();

   /*Get the range of numbers from the user                           */
   get_number_range(&p_lowEnd, &p_highEnd);

   /*
   printf("\nEnter a range of whole numbers now, lower number first:");
   printf("\n    What is your small number: ");
   printf("    Give me your large number: "); */

   /* Assign the pointer value to integer values to sum               */
   lowNumber  = *p_lowEnd;
   highNumber = *p_highEnd;

   /*Calculate the sum of the range                                   */
   sum_number_range(lowNumber, highNumber);

   /*Print the closing message and terminate the program              */
   printf("\n\nThanks for your range summing.  Have a nice day! ;-)");
   printf("\n\n\n\n\n\n");
   return 0;
}

/**********************************************************************/
/*                    Print the Program Heading                       */
/**********************************************************************/
void printHeading()
{
   printf("\n========================================================");
   printf("\n                Program Number: %d",    PROGRAM_NUMBER);
   printf("\n                Programmer: %s",        USER_NAME);
   printf("\n                PCC Course Number: %s", COURSE_NUMBER);
   printf("\n========================================================");
   printf("\nI'll sum whole numbers in a number range (inclusively).");
   printf("\n-------------------------------------------------------");

   return;
}

/**********************************************************************/
/*          Ask for the two numbers at the ends of the range          */
/**********************************************************************/
int get_number_range(int *p_lowEnd, int *p_highEnd)
{
   printf("\nEnter a range of whole numbers now, lower number first:");
   printf("\n    What is your small number: ");
   scanf ("%d", p_lowEnd);
   printf("    Give me your large number: ");
   scanf ("%d", p_highEnd);

   return;
}

/**********************************************************************/
/*                 Calculate the Sum of the Range                     */
/**********************************************************************/
int sum_number_range(int lowNumber, int highNumber)
{
   int result;

   for(result = 0; lowNumber <= highNumber; lowNumber++)
      result += lowNumber;

   return result;
}
