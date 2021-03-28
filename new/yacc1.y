%{
#include "tree.h"
#include "main.h"
#include "Praser.h"
#include "ToObject.h"
extern "C"			
{					
	void yyerror(const char *s);
	extern int yylex(void);
}
extern char *yytext;
extern int column;
extern FILE * yyin;
extern FILE * yyout;
treeNode *root;
extern int yylineno;
%}

%union{
	struct treeNode* tn;
}

%token<tn> IDENTIFIER CONSTANT STRING_LITERAL SIZEOF CONSTANT_INT CONSTANT_DOUBLE TRUE FALSE
%token<tn> PTR_OP INC_OP DEC_OP LEFT_OP RIGHT_OP LE_OP GE_OP EQ_OP NE_OP
%token<tn> AND_OP OR_OP MUL_ASSIGN DIV_ASSIGN MOD_ASSIGN ADD_ASSIGN
%token<tn> SUB_ASSIGN LEFT_ASSIGN RIGHT_ASSIGN AND_ASSIGN
%token<tn> XOR_ASSIGN OR_ASSIGN TYPE_NAME

%token<tn> TYPEDEF EXTERN STATIC AUTO REGISTER
%token<tn> CHAR SHORT INT LONG SIGNED UNSIGNED FLOAT DOUBLE CONST VOLATILE VOID BOOL 
%token<tn> STRUCT UNION ENUM ELLIPSIS

%token<tn> CASE DEFAULT IF ELSE SWITCH WHILE DO FOR GOTO CONTINUE BREAK RETURN 
%token <tn> ';' ',' ':' '=' '[' ']' '.' '&' '!' '~' '-' '+' '*' '/' '%' '<' '>' '^' '|' '?' '{' '}' '(' ')'

%type <tn> primary_expression postfix_expression argument_expression_list unary_expression unary_operator
%type <tn> multiplicative_expression additive_expression shift_expression relational_expression equality_expression
%type <tn> and_expression exclusive_or_expression inclusive_or_expression logical_and_expression logical_or_expression
%type <tn> assignment_expression assignment_operator expression

%type <tn> declaration init_declarator_list init_declarator type_specifier

%type <tn> declarator 

%type <tn> parameter_list parameter_declaration identifier_list translation_unit 
%type <tn> abstract_declarator initializer initializer_list designation designator_list
%type <tn> designator statement labeled_statement compound_statement block_item_list block_item expression_statement
%type <tn> selection_statement iteration_statement jump_statement translation_unit external_declaration function_definition
%type <tn> declaration_list
%nonassoc LOWER_THAN_ELSE
%nonassoc ELSE
%%
Program: 
	translation_unit { //��ʼ��ͷ�ڵ㣬��ʼ����AST
		root = create_tree("Program",1,$1);
	}
	;
/*�������ʽ*/
primary_expression: 
	IDENTIFIER {//$$�����ǽ���ѹ��ջ�еı�����$n�Ǵ���ǰ�����Լ�ĵ�n��Ԫ��
		$$ = create_tree("primary_expression",1,$1);
	}
	|
	TRUE {
		$$ = create_tree("primary_expression",1,$1);
	}
	|
	FALSE {
		$$ = create_tree("primary_expression",1,$1);
	}
	| CONSTANT_INT {
		$$ = create_tree("primary_expression",1,$1);
		
	}
	| CONSTANT_DOUBLE {
		$$ = create_tree("primary_expression",1,$1);
	}
	| '(' expression ')'{
		$$ = create_tree("primary_expression",3,$1,$2,$3);
	}
	;

/*��׺���ʽ*/
postfix_expression:
	primary_expression{
		$$ = create_tree("postfix_expression",1,$1);
	}
	| 	postfix_expression '[' expression ']'{
		$$ = create_tree("postfix_expression",4,$1,$2,$3,$4);
		//������÷�����
	}
	| 	postfix_expression '(' ')'{
		$$ = create_tree("postfix_expression",3,$1,$2,$3);
		//������������
	}
	| 	postfix_expression '(' argument_expression_list ')'{
		$$ = create_tree("postfix_expression",4,$1,$2,$3,$4);
		//�������ã���������
	}
	| 	postfix_expression INC_OP{
		//++
		$$ = create_tree("postfix_expression",2,$1,$2);
	}
	| 	postfix_expression DEC_OP{
		//--
		$$ = create_tree("postfix_expression",2,$1,$2);
	}
	;
/*������*/
argument_expression_list:
	assignment_expression{
		$$ = create_tree("argument_expression_list",1,$1);
	}
	| 	argument_expression_list ',' assignment_expression {
                                //�������
		$$ = create_tree("argument_expression_list",3,$1,$2,$3);
	}
	;

/*һԪ���ʽ*/
unary_expression:
	postfix_expression{
		$$ = create_tree("unary_expression",1,$1);
	}
	| 	INC_OP unary_expression{
		//++
		$$ = create_tree("unary_expression",2,$1,$2);
	}
	| 	DEC_OP unary_expression{
		//--
		$$ = create_tree("unary_expression",2,$1,$2);
	}
	| 	unary_operator unary_expression{
		$$ = create_tree("unary_expression",2,$1,$2);
	}
	;

/*��Ŀ�����*/
unary_operator:
	'+' {
		$$ = create_tree("unary_operator",1,$1);
	}
	| '-' {
		$$ = create_tree("unary_operator",1,$1);
	}
	| '~' {
		$$ = create_tree("unary_operator",1,$1);
	}
	| '!' {
		$$ = create_tree("unary_operator",1,$1);
	}
	;

/*�˱��ʽ*/
multiplicative_expression:
	unary_expression {
		$$ = create_tree("multiplicative_expression",1,$1);
	}
	| multiplicative_expression '*' unary_expression {
		$$ = create_tree("multiplicative_expression",3,$1,$2,$3);
	}
	| multiplicative_expression '/' unary_expression {
		$$ = create_tree("multiplicative_expression",3,$1,$2,$3);
	}
	| multiplicative_expression '%' unary_expression {
		$$ = create_tree("multiplicative_expression",3,$1,$2,$3);
	}
	;

/*�ӱ��ʽ*/
additive_expression:
	multiplicative_expression  {
		$$ = create_tree("additive_expression",1,$1);
	}
	| additive_expression '+' multiplicative_expression {
		$$ = create_tree("additive_expression",3,$1,$2,$3);
	}
	| additive_expression '-' multiplicative_expression {
		$$ = create_tree("additive_expression",3,$1,$2,$3);
	}
	;

/*��������*/
shift_expression:
	additive_expression {
		$$ = create_tree("shift_expression",1,$1);
	}
	| shift_expression LEFT_OP additive_expression {
		//<<
		$$ = create_tree("shift_expression",3,$1,$2,$3);
	}
	| shift_expression RIGHT_OP additive_expression {
		//<<
		$$ = create_tree("shift_expression",3,$1,$2,$3);
	}
	;

/*��ϵ���ʽ*/
relational_expression:
	shift_expression {
		$$ = create_tree("relational_expression",1,$1);
	}
	| relational_expression '<' shift_expression {
		// <
		$$ = create_tree("relational_expression",3,$1,$2,$3);
	}
	| relational_expression '>' shift_expression {
		// > 
		$$ = create_tree("relational_expression",3,$1,$2,$3);
	}
	| relational_expression LE_OP shift_expression {
		// <= 
		$$ = create_tree("relational_expression",3,$1,$2,$3);
	}
	| relational_expression GE_OP shift_expression {
		// >=
		$$ = create_tree("relational_expression",3,$1,$2,$3);
	}
	;

/*��ȱ��ʽ*/
equality_expression:
	relational_expression {
		$$ = create_tree("equality_expression",1,$1);
	}
	| equality_expression EQ_OP relational_expression {
		// ==
		$$ = create_tree("equality_expression",3,$1,$2,$3);
	}
	| equality_expression NE_OP relational_expression {
		// !=
		$$ = create_tree("equality_expression",3,$1,$2,$3);
	}
	;
/*��*/
and_expression:
	equality_expression {
		$$ = create_tree("and_expression",1,$1);
	}
	| and_expression '&' equality_expression {
		$$ = create_tree("and_expression",3,$1,$2,$3);
	}
	;

/*���*/
exclusive_or_expression:
	and_expression {
		$$ = create_tree("exclusive_or_expression",1,$1);
	}
	| exclusive_or_expression '^' and_expression {
		$$ = create_tree("exclusive_or_expression",3,$1,$2,$3);
	}
	;

/*��*/
inclusive_or_expression:
	exclusive_or_expression {
		$$ = create_tree("inclusive_or_expression",1,$1);
	}
	| inclusive_or_expression '|' exclusive_or_expression {
		$$ = create_tree("inclusive_or_expression",3,$1,$2,$3);
	}
	;

/*�߼�����ʽ*/
logical_and_expression:
	inclusive_or_expression {
		$$ = create_tree("logical_and_expression",1,$1);
	}
	| logical_and_expression AND_OP inclusive_or_expression {
		//&&
		$$ = create_tree("logical_and_expression",3,$1,$2,$3);
	}
	;

/*�߼�����ʽ*/
logical_or_expression:
	logical_and_expression {
		$$ = create_tree("logical_or_expression",1,$1);
	}
	| logical_or_expression OR_OP logical_and_expression {
		//||
		$$ = create_tree("logical_or_expression",3,$1,$2,$3);
	}
	;

/*��ֵ���ʽ*/
assignment_expression:
	logical_or_expression {
		//�������ʽ
		$$ = create_tree("assignment_expression",1,$1);
	}
	| unary_expression assignment_operator assignment_expression {
		$$ = create_tree("assignment_expression",3,$1,$2,$3);
	}
	;

/*������ֵ�����*/
assignment_operator:
	'=' {
		$$ = create_tree("assignment_operator",1,$1);
	}
	| MUL_ASSIGN {
		//*=
		$$ = create_tree("assignment_operator",1,$1);
	}
	| DIV_ASSIGN {
		// /=
		$$ = create_tree("assignment_operator",1,$1);
	}
	| MOD_ASSIGN {
		// %=
		$$ = create_tree("assignment_operator",1,$1);
	}
	| ADD_ASSIGN {
		// += 
		$$ = create_tree("assignment_operator",1,$1);
	}
	| SUB_ASSIGN {
		// -=
		$$ = create_tree("assignment_operator",1,$1);
	}
	| LEFT_ASSIGN {
		// <<=
		$$ = create_tree("assignment_operator",1,$1);
	}
	| RIGHT_ASSIGN {
		// >>=
		$$ = create_tree("assignment_operator",1,$1);
	}
	| AND_ASSIGN {
		// &=
		$$ = create_tree("assignment_operator",1,$1);
	}
	| XOR_ASSIGN {
		// ^=
		$$ = create_tree("assignment_operator",1,$1);
	}
	| OR_ASSIGN {
		// |=
		$$ = create_tree("assignment_operator",1,$1);
	}
	;

/*���ʽ*/
expression:
	assignment_expression {
		//��ֵ���ʽ
		$$ = create_tree("expression",1,$1);
	}
	| expression ',' assignment_expression {
		//���ű��ʽ
		$$ = create_tree("expression",3,$1,$2,$3);
	}
	;

/*��������*/
declaration:
	type_specifier ';' {
		$$ = create_tree("declaration",2,$1,$2); //?
	}
	| type_specifier init_declarator_list ';' {
		$$ = create_tree("declaration",3,$1,$2,$3);
	}
	;


init_declarator_list:
	init_declarator {
		$$ = create_tree("init_declarator_list",1,$1);
	}
	| init_declarator_list ',' init_declarator {
		$$ = create_tree("init_declarator_list",3,$1,$2,$3);
	}
	;

init_declarator:
	declarator {
		$$ = create_tree("init_declarator",1,$1);
	}
	| declarator '=' initializer {
		$$ = create_tree("init_declarator",3,$1,$2,$3);
	}
	;


/*���Ͷ���*/
type_specifier:
	VOID {
		$$ = create_tree("type_specifier",1,$1);
	}
	| CHAR {
		$$ = create_tree("type_specifier",1,$1);
	}
	| INT {
		$$ = create_tree("type_specifier",1,$1);
	}
	| DOUBLE {
		$$ = create_tree("type_specifier",1,$1);	
	}
	| BOOL {
		$$ = create_tree("type_specifier",1,$1);
	}
	;


/*������ʶ��*/
declarator:
	IDENTIFIER {
		//����
		$$ = create_tree("declarator",1,$1);
	}
	| '(' declarator ')' {
		//.....
		$$ = create_tree("declarator",3,$1,$2,$3);
	}
	| declarator '[' assignment_expression ']' {
		//����
		//printf("assignment_expression");
		$$ = create_tree("declarator",4,$1,$2,$3,$4);
	}
	| declarator '[' '*' ']' {
		//....
		$$ = create_tree("declarator",4,$1,$2,$3,$4);
	}
	| declarator '[' ']' {
		//����
		$$ = create_tree("declarator",3,$1,$2,$3);
	}
	| declarator '(' parameter_list ')' {
		//����
		$$ = create_tree("declarator",4,$1,$2,$3,$4);
	}
	| declarator '(' identifier_list ')' {
		//����
		$$ = create_tree("declarator",4,$1,$2,$3,$4);
	}
	| declarator '(' ')' {
		//����
		$$ = create_tree("declarator",3,$1,$2,$3);
	}
	;

/*�β��б�*/
parameter_list:
	parameter_declaration {
		$$ = create_tree("parameter_list",1,$1);
	}
	| parameter_list ',' parameter_declaration {
		$$ = create_tree("parameter_list",3,$1,$2,$3);
	}
	;

parameter_declaration:
	type_specifier declarator {
		$$ = create_tree("parameter_declaration",2,$1,$2);
	}
	| type_specifier abstract_declarator {
		$$ = create_tree("parameter_declaration",2,$1,$2);
	}
	| type_specifier {
		$$ = create_tree("parameter_declaration",1,$1);
	}
	;
/*��ʶ���б�*/
identifier_list:
	IDENTIFIER {
		$$ = create_tree("identifier_list",1,$1);
	}
	| identifier_list ',' IDENTIFIER {
		$$ = create_tree("identifier_list",3,$1,$2,$3);
	}
	;

abstract_declarator:
	'(' abstract_declarator ')' {
		$$ = create_tree("abstract_declarator",3,$1,$2,$3);
	}
	| '[' ']' {
		$$ = create_tree("abstract_declarator",2,$1,$2);
	}
	| '[' assignment_expression ']' {
		$$ = create_tree("abstract_declarator",3,$1,$2,$3);
	}
	| abstract_declarator '[' ']' {
		$$ = create_tree("abstract_declarator",3,$1,$2,$3);
	}
	| abstract_declarator '[' assignment_expression ']' {
		$$ = create_tree("abstract_declarator",4,$1,$2,$3,$4);
	}
	| '[' '*' ']' {
		$$ = create_tree("abstract_declarator",3,$1,$2,$3);
	}
	| abstract_declarator '[' '*' ']' {
		$$ = create_tree("abstract_declarator",4,$1,$2,$3,$4);
	}
	| '(' ')' {
		$$ = create_tree("abstract_declarator",2,$1,$2);
	}
	| '(' parameter_list ')' {
		$$ = create_tree("abstract_declarator",3,$1,$2,$3);
	}
	| abstract_declarator '(' ')' {
		$$ = create_tree("abstract_declarator",3,$1,$2,$3);
	}
	| abstract_declarator '(' parameter_list ')' {
		$$ = create_tree("abstract_declarator",4,$1,$2,$3,$4);
	}
	;

//��ʼ��
initializer:
	assignment_expression {
		$$ = create_tree("initializer",1,$1);
	}
	| '{' initializer_list '}' {
		//�б��ʼ�� {1,1,1}
		$$ = create_tree("initializer",3,$1,$2,$3);
	}
	| '{' initializer_list ',' '}' {
		//�б��ʼ�� {1,1,1,}
		$$ = create_tree("initializer",4,$1,$2,$3,$4);
	}
	;

initializer_list:
	initializer {
		$$ = create_tree("initializer_list",1,$1);
	}
	| designation initializer {
		$$ = create_tree("initializer_list",2,$1,$2);
	}
	| initializer_list ',' initializer {
		$$ = create_tree("initializer_list",3,$1,$2,$3);
	}
	| initializer_list ',' designation initializer {
		$$ = create_tree("initializer_list",3,$1,$2,$3);
	}
	;

designation:
	designator_list '=' {
		$$ = create_tree("designation",2,$1,$2);
	}
	;

designator_list:
	designator {
		$$ = create_tree("designator_list",1,$1);
	}
	| designator_list designator {
		$$ = create_tree("designator_list",2,$1,$2);
	}
	;

designator: 
	'[' logical_or_expression ']' {
		$$ = create_tree("designator",3,$1,$2,$3);
	}
	| '.' IDENTIFIER {
		$$ = create_tree("designator",2,$1,$2);
	}
	;

/*���*/
statement:
	labeled_statement {
		//��ǩ
		$$ = create_tree("statement",1,$1);
	}
	| compound_statement {
		//����
		$$ = create_tree("statement",1,$1);
	}
	| expression_statement{
		//���ʽ
		$$ = create_tree("statement",1,$1);
	}
	| selection_statement {
		//��֧
		$$ = create_tree("statement",1,$1);
	}
	| iteration_statement {
		//ѭ��
		$$ = create_tree("statement",1,$1);
	}
	| jump_statement {
		//��ת
		$$ = create_tree("statement",1,$1);
	}
	;

/*��ǩ����*/
labeled_statement:
	IDENTIFIER ':' statement {
		$$ = create_tree("labeled_statement",3,$1,$2,$3);
	}
	| CASE logical_or_expression ':' statement {
		$$ = create_tree("labeled_statement",4,$1,$2,$3,$4);
	}
	;

/*�������*/
compound_statement:
	'{' '}' {
		$$ = create_tree("compound_statement",2,$1,$2);
	}
	| '{' block_item_list '}' {
		$$ = create_tree("compound_statement",3,$1,$2,$3);
	}
	;
/*�����*/
block_item_list:
	block_item {
		$$ = create_tree("block_item_list",1,$1);
	}
	| block_item_list block_item {
		$$ = create_tree("block_item_list",2,$1,$2);
	}
	;

block_item:
	declaration {
		$$ = create_tree("block_item",1,$1);
	}
	| statement {
		$$ = create_tree("block_item",1,$1);
	}
	;

expression_statement:
	';' {
		$$ = create_tree("expression_statement",1,$1);
	}
	| expression ';' {
		$$ = create_tree("expression_statement",2,$1,$2);
	}
	;

/*��֧���*/
selection_statement:
	IF '(' expression ')' statement %prec LOWER_THAN_ELSE {
		$$ = create_tree("selection_statement",5,$1,$2,$3,$4,$5);
	}
    | IF '(' expression ')' statement ELSE statement {
		$$ = create_tree("selection_statement",7,$1,$2,$3,$4,$5,$6,$7);
	}
    | SWITCH '(' expression ')' statement {
		$$ = create_tree("selection_statement",5,$1,$2,$3,$4,$5);
	}
    ;

/*ѭ�����*/
iteration_statement:
	WHILE '(' expression ')' statement {
		$$ = create_tree("iteration_statement",5,$1,$2,$3,$4,$5);
	}
	| DO statement WHILE '(' expression ')' ';' {
		$$ = create_tree("iteration_statement",7,$1,$2,$3,$4,$5,$6,$7);
	}
	| FOR '(' expression_statement expression_statement ')' statement {
		$$ = create_tree("iteration_statement",6,$1,$2,$3,$4,$5,$6);
	}
	| FOR '(' expression_statement expression_statement expression ')' statement {
		$$ = create_tree("iteration_statement",7,$1,$2,$3,$4,$5,$6,$7);
	}
	| FOR '(' declaration expression_statement ')' statement {
		$$ = create_tree("iteration_statement",6,$1,$2,$3,$4,$5,$6);
	}
	| FOR '(' declaration expression_statement expression ')' statement {
		$$ = create_tree("iteration_statement",7,$1,$2,$3,$4,$5,$6,$7);
	}
	;

/*��תָ��*/
jump_statement:
	GOTO IDENTIFIER ';' {
		$$ = create_tree("jump_statement",2,$1,$2);
	}
	| CONTINUE ';' {
		$$ = create_tree("jump_statement",2,$1,$2);
	}
	| BREAK ';' {
		$$ = create_tree("jump_statement",2,$1,$2);
	}
	| RETURN ';' {
		$$ = create_tree("jump_statement",2,$1,$2);
	}
	| RETURN expression ';' {
		$$ = create_tree("jump_statement",3,$1,$2,$3);
	}
	;

translation_unit:
	external_declaration {
		$$ = create_tree("translation_unit",1,$1);
	}
	| translation_unit external_declaration {
		$$ = create_tree("translation_unit",2,$1,$2);
	}
	;
/*�ⲿ����*/
external_declaration:
	function_definition {
		$$ = create_tree("external_declaration",1,$1);
	}
	| declaration {
		$$ = create_tree("external_declaration",1,$1);
	}
	;

function_definition:
	type_specifier declarator declaration_list compound_statement {
		$$ = create_tree("function_definition",4,$1,$2,$3,$4);
	}
	| type_specifier declarator compound_statement {
		$$ = create_tree("function_definition",3,$1,$2,$3);
	}
	;

declaration_list:
	declaration {
		$$ = create_tree("declaration_list",1,$1);
	}
	| declaration_list declaration {
		$$ = create_tree("declaration_list",2,$1,$2);
	}
	;

%%


void yyerror(char const *s)
{
	fflush(stdout);
	printf("\n%*s\n%*s\n", column, "^", column, s);
}


int main(int argc,char* argv[]) {
	yyin = fopen(argv[1],"r");
	yyparse();
	printf("\n");
	/*eval(root,0);*/	//����﷨������
	Praser praser(root); //�����м��������
	fclose(yyin);
	ToObject tbj(praser);
	freetreeNode(root); //�ͷſռ�
	return 0;
}