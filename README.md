# Welcome to My Mastermind
***

## Task
The task is to implement My Mastermind game using code written in C. In this game the user guesses the 4 digit number and computer reports wellplaced and missplaced number of digits.

## Description
The problem is solved by creation of several files: 1) main.c (contains main file), 2) hf.c (contains all required functions), 3) init.c (initialized the code and number of attempts using struct), 4) source.h (contains all needed directories and function names). The program compares the input with predefined OR randomly generated secret code.

## Installation
To install the project, it is necessary to run "make" command to compile the files. Then "./my_mastermind -c XXXX -t YY" command is executed, where XXXX is the 4 digit code to be initialized, and YY is the number of attempts to be initialized. If -c is not set, the secret-code is generated randomly; if -t is not set, default number of attempts is 10.

## Usage
To use the code, run "./my_mastermind -c XXXX -t YY" command. "-c" flag responsible for setting the secret-code, while "-t" flag is responsible for setting the number of attempts. If two are not set, the secret-code is generated randomly and number of attempts is set to 10. Entered secret-code needs to be 4-digit number where each digit is distinct number from 0 to 7.

### The Core Team


<span><i>Made at <a href='https://qwasar.io'>Qwasar Silicon Valley</a></i></span>
<span><img alt='Qwasar Silicon Valley Logo' src='https://storage.googleapis.com/qwasar-public/qwasar-logo_50x50.png' width='20px'></span>
