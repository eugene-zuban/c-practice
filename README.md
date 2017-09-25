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

5. [Sum linked lists in reverse order](https://github.com/jack-zuban/c-practice/blob/master/linked-lists/sum-reverse-lists/sum-reverse-lists/main.c) and [recursion version:](https://github.com/jack-zuban/c-practice/blob/master/linked-lists/sum-reverse-lists/sum-reverse-lists/recursion.c) add two linked lists which represent integer numbers in reverse order, and write the result into a linked list in reverse order too. Example: (1 -> 3 -> 5) + (2 -> 3 -> 4) = (3 -> 6 -> 9) represents 531 + 432 = 963.

6. [Sum linked lists](https://github.com/jack-zuban/c-practice/blob/master/linked-lists/sum-lists/sum-lists/main.c) add two linked lists which represent integer numbers and write the result into a linked list using left to right numbers order. Example: (1 -> 3 -> 5) + (2 -> 3 -> 4) = (3 -> 6 -> 9) represents 135 + 234 = 369.

8. [Palindrome](https://github.com/jack-zuban/c-practice/blob/master/linked-lists/palindrome/palindrome/main.c) determine if a given linked list is a palindrome.

9. [intersection](https://github.com/jack-zuban/c-practice/blob/master/linked-lists/intersection/intersection/main.c) find if two linked list intersects sharing the same nodes by references.
