# Vector

# What is this?
Simple vector implementation in C inspired by C++ Vector class.

# Why have I wrote this?
I wrote this because I didn't find any other C implementation of vector I would be satisfied with. I like OOP way of thinking even when programming in pure C and I was very familiar with using vector while learning C++. I needed some comfortable way to store   and process gigabytes of scientific data while parsing them out of database, all as part of my diploma thesis.

# How to use this?
vector.c and vector.h can be used as any other C header and source files - just copy them to project directory, include header files when needed and compile it together, or create a real library and use it.

# Does it work?
Well, I hope so, I did just simple test, file test.c is also included as a usage example. I compiled it with -std=c99 -pedantic -Wall -Werror flags on my Ubuntu machine and runned also with valgrind, it caused no memory leaks or other errors and it seems it does what it is suposed to do.

# Can you help me?
Sure - if you would like to write some real tests, I will be very glad. I will be also really thankful for any bug report, advice, recommendation or suggestion for additional funcionality you miss - you can leave comment here on github or write me to michalpajtinka@gmail.com.

# License
This project is licensed under the terms of the MIT license.
