#### stoat
A small compiler for some subset of C using Bison, Flex and LLVM.

#### WiP:
[Fix leaks](https://image.emojisky.com/937/872937-middle.png)

- [x] Get it working for the most minimalistic version I can think of:
    - [x] Parse some tokens with Flex
    - [x] Use Bison to make AST
    - [x] Try to make LLVM IR from the AST in the dumbest way possible
- [ ] Add variables
- [ ] Add operators
- [ ] Add functions
    - [x] Support definition without arguments
    - [x] No return value / empty body
    - [x] Return things
    - [ ] Codegen body correctly
    - [ ] Add arguments
    - [ ] Declarations
- [ ] Add control flow statements
- [ ] Add strings and comments (they should be similar in some sense)
- [ ] Add other C types

#### Want to do at some point:
- [ ] Generate ASM instructions instead of calling the LLVM API
- [ ] Read includes?
- [ ] How can I implement pointers? Should I do it?

#### QoL things:
- [ ] Better build setup - cmake or something like that
- [ ] Tests
- [ ] Print AST?

Error handling? Error recovery?
Anything else?
