# Advent of Code 2020
[Advent of Code](https://adventofcode.com/2020) is an annual competition
that takes place some days just before xmas. Each day two new problems are being announced and
users are being awarded with a golden star for each problem they solve.
## Day 1
1. You are given a list of integers and you have to find the product of the
   (unique) **pair** that its sum is equal to 2020. The standard method of
   handling _2SUM_ is hashing with key: `target-num`.
1. The second part is almost the same; you have to find the sum of the
   **triplet** that its sum is equal to 2020. I sorted the array and used
   double indexes from bottom and top for each element of the array.

## Day 2
You are given a list of strings in the form `X-Y c: s*` and you are asked to check:
1. how many passwords have at least _X_ and no more than _Y_ occurrences of character _c_
1. how many passwords have `s[X]==c && s[Y]==c`

## Day 3
You are given a list of strings that represent a grid that expands infinitely to the right. You
are asked to calculate how many _#_ characters you meet while moving _X_ lines below and _Y_ to
the right. The proper use of modulo operator and string indexes reveal the answer.

## Day 4
You are given a list of strings that represent passports' properties. You have to calculate:
1. how many passports have all the required properties
1. how many passports are valid using the above criteria but also have valid data in their
   properties

The use of regular expressions and string manipulation reveal the answer.

## Day 5
You are given a list of strings using binary space partitioning and you have to find:
1. the highest seat ID
1. your own id which requires that both the next and the previous seat are occupied

Proper use of bitwise operators solves the problem.

## Day 6
You are given a list of characters where each character represents an affirmative
answer to a question, each line separates answerers and each empty line separates
people groups. You have to calculate:
1. the sum of the questions that there exists at least one person per group that
   answered "yes"
1. the sum of the questions that were unanimously approved for people in each
   group

## Day 7
You are given a list of sentences that start with a colored bag and describe a
containment relationship with one or several differently colored bags. You are
asked to calculate:
1. the number of bags eventually contain at least one _shiny gold_ bag
1. the number of bags a _shiny gold_ bag contains in total

An interesting problem that can easily be solved by considering the containment
as an edge relation (and bag colors as nodes). BFS traversal solves the first
question. For the second question I used recursion with memoization in order
to calculate the number of bags contained in the inside for each bag.

## Day 8
You are given a list of _assembly-like_ instructions and you are asked to calculate:
1. the value of the accumulator before an instruction is executed twice
1. the value of the accumulator after fixing the boot loop and terminating the program

Honestly I don't know if there is a better to accomplish the task without simulations;
halting questions are tricky lol.

~~I found that the questions were merely about transforming/using the input, so I kinda
lost interest.~~