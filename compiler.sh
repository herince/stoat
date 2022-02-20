echo "Clean up old generated files..."
rm src/generated/*
echo "Generate parser..."
bison src/grammar.in -o src/generated/c-parser-generated.cpp
echo "Generate lexer..."
flex -d -o src/generated/c-lexer-generated.cpp src/c.flex
echo "Compile..."
g++ src/generated/*.cpp src/*.cpp `llvm-config --system-libs --cppflags --ldflags --libs core` -o out/compiler
echo "Run..."
./out/compiler < test-files/test.c
# valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./out/compiler < test-files/test.c