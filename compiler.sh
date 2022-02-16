rm src/generated/*
bison src/grammar.in -o src/generated/c-parser-generated.cpp
flex -d -o src/generated/c-lexer-generated.cpp src/c.flex
g++ src/generated/*.cpp src/*.cpp -o out/compiler
./out/compiler < test-files/test.c
# valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./out/compiler < test-files/test.c