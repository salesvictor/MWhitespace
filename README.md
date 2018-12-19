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
push | [Space] | Number | Push *Number* into the stack
dup | [Linefeed][Space] | - | Duplicate first stack element
cp | [Tab][Space] | Number | Copy the *Number*-th item on the stack to the top
swp | [Linefeed][Tab] | - | Swap first and second stack elements
pop | [Linefeed][Linefeed] | - | Pop the stack
slide | [Tab][Linefeed] | Number | Discard *Number* itens from the stack, keeping the top element

### Arithmetic

Be aware: The arithmetic instructions consumes the first two stack elements.

MINS | INS | Parameters | Description
---- | --- | ---------- | -----------
add | [Space][Space] | - | T = A + B
sub | [Space][Tab] | - | T = A - B
mul | [Space][Linefeed] | - | T = A * B
div | [Tab][Space] | - | T = A / B
mod | [Tab][Tab] | - | T = A mod B

### Heap Access

MINS | INS | Parameters | Description
---- | --- | ---------- | -----------
str | [Space] | - | Heap[B] = A
rtr | [Tab] | - | T = Heap[A]

### Flow Control

MINS | INS | Parameters | Description
---- | --- | ---------- | -----------
label | [Space][Space] | Label | Marks *Label* on the program
call | [Space][Tab] | Label | Calls subroutine marked at *Label*
jmp | [Space][Linefeed] | Label | Unconditional jump to *Label*
jz | [Tab][Space] | Label | Jumps to *Label* if top stack element is zero
js | [Tab][Tab] | Label | Jumps to *Label* if top stack element is negative
ret | [Tab][Linefeed] | - | End subroutine
end | [Linefeed][Linefeed] | - | End the program

### IO

MINS | INS | Parameters | Description
---- | --- | ---------- | -----------
outc | [Space][Space] | - | Output top of the stack as character
out | [Space][Tab] | - | Output top of the stack as integer
inc | [Tab][Space] | - | Read input as character and push to the stack
in | [Tab][Tab] | - | Read input as integer and push to the stack

## How to use
