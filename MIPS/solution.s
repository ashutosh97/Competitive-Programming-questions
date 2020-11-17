# This program computes and displays the sum of integers from 1 up to n,
# where n is entered by the user.


    .globl main

    .data

prompt:     .asciiz  "Please enter a positive integer:  "
result1:    .asciiz  "The sum of the first "
result2:    .asciiz  " integers is "
newline:    .asciiz  "\n"
      