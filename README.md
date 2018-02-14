# TMacro
A text processing scripting language.

Modeled after the Notepad++ macro-recording feature, TMacro, or Text-Macro is a
scripting language giving the user the ability to programatically manipulate
large volumes of text with a clean, easy to understand syntax. 

## Syntax 

There are several different kinds of syntax; here they are grouped by type of work; note that most of the syntax behind TMacro is very much like your typical programming languages; i.e. string literals appear inside double-quotes, character literals appear inside single quotes, basic numeric literals like integers and floating point numbers are written like you would expect. TMacro elects to use square brackets for argument lists instead of parentheses; why use the shift key when you don't need to? 

### Comments 
TMacro supports basic C++ style single-line and block comments. Comments do not affect the execution of the program; they serve to help the user mark up his or script with useful information 

    // This is a single-line comment, it ends at the new-line 
    
    /* This is a block comment 
       It doesn't end until it sees a closing 
       asterisk+forward-slash pair */

 

### File I/O, Initialization

 #### OPEN  
 Opens and reads the given file into the internal buffer of the program. At least one open call must be done prior to any text formatting. The file must be closed before opening another one. 

    OPEN["C:/path/to/my/file.txt"] 

#### CLOSE
Closes the currently open file. 

`CLOSE`

#### WRITE
Writes the current state of the buffer out to disk. Can accept an optional file path parameter to write the buffer to a different file; otherwise the file that was OPEN'ed will be overwritten.

    WRITE["C:/path/to/my/file2.txt"]

### Navigating Through the File
#### L/R 
Move the cursor left or right on the current line. Accepts one of twoz possible arguments: an integer or a condition list. 
##### Integer
Moves the cursor left or right on the current line a number of spaces equal to the given integer. If the cursor cannot move the number of spaces due to reaching an EOL (end-of-line,) BOL (beginning-of-line,) EOF (end-of-file,) or BOF (beginning-of-file,) then the cursor will not move. In the example below, the square brackets denote the current position of the cursor. 

> "[H]ello world, and welcome to my universe."

    R[4]

> "Hell[o] world, and welcome to my universe."

    L[2]

> "He[l]lo world, and welcome to my universe."

    R[40]
 
 > "He[l]lo world, and welcome to my universe."

##### Condition List
The cursor can move left or right a number of times depending on if the character or characters being read match a condition, or any number of conditions. The cursor will stop on the first character of the matching condition. If the condition is never met, the cursor will not move.

For example: 

    R['u']
> "Hello world, and welcome to my [u]niverse."

    L["and"]

> "Hello world, [a]nd welcome to my universe."

    R["to" | "me"]

> "Hello world, and welco[m]e to my universe."

    L['x' | 'y' | 'z']
> "Hello world, and welco[m]e to my universe."

##### *Token parameter
L and R take an optional character literal parameter. The character represents the delimiter for the tokenization of the line. The cursor will move through the line token-by-token instead of character-by-character. This parameter can be paired together with condition lists to find the a word that begins with a specific substring. 

> "[H]ello world, and welcome to my universe."

    R[3, ' ']
    
> "Hello world, and [w]elcome to my universe."

This parameter can be paired together with condition lists as well: 

> "[W]ell, she is welcome, but I had never met her." 

    R["me", ' ']
 
> "Well, she is welcome, but I had never [m]et her." 

Notice that without tokenization, the cursor would have stopped on the 'm' in "welcome". 


#### U/D
Moves the cursor up or down the current text column. U and D accept an integer or condition list as well, and if the integer provided is out of bounds, or if the condition is never met, the cursor does not move. U and D do not accept a tokenization parameter. 

**Notice:** L/R and U/D condition lists do not currently support regular expressions, but that will be supported in the future.  

#### BOL/EOL
Moves the cursor to the **b**eginning or **e**nd of the current line.

#### FL/LL
Moves the cursor to the **f**irst line or **l**ast line of the file, trying to stay within the same column. If it cannot stay within the same column, it will move to the end of the first or last line instead. 

#### BOF/EOF
Moves the cursor to the beginning or end of file. 

### Manipulating the File 

There are many ways to manipulate the internal string buffer during program execution. The original file is left unchanged unless it's overwritten with `WRITE`.

#### INSERT
Inserts the text given by the first string-literal or character-literal parameter into the string buffer just before the cursor position. 

> "[H]ello world, and welcome to my universe." 

    R["universe"]
    INSERT["amazing "]
> "Hello world, and welcome to my amazing [u]niverse."

##### Integer
INSERT can take an optional secondary parameter, determining how many of the preceding string or character to insert. 

> "[H]ello world, and welcome to my universe." 

    R[4]
    INSERT['o', 5]
> "Hellooooo[o] world, and welcome to my universe."

#### UPDATE
Updates the text at the current cursor position with the text given by the string-literal or character-literal parameter. Unlike INSERT, update does not push text to the right of the cursor down, instead it overwrites whatever text is there. 

> "[H]ello world, and welcome to my universe." 

    R[6]
    UPDATE["globe"]

> "Hello globe[,] and welcome to my universe." 

##### Integer 
UPDATE can take an optional integer parameter which determines how many of the preceding string or character to insert into the text. 

> "[H]ello world, and welcome to my universe." 

    UPDATE['A', 5]

> "AAAA[ ]world, and welcome to my universe." 

#### DELETE 
Deletes n characters or tokens from the internal string buffer, where n is the value of the integer parameter given. Can take an optional second character-literal parameter which determines how to tokenize the current line. 

> "[H]ello world, and welcome to my universe." 

    R[5]
    DELETE[6]

> "Hello[,] and welcome to my universe." 

    R[2]
    DELETE[3, ' '] // delete the next three tokens 
    
> "Hello, my universe." 

#### GET
Reads the current character or string, and returns it. Can take an optional integer parameter which denotes how many characters to read. A secondary parameter may be given to delimit how to tokenize the string; if it is supplied, the integer parameter denotes how many tokens to read instead. 

If there are not enough characters after the cursor position in the buffer to read the number of characters indicated by the parameter, GET will read as many as it can. Unlike INSERT or UPDATE, GET does not move the cursor forward. 

> "[H]ello world, and welcome to my universe." 

    GET[5]      // returns "Hello" 
    GET         // returns 'H' 
    GET[1, ' '] // returns "Hello"
    GET[3, ' '] // returns "Hello world, and"

#### SPLIT
Splits the current line into two at the current cursor position, moving the second half of the line to the next line. 

### Logic Syntax 

#### Variables 
TMacro allows you to define variables which can be used throughout the script for INSERT, UPDATE, etc. TMacro evaluates the input script top-down, which means variables cannot be used before they are defined. In fact, it's impossible to declare a variable without defining it. This keeps the variable syntax simple. There is no special reserved word, just use any string not surrounded by double quotes.

    MYNAME = "Vuk"

Then use the variable in the script exactly how you would expect: 

> "[H]ello world, and welcome to my universe." 

    R[6]
    DELETE[5]
    INSERT[MYNAME]
 
 > "Hello Vuk, and welcome to my universe." 

Variables can be paired up nicely with the GET command, to store different values from the internal text buffer for later re-use. 

> "[H]ello world, and welcome to my universe." 

    R[6]         // move right 6 characters
    WHO = GET[5] // grab the next 5 characters, store them in WHO
    R[5, ' ']    // move right 5 tokens, delimited by a space character
    DELETE[8]    // delete 8 characters 
    INSERT[WHO]  // insert the value stored in the WHO variable 

> "Hello world, and welcome to my world[.]" 

Variables can be integers as well: 

> "[H]ello world, and welcome to my universe." 

    WORD_LENGTH = 6
    R[5]
    DELETE[WORD_LENGTH]

> "Hello[,] and welcome to my universe." 

Note that variable names can be re-used, and that if re-used, the variables' current value will be overwritten.

#### Concatenation 
Variables and values can be concatenated (combined) together with the '+' operator. This works the same way you would expect it to in languages like Java or JavaScript. 

> "[H]ello world, and welcome to my universe." 

    VAL1 = "feast"
    VAL2 = "upon" 
    VAL3 = VAL1 + " " + VAL2 + " "
    R[3, ' ']
    DELETE[2, ' ']
    INSERT[VAL3]

> "Hello world, and feast upon my universe." 

#### Incrementing and Decrementing 
You can increment or decrement numeric variables with **INCR** and **DECR**.

    MYVAL = 5
    INCR[MYVAL] // MYVAL is 6 now 
    DECR[MYVAL] // MYVAL is 5 again 

Both commands take an optional integer parameter which designate how much to increment or decrement by.

    MYVAL = 5
    INCR[MYVAL, 5] // MYVAL is 10 now 
    DECR[MYVAL, 2] // MYVAL is 8 now 

#### Conditionals 
It can be really useful to change how TMacro processes given text based on certain conditions. Conditionals here are just like in many other languages, using operators like < (less-than,) > (greater than,) = (equal-to,) != (not-equal-to,) etc., and they support typical grouping operators AND, and OR. 

##### IF/ELSE IF/ELSE
    MYVAL = 5;
    IF MYVAL > 5
        DELETE[3]   // delete next three tokens 
        DECR[MYVAL] // decrement MYVAL by one 
    ELSE IF MYVAL <= 5
        INSERT["It's less than or equal to 5"]

##### SWITCH/CASE/DEFAULT

    MYVAL = 5
    SWITCH MYVAL 
        CASE 4
           INSERT["IT'S 4"]
        CASE 5
           INSERT["IT'S 5"]
        DEFAULT
           INSERT["NOT SURE WHAT IT IS"]

#### Looping 
TMacro supports looping functionality to really give users the ability to manipulate large amounts of text. 

##### DO n TIMES 
The most basic loop is the Do N Times loop. It's like if the for-loop and while-loop had a baby.

> "[]"

    HELLO_NUM = 1
    DO
        INSERT["HELLO WORLD x "]
        INSERT[HELLO_NUM]
        INCR[HELLO_NUM]
        SPLIT
    5 TIMES

> "HELLO WORLD x 1
> HELLO WORLD x 2
> HELLO WORLD x 3 
> HELLO WORLD x 4
> HELLO WORLD x 5[]"

Note that the n in 'n times' need not be a numeric literal, and can be the name of a variable. 

##### DO WHILE
You classic do-while loop; loops while a certain condition is true; executes inner code at least once. 

    MYVAL = 5
    DO
        INSERT[MYVAL]
        DECR[MYVAL] 
    WHILE MYVAL > 0

todo: 
Document UPDATE, DELETE, SPLIT (shorthand for INSERT["\n"], setting and using variables, concatenation, math, increment/decrement, loops, conditionals, etc.

##### Math Expressions 
TMacro supports arbitraty math expressions involving + (addition,) - (subtraction,) / (division,) * (multiplication,) ^ (exponentiation,) MOD (modulus,) etc. 

    MYVAL = 5          // MYVAL is 5 
    MYVAL = MYVAL * 2  // MYVAL is 10 
    MYVAL = MYVAL ^ 2  // MYVAL is 100
    MYVAL = (10 + (2 * 7) - 4 ^ 2)

### Misc. Syntax 
Other planned commands and syntax include LENGTH, MAX, MIN, for-loops, while-loops, logging functionality, PRINT, debugging functionality, and more. 

## License

Copyright 2018 Vuk Petrovic

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.