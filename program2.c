/**********************************************************************/
/*                                                                    */
/* Program Name: program2 - Perform different math operations         */
/* Author:       Ian McPherson                                        */
/* Installation: Pensacola Christian College, Pensacola, Florida      */
/* Course:       CS277, Data Structures and Algorithms                */
/* Date Written: September 6, 2019                                    */
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
/* This program will display a menu asking for a choice of which      */
/* mathematical operation to perform on two whole number inputs.      */
/* It will then perform the operation and prints that value.          */
/*                                                                    */
/**********************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/**********************************************************************/
/*                        Symbolic Constants                          */
/**********************************************************************/
#define COURSE_NUMBER   "CS227"     
   /* PCC assigned course number                                      */
#define PROGRAM_NUMBER  2           
   /* Teacher assigned program number                                 */
#define PROGRAMMER_NAME "McPherson" 
   /* The programmer's last name                                      */
#define MIN_MENU_CHOICE 1           
   /* Minimum possible menu choice                                    */
#define MAX_MENU_CHOICE 5
   /* Maximum possible menu choice                                    */
#define MENU_CHOICE_ERR 1
   /* Sets the value for the menu choice error                        */
#define QUIT            5 
   /* Ends the loop when entered                                      */ 

/**********************************************************************/
/*                        Function Prototypes                         */
/**********************************************************************/
void   print_heading();
   /* Prints the heading                                              */
void   print_menu();
   /* Displays menu options                                           */
int    get_menu_choice(int menu_choice);
   /* Receives the                   */
void   get_whole_numbers(int *p_first_number, int *p_second_number);
   /* Gets two whole number inputs                                    */
int    get_number_sum(int first_number, int second_number);
   /* Adds the whole numbers together and returns the value           */
double multiply_exponent(int first_number, int second_number);
   /* Sets the first whole number to the power of the other           */
int    sum_number_range(int first_number, int second_number);
   /* Sums whole numbers in a range                                   */
void   order_numbers(int *p_first_number, int *p_second_number);
   /* Orders the whole numbers from smallest to greatest              */

/**********************************************************************/
/*                          Main Function                             */
/**********************************************************************/
int main()
{
   int first_number,  /* Gets the first whole number input            */
       menu_choice,   /* Holds the menu choice for the switch         */
       second_number; /* Stores the second whole number input         */

       
   /* Print the program heading                                       */
   print_heading();
   
   /* While loop for the menu, user input, and mathematical functions */
   while(print_menu(), (menu_choice = 
                                 get_menu_choice(menu_choice)) != QUIT)
   {
      /* Gets the whole number input                                  */
      get_whole_numbers(&first_number, &second_number);    
      
      /* Manages the menu options                                     */
      switch (menu_choice)
      {   
         /* Adds the two whole numbers                                */
         case 1:
            printf("\nThe sum of %d and %d is %d", 
                  first_number, second_number,
                  get_number_sum(first_number, second_number));
            break;
            
         /* Sets the first number to the power of the second          */
         case 2:
            printf("\n%d raised to the power of %d = %1.6e",
                  first_number, second_number,
                  multiply_exponent(first_number, second_number));
            break;
            
         /* Orders numbers then finds the sum of the range            */
         case 3:
            order_numbers(&first_number, &second_number);
            printf("The sum of the numbers between ");
            printf("%d and %d (inclusive) is %d", 
                  first_number, second_number,
                  sum_number_range(first_number, second_number));
            break;
         
         /* Finds the order of the numbers                            */
         case 4:
            if      (first_number == second_number ||
                     first_number <  second_number)
            {
               printf("\n%d and %d are already in order",
                     first_number, second_number);
            }
            else
            {
               printf("\n%d and %d properly ordered are: ", first_number, 
                     second_number);
               order_numbers(&first_number, &second_number);      
               printf("%d and %d", first_number, second_number);
            }
            break;
         default:
            printf("\nError #1 occurred in main().");
            printf("\nImpossible menu choice error occurred.");
            printf("\nThe program is aborting.");
            printf("\n\n\n\n\n");
            exit(MENU_CHOICE_ERR);
      }
   }

   printf("\nThanks for processing numbers.  Have a nice day! ;-)");
   printf("\n\n\n\n\n");
   return 0;
}

/**********************************************************************/
/*                    Print the Program Heading                       */
/**********************************************************************/
void print_heading()
{
   printf("\n\n\n\n\n\n\n");
   printf("\n========================================================");
   printf("\n                Program Number: %d",    PROGRAM_NUMBER);
   printf("\n                Programmer: %s",        PROGRAMMER_NAME);
   printf("\n                PCC Course Number: %s", COURSE_NUMBER);
   printf("\n========================================================");
   printf("\n   Miscellaneous operations on your two whole numbers");
   return;
}

/**********************************************************************/
/*                        Displays the menu                           */
/**********************************************************************/
void print_menu()
{
   printf("\n\nMake a selection from the following menu:");
   printf("\n-----------------------------------------");
   printf("\n    1 - Add two whole numbers");
   printf("\n    2 - Raise the 1st number to the power of the 2nd");
   printf("\n    3 - Sum all numbers between two whole numbers");
   printf("\n    4 - Put two whole numbers into ascending order");
   printf("\n    5 - Quit");
   return;
}

/**********************************************************************/
/*                       Get user menu choice                         */
/**********************************************************************/
int get_menu_choice(int menu_choice)
{   
   do {
      printf("\nEnter your menu selection (1-5): ");
      scanf ("%d", &menu_choice);
   } while(menu_choice < MIN_MENU_CHOICE || 
           menu_choice > MAX_MENU_CHOICE);
   return menu_choice;
}

/**********************************************************************/
/*                    Ask for the two whole numbers                   */
/**********************************************************************/
void get_whole_numbers(int *p_first_number, int *p_second_number)
{
   printf("\nType in any two whole numbers now:");
   printf("\n    What is your small number: ");
   scanf ("%d", p_first_number);
   printf(  "    Give me your large number: ");
   scanf ("%d", p_second_number);
   return;
}

/**********************************************************************/
/*                      Calculate sum of numbers                      */
/**********************************************************************/
int get_number_sum(int first_number, int second_number)
{
   return (first_number + second_number);
}

/**********************************************************************/
/*                   Calculate exponent of numbers                    */
/**********************************************************************/
double multiply_exponent(int first_number, int second_number)
{  
   double first_number_double,  
      /* Stores first_number and typecasts as double                  */
          second_number_double;
      /* Gets the value of second_number and typecasts as double      */
   
   /* Typecasts so the values can be used with pow()                  */
   first_number_double  = (double) first_number;
   second_number_double = (double) second_number;

   return (pow(first_number_double, second_number_double));
}

/**********************************************************************/
/*                 Calculate the Sum of the Range                     */
/**********************************************************************/
int sum_number_range(int range_start, int range_end)
{   
   int sum_of_range = 0, /* Stores the sum of the range               */
       range_counter;    /* Gets the value of range_start             */

   for(range_counter = range_start; range_counter <= range_end; 
                                                        range_counter++)
      sum_of_range += range_counter;   
   return sum_of_range;
}

/**********************************************************************/
/*                 Put the numbers in ascending order                 */
/**********************************************************************/
void order_numbers(int *p_first_number, int *p_second_number)
{
   int temporary_holder; /* Holds the value of p_first_number to swap */
   
   if (*p_first_number > *p_second_number)
   {
      temporary_holder = *p_first_number;
      *p_first_number  = *p_second_number;
      *p_second_number = temporary_holder;
   }
   return;
}