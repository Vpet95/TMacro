# TMacro
A text processing scripting language.

Modeled after the Notepad++ macro-recording feature, TMacro, or Text-Macro is a
scripting language giving the user the ability to programatically manipulate
large volumes of text with a clean, easy to understand syntax. 

## Syntax 

There are several different kinds of syntax; here they are grouped by type of work; note that most of the syntax behind TMacro is very much like your typical programming languages; i.e. string literals appear inside double-quotes, character literals appear inside single quotes, basic numeric literals like integers and floating point numbers are written like you would expect. TMacro elects to use square brackets for argument lists instead of parentheses; why use the shift key when you don't need to? 


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

todo: 
Document UPDATE, DELETE, SPLIT (shorthand for INSERT["\n"], setting and using variables, concatenation, math, increment/decrement, loops, conditionals, etc.

---

Copyright 2018 Vuk Petrovic

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.