# Push Swap
This is an implementation of the popular game Push Swap, which is a sorting algorithm game.

## How to use

To use this program, you can compile it using a command like 
```bash
gcc main.c -o push_swap
```
Then, you can run the program by passing it a list of integers as command line arguments. For example:
```
./push_swap 3 2 1
```
This will sort the list of integers in ascending order.

## How it works
This implementation uses a combination of radix sort and custom sorting algorithm.
If the size of the input stack is greater than 5, it uses radix sort, otherwise it uses custom sorter.

## Note
-This implementation checks for input arguments for invalid input, if invalid input is passed it will return error
-If the input is already sorted, the program exits immediately and it doesn't perform any sort
-The input stack is indexed and maintained using linked list, stack B is also maintained using linked list.
