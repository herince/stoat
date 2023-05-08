echo "Clean up old generated files..."
rm src/generated/*

echo "Generate parser..."
bison src/grammar.in -o src/generated/c-parser-generated.cpp

echo "Generate lexer..."
flex -d -o src/generated/c-lexer-generated.cpp src/c.flex

echo "Compile the compiler..."
# g++ -D DEBUG_PARSING -O3 src/generated/*.cpp src/*.cpp src/ast-types/*.cpp `llvm-config --system-libs --cppflags --ldflags --libs core` -o out/compiler
g++ -O3 src/generated/*.cpp src/*.cpp src/ast-types/*.cpp `llvm-config --system-libs --cppflags --ldflags --libs core` -o out/compiler

echo "Generate LLVM IR..."
./out/compiler < test-files/test.c
# valgrind --track-origins=yes ./out/compiler < test-files/test.c
# valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./out/compiler < test-files/test.c

# echo "Generate binary (from .ll)..."
# llc -filetype=obj out/test.ll -o out/test
# ./out/test

# echo "Generate assembly..."
# llc -filetype=asm out/test.ll -o out/test.s