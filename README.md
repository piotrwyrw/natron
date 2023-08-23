```
 __         ______                                           
|  \       /      \                                          
| $$____  |  $$$$$$\         _______  ______ ____    ______  
| $$    \ | $$_  \$$______  /       \|      \    \  /      \ 
| $$$$$$$\| $$ \   |      \|  $$$$$$$| $$$$$$\$$$$\|  $$$$$$\
| $$  | $$| $$$$    \$$$$$$| $$      | $$ | $$ | $$| $$  | $$
| $$__/ $$| $$             | $$_____ | $$ | $$ | $$| $$__/ $$
| $$    $$| $$              \$$     \| $$ | $$ | $$| $$    $$
 \$$$$$$$  \$$               \$$$$$$$ \$$  \$$  \$$| $$$$$$$ 
                                                   | $$      
                                                   | $$      
                                                    \$$      
```

A minimalist transpiler for a steroid brainfuck variant.

### CLI Usage

```shell
./bfcmp
 --source src_file    # The input file containing the source code
 --output out_file    # The output file
 
 --compile            # Compile brainfuck source code to C
 --reformat           # Reformat the brainfuck source code
 
 --acknowledge-reformatting-damage  # Confirm that you do indeed want the reformatting step to remove
                                    # all brainfuck source code comments.
```

### Variant differences

`BF++` is based around the concept of Brainfuck, and is still very much esoteric.
However, just for fun, I decided to expand the language by adding support for "units".
A unit is a section of the program that can be executed (called) by brainfuck code like regular functions
you know from other programming languages, though it resembles the behaviour of assembly labels more than of anything
else.

All classic brainfuck code in the program must be contained within a unit, though it is worth noting that the
compiler does not require any units for a successful compilation (the output may just not be as useful).

The program may contain as little or as many regular units as you'd like, and at most one unit that is marked as the
program's entry point. Such main unit is however also not required, which may become useful if you'd like to
link multiple brainfuck files together, but effectively renders the resulting C program unusable by default.

### Additional syntax
```brainfuck
# Returns at a cell with the value '10' in it
count_to_ten
{
    +++++[
        >++<-
    ]
    >
}

# Sets the current cell to zero
zero_out
{
    [-]
}

&entry {
    @count_to_ten
    @zero_out
}
```

#### Comments
The classic version of brainfuck ignores all characters that are irrelevant for its operation, effectively
treating them as comments. Here, however, you need to explicitly create a line comment to annotate your
code. A line comment - as its name suggests - comments out everything from the initial character (`#`) till the
end of the line (Or _EOF_ if _EOL_ is not available)

#### Units
A unit definition looks as follows:
```
[ "&" ] identifier "{" brainfuck-code "}"
```
Every unit must have its own unique `identifier`. If the identifier is preceded with an ampersand (`&`),
the unit gets marked the main entry point of the program. Classic brainfuck code constitutes the body of the unit, which
is located between the curly brackets.

#### Unit calls
```
"@" identifier
```
_Note: The identifier must "stick" directly to the "@": There may not be any spaces separating the two tokens._