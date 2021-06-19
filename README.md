# push_swap
42 Project: The aim of this project is to sort data on a stack, with a limited set of instructions, using the lowest possible number of actions

## Summary:

> To succeed you’ll have to manipulate various types of algorithms and choose the one (of many) most appropriate solution for an optimized data sorting.
push_swap project is a very simple and highly effective algorithm project: data will need to be sorted. You have at your disposal a set of int values, 2 stacks and a set of instructions to manipulate both stacks.

> Your goal ? Write a program in C called push_swap which calculates and displays on the standard output the smallest program using push_swap instruction language that sorts the integer arguments received.

## To run the program:
> Clone this directory and call make in the root. This should create an executable called 'push_swap'

> Call ./cub3D with a valid list of integers for example: ARG="4 67 3 87 23"; ./push_swap $ARG

> Now, you can see what operations are being called to sort the list.

> In order to see how many operation it takes and check if it's sorting correctly, use these commands:

```
$>ARG="4 67 3 87 23"; ./push_swap $ARG | wc -l
6
$>ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker_Mac $ARG
OK
$>
```

### Mandatory Part

**Game rules**

• The game is composed of 2 stacks named a and b.

• To start with: a contains a random number of either positive or negative numbers without any duplicates. b is empty

• The goal is to sort in ascending order numbers into stack a.

• To do this you have `the following operations` at your disposal:

```makefile
sa : swap a - swap the first 2 elements at the top of stack a. Do nothing if there
is only one or no elements).
sb : swap b - swap the first 2 elements at the top of stack b. Do nothing if there
is only one or no elements).
ss : sa and sb at the same time.
pa : push a - take the first element at the top of b and put it at the top of a. Do
nothing if b is empty.
pb : push b - take the first element at the top of a and put it at the top of b. Do
nothing if a is empty.
ra : rotate a - shift up all elements of stack a by 1. The first element becomes
the last one.
rb : rotate b - shift up all elements of stack b by 1. The first element becomes
the last one.
rr : ra and rb at the same time.
rra : reverse rotate a - shift down all elements of stack a by 1. The last element
becomes the first one.
rrb : reverse rotate b - shift down all elements of stack b by 1. The last elementbecomes the first one.
rrr : rra and rrb at the same time.
```

**the `push_swap` program**

• You have to write a program named push_swap which will receive as an argument the stack a formatted as a list of integers. The first argument should be at the top of the stack (be careful about the order).

• The program must display the smallest list of instructions possible to sort the stack a, the smallest number being at the top.

• Instructions must be separaed by a ’\n’ and nothing else.

• The goal is to sort the stack with the minimum possible number of operations. During defence we’ll compare the number of instructions your program found with a maximum number of operations tolerated. If your program either displays a list
too big or if the list isn’t sorted properly, you’ll get no points.

• In case of error, you must display Error followed by a ’\n’ on the standard error. Errors include for example: some arguments aren’t integers, some arguments are bigger than an integer, and/or there are duplicates.



## My implementation

I use linked lists to parse the arguments and implemented an optimised insertion sort. I found the idea from the medium article below.

## Things done as I go

- [ ]  transform string arguments to integer & save them in a linked list & input validation (is it a number, is it an integer, check doubles in stack)
- [ ]  write operation functions: rotate (sa, sb, ss, pa, pb, ra, rb, rr, rra, rrb, rrr)
- [ ]  sort list with 2 elements with max 1 instruction
- [ ]  write print_stacks func to see what's inside stacks whenever you want
- [ ]  researched for countless implementations of algorithms
- [ ]  decided to implement the simplest sorting solution to see how many instructions it will take = failure with num of instructions (5 elements sorted with 35 instructions, 100 elements > 10200, 500 elements > 251507 ) but a good learning process for manipulating linked lists
- [ ]  implemented some sort of bubble_sort initial version (5el: 14, 100el:8554, 500el:203535)
- [ ]  write your own tester bash script with input validation, amount of instructions for random lists with 3, 5, 100, 500 elements, ability to call tester bash script with arguments and calling ./push_swap with this spesific set of arguments
- [ ]  figured out how ./checker_Mac works and used it in my tester to printf out if a list is sorted based on push_swap's output: the instruction list.
- [ ]  sort list of 3 elements with max 3 instructions
- [ ]  sort list of 4 and 5 elements by using sort_three()
- [ ]  implemented a new sorting algo midi_sort which finds minimums and pushes them one by one to Stack B until 3 numbers left in A. So, numbers in Stack B are now reverse sorted. Then, it employs three_sort, then push everything in Stack B back to Stack A. (5el: 8-12, 100el:1483, 500el:31344)
- [ ]  implemented quick_sort but had to adjust my list for its purposes. transformed my singly linked list to doubly list.
- [ ]  adjusted parse_arguments + operations to doubly linked lists = took half of the day but it was very informative
- [ ]  implemented a special quick_sort where the pivot is the top element of stack A. I can solve 30-50 number lists but there it still needs debugging. > solved the randomness problem but instruction number to sort the list is way more than I expected. (100el:3483, 500el:46344)
- [ ]  found a bug while parsing negative numbers && fixed it
- [ ]  finally implemented an optimized insertion_sort from a medium article idea. (100el:750-850, 500el:7500-8000). So, it was enough to pass the project!

### References

[https://www.bigocheatsheet.com/](https://www.bigocheatsheet.com/)

[https://medium.com/nerd-for-tech/push-swap-tutorial-fa746e6aba1e](https://medium.com/nerd-for-tech/push-swap-tutorial-fa746e6aba1e)

[https://medium.com/@jamierobertdawson/push-swap-the-least-amount-of-moves-with-two-stacks-d1e76a71789a](https://medium.com/@jamierobertdawson/push-swap-the-least-amount-of-moves-with-two-stacks-d1e76a71789a)
