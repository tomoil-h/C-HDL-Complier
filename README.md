# C-HDL-Complier
Just a toy complier base on the C and HDL,it can finish some basic translation between the 2 languages.  

This project runs under Windows, requires Flex and Bison, and builds MinGW environment.
  
**How to Run**  
1.cd the file‘s dircetory.  
  
2.makefile.bat
   
It can help you finish front-end and back-end of the compiler automatically.
  
**Files' structure**   
tree.h  
  
Is the data structure which the lex and Yacc need.  
  
block.h   
  
Can help the the build of code block.  
  
lex.l lex.yy.c lex.yy.o   
  
Are the Flex need and produce.  
  
yacc.y y.tab.c y.tab.h   
  
Are the Bison need and produce.  
  
Praser.h interMediate.h codeOptimize.h   
  
Are the files about semantic analysis. 

objectCode.h objectCode.cpp  

the back-end files.  



