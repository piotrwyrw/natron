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

A minimalist transpiler for the Brainfuck programming language.

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

_Tested on macOS Ventura 13.4 as well as on Ubuntu 22.04_