# MWhitespace

## What's this?

MWhitespace, which stands for (Mnemonic Whitespace), is a personal project that
aims to construct an assembly-like language that gets assembled into a Whitespace
source code. It will also include a compiler to run your Whitespace codes.

## Mnemonics

### Instruction Modifier Parameters

MIMP | IMP | Description
---- | --- | -----------
sm | [Space] | Stack manipulation
am | [Tab][Space] | Arithmetic with the stack
ha | [Tab][Tab] | Heap access
fc | [Linefeed] | Flow control
io | [Tab][Linefeed] | I/O

### Stack Manipulation

MINS | INS | Description
---- | --- | -----------
push | [Space] | Push into the stack
dup | [Linefeed][Space] | Duplicate first stack element
swp | [Linefeed][Tab] | Swap first and second stack elements
pop | [Linefeed][Linefeed] | Pop the stack

### Arithmetic

MINS | INS | Description
---- | --- | -----------
add | [Space] | A + B
sub | [Linefeed][Space] | A - B
mul | [Linefeed][Tab] | A * B
div | [Linefeed][Linefeed] | A / B
mod | [Tab][Tab] | A mod B

### Heap Access

MINS | INS | Description
---- | --- | -----------
str | [Space] | Store 
rtr | [Tab] | Retrieve

### Flow Control

MINS | INS | Description
---- | --- | -----------
label | [Space] | Starts label
call | [Linefeed][Space] | Call subroutine
jmp | [Linefeed][Tab] | Unconditional jump
brnz | [Linefeed][Linefeed] | Branch if not zero
ret | [Tab][Tab] | Return
end | [Linefeed][Linefeed] | End the program

### IO

MINS | INS | Description
---- | --- | -----------
putc | [Space][Space] | Output top of the stack as character
puti | [Space][Tab] | Output top of the stack as integer
getc | [Tab][Space] | Read input as character and push to the stack
geti | [Tab][Tab] | Read input as integer and push to the stack

## How to use
