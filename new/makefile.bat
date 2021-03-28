flex lex1.l
bison -vdty yacc1.y
g++ -std=gnu++11 -o all1 tree.cpp cast.cpp interMediate.cpp codeOptimize.cpp Praser.cpp ToObject.cpp lex.yy.c y.tab.c
all1.exe test/test0.c
