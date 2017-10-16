# c-practice
Practicing C language: small and easy code examples on C for fun.

This repo includes small solutions written on C using different sources for ideas:

1. A part of the code examples and ideas are based on "Programming in C" book written by Stephen G. Kochan.

2. Another part of the code are solutions to the coding tasks from "Cracking the Coding Interview" book written by Gaylee Laakmann McDowell.

### Solutions to the "Cracking the Coding Interview" tasks.


**Arrays and Strings**
1. [String unique characters check:](https://github.com/jack-zuban/c-practice/tree/master/array-and-strings/unique-characters/unique-characters/main.c) Determine if given string has all unique characters.

2. [Strings permutation check:](https://github.com/jack-zuban/c-practice/blob/master/array-and-strings/string-permutation-check/string-permutation-check/main.c) Determine if one of the two given string is a permutation of the other.

3. [Replacing spaces using pointers:](https://github.com/jack-zuban/c-practice/tree/master/array-and-strings/URLfy/URLfy/main.c) URLfy: a method to replace all spaces in a string with '%20'. The algorithm in my code does replacements from the end of the string.

4. [Permutation of a palindrome check using bit mask:](https://github.com/jack-zuban/c-practice/blob/master/array-and-strings/palindrome-permutation/palindrome-permutation/main.c) Check if given string is a permutation of a palindrome. The palindrome could be any character sequence and it does not need to be limited to dictionary words.

5. [One edit away checker:](https://github.com/jack-zuban/c-practice/blob/master/array-and-strings/one-away/one-away/main.c) Check that two strings are one (or none) edit away from each other.

6. [String compression:](https://github.com/jack-zuban/c-practice/blob/master/array-and-strings/string-compression/string-compression/main.c) Compress a given string using the count of repeated characters. Return the original string if the compressed string length is more or equal original.

7. [Matrix Rotation:](https://github.com/jack-zuban/c-practice/blob/master/array-and-strings/matrix-rotation/matrix-rotation/main.c) Rotate a given NxN matrix 90 by degrees doing in place rotation.

8. [Zero Matrix:](https://github.com/jack-zuban/c-practice/blob/master/array-and-strings/zero-matrix/zero-matrix/main.c) On a given matrix MxN if an element is 0, set its entire row and col to 0 without using extra space for storage.

9. [String Rotation Check:](https://github.com/jack-zuban/c-practice/blob/master/array-and-strings/string-rotation/string-rotation/main.c) Given two strings s1 and s2, check if s2 is a rotation of s1.


**Linked Lists**
1. [Remove duplicates:](https://github.com/jack-zuban/c-practice/blob/master/linked-lists/remove-duplicates/remove-duplicates/main.c) Remove duplicates from a linked list.

2. [Return nth to last:](https://github.com/jack-zuban/c-practice/blob/master/linked-lists/find-nth-to-last/find-nth-to-last/main.c) Return Nth to last element in a linked list using recursion during searhing.

3. [Delete middle node:](https://github.com/jack-zuban/c-practice/blob/master/linked-lists/delete-middle-node/delete-middle-node/main.c) Delete a node in the middle from a linked list given access to this node only.

4. [Linked list partitioning:](https://github.com/jack-zuban/c-practice/blob/master/linked-lists/list-partition/list-partition/main.c) Partition a linked list around given X by moving nodes less than X to the left, and more or equal to the right side of the list.

5. [Sum linked lists in reverse order:](https://github.com/jack-zuban/c-practice/blob/master/linked-lists/sum-reverse-lists/sum-reverse-lists/main.c) and [recursion version:](https://github.com/jack-zuban/c-practice/blob/master/linked-lists/sum-reverse-lists/sum-reverse-lists/recursion.c) add two linked lists which represent integer numbers in reverse order, and write the result into a linked list in reverse order too. Example: (1 -> 3 -> 5) + (2 -> 3 -> 4) = (3 -> 6 -> 9) represents 531 + 432 = 963.

6. [Sum linked lists:](https://github.com/jack-zuban/c-practice/blob/master/linked-lists/sum-lists/sum-lists/main.c) add two linked lists which represent integer numbers and write the result into a linked list using left to right numbers order. Example: (1 -> 3 -> 5) + (2 -> 3 -> 4) = (3 -> 6 -> 9) represents 135 + 234 = 369.

8. [Palindrome:](https://github.com/jack-zuban/c-practice/blob/master/linked-lists/palindrome/palindrome/main.c) determine if a given linked list is a palindrome.

9. [Intersection:](https://github.com/jack-zuban/c-practice/blob/master/linked-lists/intersection/intersection/main.c) find if two linked list intersects sharing the same nodes by references.

10. [Loop detection:](https://github.com/jack-zuban/c-practice/blob/master/linked-lists/loop-detection/loop-detection/main.c) find if a given list has a loop, and return the loop head if it exists.


**Stack and queue**
1. [Three stacks in one array:](https://github.com/jack-zuban/c-practice/blob/master/stack-and-queues/stack-in-array/stack-in-array/main.c) Implement three stacks using a single array.

2. [Stack min():](https://github.com/jack-zuban/c-practice/tree/master/stack-and-queues/stack-min/stack-min) Add min() function to a stack implementation which returns the minimum element from the stack in O(1) time.

3. [Stack of plates:](https://github.com/jack-zuban/c-practice/blob/master/stack-and-queues/stack-of-plates/stack-of-plates/main.c) Implement a data structure that will work as a stack of plates using fixed-size stacks for storing nodes. pop() and push() on the stack of plates structure should function identically to a regular stack.

4. [Queue via Stacks:](https://github.com/jack-zuban/c-practice/blob/master/stack-and-queues/queue-via-stacks/queue-via-stacks/main.c) Implement a queue that will use two stacks for its nodes.

5. [Sort a stack:](https://github.com/jack-zuban/c-practice/blob/master/stack-and-queues/sort-stack/sort-stack/main.c) Sort a given stack using only one additional temp stack.

6. [Animal Shelter:](https://github.com/jack-zuban/c-practice/blob/master/stack-and-queues/animal-shelter/animal-shelter/main.c) A FIFO queue that accepts dogs and cats and returns the "oldest" cat or dog as requested.

**Trees and Graphs**
1. [Route between nodes](https://github.com/jack-zuban/c-practice/blob/master/trees-and-graphs/route-between-nodes/route-between-nodes/main.c). Find if there is a route between two nodes in a given directed graph.

**Recursion and Dynamic programming**
1. [Robot in a Grid path:](https://github.com/jack-zuban/c-practice/blob/master/recursion-and-dynamic-programming/robot-in-a-grid/robot-in-a-grid/main.c) Find a path from the top left to the bottom right corner for a robot in a MxN grid where the robot can move only right and down, and some cells on the grid are marked as closed.
