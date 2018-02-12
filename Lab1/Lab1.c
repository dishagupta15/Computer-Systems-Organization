
/*
 * IMPORTANT: WRITE YOUR NAME AND NetID BELOW.
 * 
 * Last Name: Gupta
 * First Name: Disha
 * Netid: dg2703
 * 
 * You will do your project in this file only.
 * Do not change function delarations. However, feel free to add new functions if you want.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>

/* Function declarations: do not change that, but you may add your own functions */
void arrange(int *, int);
void find_fibonacci(int, int);
void flipping(unsigned int);
void file_histogram(char *);
void file2upper(char *);
void file_encrypt(char *);

/* Add here function declarations of your own, if any. */

// The sort() function takes in a pointer to an array, list, and the length of that array, num.
// This function implements bubble sort to sort the given array. 
void sort(int *list, int num) {
  for (int i = 0; i < (num-1); i++) {
    for (int j = 0; j < (num-i-1); j++) {
      // Check if the first element is bigger than the next element.
      if (list[j] > list[j+1]) {
        // If it is, store the first element in a variable swap.
        int swap = list[j];
        // Set the first element to the smaller value, the second element.
        list[j] = list[j+1];
        // Set the second element to the bigger value, the first element (swap).
        list[j+1] = swap;
      }
    }
  }
}

/*********************************************************************************/

/* 
 * Do  NOT change anything in main function 
 */
int main(int argc, char * argv[])
{
  int option = 0;
  int i, j;
  int * list;
  
  if(argc < 2 )
  {
     fprintf(stderr,"Usage: lab1 num [input]\n");
     fprintf(stderr,"num: 1, 2, 3, 4, 5, or 6\n");
     exit(1);
  }
  
  option = atoi(argv[1]);
  
  switch(option)
  {
    case 1: if(argc != 3)
	    {
	      fprintf(stderr,"Usage: lab1 1 num\n");
	      fprintf(stderr,"num: number of elements of the array to be arranged\n");
	      exit(1);
	    }
	    j = atoi(argv[2]);
	    list = (int *)malloc(j*sizeof(int));
	    if(!list)
	    {
	      fprintf(stderr,"Cannot allocate list in option 1\n");
	      exit(1);
	    }
	    
	    /* Generate random numbers in the range [0, 100) */
	    for(i = 0; i < j; i++)
	      list[i] = rand()% 100;
	    
	    /* Print the unsorted array */
	    printf("The original array:\n");
	    for(i = 0; i < j; i++) 
	      printf("%d ", list[i]);
	    printf("\n");
	    
	    printf("The arranged array:\n");
	    arrange(list, j);
	    
	    break;
	    
	    
    case 2: if(argc != 4)
	    {
	      fprintf(stderr,"Usage: lab1 2 x y\n");
	      fprintf(stderr,"x and y: positive integers and x < y and y < 1 million\n");
	      exit(1);
	    }
	    i = atoi(argv[2]);
	    j = atoi(argv[3]);
	    
	    find_fibonacci(i, j);
	    
	    break;

	    
    case 3: if(argc != 3)
	    {
	      fprintf(stderr,"Usage: lab1 3 num\n");
	      fprintf(stderr,"num: unsigned intger number\n");
	      exit(1);
	    }
	    
	    flipping( atof(argv[2]));
	    
	    break; 
	    
	    
    case 4: if(argc != 3)
	    {
	      fprintf(stderr,"Usage: lab1 4 filename\n");
	      exit(1);
	    }
	    
	    file_histogram(argv[2]);
	    
	    break;

	    
    case 5: if(argc != 3)
	    {
	      fprintf(stderr,"Usage: lab1 5 filename\n");
	      exit(1);
	    } 
	    
	    file2upper(argv[2]);
	    
	    break;

	    
    case 6: if(argc != 3)
	    {
	      fprintf(stderr,"Usage: lab1 46filename\n");
	      exit(1);
	    }
	    
	    file_encrypt(argv[2]);
	    
	    break;	      
	    
    default: fprintf(stderr, "You entered an invalid option!\n");
	     exit(1);
  }
  
  return 0;
}

/******* Start filling the blanks from here and add any extra functions you want, if any *****/

/*
 * Part 1:
 * In this function, you are given two inputs:
 * inputs: 
 * 	an array of int list[] 
 * 	The number of elements in that array: num
 * You need to put the even numbers first (if any), sorted in ascending order, followed
 * by the odd numbers (if any) sorted in ascending order too.
 * Example: a list of 5 elements: 5 4 3 2 1 
 * The output will be: 2 4 1 3 5 
 * Finally, print the array on the screen.
 * */

void arrange(int *list, int num)
{
  // Create an array to store the even numbers and give it the length of the original array. 
  int evenNums[num];
  // Create a counter to keep track of the number of even numbers.
  int evenCounter = 0; 
  
  // Create an array to store the odd numbers and give it the length of the original array.
  int oddNums[num];
  // Create a counter to keep track of the number of odd numbers.
  int oddCounter = 0;
  
  // Loop through the original array.
  for (int i = 0; i < num; i++) {
    // Check if the values in the array are divisible by 2.
    if (list[i] % 2 == 0) {
      // If they are, add the even number to the even number array.
      evenNums[evenCounter] = list[i];
      // Increment the even counter.
      evenCounter++;
    }
    // Else, the number is odd.
    else {
      // Add the odd number to the odd number array.
      oddNums[oddCounter] = list[i];
      // Increment the odd counter.
      oddCounter++;
    }
  }
  
  // Call the sort function on both arrays to sort the numbers in ascending order.
  sort(evenNums,evenCounter);
  sort(oddNums,oddCounter);
  
  // Loop through the even number array and print out the numbers.
  for (int i = 0; i < evenCounter; i++) {
    printf("%d ", evenNums[i]);
  }
  
  // Loop throguh the odd number array and print out the numbers.
  for (int i = 0; i < oddCounter; i++) {
    printf("%d ", oddNums[i]);
  }
}

/*********************************************************************************/

/* 
 * Part 2:
 * In this part, you are given two positive integers, x and y, larger than 0.
 * You need to print all the Fibonacci numbers between x and y (NOT including x and y themselves), if any.
 */

void find_fibonacci(int x, int y)
{
  // Declare an int, fib, to hold the new fibonacci number as it is generated each time.
  int fib;
  // Declare the ints fib1 and fib2, to hold the first two fibonacci numbers.
  int fib1 = 0;
  int fib2 = 1;
  
  // Calculate the first fibonacci number.
  fib = fib1 + fib2;
  
  // Set the upper bound to be y.
  while (fib1 < y) {
    // Check to make sure that fib is between x and y.
    if (fib > x && fib < y) {
      // Print out the fibonacci numbers between x and y.
      printf("%d ",fib);
    }
    
    // Set fib1 to fib2 and fib2 to fib in order to keep moving up the fibonacci sequence.
    fib1 = fib2;
    fib2 = fib;
    // Recalculate the fibonacci nunmber.
    fib = fib1 + fib2;
  }
}

/*********************************************************************************/

/*
 * Part 3:
 * Given an unsigned integer (so has values of 0 and up), print on the screen 
 * the flipping of that number.
 * That is, if the number given is: 1234  then you print: 4321
 */

void flipping(unsigned int num)
{
  // Declare an int to hold the reversed number.
  int reverse = 0;
  
  // Loop over num until it equals 0.
  while (num != 0) {
    // Add the reversed number times 10 and the remainder of num together until num = 0.
    reverse = (reverse*10) + (num%10);
    
    // Divide num by 10 to get rid of the last digit.
    num = num/10;
  }
  
  // Print out the reversed number.
  printf("%d", reverse);
}

/*********************************************************************************/

/*
 * Part 4
 * The input is a filename.
 * The filename contains a string of characters (can be upper case letters, lower case letters, numbers, ...).
 * The output is a histogram of the file printed on the screen ONLY for lower case letters.
 * Example: 
 * The input file in.txt contains:  a1aaAbBBb709bbc
 * The output will be:
 * a: 3
 * b: 4
 * c: 1
 * .... and so one
 * The file can contain any characters, not necessarily only lower case characters.
 */

void file_histogram(char *filename)
{ 
  // Open the file passed to the function in read mode and store it in the pointer file.
  FILE *file = fopen(filename, "r");
  
  // Check if the file exists.
  if (access(filename, F_OK) != -1) {
    // Create a char variable.
    char c;
    // Create an array of length 26 and initalize all of the values to 0.
    // This array tracks the number of times each letter appears.
    int alphabet[26] = {0};
    
    // Loop over the file.
    while (c != EOF) {
      // Get the first character in the file.
      c = fgetc(file);
      // Check to see if the character is a lowercase letter.
      // Do this by comparing the character's ASCII value.
      if (c >= 'a' || c <= 'z') {
	// If it is, increment that letter's spot in the array.
	alphabet[c-97]++;
      }
    }
    
    // Loop over the alphabet array.
    for (int i = 0; i < 26; i++) {
      // Print out the letter.
      printf("%c:", i+97);
      // Print out the counter for the letter.
      printf("%d\n", alphabet[i]);
    }
  }
}

/*********************************************************************************/

/* 
 * Part 5:
 * Input: filename
 * Output:filenameCAPITAL
 * The output files contains the same characters as the input file but in upper case.
 * The input file will ONLY contain lower case letters and no spaces.
 * If the input filename is: mmmm 
 * The output filename is: mmmmCAPITAL
 */

void file2upper(char *filename)
{
  // Open the file passed to the function in read mode and store it in the pointer file.
  FILE *file = fopen(filename, "r");
  
  // Create a string that is the length of the filename plus seven extra characters.
  // The seven extra characters accounts for the phrase "CAPITAL" that will later be added onto the file name.
  char str[strlen(filename) + 7];
  // Copy the original filename  to the string.
  strcpy(str, filename);
  // Concatenate "CAPITAL.txt" to the string.
  // This gives you the name of the output file.
  strcat(str, "CAPITAL");
  
  // Create a new file with the output file name and open it in write mode.
  FILE *fileOutput = fopen(str, "w");
  
  // Create a char variable.
  char c;
  
  // Loop over the file.
  while (c != EOF) {
    // Get the next character in the file.
    c = fgetc(file);
    // Convert the character to uppercase.
    c = toupper(c);
    // Add the new character to the output file.
    fputc(c,fileOutput);
  }
  
  // Close the file.
  fclose(file);
}

/*********************************************************************************/

/*
 * Part 6:
 * In that last part, you will learn to implement a very simple encryption.
 * Given a file that contains a series of lower case charaters (may be separated by white space),
 * replace all non-white space with the lower case letter that exists 3 letters before, in a circular way.
 * For example: 
 * e will be replaced with b
 * d will be replaced with a 
 * c will be replaced with z  <--- circular
 * b will be replaced with y  <--- circular
 * and white spaces will be left unchanged.
 * Print the output on the screen.
 */

void file_encrypt(char * filename)
{
  // Open the file passed to the function in read mode and store it in the pointer file.
  FILE *file = fopen(filename, "r");
  
  // Create a char variable.
  char c;
  
  // Check if the file exists.
  if (access(filename, F_OK) != -1) {
    // Loop over the file.
    while (c != EOF) {
      // Get the next character in the file.
      c = fgetc(file);
      // Check to see if the character is a space.
      // On the ASCII table, 32 corresponds to a space.
      if (c == 32) {
        // If it is, print out a space.
        printf("%c", ' ');
      }
      // Check to see if the character is a, b, or c.
      if (c >= 97 && c <= 99) {
        // If it is, print out its corresponding encrypted character.
        printf("%c", (c+23));
      }
      else {
	// Else, print out the other lowercase characters.
	printf("%c", (c-3));
      }
    }
  }
}
