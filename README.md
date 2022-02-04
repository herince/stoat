#### stoat
A small compiler for some subset of C using Bison, Flex and LLVM.
A project for the course - Implementation of Programming Languages.

A small animal name for a small compiler.

#### TODO:

- Stop the leaks <.<

- [ ] Get it working for the most minimalistic version I can think of:
    - [ ] Parse some tokens with Flex
    - [ ] Use Bison to make AST
    - [ ] Try to make LLVM IR from the AST in the dumbest way possible
- [ ] Easy way to build and run not by hand
- [ ] Add operators
- [ ] Add varible definitions and assignment expressions
- [ ] Add controw flow statements
- [ ] Add strings and comments (they should be similar in some sense)
- [ ] Add other C types

#### Bonus levels:
- [ ] Read includes?
- [ ] Setup some automated way to test the code
- [ ] Autmated way to test the compiler itself (make a script or something)
- [ ] Print AST?

Error handling? Error recovery?
How can I implement pointers? Should I do it?
Anything else?