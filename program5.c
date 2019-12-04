/**********************************************************************/
/*                                                                    */
/* Program Name: program5 - Recursively sum even numbers in a range   */
/* Author:       Ian McPherson                                        */
/* Installation: Pensacola Christian College, Pensacola, Florida      */
/* Course:       CS227, Data Structures and Algorithms                */
/* Date Written: October 18, 2019                                     */
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
/* This program recursively sums even numbers in a range, asking for  */
/* two range ends and swap them if the first is larger than the       */
/* second.  It will then recursively sum the even numbers in the      */
/* range.                                                             */
/*                                                                    */
/**********************************************************************/

#include <stdio.h> /* scanf(), printf()                               */
#include <ctype.h> /* tolower()                                       */

/**********************************************************************/
/*                        Symbolic Constants                          */
/**********************************************************************/
#define COURSE_NUMBER   "CS227" /* PCC assigned course number         */
#define PROGRAM_NUMBER  5       /* Teacher assigned program number    */
#define PROGRAMMER_NAME "McPherson"
                                /* The programmer's last name         */
#define MINIMUM_RANGE   -5000   /* The lowest possible end of the     */
                                /* range                              */
#define MAXIMUM_RANGE   5000    /* The highest possible end of the    */
                                /* range                              */

/**********************************************************************/
/*                        Function Prototypes                         */
/**********************************************************************/
void print_heading();
   /* Prints the program heading                                      */
void print_instructions();
   /* Prints the program instructions                                 */
char get_menu_option();
   /* Gets the menu option                                            */
void get_range(int *p_range_low, int *p_range_high);
   /* Gets the range ends                                             */
void swap_numbers(int *p_range_low, int *p_range_high);
   /* Swaps the range ends                                            */
int  sum_evens(int *p_range_low, int *p_range_high);
   /* Sums every even number in the range                             */
int  is_even(int *p_range_low);
   /* Checks for evens                                                */

/**********************************************************************/
/*                          Main Function                             */
/**********************************************************************/
int main()
{
   int range_low,  /* The low end of the range                        */
       range_high; /* The high end of the range                       */

   /* Print the program heading and instructions                      */
   print_heading();
   print_instructions();

   /* Loop processing numbers in a range until the user says to quit  */
   while (get_menu_option() == 'y')
   {
      /* Gets the ends of the range                                   */
      get_range(&range_low, &range_high);

      /* Swap the range ends if the first is larger than the second   */
      /* and print the sum of the even numbers in the range           */
      if(range_low > range_high)
         swap_numbers(&range_low, &range_high);
      printf("\nProcessing the range %d to %d:", range_high, range_low);
      printf("\nThe sum of all even numbers in the range %d to %d is: %d",
         ++range_low, range_high, sum_evens(&range_low, &range_high));
   }

   /* Says goodbye and terminates the program                         */
   printf("\nThanks for \"even summing\".  Have a nice day! ;-)");
   printf("\n\n\n\n\n\n");
   return 0;
}

/**********************************************************************/
/*                    Print the Program Heading                       */
/**********************************************************************/
void print_heading()
{
   printf(  "\n\n\n\n\n\n\n");
   printf(  "\n========================================================");
   printf(  "\n                Program Number: %d",    PROGRAM_NUMBER);
   printf(  "\n                Programmer: %s",        PROGRAMMER_NAME);
   printf(  "\n                PCC Course Number: %s", COURSE_NUMBER);
   printf(  "\n========================================================");
   return;
}

/**********************************************************************/
/*                   Print the program instructions                   */
/**********************************************************************/
void print_instructions()
{
   printf("\nThis program recursively calculates the sum of all");
   printf("\neven whole numbers between two numbers inclusively.");
   printf("\nYou are repeatedly asked to enter in the start and");
   printf("\nend of a range, and the sum of all even numbers in");
   printf("\nthat range is calculated and printed.  Information");
   printf("\nabout the recursive action of the function is also");
   printf("\nprinted so the recursive nature of the calculation");
   printf("\n                 may be observed.");
   return;
}

/**********************************************************************/
/*                Get the response to continue or quit                */
/**********************************************************************/
char get_menu_option()
{
   char menu_option[2]; /* Stores the menu option entered by the user */
   do
   {
      printf("\n\nDo you want to process another range (y or n): ");
      scanf("%1s", &menu_option[0]);
      menu_option[0] = tolower(menu_option[0]);
   } 
   while ((menu_option[0] != 'y') && (menu_option[0] != 'n'));
   return menu_option[0];
}

/**********************************************************************/
/*                         Get the range ends                         */
/**********************************************************************/
void get_range(int *p_range_low, int *p_range_high)
{
   do
   {
      printf("\nEnter in the first number (from -5000 to 5000): ");
      scanf ("%d", p_range_low);
   } 
   while (*p_range_low > MAXIMUM_RANGE || *p_range_low < MINIMUM_RANGE);
   do
   {
      printf("\nEnter in the second number (from -5000 to 5000): ");
      scanf ("%d", p_range_high);
   } 
   while (*p_range_high > MAXIMUM_RANGE || *p_range_high < MINIMUM_RANGE);
   return;
}

/**********************************************************************/
/*          Swap the range ends without a temporary variable          */
/**********************************************************************/
void swap_numbers(int *p_range_low, int *p_range_high)
{
   *p_range_low  += *p_range_high;
   *p_range_high =  *p_range_low - *p_range_high;
   *p_range_low  -= *p_range_high;
   return;
}

/**********************************************************************/
/*           Recursively sum the even numbers in the range            */
/**********************************************************************/
int sum_evens(int *p_range_low, int *p_range_high)
{
   int even_sum = 0; /* The value of the sum of the evens in the range */

   printf("\n    Entering sum function for range %d to %d", *p_range_low,
      *p_range_high);
   if (*p_range_low <= *p_range_high)
   {
      if (is_even(p_range_low))
      {
         printf("\n        Adding: %d", *p_range_low);
         even_sum += *p_range_low;
      }
      else
         printf("\n        Skipping: %d", *p_range_low);
      (*p_range_low)++;
      even_sum += sum_evens(p_range_low, p_range_high);
   }
   printf("\n    Exiting sum function for range %d to %d with result: %d", 
      (*p_range_low)--, *p_range_high, even_sum);
   return even_sum;
}

/**********************************************************************/
/*                Checks to see if the number is even                 */
/**********************************************************************/
int is_even(int *p_range_low)
{
   return ((*p_range_low % 2) == 0);
}