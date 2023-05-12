#### stoat
A small compiler for some subset of C using Flex, Bison and LLVM.

---

### Work in progress:

- [x] Get it working for the most minimalistic version I can think of:
    - [x] Parse some tokens with Flex
    - [x] Use Bison to make AST
    - [x] Try to make LLVM IR from the AST in the dumbest way possible
- [ ] Add variables
- [ ] Add operators
    - [ ] Add
    - [ ] Subtract
    - [ ] Mult
    - [ ] Divide
    - [ ] Comparison
- [ ] Add functions
    - [x] Support definition without arguments
    - [x] No return value / empty body
    - [x] Return things
    - [x] Codegen body in the right order
    - [ ] Add arguments
    - [ ] Declarations
- [ ] Add control flow statements
- [ ] Add strings and comments (they should be similar in some sense)
- [ ] Add other C types

### Want to do at some point:

- [ ] Generate ASM instructions instead of calling the LLVM API
- [ ] Read includes?
- [ ] How can I implement pointers? Should I do it?


### Quality of life things:

- [ ] Better build setup - cmake or something like that
- [ ] Tests
- [ ] Print AST?

Error handling? Error recovery?
Anything else?
