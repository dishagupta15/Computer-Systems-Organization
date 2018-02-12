# Lab 1

This lab consists of six parts. Each part is described below.

1. Number Arrangement: In this function, the user enters the number of elements X. The main() function will generate a list of 
X random numbers. This list together with X are passed to the function arrange() where you have to arrange the elements as 
follows. First, the even elements, if any, are inserted first and sorted in ascending order. Then, the odd numbers, if any, 
are inserted and sorted in ascending order too. Note that numbers can be repeated. For example, if we have a 
list of 5 elements: 5 5 4 3 2 3 1 then the output of your function, printed on the screen, will be: 2 4 1 3 3 5 5.

2. Fibonacci Sequence: Your second function is called find_fibonacci(). It takes two positive numbers x and y where x < y. 
The function must print all the Fibonacci series between x and y (not including x and y). Fibonacci is a series 
of numbers in which each number is the sum of the two preceding numbers. It starts as: 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, etc.
So, if x= 5 and y = 20 then your function must print on the screen: 8 13. Both x and y will be positive numbers less 
than 1,000,000 (one million).

3. Flipping: This function reads a integer and prints it in reverse order. So, if the user enters 12345, your function 
must print: 54321.

4. Histogram: This function reads a text file that contains a string of characters (they can be upper case
letters, lower case letters, numbers, spaces, ...).. Then your function prints on the screen a
histogram of the lower case characters ONLY. For example, if the file contains: "AAaaa77b bc" the function 
must print on the screen:
a: 3
b: 2
c: 1
d: 0
e: 0
.
.
.
z: 0

5. From Lower Case to Upper: Here, you will design a function that reads a text file containing only lower case characters. 
It generates a different file, with a different name as indicated in
the comments in lab1.c, that contains the same characters but in upper case.

6. Encryption: Here, you will read a text file and print on the screen an encrypted version of that file, as
follows:
- Each character will be replaced with another character 3 letters before. For
example: f is replaced with c, h is replaced with e, and so on.
- The encryption is circular, so a is replaced with x, b with y, and so on.
- White spaces are ignored and printed unchanged.
- The input file will contain nothing but lower case characters and spaces (no digits,
no upper case, etc).
- The output is printed on the screen.
