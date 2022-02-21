#### stoat
A small compiler for some subset of C using Bison, Flex and LLVM.
A project for the course - Implementation of Programming Languages.

A small animal name for a small compiler.

#### TODO:

[Fix leaks](https://image.emojisky.com/937/872937-middle.png)

- [x] Get it working for the most minimalistic version I can think of:
    - [x] Parse some tokens with Flex
    - [x] Use Bison to make AST
    - [x] Try to make LLVM IR from the AST in the dumbest way possible
- [ ] Add variables
- [ ] Add operators
- [ ] Add functions
- [ ] Add control flow statements
- [ ] Add strings and comments (they should be similar in some sense)
- [ ] Add other C types

#### Bonus levels:
- [ ] Better build setup - cmake or something like that
- [ ] Read includes?
- [ ] Tests
- [ ] Print AST?
- [ ] How can I implement pointers? Should I do it?
- [ ] Preprocessors?

Error handling? Error recovery?
Anything else?