# MWhitespace

## What's this?

MWhitespace, which stands for Mnemonic Whitespace, is a personal project that
aims to construct an assembly-like language that gets assembled into a
Whitespace source code. It will also include a compiler to run your Whitespace
codes.

## Mnemonics

On the following, T means top of the stack, A represents the first element and
B represents the second.

### Instruction Modifier Parameters

MIMP | IMP | Description
---- | --- | -----------
sm | [Space] | Stack manipulation
am | [Tab][Space] | Arithmetic with the stack
ha | [Tab][Tab] | Heap access
fc | [Linefeed] | Flow control
io | [Tab][Linefeed] | I/O

### Stack Manipulation

MINS | INS | Parameters | Description
---- | --- | ---------- | -----------
push | [Space] | N | Push N into the stack
dup | [Linefeed][Space] | - | Duplicate first stack element
swp | [Linefeed][Tab] | - | Swap first and second stack elements
pop | [Linefeed][Linefeed] | - | Pop the stack

### Arithmetic

Be aware: The arithmetic instructions consumes the first two stack elements.

MINS | INS | Parameters | Description
---- | --- | ---------- | -----------
add | [Space] | - | T = A + B
sub | [Linefeed][Space] | - | T = A - B
mul | [Linefeed][Tab] | - | T = A * B
div | [Linefeed][Linefeed] | - | T = A / B
mod | [Tab][Tab] | - | T = A mod B

### Heap Access

MINS | INS | Parameters | Description
---- | --- | ---------- | -----------
str | [Space] | - | Heap[B] = A
rtr | [Tab] | - | T = Heap[A]

### Flow Control

MINS | INS | Parameters | Description
---- | --- | ---------- | -----------
label | [Space] | Label | Starts label
call | [Linefeed][Space] | Label | Call subroutine marked at Label
jmp | [Linefeed][Tab] | Label | Unconditional jump to Label
brnz | [Linefeed][Linefeed] | Label | Branch if not zero to Label
ret | [Tab][Tab] | - | End subroutine
end | [Linefeed][Linefeed] | - | End the program

### IO

MINS | INS | Parameters | Description
---- | --- | ---------- | -----------
putc | [Space][Space] | - | Output top of the stack as character
puti | [Space][Tab] | - | Output top of the stack as integer
getc | [Tab][Space] | - | Read input as character and push to the stack
geti | [Tab][Tab] | - | Read input as integer and push to the stack

## How to use
