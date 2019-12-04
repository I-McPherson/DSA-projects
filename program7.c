/**********************************************************************/
/*                                                                    */
/* Program Name: program7 - Demonstrate various search algorithms     */
/* Author:       Ian McPherson                                        */
/* Installation: Pensacola Christian College, Pensacola, Florida      */
/* Course:       CS227, Data Structures and Algorithms                */
/* Date Written: November 1, 2019                                     */
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
/* This program searches for a user's search target in a list, using  */
/* three different searching methods:                                 */
/*    Ordered Sequential Search,                                      */
/*    Probability Search,                                             */
/*    and Binary Search.                                              */
/* Then it will demonstrate the searches showing the target, the      */
/* index where it was found, and the search path taken.               */
/*                                                                    */
/**********************************************************************/

#include <stdio.h> /* scanf()                                         */

/**********************************************************************/
/*                        Symbolic Constants                          */
/**********************************************************************/
#define COURSE_NUMBER   "CS227" /* PCC assigned course number         */
#define DATA_SIZE       15      /* The size of the ordered list       */
#define LAST_INDEX      (DATA_SIZE - 1)
                                /* Last index of the ordered list     */
#define PROGRAM_NUMBER  7       /* Teacher assigned program number    */
#define PROGRAMMER_NAME "McPherson"
                                /* The programmer's last name         */                              
#define QUIT            0       /* Program exit value                 */

/**********************************************************************/
/*                        Function Prototypes                         */
/**********************************************************************/
void print_heading();
   /* Prints the program heading                                      */
void print_instructions();
   /* Prints the program instructions                                 */
void get_data(int ordered_data[], int last_index);
   /* Fills the arrays with the ordered data                          */
void show_data(int p_data[], int search_target, int last_index);
   /* Prints the indexes, data at each index, and the search targets  */
   /* of the lists                                                    */
void print_result(char result, int *p_location);
   /* Prints the result of the searching algorithms                   */
int  ordered_sequential_search(int seq_data[], int search_target,
                               int *p_location, int last_index);
   /* Searches the data using an ordered sequential search            */
int  probability_search(int prb_data[], int search_target, 
                        int *p_location, int last_index);
   /* Searches the data using a probability search                    */
int  binary_search(int bin_data[], int search_target, 
                   int *p_location, int last_index);
   /* Searches the data using a binary search                         */

/**********************************************************************/
/*                          Main Function                             */
/**********************************************************************/
int main()
{
   int bin_data[DATA_SIZE], /* Data for the binary search             */
       p_location,          /* Points to location of the target       */
       prb_data[DATA_SIZE], /* Data for the probability search        */
       search_target,       /* Target to be searched for              */
       seq_data[DATA_SIZE]; /* Data for ordered sequential search     */
       
   /* Prints the program heading and instructions                     */
   print_heading();
   print_instructions();

   /* Fill the arrays with the whole number data                      */
   get_data(seq_data, LAST_INDEX);
   get_data(prb_data, LAST_INDEX);
   get_data(bin_data, LAST_INDEX);

   /* Loop processing various search algorithms until the user says   */
   /* to quit                                                         */
   while (printf("\n\n\nEnter an integer search target (%d to quit): ",
      QUIT), scanf("%d", &search_target), search_target != QUIT)
   {
      /* Search for the target and print the results of the ordered   */
      /* sequential search                                            */
      printf("\n\nOrdered Sequential Search:");
      show_data(seq_data, search_target, LAST_INDEX);
      if (ordered_sequential_search(seq_data, search_target, 
                                   &p_location, LAST_INDEX))
         print_result('S', &p_location);
      else
         print_result('U', &p_location);

      /* Search for the target and print the results of the           */
      /* probability search                                           */
      printf("\n\nProbability Search:");
      show_data(prb_data, search_target, LAST_INDEX);
      if (probability_search(prb_data, search_target, &p_location,
            LAST_INDEX))
         print_result('S', &p_location);
      else
         print_result('U', &p_location);

      /* Search for the target and print the rsults of the binary     */
      /* search                                                       */
      printf("\n\nBinary Search:");
      show_data(bin_data, search_target, LAST_INDEX);
      if (binary_search(bin_data, search_target, &p_location,
            LAST_INDEX))
         print_result('S', &p_location);
      else
         print_result('U', &p_location);
   }

   /* Print a goodbye message and terminate the program               */
   printf("\nThanks for searching.  Have a nice day! ;-)");
   printf("\n\n\n\n\n\n");
   return 0;
}

/**********************************************************************/
/*                    Print the program heading                       */
/**********************************************************************/
void print_heading()
{
   printf("\n\n\n\n\n\n");
   printf("\n======================================================");
   printf("\n               Program Number: %d",    PROGRAM_NUMBER);
   printf("\n               Programmer: %s",        PROGRAMMER_NAME);
   printf("\n               PCC Course Number: %s", COURSE_NUMBER);
   printf("\n======================================================");
   return;
}

/**********************************************************************/
/*                Print the program instructions                      */
/**********************************************************************/
void print_instructions()
{
   printf("\nThis program demonstrates various search algorithms.");
   printf("\nYou enter in any whole number, and the program will");
   printf("\nsearch for it in an ORDERED array of whole numbers");
   printf("\nusing each of the following search algorithms:");
   printf("\n     1. Ordered Sequential Search");
   printf("\n     2. Probability Search");
   printf("\n     3. Binary Search");
   printf("\nThe progress of each search is shown so the efficiency");
   printf("\nof the search algorithms can be compared.");
   return;
}

/**********************************************************************/
/*                Fill the arrays with ordered data                   */
/**********************************************************************/
void get_data(int ordered_data[], int last_index)
{
   int array_index = 0; /* Index for the ordered list                 */

   for (array_index = 0; array_index <= last_index; array_index++)
      ordered_data[array_index] = (array_index * 5) + 10;
   return;
}

/**********************************************************************/
/*       Print each index, the data stored there, and the target      */
/**********************************************************************/
void show_data(int p_data[], int search_target, int last_index)
{
   int array_index; /* Index for each item in the list                */

   printf("\n   Array Index: ");
   for (array_index = 0; array_index <= last_index; array_index++)
      printf("[%2d]", array_index);
   printf("\n    Array Data:");
   for (array_index = 0; array_index <= last_index; array_index++)
      printf("  %2d", p_data[array_index]);
   printf("\n   User Target:  %2d", search_target);
   return;
}

/**********************************************************************/
/*                 Print the result of the searches                   */
/**********************************************************************/
void print_result(char result, int *p_location)
{
   printf("\nSearch Outcome: ");
   if (result == 'S')
      printf("Successful - target found at index [%2d]", *p_location);
   else   
      if (result == 'U')
         printf("Unsuccessful - target not found");
      else
         printf("Undetermined");
   return;
}

/**********************************************************************/
/*   Search for a number in an ordered list with a sequential search  */
/**********************************************************************/
int ordered_sequential_search(int seq_data[], int search_target, 
                              int *p_location, int last_index)
{
   int array_index = 0; /* Looker for each index in the list          */
   
   printf("\n   Search Path: ");
   if (search_target <= seq_data[last_index])
      while (search_target > seq_data[array_index])
      {
         printf("[%2d]", array_index);
         array_index++;
      }
   else
      array_index = last_index;
   *p_location = array_index;
   printf("[%2d]", *p_location);
   return (seq_data[*p_location] == search_target);
}

/**********************************************************************/
/*  Search for a number in an ordered list with a probability search  */
/**********************************************************************/
int probability_search(int prb_data[], int search_target, 
                       int *p_location, int last_index)
{
   int array_index = 0, /* Index for the ordered list                 */
       temp_index;      /* Temporary index for the swap               */

   printf("\n   Search Path: ");
   while(array_index <= last_index)
   {
      printf("[%2d]", array_index);
      if(prb_data[array_index] == search_target)
      {
         *p_location = array_index;
         array_index       = last_index;
      }
      array_index++;
   }
   if (prb_data[*p_location] == search_target)
      if (*p_location > 0)
      {
         temp_index                = prb_data[*p_location - 1];
         prb_data[*p_location - 1] = prb_data[*p_location];
         prb_data[*p_location]     = temp_index;
         *p_location               = (*p_location - 1);
      }
   return (prb_data[*p_location] == search_target);  
}

/**********************************************************************/
/*     Search for a number in an ordered list with a binary search    */
/**********************************************************************/
int binary_search(int bin_data[], int search_target, 
                  int *p_location, int last_index)
{
   int beginning_index = 0,          /* Beginning index in the search */
       middle_index    = 0,          /* Middle index in the search    */
       ending_index    = last_index; /* Last index in the search      */

   printf("\n   Search Path: ");
   while (beginning_index <= ending_index)
   {
      middle_index = ((beginning_index + ending_index) / 2);
      printf("[%2d]", middle_index);
      if (search_target > bin_data[middle_index])
         beginning_index = middle_index + 1;
      else
      {
         if (search_target < bin_data[middle_index])
            ending_index = middle_index - 1;
         else
            beginning_index = ending_index + 1;
         }
   }
   *p_location = middle_index;
   return (bin_data[middle_index] == search_target);
}