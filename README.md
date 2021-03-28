# C-HDL-Complier
Just a toy complier base on the C and HDL,it can finish some basic translation between the 2 languages.  

This project runs under Windows, requires Flex and Bison, and builds MinGW environment.
  
**How to Run**  
1.cd the file‘s dircetory.  
  
3.makefile.bat
   
it can help you finish front-end and back-end of the compiler automatically.
  
**Files' structure** 
tree.h  
  
is the data structure which the lex and Yacc need.  
  
block.h   
  
can help the the build of code block.  
  
lex.l lex.yy.c lex.yy.o   
  
are the Flex need and produce.  
  
yacc.y y.tab.c y.tab.h   
  
are the Bison need and produce.  
  
Praser.h interMediate.h codeOptimize.h   
  
are the files about semantic analysis. 
  
what in the behind is the back-end files.  



