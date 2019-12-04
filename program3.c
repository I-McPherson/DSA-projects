/**********************************************************************/
/*                                                                    */
/* Program Name: program3  - Processing scientific data                */
/* Author:       Ian McPherson                                        */
/* Installation: Pensacola Christian College, Pensacola, Florida      */
/* Course:       CS277, Data Structures and Algorithms                */
/* Date Written: September 24, 2019                                   */
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
/* This program asks the user for the amount of scientific data to    */
/* process, then will ask for the data, converting negative values to */
/* positive.  It will then sort the data and print the sorted data    */
/* noting duplicates.                                                 */
/*                                                                    */
/**********************************************************************/

#include <stdio.h>  /* scanf(), printf()                              */
#include <stdlib.h> /* exit(), free(), malloc()                       */
#include <string.h> /* memcpy()                                       */

/**********************************************************************/
/*                        Symbolic Constants                          */
/**********************************************************************/
#define COURSE_NUMBER    "CS227"     /* PCC assigned course number    */
#define PROGRAM_NUMBER   3           
   /* Teacher assigned program number                                 */
#define PROGRAMMER_NAME  "McPherson" /* The programmer's last name    */
#define MINIMUM_QUANTITY 2           /* Minimum Quantity              */
#define MAXIMUM_QUANTITY 100         /* Maximum Quantity              */
#define QUIT             0           /* Quit Value                    */
#define DATA_ALLOC_ERR   1           /* Error for memory allocation   */
#define SORT_ALLOC_ERR   2           /* Error for sorting memory      */

/**********************************************************************/
/*                        Function Prototypes                         */
/**********************************************************************/
void  print_heading();      
   /* Print the program and instructions for the user                 */
void  print_instructions();
   /* Print the program instructions for the user                     */
int   get_quantity();
   /* Get the quantity of the data from the user                      */
void  get_data(float *p_data_start, int data_quantity);
   /* Get the data values from the user                               */
void  sort_data(float *p_data_start, int data_quantity);
   /* Sorts the data from largest to smallest                         */
void  print_data(float *p_data_start, int data_quantity);
   /* Prints the sorted data, noting duplicates                       */
float sum_data(float *p_data_start, int data_quantity);
   /* Sums the value of the data in a range                           */
void  print_sum(float data_sum);
   /* prints the sum of the range                                     */
   
/**********************************************************************/
/*                          Main Function                             */
/**********************************************************************/
int main()
{
   int   data_quantity; /* Quantity of scientific data                */
   float *p_data;       /* Points to the array of scientific data     */
   
   /* Print the program header                                        */
   print_heading();
   
   /* Loop processing data until the user says to quit                */
   while(print_instructions(), (data_quantity = get_quantity()) != QUIT)
   {
      /* Allocates memory for the experimental scientific data if     */
      /* memory is available                                          */
      if ((p_data = (float *) malloc (sizeof(*p_data) * 
                                                data_quantity)) == NULL)
      {
         printf("\nError #%d occurred in main().", DATA_ALLOC_ERR);
         printf("\nImpossible menu choice error occurred.");
         printf("\nThe program is aborting.");
         printf("\n\n\n\n\n");
         exit  (DATA_ALLOC_ERR);
      }
      else
      {
         /* Get, sort, print sorted data, sum, and print the          */
         /* experimental scientific data                              */
         get_data   (p_data, data_quantity);
         sort_data  (p_data, data_quantity);
         print_data (p_data, data_quantity);
         sum_data   (p_data, data_quantity);
         print_sum  (sum_data(p_data, data_quantity));
         
         /* Frees the memory used by the array                        */
         free(p_data);
      }
   }
   
   /* Says goodbye and terminates the program                         */
   printf("\nThanks for processing data. Have a nice day! ;-)");
   printf("\n\n\n\n\n\n\n");
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
/*                Print the program instructions                      */
/**********************************************************************/
void print_instructions()
{
   printf("\n\nThis program processes experimental scientific data");
   printf(  "\n---------------------------------------------------");
   return;
}
/**********************************************************************/
/*                     Get the data quantity                          */
/**********************************************************************/
int get_quantity()
{
   int data_quantity; /* Quantity of experimental scientific data     */

   do 
   { 
      printf("\nHow many data values are there (%d to %d, %d=quit): ",
              MINIMUM_QUANTITY, MAXIMUM_QUANTITY, QUIT);
      scanf ("%d", &data_quantity);
   } 
   while(((data_quantity < MINIMUM_QUANTITY) || 
         (data_quantity > MAXIMUM_QUANTITY)) && (data_quantity != QUIT));
   return data_quantity;
}

/**********************************************************************/
/*                   Get the experimental data                        */
/**********************************************************************/
void get_data(float *p_data_start, int data_quantity)
{
   float *p_data;
   /* Points to the beginning of the experimental scientific data     */
   
   /* Loops until all experimental scientific data is input           */
   for (p_data = p_data_start; (p_data - p_data_start) < data_quantity;
                                                              p_data++)
   {
      printf("   Enter data value %d: ", (int)
                                         (p_data - p_data_start + 1));
      scanf ("%f", p_data);
      if (*p_data < 0)
      {
         printf("     Negative %.2f converted to positive ", *p_data);
         *p_data = -(*p_data);
         printf("%.2f", *p_data);
         printf("\n");
      }
   }
   return;
}

/**********************************************************************/
/*                     Sort experimental data                         */
/**********************************************************************/
void sort_data(float *p_data_start, int data_quantity)
{
   float *p_biggest,    
            /* Points to the biggest experimental scientific data     */
            /* value                                                  */
         *p_data,
            /* Points to the start of the experimental scientific     */
            /* data                                                   */
         *p_sort,       
            /* Gets the sorted experimental scientific data           */
         *p_sort_start; 
            /* Points to the start of the sorted experimental         */
            /* scientific data                                        */

   /* Alloces memory for the sorted experimental scientific data if   */
   /* memory is available                                             */
   if ((p_sort = (float *) malloc (sizeof(*p_sort) * 
                                               data_quantity)) == NULL)
   {
      printf("\nError #%d occurred in main().", SORT_ALLOC_ERR);
      printf("\nImpossible menu choice error occurred.");
      printf("\nThe program is aborting.");
      printf("\n\n\n\n\n");
      exit  (SORT_ALLOC_ERR);
   }
   else
   {
       for (p_sort_start = p_sort; (p_sort - p_sort_start) < 
                                                data_quantity; p_sort++)
      {
         *p_sort = 0.0f;
         for (p_data = p_data_start; (p_data - p_data_start) < 
               data_quantity; p_data++)
            if (*p_data >= *p_sort)
            {
               *p_sort   = *p_data;
               p_biggest = p_data;
            }
         *p_biggest = 0.0f; 
         p_data     = p_data_start;
      }
   }
   /* Copies the sorted data from p_sort to p_data                    */
   memcpy (p_data_start, p_sort_start, sizeof(*p_sort) * data_quantity);
   
   /* Frees the data used with p_sort_start                           */
   free   (p_sort_start);
   return;
}

/**********************************************************************/
/*                    Prints the ordered data                         */
/**********************************************************************/
void print_data(float *p_data_start, int data_quantity)
{
   float *p_data; /* Points to the start of the experimental          */
                  /* scientific data array                            */

   printf("\nThe data in descending order (with duplicates noted):");
   printf("\n-----------------------------------------------------");
   for (p_data = p_data_start; (p_data - p_data_start) < data_quantity;
                                                              p_data++)
   {
      if (p_data == p_data_start)
         printf("\n                 %9.2f", *p_data);
      else if (*p_data == *(p_data - 1))
         printf("\n                 %9.2f (duplicate)", *p_data);
      else
         printf("\n                 %9.2f", *p_data);

   }
   return;                                                          
}

/**********************************************************************/
/*                     Sum Experimental Data                          */
/**********************************************************************/
float sum_data(float *p_data_start, int data_quantity)
{
   float data_sum = 0.0f,
            /* The sum of the experimental scientific data            */
         *p_data; 
            /* Points to the experimental scientific data             */

   
   /* Loop processing the sum of the experimental scientific data     */
   for (p_data = p_data_start; (p_data - p_data_start) < data_quantity;
                                                              p_data++)
      data_sum += *p_data;
   return data_sum;
}

/**********************************************************************/
/*                     Print the summed range                         */
/**********************************************************************/
void print_sum(float data_sum)
{
   printf("\n                 ---------");
   printf("\n                 %9.2f total", data_sum);
   return;
}