
/*  A Bison parser, made from yacc1.y
    by GNU Bison version 1.28  */

#define YYBISON 1  /* Identify Bison output.  */

#define	IDENTIFIER	257
#define	CONSTANT	258
#define	STRING_LITERAL	259
#define	SIZEOF	260
#define	CONSTANT_INT	261
#define	CONSTANT_DOUBLE	262
#define	TRUE	263
#define	FALSE	264
#define	PTR_OP	265
#define	INC_OP	266
#define	DEC_OP	267
#define	LEFT_OP	268
#define	RIGHT_OP	269
#define	LE_OP	270
#define	GE_OP	271
#define	EQ_OP	272
#define	NE_OP	273
#define	AND_OP	274
#define	OR_OP	275
#define	MUL_ASSIGN	276
#define	DIV_ASSIGN	277
#define	MOD_ASSIGN	278
#define	ADD_ASSIGN	279
#define	SUB_ASSIGN	280
#define	LEFT_ASSIGN	281
#define	RIGHT_ASSIGN	282
#define	AND_ASSIGN	283
#define	XOR_ASSIGN	284
#define	OR_ASSIGN	285
#define	TYPE_NAME	286
#define	TYPEDEF	287
#define	EXTERN	288
#define	STATIC	289
#define	AUTO	290
#define	REGISTER	291
#define	CHAR	292
#define	SHORT	293
#define	INT	294
#define	LONG	295
#define	SIGNED	296
#define	UNSIGNED	297
#define	FLOAT	298
#define	DOUBLE	299
#define	CONST	300
#define	VOLATILE	301
#define	VOID	302
#define	BOOL	303
#define	STRUCT	304
#define	UNION	305
#define	ENUM	306
#define	ELLIPSIS	307
#define	CASE	308
#define	DEFAULT	309
#define	IF	310
#define	ELSE	311
#define	SWITCH	312
#define	WHILE	313
#define	DO	314
#define	FOR	315
#define	GOTO	316
#define	CONTINUE	317
#define	BREAK	318
#define	RETURN	319
#define	LOWER_THAN_ELSE	320

#line 1 "yacc1.y"

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

#line 19 "yacc1.y"
typedef union{
	struct treeNode* tn;
} YYSTYPE;
#ifndef YYDEBUG
#define YYDEBUG 1
#endif

#include <stdio.h>

#ifndef __cplusplus
#ifndef __STDC__
#define const
#endif
#endif



#define	YYFINAL		269
#define	YYFLAG		-32768
#define	YYNTBASE	91

#define YYTRANSLATE(x) ((unsigned)(x) <= 320 ? yytranslate[x] : 137)

static const char yytranslate[] = {     0,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,    74,     2,     2,     2,    80,    73,     2,    88,
    89,    78,    77,    67,    76,    72,    79,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,    68,    66,    81,
    69,    82,    85,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
    70,     2,    71,    83,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,    86,    84,    87,    75,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     1,     3,     4,     5,     6,
     7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
    17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
    27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
    37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
    47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
    57,    58,    59,    60,    61,    62,    63,    64,    65,    90
};

#if YYDEBUG != 0
static const short yyprhs[] = {     0,
     0,     2,     4,     6,     8,    10,    12,    16,    18,    23,
    27,    32,    35,    38,    40,    44,    46,    49,    52,    55,
    57,    59,    61,    63,    65,    69,    73,    77,    79,    83,
    87,    89,    93,    97,    99,   103,   107,   111,   115,   117,
   121,   125,   127,   131,   133,   137,   139,   143,   145,   149,
   151,   155,   157,   161,   163,   165,   167,   169,   171,   173,
   175,   177,   179,   181,   183,   185,   189,   192,   196,   198,
   202,   204,   208,   210,   212,   214,   216,   218,   220,   224,
   229,   234,   238,   243,   248,   252,   254,   258,   261,   264,
   266,   268,   272,   276,   279,   283,   287,   292,   296,   301,
   304,   308,   312,   317,   319,   323,   328,   330,   333,   337,
   342,   345,   347,   350,   354,   357,   359,   361,   363,   365,
   367,   369,   373,   378,   381,   385,   387,   390,   392,   394,
   396,   399,   405,   413,   419,   425,   433,   440,   448,   455,
   463,   467,   470,   473,   476,   480,   482,   485,   487,   489,
   494,   498,   500
};

static const short yyrhs[] = {   133,
     0,     3,     0,     9,     0,    10,     0,     7,     0,     8,
     0,    88,   109,    89,     0,    92,     0,    93,    70,   109,
    71,     0,    93,    88,    89,     0,    93,    88,    94,    89,
     0,    93,    12,     0,    93,    13,     0,   107,     0,    94,
    67,   107,     0,    93,     0,    12,    95,     0,    13,    95,
     0,    96,    95,     0,    77,     0,    76,     0,    75,     0,
    74,     0,    95,     0,    97,    78,    95,     0,    97,    79,
    95,     0,    97,    80,    95,     0,    97,     0,    98,    77,
    97,     0,    98,    76,    97,     0,    98,     0,    99,    14,
    98,     0,    99,    15,    98,     0,    99,     0,   100,    81,
    99,     0,   100,    82,    99,     0,   100,    16,    99,     0,
   100,    17,    99,     0,   100,     0,   101,    18,   100,     0,
   101,    19,   100,     0,   101,     0,   102,    73,   101,     0,
   102,     0,   103,    83,   102,     0,   103,     0,   104,    84,
   103,     0,   104,     0,   105,    20,   104,     0,   105,     0,
   106,    21,   105,     0,   106,     0,    95,   108,   107,     0,
    69,     0,    22,     0,    23,     0,    24,     0,    25,     0,
    26,     0,    27,     0,    28,     0,    29,     0,    30,     0,
    31,     0,   107,     0,   109,    67,   107,     0,   113,    66,
     0,   113,   111,    66,     0,   112,     0,   111,    67,   112,
     0,   114,     0,   114,    69,   119,     0,    48,     0,    38,
     0,    40,     0,    45,     0,    49,     0,     3,     0,    88,
   114,    89,     0,   114,    70,   107,    71,     0,   114,    70,
    78,    71,     0,   114,    70,    71,     0,   114,    88,   115,
    89,     0,   114,    88,   117,    89,     0,   114,    88,    89,
     0,   116,     0,   115,    67,   116,     0,   113,   114,     0,
   113,   118,     0,   113,     0,     3,     0,   117,    67,     3,
     0,    88,   118,    89,     0,    70,    71,     0,    70,   107,
    71,     0,   118,    70,    71,     0,   118,    70,   107,    71,
     0,    70,    78,    71,     0,   118,    70,    78,    71,     0,
    88,    89,     0,    88,   115,    89,     0,   118,    88,    89,
     0,   118,    88,   115,    89,     0,   107,     0,    86,   120,
    87,     0,    86,   120,    67,    87,     0,   119,     0,   121,
   119,     0,   120,    67,   119,     0,   120,    67,   121,   119,
     0,   122,    69,     0,   123,     0,   122,   123,     0,    70,
   106,    71,     0,    72,     3,     0,   125,     0,   126,     0,
   129,     0,   130,     0,   131,     0,   132,     0,     3,    68,
   124,     0,    54,   106,    68,   124,     0,    86,    87,     0,
    86,   127,    87,     0,   128,     0,   127,   128,     0,   110,
     0,   124,     0,    66,     0,   109,    66,     0,    56,    88,
   109,    89,   124,     0,    56,    88,   109,    89,   124,    57,
   124,     0,    58,    88,   109,    89,   124,     0,    59,    88,
   109,    89,   124,     0,    60,   124,    59,    88,   109,    89,
    66,     0,    61,    88,   129,   129,    89,   124,     0,    61,
    88,   129,   129,   109,    89,   124,     0,    61,    88,   110,
   129,    89,   124,     0,    61,    88,   110,   129,   109,    89,
   124,     0,    62,     3,    66,     0,    63,    66,     0,    64,
    66,     0,    65,    66,     0,    65,   109,    66,     0,   134,
     0,   133,   134,     0,   135,     0,   110,     0,   113,   114,
   136,   126,     0,   113,   114,   126,     0,   110,     0,   136,
   110,     0
};

#endif

#if YYDEBUG != 0
static const short yyrline[] = { 0,
    53,    59,    63,    67,    71,    75,    78,    84,    88,    92,
    96,   100,   104,   110,   114,   121,   125,   129,   133,   139,
   143,   146,   149,   155,   159,   162,   165,   171,   175,   178,
   184,   188,   192,   199,   203,   207,   211,   215,   222,   226,
   230,   236,   240,   246,   250,   256,   260,   266,   270,   277,
   281,   288,   293,   299,   303,   307,   311,   315,   319,   323,
   327,   331,   335,   339,   346,   351,   358,   362,   368,   372,
   377,   381,   388,   392,   395,   398,   401,   408,   413,   417,
   422,   426,   430,   434,   438,   445,   449,   454,   458,   461,
   466,   470,   475,   479,   482,   485,   488,   491,   494,   497,
   500,   503,   506,   512,   516,   520,   526,   530,   533,   536,
   541,   547,   551,   556,   560,   566,   571,   575,   579,   583,
   587,   594,   598,   604,   608,   613,   617,   622,   626,   631,
   635,   641,   645,   648,   654,   658,   661,   664,   667,   670,
   676,   680,   683,   686,   689,   694,   698,   703,   707,   712,
   716,   721,   725
};
#endif


#if YYDEBUG != 0 || defined (YYERROR_VERBOSE)

static const char * const yytname[] = {   "$","error","$undefined.","IDENTIFIER",
"CONSTANT","STRING_LITERAL","SIZEOF","CONSTANT_INT","CONSTANT_DOUBLE","TRUE",
"FALSE","PTR_OP","INC_OP","DEC_OP","LEFT_OP","RIGHT_OP","LE_OP","GE_OP","EQ_OP",
"NE_OP","AND_OP","OR_OP","MUL_ASSIGN","DIV_ASSIGN","MOD_ASSIGN","ADD_ASSIGN",
"SUB_ASSIGN","LEFT_ASSIGN","RIGHT_ASSIGN","AND_ASSIGN","XOR_ASSIGN","OR_ASSIGN",
"TYPE_NAME","TYPEDEF","EXTERN","STATIC","AUTO","REGISTER","CHAR","SHORT","INT",
"LONG","SIGNED","UNSIGNED","FLOAT","DOUBLE","CONST","VOLATILE","VOID","BOOL",
"STRUCT","UNION","ENUM","ELLIPSIS","CASE","DEFAULT","IF","ELSE","SWITCH","WHILE",
"DO","FOR","GOTO","CONTINUE","BREAK","RETURN","';'","','","':'","'='","'['",
"']'","'.'","'&'","'!'","'~'","'-'","'+'","'*'","'/'","'%'","'<'","'>'","'^'",
"'|'","'?'","'{'","'}'","'('","')'","LOWER_THAN_ELSE","Program","primary_expression",
"postfix_expression","argument_expression_list","unary_expression","unary_operator",
"multiplicative_expression","additive_expression","shift_expression","relational_expression",
"equality_expression","and_expression","exclusive_or_expression","inclusive_or_expression",
"logical_and_expression","logical_or_expression","assignment_expression","assignment_operator",
"expression","declaration","init_declarator_list","init_declarator","type_specifier",
"declarator","parameter_list","parameter_declaration","identifier_list","abstract_declarator",
"initializer","initializer_list","designation","designator_list","designator",
"statement","labeled_statement","compound_statement","block_item_list","block_item",
"expression_statement","selection_statement","iteration_statement","jump_statement",
"translation_unit","external_declaration","function_definition","declaration_list", NULL
};
#endif

static const short yyr1[] = {     0,
    91,    92,    92,    92,    92,    92,    92,    93,    93,    93,
    93,    93,    93,    94,    94,    95,    95,    95,    95,    96,
    96,    96,    96,    97,    97,    97,    97,    98,    98,    98,
    99,    99,    99,   100,   100,   100,   100,   100,   101,   101,
   101,   102,   102,   103,   103,   104,   104,   105,   105,   106,
   106,   107,   107,   108,   108,   108,   108,   108,   108,   108,
   108,   108,   108,   108,   109,   109,   110,   110,   111,   111,
   112,   112,   113,   113,   113,   113,   113,   114,   114,   114,
   114,   114,   114,   114,   114,   115,   115,   116,   116,   116,
   117,   117,   118,   118,   118,   118,   118,   118,   118,   118,
   118,   118,   118,   119,   119,   119,   120,   120,   120,   120,
   121,   122,   122,   123,   123,   124,   124,   124,   124,   124,
   124,   125,   125,   126,   126,   127,   127,   128,   128,   129,
   129,   130,   130,   130,   131,   131,   131,   131,   131,   131,
   132,   132,   132,   132,   132,   133,   133,   134,   134,   135,
   135,   136,   136
};

static const short yyr2[] = {     0,
     1,     1,     1,     1,     1,     1,     3,     1,     4,     3,
     4,     2,     2,     1,     3,     1,     2,     2,     2,     1,
     1,     1,     1,     1,     3,     3,     3,     1,     3,     3,
     1,     3,     3,     1,     3,     3,     3,     3,     1,     3,
     3,     1,     3,     1,     3,     1,     3,     1,     3,     1,
     3,     1,     3,     1,     1,     1,     1,     1,     1,     1,
     1,     1,     1,     1,     1,     3,     2,     3,     1,     3,
     1,     3,     1,     1,     1,     1,     1,     1,     3,     4,
     4,     3,     4,     4,     3,     1,     3,     2,     2,     1,
     1,     3,     3,     2,     3,     3,     4,     3,     4,     2,
     3,     3,     4,     1,     3,     4,     1,     2,     3,     4,
     2,     1,     2,     3,     2,     1,     1,     1,     1,     1,
     1,     3,     4,     2,     3,     1,     2,     1,     1,     1,
     2,     5,     7,     5,     5,     7,     6,     7,     6,     7,
     3,     2,     2,     2,     3,     1,     2,     1,     1,     4,
     3,     1,     2
};

static const short yydefact[] = {     0,
    74,    75,    76,    73,    77,   149,     0,     1,   146,   148,
    78,    67,     0,     0,    69,    71,   147,     0,    68,     0,
     0,     0,     0,     0,   152,     0,   151,     0,    79,    70,
    71,     2,     5,     6,     3,     4,     0,     0,    23,    22,
    21,    20,     0,     0,     8,    16,    24,     0,    28,    31,
    34,    39,    42,    44,    46,    48,    50,    52,   104,    72,
    82,     0,     0,     2,     0,     0,     0,     0,     0,     0,
     0,     0,     0,     0,   130,   124,    65,     0,   128,   129,
   116,   117,     0,   126,   118,   119,   120,   121,    91,    85,
    90,     0,    86,     0,   153,   150,    17,    18,     0,     0,
   107,     0,     0,     0,   112,     0,    12,    13,     0,     0,
    55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
    54,     0,    19,     0,     0,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,    81,    80,     0,    24,     0,     0,     0,     0,     0,
     0,     0,   142,   143,   144,     0,   131,     0,   125,   127,
     0,     0,    88,    89,     0,    83,     0,    84,     0,   115,
     0,   105,   108,   111,   113,     7,     0,    10,     0,    14,
    53,    25,    26,    27,    30,    29,    32,    33,    37,    38,
    35,    36,    40,    41,    43,    45,    47,    49,    51,   122,
     0,     0,     0,     0,     0,     0,     0,   141,   145,    66,
    94,     0,     0,   100,     0,     0,     0,     0,    87,    92,
   114,   106,   109,     0,     9,     0,    11,   123,     0,     0,
     0,     0,     0,     0,    98,    95,   101,    93,    96,     0,
     0,   102,     0,   110,    15,   132,   134,   135,     0,     0,
     0,     0,     0,    99,    97,   103,     0,     0,   139,     0,
   137,     0,   133,   136,   140,   138,     0,     0,     0
};

static const short yydefgoto[] = {   267,
    45,    46,   179,    47,    48,    49,    50,    51,    52,    53,
    54,    55,    56,    57,    58,    77,   122,    78,     6,    14,
    15,    26,    18,    92,    93,    94,   164,    60,   102,   103,
   104,   105,    80,    81,    82,    83,    84,    85,    86,    87,
    88,     8,     9,    10,    28
};

static const short yypact[] = {   310,
-32768,-32768,-32768,-32768,-32768,-32768,     8,   310,-32768,-32768,
-32768,-32768,     6,   153,-32768,   283,-32768,   -51,-32768,     6,
   556,   204,   250,   133,-32768,     8,-32768,   316,-32768,-32768,
   -42,-32768,-32768,-32768,-32768,-32768,   663,   663,-32768,-32768,
-32768,-32768,   524,   663,-32768,   135,    32,   663,   171,   154,
    84,    23,   219,   -52,   -36,   -34,    64,    10,-32768,-32768,
-32768,    24,    75,    18,   663,    46,    49,    61,   414,   101,
   191,   130,   137,   571,-32768,-32768,-32768,   198,-32768,-32768,
-32768,-32768,   332,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
    15,   -45,-32768,   -22,-32768,-32768,-32768,-32768,   663,   212,
-32768,   -53,   556,   176,-32768,    21,-32768,-32768,   663,    68,
-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
-32768,   663,-32768,   663,   663,   663,   663,   663,   663,   663,
   663,   663,   663,   663,   663,   663,   663,   663,   663,   663,
   663,-32768,-32768,   414,-32768,    11,   663,   663,   663,   165,
   447,   163,-32768,-32768,-32768,   203,-32768,   663,-32768,-32768,
   540,     3,    65,    96,   310,-32768,   244,-32768,    -1,-32768,
   429,-32768,-32768,-32768,-32768,-32768,    26,-32768,    22,-32768,
-32768,-32768,-32768,-32768,   171,   171,   154,   154,    84,    84,
    84,    84,    23,    23,   219,   -52,   -36,   -34,    64,-32768,
   414,    42,    63,    66,   164,   648,   648,-32768,-32768,-32768,
-32768,   183,   190,-32768,    83,   113,   548,   228,-32768,-32768,
-32768,-32768,-32768,   556,-32768,   663,-32768,-32768,   414,   414,
   414,   663,   151,   167,-32768,-32768,-32768,-32768,-32768,   196,
   215,-32768,   119,-32768,-32768,   217,-32768,-32768,   120,   414,
   132,   414,   143,-32768,-32768,-32768,   414,   221,-32768,   414,
-32768,   414,-32768,-32768,-32768,-32768,   289,   291,-32768
};

static const short yypgoto[] = {-32768,
-32768,-32768,-32768,   -12,-32768,   144,   155,   102,   158,   146,
   159,   157,   160,   161,   -50,   -20,-32768,   -41,   -11,-32768,
   281,     0,     9,  -149,   138,-32768,   145,   -39,-32768,   134,
-32768,   214,   -62,-32768,    14,-32768,   236,  -141,-32768,-32768,
-32768,-32768,   312,-32768,-32768
};


#define	YYLAST		751


static const short yytable[] = {     7,
    59,    63,   106,   101,    25,    11,   150,     7,    11,   207,
    11,    79,   215,   171,   146,    16,    95,    11,    22,   141,
   137,   165,    59,    91,    97,    98,    21,    22,    31,    27,
   141,   141,   156,   172,    31,   123,    24,    29,   131,   132,
     1,    96,     2,   166,   167,    24,   138,     3,   169,   139,
     4,     5,   145,   111,   112,   113,   114,   115,   116,   117,
   118,   119,   120,   173,   233,   234,   168,   177,   243,   221,
    32,    79,   161,    12,    33,    34,    35,    36,   201,    37,
    38,   200,    59,   140,   161,   144,   145,   158,   226,   180,
   162,   214,   158,    13,   142,    13,   225,   129,   130,   163,
   121,   181,   162,   133,   134,   202,   203,   204,   158,   176,
   227,   182,   183,   184,   145,   145,   145,   145,   145,   145,
   145,   145,   145,   145,   145,   145,   145,   145,   145,   158,
   229,   223,   158,   147,    22,    89,   148,   210,   228,   206,
   213,    39,    40,    41,    42,   143,   107,   108,   149,   165,
    59,   230,    24,    32,   231,    44,   178,    33,    34,    35,
    36,    91,    37,    38,    91,   217,   246,   247,   248,    32,
     1,   237,     2,    33,    34,    35,    36,     3,    37,    38,
     4,     5,   217,   218,   244,   165,   158,   259,   151,   261,
   249,   251,   253,   152,   263,   153,   241,   265,   158,   266,
   218,   238,   154,    59,   109,   245,    32,   256,   258,   158,
    33,    34,    35,    36,   170,    37,    38,    91,    19,    20,
   260,    90,   110,   205,    39,    40,    41,    42,   208,   127,
   128,   262,   189,   190,   191,   192,   135,   136,    44,   250,
    39,    40,    41,    42,   174,    99,   220,   100,   124,   125,
   126,   232,    64,   235,    44,   252,    33,    34,    35,    36,
   236,    37,    38,   157,   158,     1,   254,     2,   209,   158,
   185,   186,     3,   257,    61,     4,     5,    39,    40,    41,
    42,    62,   195,   187,   188,   255,   264,     1,   268,     2,
   269,    44,   193,   194,     3,   197,   196,     4,     5,   198,
    30,   199,   219,    65,   224,    66,   216,    67,    68,    69,
    70,    71,    72,    73,    74,    75,   242,   175,   160,    17,
     1,     0,     2,    39,    40,    41,    42,     3,     0,     0,
     4,     5,     0,     0,    64,    23,    76,    44,    33,    34,
    35,    36,     0,    37,    38,     0,     0,     1,     0,     2,
     0,    21,    22,     1,     3,     2,     0,     4,     5,     0,
     3,     0,     0,     4,     5,     0,     0,     0,    23,     1,
    24,     2,     0,     0,     0,     0,     3,     0,     0,     4,
     5,     0,     0,     0,     0,    65,     0,    66,     0,    67,
    68,    69,    70,    71,    72,    73,    74,    75,     0,     0,
     0,    23,     0,     0,     0,    39,    40,    41,    42,     0,
     0,     0,     0,     0,     0,     0,    64,    23,   159,    44,
    33,    34,    35,    36,     0,    37,    38,     0,     0,     0,
     0,    32,     0,     0,     0,    33,    34,    35,    36,     0,
    37,    38,     0,     0,     0,     0,     0,     0,     0,    32,
     0,     0,     0,    33,    34,    35,    36,     0,    37,    38,
     0,     0,     0,     0,     0,     0,     0,    65,     0,    66,
     0,    67,    68,    69,    70,    71,    72,    73,    74,    75,
     0,     0,     0,     0,     1,     0,     2,    39,    40,    41,
    42,     3,     0,     0,     4,     5,     0,     0,    99,    23,
   100,    44,    39,    40,    41,    42,     0,     0,     0,     0,
     0,     0,    75,     0,    43,   222,    44,     0,     0,     0,
    39,    40,    41,    42,     0,     0,    32,     0,     0,     0,
    33,    34,    35,    36,    44,    37,    38,     0,     0,     0,
     0,     0,    32,     0,     0,     0,    33,    34,    35,    36,
    32,    37,    38,     0,    33,    34,    35,    36,    32,    37,
    38,     0,    33,    34,    35,    36,     0,    37,    38,     0,
     0,     0,     0,    32,     0,     0,     0,    33,    34,    35,
    36,     0,    37,    38,     0,     0,     0,     0,     0,     0,
     0,     0,     0,    99,     0,   100,     0,    39,    40,    41,
    42,     0,     0,     0,     0,     0,     0,     0,     0,    43,
   211,    44,     0,    39,    40,    41,    42,   212,   239,     0,
     0,    39,    40,    41,    42,   240,     0,    44,     0,    39,
    40,    41,    42,     0,     0,    44,   155,     0,     0,     0,
     0,    43,     0,    44,    39,    40,    41,    42,     0,     0,
    32,     0,     0,     0,    33,    34,    35,    36,    44,    37,
    38,     0,     0,     0,     0,    32,     0,     0,     0,    33,
    34,    35,    36,     0,    37,    38,     0,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,     0,     0,    75,     0,     0,     0,     0,     0,     0,
     0,    39,    40,    41,    42,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,    44,    39,    40,    41,    42,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    44
};

static const short yycheck[] = {     0,
    21,    22,    44,    43,    16,     3,    69,     8,     3,   151,
     3,    23,   162,    67,    65,     7,    28,     3,    70,    21,
    73,    67,    43,    24,    37,    38,    69,    70,    20,    16,
    21,    21,    74,    87,    26,    48,    88,    89,    16,    17,
    38,    28,    40,    89,    67,    88,    83,    45,    99,    84,
    48,    49,    65,    22,    23,    24,    25,    26,    27,    28,
    29,    30,    31,   103,   206,   207,    89,   109,   218,    71,
     3,    83,    70,    66,     7,     8,     9,    10,    68,    12,
    13,   144,   103,    20,    70,    68,    99,    67,    67,   110,
    88,    89,    67,    88,    71,    88,    71,    14,    15,    91,
    69,   122,    88,    81,    82,   147,   148,   149,    67,    89,
    89,   124,   125,   126,   127,   128,   129,   130,   131,   132,
   133,   134,   135,   136,   137,   138,   139,   140,   141,    67,
    89,   171,    67,    88,    70,     3,    88,   158,   201,   151,
   161,    74,    75,    76,    77,    71,    12,    13,    88,    67,
   171,    89,    88,     3,    89,    88,    89,     7,     8,     9,
    10,   162,    12,    13,   165,    70,   229,   230,   231,     3,
    38,    89,    40,     7,     8,     9,    10,    45,    12,    13,
    48,    49,    70,    88,   224,    67,    67,   250,    88,   252,
   232,   233,   234,     3,   257,    66,   217,   260,    67,   262,
    88,    89,    66,   224,    70,   226,     3,    89,    89,    67,
     7,     8,     9,    10,     3,    12,    13,   218,    66,    67,
    89,    89,    88,    59,    74,    75,    76,    77,    66,    76,
    77,    89,   131,   132,   133,   134,    18,    19,    88,    89,
    74,    75,    76,    77,    69,    70,     3,    72,    78,    79,
    80,    88,     3,    71,    88,    89,     7,     8,     9,    10,
    71,    12,    13,    66,    67,    38,    71,    40,    66,    67,
   127,   128,    45,    57,    71,    48,    49,    74,    75,    76,
    77,    78,   137,   129,   130,    71,    66,    38,     0,    40,
     0,    88,   135,   136,    45,   139,   138,    48,    49,   140,
    20,   141,   165,    54,   171,    56,   162,    58,    59,    60,
    61,    62,    63,    64,    65,    66,    89,   104,    83,     8,
    38,    -1,    40,    74,    75,    76,    77,    45,    -1,    -1,
    48,    49,    -1,    -1,     3,    86,    87,    88,     7,     8,
     9,    10,    -1,    12,    13,    -1,    -1,    38,    -1,    40,
    -1,    69,    70,    38,    45,    40,    -1,    48,    49,    -1,
    45,    -1,    -1,    48,    49,    -1,    -1,    -1,    86,    38,
    88,    40,    -1,    -1,    -1,    -1,    45,    -1,    -1,    48,
    49,    -1,    -1,    -1,    -1,    54,    -1,    56,    -1,    58,
    59,    60,    61,    62,    63,    64,    65,    66,    -1,    -1,
    -1,    86,    -1,    -1,    -1,    74,    75,    76,    77,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,     3,    86,    87,    88,
     7,     8,     9,    10,    -1,    12,    13,    -1,    -1,    -1,
    -1,     3,    -1,    -1,    -1,     7,     8,     9,    10,    -1,
    12,    13,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,
    -1,    -1,    -1,     7,     8,     9,    10,    -1,    12,    13,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,    54,    -1,    56,
    -1,    58,    59,    60,    61,    62,    63,    64,    65,    66,
    -1,    -1,    -1,    -1,    38,    -1,    40,    74,    75,    76,
    77,    45,    -1,    -1,    48,    49,    -1,    -1,    70,    86,
    72,    88,    74,    75,    76,    77,    -1,    -1,    -1,    -1,
    -1,    -1,    66,    -1,    86,    87,    88,    -1,    -1,    -1,
    74,    75,    76,    77,    -1,    -1,     3,    -1,    -1,    -1,
     7,     8,     9,    10,    88,    12,    13,    -1,    -1,    -1,
    -1,    -1,     3,    -1,    -1,    -1,     7,     8,     9,    10,
     3,    12,    13,    -1,     7,     8,     9,    10,     3,    12,
    13,    -1,     7,     8,     9,    10,    -1,    12,    13,    -1,
    -1,    -1,    -1,     3,    -1,    -1,    -1,     7,     8,     9,
    10,    -1,    12,    13,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,    70,    -1,    72,    -1,    74,    75,    76,
    77,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    86,
    71,    88,    -1,    74,    75,    76,    77,    78,    71,    -1,
    -1,    74,    75,    76,    77,    78,    -1,    88,    -1,    74,
    75,    76,    77,    -1,    -1,    88,    66,    -1,    -1,    -1,
    -1,    86,    -1,    88,    74,    75,    76,    77,    -1,    -1,
     3,    -1,    -1,    -1,     7,     8,     9,    10,    88,    12,
    13,    -1,    -1,    -1,    -1,     3,    -1,    -1,    -1,     7,
     8,     9,    10,    -1,    12,    13,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,    66,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    74,    75,    76,    77,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,    88,    74,    75,    76,    77,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    88
};
/* -*-C-*-  Note some compilers choke on comments on `#line' lines.  */
#line 3 "/usr/local/share/bison.simple"
/* This file comes from bison-1.28.  */

/* Skeleton output parser for bison,
   Copyright (C) 1984, 1989, 1990 Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 59 Temple Place - Suite 330,
   Boston, MA 02111-1307, USA.  */

/* As a special exception, when this file is copied by Bison into a
   Bison output file, you may use that output file without restriction.
   This special exception was added by the Free Software Foundation
   in version 1.24 of Bison.  */

/* This is the parser code that is written into each bison parser
  when the %semantic_parser declaration is not specified in the grammar.
  It was written by Richard Stallman by simplifying the hairy parser
  used when %semantic_parser is specified.  */

#ifndef YYSTACK_USE_ALLOCA
#ifdef alloca
#define YYSTACK_USE_ALLOCA
#else /* alloca not defined */
#ifdef __GNUC__
#define YYSTACK_USE_ALLOCA
#define alloca __builtin_alloca
#else /* not GNU C.  */
#if (!defined (__STDC__) && defined (sparc)) || defined (__sparc__) || defined (__sparc) || defined (__sgi) || (defined (__sun) && defined (__i386))
#define YYSTACK_USE_ALLOCA
#include <alloca.h>
#else /* not sparc */
/* We think this test detects Watcom and Microsoft C.  */
/* This used to test MSDOS, but that is a bad idea
   since that symbol is in the user namespace.  */
#if (defined (_MSDOS) || defined (_MSDOS_)) && !defined (__TURBOC__)
#if 0 /* No need for malloc.h, which pollutes the namespace;
	 instead, just don't use alloca.  */
#include <malloc.h>
#endif
#else /* not MSDOS, or __TURBOC__ */
#if defined(_AIX)
/* I don't know what this was needed for, but it pollutes the namespace.
   So I turned it off.   rms, 2 May 1997.  */
/* #include <malloc.h>  */
 #pragma alloca
#define YYSTACK_USE_ALLOCA
#else /* not MSDOS, or __TURBOC__, or _AIX */
#if 0
#ifdef __hpux /* haible@ilog.fr says this works for HPUX 9.05 and up,
		 and on HPUX 10.  Eventually we can turn this on.  */
#define YYSTACK_USE_ALLOCA
#define alloca __builtin_alloca
#endif /* __hpux */
#endif
#endif /* not _AIX */
#endif /* not MSDOS, or __TURBOC__ */
#endif /* not sparc */
#endif /* not GNU C */
#endif /* alloca not defined */
#endif /* YYSTACK_USE_ALLOCA not defined */

#ifdef YYSTACK_USE_ALLOCA
#define YYSTACK_ALLOC alloca
#else
#define YYSTACK_ALLOC malloc
#endif

/* Note: there must be only one dollar sign in this file.
   It is replaced by the list of actions, each action
   as one case of the switch.  */

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		-2
#define YYEOF		0
#define YYACCEPT	goto yyacceptlab
#define YYABORT 	goto yyabortlab
#define YYERROR		goto yyerrlab1
/* Like YYERROR except do call yyerror.
   This remains here temporarily to ease the
   transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */
#define YYFAIL		goto yyerrlab
#define YYRECOVERING()  (!!yyerrstatus)
#define YYBACKUP(token, value) \
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    { yychar = (token), yylval = (value);			\
      yychar1 = YYTRANSLATE (yychar);				\
      YYPOPSTACK;						\
      goto yybackup;						\
    }								\
  else								\
    { yyerror ("syntax error: cannot back up"); YYERROR; }	\
while (0)

#define YYTERROR	1
#define YYERRCODE	256

#ifndef YYPURE
#define YYLEX		yylex()
#endif

#ifdef YYPURE
#ifdef YYLSP_NEEDED
#ifdef YYLEX_PARAM
#define YYLEX		yylex(&yylval, &yylloc, YYLEX_PARAM)
#else
#define YYLEX		yylex(&yylval, &yylloc)
#endif
#else /* not YYLSP_NEEDED */
#ifdef YYLEX_PARAM
#define YYLEX		yylex(&yylval, YYLEX_PARAM)
#else
#define YYLEX		yylex(&yylval)
#endif
#endif /* not YYLSP_NEEDED */
#endif

/* If nonreentrant, generate the variables here */

#ifndef YYPURE

int	yychar;			/*  the lookahead symbol		*/
YYSTYPE	yylval;			/*  the semantic value of the		*/
				/*  lookahead symbol			*/

#ifdef YYLSP_NEEDED
YYLTYPE yylloc;			/*  location data for the lookahead	*/
				/*  symbol				*/
#endif

int yynerrs;			/*  number of parse errors so far       */
#endif  /* not YYPURE */

#if YYDEBUG != 0
int yydebug;			/*  nonzero means print parse trace	*/
/* Since this is uninitialized, it does not stop multiple parsers
   from coexisting.  */
#endif

/*  YYINITDEPTH indicates the initial size of the parser's stacks	*/

#ifndef	YYINITDEPTH
#define YYINITDEPTH 200
#endif

/*  YYMAXDEPTH is the maximum size the stacks can grow to
    (effective only if the built-in stack extension method is used).  */

#if YYMAXDEPTH == 0
#undef YYMAXDEPTH
#endif

#ifndef YYMAXDEPTH
#define YYMAXDEPTH 10000
#endif

/* Define __yy_memcpy.  Note that the size argument
   should be passed with type unsigned int, because that is what the non-GCC
   definitions require.  With GCC, __builtin_memcpy takes an arg
   of type size_t, but it can handle unsigned int.  */

#if __GNUC__ > 1		/* GNU C and GNU C++ define this.  */
#define __yy_memcpy(TO,FROM,COUNT)	__builtin_memcpy(TO,FROM,COUNT)
#else				/* not GNU C or C++ */
#ifndef __cplusplus

/* This is the most reliable way to avoid incompatibilities
   in available built-in functions on various systems.  */
static void
__yy_memcpy (to, from, count)
     char *to;
     char *from;
     unsigned int count;
{
  register char *f = from;
  register char *t = to;
  register int i = count;

  while (i-- > 0)
    *t++ = *f++;
}

#else /* __cplusplus */

/* This is the most reliable way to avoid incompatibilities
   in available built-in functions on various systems.  */
static void
__yy_memcpy (char *to, char *from, unsigned int count)
{
  register char *t = to;
  register char *f = from;
  register int i = count;

  while (i-- > 0)
    *t++ = *f++;
}

#endif
#endif

#line 217 "/usr/local/share/bison.simple"

/* The user can define YYPARSE_PARAM as the name of an argument to be passed
   into yyparse.  The argument should have type void *.
   It should actually point to an object.
   Grammar actions can access the variable by casting it
   to the proper pointer type.  */

#ifdef YYPARSE_PARAM
#ifdef __cplusplus
#define YYPARSE_PARAM_ARG void *YYPARSE_PARAM
#define YYPARSE_PARAM_DECL
#else /* not __cplusplus */
#define YYPARSE_PARAM_ARG YYPARSE_PARAM
#define YYPARSE_PARAM_DECL void *YYPARSE_PARAM;
#endif /* not __cplusplus */
#else /* not YYPARSE_PARAM */
#define YYPARSE_PARAM_ARG
#define YYPARSE_PARAM_DECL
#endif /* not YYPARSE_PARAM */

/* Prevent warning if -Wstrict-prototypes.  */
#ifdef __GNUC__
#ifdef YYPARSE_PARAM
int yyparse (void *);
#else
int yyparse (void);
#endif
#endif

int
yyparse(YYPARSE_PARAM_ARG)
     YYPARSE_PARAM_DECL
{
  register int yystate;
  register int yyn;
  register short *yyssp;
  register YYSTYPE *yyvsp;
  int yyerrstatus;	/*  number of tokens to shift before error messages enabled */
  int yychar1 = 0;		/*  lookahead token as an internal (translated) token number */

  short	yyssa[YYINITDEPTH];	/*  the state stack			*/
  YYSTYPE yyvsa[YYINITDEPTH];	/*  the semantic value stack		*/

  short *yyss = yyssa;		/*  refer to the stacks thru separate pointers */
  YYSTYPE *yyvs = yyvsa;	/*  to allow yyoverflow to reallocate them elsewhere */

#ifdef YYLSP_NEEDED
  YYLTYPE yylsa[YYINITDEPTH];	/*  the location stack			*/
  YYLTYPE *yyls = yylsa;
  YYLTYPE *yylsp;

#define YYPOPSTACK   (yyvsp--, yyssp--, yylsp--)
#else
#define YYPOPSTACK   (yyvsp--, yyssp--)
#endif

  int yystacksize = YYINITDEPTH;
  int yyfree_stacks = 0;

#ifdef YYPURE
  int yychar;
  YYSTYPE yylval;
  int yynerrs;
#ifdef YYLSP_NEEDED
  YYLTYPE yylloc;
#endif
#endif

  YYSTYPE yyval;		/*  the variable used to return		*/
				/*  semantic values from the action	*/
				/*  routines				*/

  int yylen;

#if YYDEBUG != 0
  if (yydebug)
    fprintf(stderr, "Starting parse\n");
#endif

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss - 1;
  yyvsp = yyvs;
#ifdef YYLSP_NEEDED
  yylsp = yyls;
#endif

/* Push a new state, which is found in  yystate  .  */
/* In all cases, when you get here, the value and location stacks
   have just been pushed. so pushing a state here evens the stacks.  */
yynewstate:

  *++yyssp = yystate;

  if (yyssp >= yyss + yystacksize - 1)
    {
      /* Give user a chance to reallocate the stack */
      /* Use copies of these so that the &'s don't force the real ones into memory. */
      YYSTYPE *yyvs1 = yyvs;
      short *yyss1 = yyss;
#ifdef YYLSP_NEEDED
      YYLTYPE *yyls1 = yyls;
#endif

      /* Get the current used size of the three stacks, in elements.  */
      int size = yyssp - yyss + 1;

#ifdef yyoverflow
      /* Each stack pointer address is followed by the size of
	 the data in use in that stack, in bytes.  */
#ifdef YYLSP_NEEDED
      /* This used to be a conditional around just the two extra args,
	 but that might be undefined if yyoverflow is a macro.  */
      yyoverflow("parser stack overflow",
		 &yyss1, size * sizeof (*yyssp),
		 &yyvs1, size * sizeof (*yyvsp),
		 &yyls1, size * sizeof (*yylsp),
		 &yystacksize);
#else
      yyoverflow("parser stack overflow",
		 &yyss1, size * sizeof (*yyssp),
		 &yyvs1, size * sizeof (*yyvsp),
		 &yystacksize);
#endif

      yyss = yyss1; yyvs = yyvs1;
#ifdef YYLSP_NEEDED
      yyls = yyls1;
#endif
#else /* no yyoverflow */
      /* Extend the stack our own way.  */
      if (yystacksize >= YYMAXDEPTH)
	{
	  yyerror("parser stack overflow");
	  if (yyfree_stacks)
	    {
	      free (yyss);
	      free (yyvs);
#ifdef YYLSP_NEEDED
	      free (yyls);
#endif
	    }
	  return 2;
	}
      yystacksize *= 2;
      if (yystacksize > YYMAXDEPTH)
	yystacksize = YYMAXDEPTH;
#ifndef YYSTACK_USE_ALLOCA
      yyfree_stacks = 1;
#endif
      yyss = (short *) YYSTACK_ALLOC (yystacksize * sizeof (*yyssp));
      __yy_memcpy ((char *)yyss, (char *)yyss1,
		   size * (unsigned int) sizeof (*yyssp));
      yyvs = (YYSTYPE *) YYSTACK_ALLOC (yystacksize * sizeof (*yyvsp));
      __yy_memcpy ((char *)yyvs, (char *)yyvs1,
		   size * (unsigned int) sizeof (*yyvsp));
#ifdef YYLSP_NEEDED
      yyls = (YYLTYPE *) YYSTACK_ALLOC (yystacksize * sizeof (*yylsp));
      __yy_memcpy ((char *)yyls, (char *)yyls1,
		   size * (unsigned int) sizeof (*yylsp));
#endif
#endif /* no yyoverflow */

      yyssp = yyss + size - 1;
      yyvsp = yyvs + size - 1;
#ifdef YYLSP_NEEDED
      yylsp = yyls + size - 1;
#endif

#if YYDEBUG != 0
      if (yydebug)
	fprintf(stderr, "Stack size increased to %d\n", yystacksize);
#endif

      if (yyssp >= yyss + yystacksize - 1)
	YYABORT;
    }

#if YYDEBUG != 0
  if (yydebug)
    fprintf(stderr, "Entering state %d\n", yystate);
#endif

  goto yybackup;
 yybackup:

/* Do appropriate processing given the current state.  */
/* Read a lookahead token if we need one and don't already have one.  */
/* yyresume: */

  /* First try to decide what to do without reference to lookahead token.  */

  yyn = yypact[yystate];
  if (yyn == YYFLAG)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* yychar is either YYEMPTY or YYEOF
     or a valid token in external form.  */

  if (yychar == YYEMPTY)
    {
#if YYDEBUG != 0
      if (yydebug)
	fprintf(stderr, "Reading a token: ");
#endif
      yychar = YYLEX;
    }

  /* Convert token to internal form (in yychar1) for indexing tables with */

  if (yychar <= 0)		/* This means end of input. */
    {
      yychar1 = 0;
      yychar = YYEOF;		/* Don't call YYLEX any more */

#if YYDEBUG != 0
      if (yydebug)
	fprintf(stderr, "Now at end of input.\n");
#endif
    }
  else
    {
      yychar1 = YYTRANSLATE(yychar);

#if YYDEBUG != 0
      if (yydebug)
	{
	  fprintf (stderr, "Next token is %d (%s", yychar, yytname[yychar1]);
	  /* Give the individual parser a way to print the precise meaning
	     of a token, for further debugging info.  */
#ifdef YYPRINT
	  YYPRINT (stderr, yychar, yylval);
#endif
	  fprintf (stderr, ")\n");
	}
#endif
    }

  yyn += yychar1;
  if (yyn < 0 || yyn > YYLAST || yycheck[yyn] != yychar1)
    goto yydefault;

  yyn = yytable[yyn];

  /* yyn is what to do for this token type in this state.
     Negative => reduce, -yyn is rule number.
     Positive => shift, yyn is new state.
       New state is final state => don't bother to shift,
       just return success.
     0, or most negative number => error.  */

  if (yyn < 0)
    {
      if (yyn == YYFLAG)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }
  else if (yyn == 0)
    goto yyerrlab;

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Shift the lookahead token.  */

#if YYDEBUG != 0
  if (yydebug)
    fprintf(stderr, "Shifting token %d (%s), ", yychar, yytname[yychar1]);
#endif

  /* Discard the token being shifted unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  *++yyvsp = yylval;
#ifdef YYLSP_NEEDED
  *++yylsp = yylloc;
#endif

  /* count tokens shifted since error; after three, turn off error status.  */
  if (yyerrstatus) yyerrstatus--;

  yystate = yyn;
  goto yynewstate;

/* Do the default action for the current state.  */
yydefault:

  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;

/* Do a reduction.  yyn is the number of a rule to reduce with.  */
yyreduce:
  yylen = yyr2[yyn];
  if (yylen > 0)
    yyval = yyvsp[1-yylen]; /* implement default value of the action */

#if YYDEBUG != 0
  if (yydebug)
    {
      int i;

      fprintf (stderr, "Reducing via rule %d (line %d), ",
	       yyn, yyrline[yyn]);

      /* Print the symbols being reduced, and their result.  */
      for (i = yyprhs[yyn]; yyrhs[i] > 0; i++)
	fprintf (stderr, "%s ", yytname[yyrhs[i]]);
      fprintf (stderr, " -> %s\n", yytname[yyr1[yyn]]);
    }
#endif


  switch (yyn) {

case 1:
#line 54 "yacc1.y"
{ //初始化头节点，开始生成AST
		root = create_tree("Program",1,yyvsp[0].tn);
	;
    break;}
case 2:
#line 60 "yacc1.y"
{//$$代表是将会压入栈中的变量，$n是代表当前参与规约的第n个元素
		yyval.tn = create_tree("primary_expression",1,yyvsp[0].tn);
	;
    break;}
case 3:
#line 64 "yacc1.y"
{
		yyval.tn = create_tree("primary_expression",1,yyvsp[0].tn);
	;
    break;}
case 4:
#line 68 "yacc1.y"
{
		yyval.tn = create_tree("primary_expression",1,yyvsp[0].tn);
	;
    break;}
case 5:
#line 71 "yacc1.y"
{
		yyval.tn = create_tree("primary_expression",1,yyvsp[0].tn);
		
	;
    break;}
case 6:
#line 75 "yacc1.y"
{
		yyval.tn = create_tree("primary_expression",1,yyvsp[0].tn);
	;
    break;}
case 7:
#line 78 "yacc1.y"
{
		yyval.tn = create_tree("primary_expression",3,yyvsp[-2].tn,yyvsp[-1].tn,yyvsp[0].tn);
	;
    break;}
case 8:
#line 85 "yacc1.y"
{
		yyval.tn = create_tree("postfix_expression",1,yyvsp[0].tn);
	;
    break;}
case 9:
#line 88 "yacc1.y"
{
		yyval.tn = create_tree("postfix_expression",4,yyvsp[-3].tn,yyvsp[-2].tn,yyvsp[-1].tn,yyvsp[0].tn);
		//数组调用方括号
	;
    break;}
case 10:
#line 92 "yacc1.y"
{
		yyval.tn = create_tree("postfix_expression",3,yyvsp[-2].tn,yyvsp[-1].tn,yyvsp[0].tn);
		//函数调用括号
	;
    break;}
case 11:
#line 96 "yacc1.y"
{
		yyval.tn = create_tree("postfix_expression",4,yyvsp[-3].tn,yyvsp[-2].tn,yyvsp[-1].tn,yyvsp[0].tn);
		//函数调用，带参数表
	;
    break;}
case 12:
#line 100 "yacc1.y"
{
		//++
		yyval.tn = create_tree("postfix_expression",2,yyvsp[-1].tn,yyvsp[0].tn);
	;
    break;}
case 13:
#line 104 "yacc1.y"
{
		//--
		yyval.tn = create_tree("postfix_expression",2,yyvsp[-1].tn,yyvsp[0].tn);
	;
    break;}
case 14:
#line 111 "yacc1.y"
{
		yyval.tn = create_tree("argument_expression_list",1,yyvsp[0].tn);
	;
    break;}
case 15:
#line 114 "yacc1.y"
{
                                //多个参数
		yyval.tn = create_tree("argument_expression_list",3,yyvsp[-2].tn,yyvsp[-1].tn,yyvsp[0].tn);
	;
    break;}
case 16:
#line 122 "yacc1.y"
{
		yyval.tn = create_tree("unary_expression",1,yyvsp[0].tn);
	;
    break;}
case 17:
#line 125 "yacc1.y"
{
		//++
		yyval.tn = create_tree("unary_expression",2,yyvsp[-1].tn,yyvsp[0].tn);
	;
    break;}
case 18:
#line 129 "yacc1.y"
{
		//--
		yyval.tn = create_tree("unary_expression",2,yyvsp[-1].tn,yyvsp[0].tn);
	;
    break;}
case 19:
#line 133 "yacc1.y"
{
		yyval.tn = create_tree("unary_expression",2,yyvsp[-1].tn,yyvsp[0].tn);
	;
    break;}
case 20:
#line 140 "yacc1.y"
{
		yyval.tn = create_tree("unary_operator",1,yyvsp[0].tn);
	;
    break;}
case 21:
#line 143 "yacc1.y"
{
		yyval.tn = create_tree("unary_operator",1,yyvsp[0].tn);
	;
    break;}
case 22:
#line 146 "yacc1.y"
{
		yyval.tn = create_tree("unary_operator",1,yyvsp[0].tn);
	;
    break;}
case 23:
#line 149 "yacc1.y"
{
		yyval.tn = create_tree("unary_operator",1,yyvsp[0].tn);
	;
    break;}
case 24:
#line 156 "yacc1.y"
{
		yyval.tn = create_tree("multiplicative_expression",1,yyvsp[0].tn);
	;
    break;}
case 25:
#line 159 "yacc1.y"
{
		yyval.tn = create_tree("multiplicative_expression",3,yyvsp[-2].tn,yyvsp[-1].tn,yyvsp[0].tn);
	;
    break;}
case 26:
#line 162 "yacc1.y"
{
		yyval.tn = create_tree("multiplicative_expression",3,yyvsp[-2].tn,yyvsp[-1].tn,yyvsp[0].tn);
	;
    break;}
case 27:
#line 165 "yacc1.y"
{
		yyval.tn = create_tree("multiplicative_expression",3,yyvsp[-2].tn,yyvsp[-1].tn,yyvsp[0].tn);
	;
    break;}
case 28:
#line 172 "yacc1.y"
{
		yyval.tn = create_tree("additive_expression",1,yyvsp[0].tn);
	;
    break;}
case 29:
#line 175 "yacc1.y"
{
		yyval.tn = create_tree("additive_expression",3,yyvsp[-2].tn,yyvsp[-1].tn,yyvsp[0].tn);
	;
    break;}
case 30:
#line 178 "yacc1.y"
{
		yyval.tn = create_tree("additive_expression",3,yyvsp[-2].tn,yyvsp[-1].tn,yyvsp[0].tn);
	;
    break;}
case 31:
#line 185 "yacc1.y"
{
		yyval.tn = create_tree("shift_expression",1,yyvsp[0].tn);
	;
    break;}
case 32:
#line 188 "yacc1.y"
{
		//<<
		yyval.tn = create_tree("shift_expression",3,yyvsp[-2].tn,yyvsp[-1].tn,yyvsp[0].tn);
	;
    break;}
case 33:
#line 192 "yacc1.y"
{
		//<<
		yyval.tn = create_tree("shift_expression",3,yyvsp[-2].tn,yyvsp[-1].tn,yyvsp[0].tn);
	;
    break;}
case 34:
#line 200 "yacc1.y"
{
		yyval.tn = create_tree("relational_expression",1,yyvsp[0].tn);
	;
    break;}
case 35:
#line 203 "yacc1.y"
{
		// <
		yyval.tn = create_tree("relational_expression",3,yyvsp[-2].tn,yyvsp[-1].tn,yyvsp[0].tn);
	;
    break;}
case 36:
#line 207 "yacc1.y"
{
		// > 
		yyval.tn = create_tree("relational_expression",3,yyvsp[-2].tn,yyvsp[-1].tn,yyvsp[0].tn);
	;
    break;}
case 37:
#line 211 "yacc1.y"
{
		// <= 
		yyval.tn = create_tree("relational_expression",3,yyvsp[-2].tn,yyvsp[-1].tn,yyvsp[0].tn);
	;
    break;}
case 38:
#line 215 "yacc1.y"
{
		// >=
		yyval.tn = create_tree("relational_expression",3,yyvsp[-2].tn,yyvsp[-1].tn,yyvsp[0].tn);
	;
    break;}
case 39:
#line 223 "yacc1.y"
{
		yyval.tn = create_tree("equality_expression",1,yyvsp[0].tn);
	;
    break;}
case 40:
#line 226 "yacc1.y"
{
		// ==
		yyval.tn = create_tree("equality_expression",3,yyvsp[-2].tn,yyvsp[-1].tn,yyvsp[0].tn);
	;
    break;}
case 41:
#line 230 "yacc1.y"
{
		// !=
		yyval.tn = create_tree("equality_expression",3,yyvsp[-2].tn,yyvsp[-1].tn,yyvsp[0].tn);
	;
    break;}
case 42:
#line 237 "yacc1.y"
{
		yyval.tn = create_tree("and_expression",1,yyvsp[0].tn);
	;
    break;}
case 43:
#line 240 "yacc1.y"
{
		yyval.tn = create_tree("and_expression",3,yyvsp[-2].tn,yyvsp[-1].tn,yyvsp[0].tn);
	;
    break;}
case 44:
#line 247 "yacc1.y"
{
		yyval.tn = create_tree("exclusive_or_expression",1,yyvsp[0].tn);
	;
    break;}
case 45:
#line 250 "yacc1.y"
{
		yyval.tn = create_tree("exclusive_or_expression",3,yyvsp[-2].tn,yyvsp[-1].tn,yyvsp[0].tn);
	;
    break;}
case 46:
#line 257 "yacc1.y"
{
		yyval.tn = create_tree("inclusive_or_expression",1,yyvsp[0].tn);
	;
    break;}
case 47:
#line 260 "yacc1.y"
{
		yyval.tn = create_tree("inclusive_or_expression",3,yyvsp[-2].tn,yyvsp[-1].tn,yyvsp[0].tn);
	;
    break;}
case 48:
#line 267 "yacc1.y"
{
		yyval.tn = create_tree("logical_and_expression",1,yyvsp[0].tn);
	;
    break;}
case 49:
#line 270 "yacc1.y"
{
		//&&
		yyval.tn = create_tree("logical_and_expression",3,yyvsp[-2].tn,yyvsp[-1].tn,yyvsp[0].tn);
	;
    break;}
case 50:
#line 278 "yacc1.y"
{
		yyval.tn = create_tree("logical_or_expression",1,yyvsp[0].tn);
	;
    break;}
case 51:
#line 281 "yacc1.y"
{
		//||
		yyval.tn = create_tree("logical_or_expression",3,yyvsp[-2].tn,yyvsp[-1].tn,yyvsp[0].tn);
	;
    break;}
case 52:
#line 289 "yacc1.y"
{
		//条件表达式
		yyval.tn = create_tree("assignment_expression",1,yyvsp[0].tn);
	;
    break;}
case 53:
#line 293 "yacc1.y"
{
		yyval.tn = create_tree("assignment_expression",3,yyvsp[-2].tn,yyvsp[-1].tn,yyvsp[0].tn);
	;
    break;}
case 54:
#line 300 "yacc1.y"
{
		yyval.tn = create_tree("assignment_operator",1,yyvsp[0].tn);
	;
    break;}
case 55:
#line 303 "yacc1.y"
{
		//*=
		yyval.tn = create_tree("assignment_operator",1,yyvsp[0].tn);
	;
    break;}
case 56:
#line 307 "yacc1.y"
{
		// /=
		yyval.tn = create_tree("assignment_operator",1,yyvsp[0].tn);
	;
    break;}
case 57:
#line 311 "yacc1.y"
{
		// %=
		yyval.tn = create_tree("assignment_operator",1,yyvsp[0].tn);
	;
    break;}
case 58:
#line 315 "yacc1.y"
{
		// += 
		yyval.tn = create_tree("assignment_operator",1,yyvsp[0].tn);
	;
    break;}
case 59:
#line 319 "yacc1.y"
{
		// -=
		yyval.tn = create_tree("assignment_operator",1,yyvsp[0].tn);
	;
    break;}
case 60:
#line 323 "yacc1.y"
{
		// <<=
		yyval.tn = create_tree("assignment_operator",1,yyvsp[0].tn);
	;
    break;}
case 61:
#line 327 "yacc1.y"
{
		// >>=
		yyval.tn = create_tree("assignment_operator",1,yyvsp[0].tn);
	;
    break;}
case 62:
#line 331 "yacc1.y"
{
		// &=
		yyval.tn = create_tree("assignment_operator",1,yyvsp[0].tn);
	;
    break;}
case 63:
#line 335 "yacc1.y"
{
		// ^=
		yyval.tn = create_tree("assignment_operator",1,yyvsp[0].tn);
	;
    break;}
case 64:
#line 339 "yacc1.y"
{
		// |=
		yyval.tn = create_tree("assignment_operator",1,yyvsp[0].tn);
	;
    break;}
case 65:
#line 347 "yacc1.y"
{
		//赋值表达式
		yyval.tn = create_tree("expression",1,yyvsp[0].tn);
	;
    break;}
case 66:
#line 351 "yacc1.y"
{
		//逗号表达式
		yyval.tn = create_tree("expression",3,yyvsp[-2].tn,yyvsp[-1].tn,yyvsp[0].tn);
	;
    break;}
case 67:
#line 359 "yacc1.y"
{
		yyval.tn = create_tree("declaration",2,yyvsp[-1].tn,yyvsp[0].tn); //?
	;
    break;}
case 68:
#line 362 "yacc1.y"
{
		yyval.tn = create_tree("declaration",3,yyvsp[-2].tn,yyvsp[-1].tn,yyvsp[0].tn);
	;
    break;}
case 69:
#line 369 "yacc1.y"
{
		yyval.tn = create_tree("init_declarator_list",1,yyvsp[0].tn);
	;
    break;}
case 70:
#line 372 "yacc1.y"
{
		yyval.tn = create_tree("init_declarator_list",3,yyvsp[-2].tn,yyvsp[-1].tn,yyvsp[0].tn);
	;
    break;}
case 71:
#line 378 "yacc1.y"
{
		yyval.tn = create_tree("init_declarator",1,yyvsp[0].tn);
	;
    break;}
case 72:
#line 381 "yacc1.y"
{
		yyval.tn = create_tree("init_declarator",3,yyvsp[-2].tn,yyvsp[-1].tn,yyvsp[0].tn);
	;
    break;}
case 73:
#line 389 "yacc1.y"
{
		yyval.tn = create_tree("type_specifier",1,yyvsp[0].tn);
	;
    break;}
case 74:
#line 392 "yacc1.y"
{
		yyval.tn = create_tree("type_specifier",1,yyvsp[0].tn);
	;
    break;}
case 75:
#line 395 "yacc1.y"
{
		yyval.tn = create_tree("type_specifier",1,yyvsp[0].tn);
	;
    break;}
case 76:
#line 398 "yacc1.y"
{
		yyval.tn = create_tree("type_specifier",1,yyvsp[0].tn);	
	;
    break;}
case 77:
#line 401 "yacc1.y"
{
		yyval.tn = create_tree("type_specifier",1,yyvsp[0].tn);
	;
    break;}
case 78:
#line 409 "yacc1.y"
{
		//变量
		yyval.tn = create_tree("declarator",1,yyvsp[0].tn);
	;
    break;}
case 79:
#line 413 "yacc1.y"
{
		//.....
		yyval.tn = create_tree("declarator",3,yyvsp[-2].tn,yyvsp[-1].tn,yyvsp[0].tn);
	;
    break;}
case 80:
#line 417 "yacc1.y"
{
		//数组
		//printf("assignment_expression");
		yyval.tn = create_tree("declarator",4,yyvsp[-3].tn,yyvsp[-2].tn,yyvsp[-1].tn,yyvsp[0].tn);
	;
    break;}
case 81:
#line 422 "yacc1.y"
{
		//....
		yyval.tn = create_tree("declarator",4,yyvsp[-3].tn,yyvsp[-2].tn,yyvsp[-1].tn,yyvsp[0].tn);
	;
    break;}
case 82:
#line 426 "yacc1.y"
{
		//数组
		yyval.tn = create_tree("declarator",3,yyvsp[-2].tn,yyvsp[-1].tn,yyvsp[0].tn);
	;
    break;}
case 83:
#line 430 "yacc1.y"
{
		//函数
		yyval.tn = create_tree("declarator",4,yyvsp[-3].tn,yyvsp[-2].tn,yyvsp[-1].tn,yyvsp[0].tn);
	;
    break;}
case 84:
#line 434 "yacc1.y"
{
		//函数
		yyval.tn = create_tree("declarator",4,yyvsp[-3].tn,yyvsp[-2].tn,yyvsp[-1].tn,yyvsp[0].tn);
	;
    break;}
case 85:
#line 438 "yacc1.y"
{
		//函数
		yyval.tn = create_tree("declarator",3,yyvsp[-2].tn,yyvsp[-1].tn,yyvsp[0].tn);
	;
    break;}
case 86:
#line 446 "yacc1.y"
{
		yyval.tn = create_tree("parameter_list",1,yyvsp[0].tn);
	;
    break;}
case 87:
#line 449 "yacc1.y"
{
		yyval.tn = create_tree("parameter_list",3,yyvsp[-2].tn,yyvsp[-1].tn,yyvsp[0].tn);
	;
    break;}
case 88:
#line 455 "yacc1.y"
{
		yyval.tn = create_tree("parameter_declaration",2,yyvsp[-1].tn,yyvsp[0].tn);
	;
    break;}
case 89:
#line 458 "yacc1.y"
{
		yyval.tn = create_tree("parameter_declaration",2,yyvsp[-1].tn,yyvsp[0].tn);
	;
    break;}
case 90:
#line 461 "yacc1.y"
{
		yyval.tn = create_tree("parameter_declaration",1,yyvsp[0].tn);
	;
    break;}
case 91:
#line 467 "yacc1.y"
{
		yyval.tn = create_tree("identifier_list",1,yyvsp[0].tn);
	;
    break;}
case 92:
#line 470 "yacc1.y"
{
		yyval.tn = create_tree("identifier_list",3,yyvsp[-2].tn,yyvsp[-1].tn,yyvsp[0].tn);
	;
    break;}
case 93:
#line 476 "yacc1.y"
{
		yyval.tn = create_tree("abstract_declarator",3,yyvsp[-2].tn,yyvsp[-1].tn,yyvsp[0].tn);
	;
    break;}
case 94:
#line 479 "yacc1.y"
{
		yyval.tn = create_tree("abstract_declarator",2,yyvsp[-1].tn,yyvsp[0].tn);
	;
    break;}
case 95:
#line 482 "yacc1.y"
{
		yyval.tn = create_tree("abstract_declarator",3,yyvsp[-2].tn,yyvsp[-1].tn,yyvsp[0].tn);
	;
    break;}
case 96:
#line 485 "yacc1.y"
{
		yyval.tn = create_tree("abstract_declarator",3,yyvsp[-2].tn,yyvsp[-1].tn,yyvsp[0].tn);
	;
    break;}
case 97:
#line 488 "yacc1.y"
{
		yyval.tn = create_tree("abstract_declarator",4,yyvsp[-3].tn,yyvsp[-2].tn,yyvsp[-1].tn,yyvsp[0].tn);
	;
    break;}
case 98:
#line 491 "yacc1.y"
{
		yyval.tn = create_tree("abstract_declarator",3,yyvsp[-2].tn,yyvsp[-1].tn,yyvsp[0].tn);
	;
    break;}
case 99:
#line 494 "yacc1.y"
{
		yyval.tn = create_tree("abstract_declarator",4,yyvsp[-3].tn,yyvsp[-2].tn,yyvsp[-1].tn,yyvsp[0].tn);
	;
    break;}
case 100:
#line 497 "yacc1.y"
{
		yyval.tn = create_tree("abstract_declarator",2,yyvsp[-1].tn,yyvsp[0].tn);
	;
    break;}
case 101:
#line 500 "yacc1.y"
{
		yyval.tn = create_tree("abstract_declarator",3,yyvsp[-2].tn,yyvsp[-1].tn,yyvsp[0].tn);
	;
    break;}
case 102:
#line 503 "yacc1.y"
{
		yyval.tn = create_tree("abstract_declarator",3,yyvsp[-2].tn,yyvsp[-1].tn,yyvsp[0].tn);
	;
    break;}
case 103:
#line 506 "yacc1.y"
{
		yyval.tn = create_tree("abstract_declarator",4,yyvsp[-3].tn,yyvsp[-2].tn,yyvsp[-1].tn,yyvsp[0].tn);
	;
    break;}
case 104:
#line 513 "yacc1.y"
{
		yyval.tn = create_tree("initializer",1,yyvsp[0].tn);
	;
    break;}
case 105:
#line 516 "yacc1.y"
{
		//列表初始化 {1,1,1}
		yyval.tn = create_tree("initializer",3,yyvsp[-2].tn,yyvsp[-1].tn,yyvsp[0].tn);
	;
    break;}
case 106:
#line 520 "yacc1.y"
{
		//列表初始化 {1,1,1,}
		yyval.tn = create_tree("initializer",4,yyvsp[-3].tn,yyvsp[-2].tn,yyvsp[-1].tn,yyvsp[0].tn);
	;
    break;}
case 107:
#line 527 "yacc1.y"
{
		yyval.tn = create_tree("initializer_list",1,yyvsp[0].tn);
	;
    break;}
case 108:
#line 530 "yacc1.y"
{
		yyval.tn = create_tree("initializer_list",2,yyvsp[-1].tn,yyvsp[0].tn);
	;
    break;}
case 109:
#line 533 "yacc1.y"
{
		yyval.tn = create_tree("initializer_list",3,yyvsp[-2].tn,yyvsp[-1].tn,yyvsp[0].tn);
	;
    break;}
case 110:
#line 536 "yacc1.y"
{
		yyval.tn = create_tree("initializer_list",3,yyvsp[-3].tn,yyvsp[-2].tn,yyvsp[-1].tn);
	;
    break;}
case 111:
#line 542 "yacc1.y"
{
		yyval.tn = create_tree("designation",2,yyvsp[-1].tn,yyvsp[0].tn);
	;
    break;}
case 112:
#line 548 "yacc1.y"
{
		yyval.tn = create_tree("designator_list",1,yyvsp[0].tn);
	;
    break;}
case 113:
#line 551 "yacc1.y"
{
		yyval.tn = create_tree("designator_list",2,yyvsp[-1].tn,yyvsp[0].tn);
	;
    break;}
case 114:
#line 557 "yacc1.y"
{
		yyval.tn = create_tree("designator",3,yyvsp[-2].tn,yyvsp[-1].tn,yyvsp[0].tn);
	;
    break;}
case 115:
#line 560 "yacc1.y"
{
		yyval.tn = create_tree("designator",2,yyvsp[-1].tn,yyvsp[0].tn);
	;
    break;}
case 116:
#line 567 "yacc1.y"
{
		//标签
		yyval.tn = create_tree("statement",1,yyvsp[0].tn);
	;
    break;}
case 117:
#line 571 "yacc1.y"
{
		//复合
		yyval.tn = create_tree("statement",1,yyvsp[0].tn);
	;
    break;}
case 118:
#line 575 "yacc1.y"
{
		//表达式
		yyval.tn = create_tree("statement",1,yyvsp[0].tn);
	;
    break;}
case 119:
#line 579 "yacc1.y"
{
		//分支
		yyval.tn = create_tree("statement",1,yyvsp[0].tn);
	;
    break;}
case 120:
#line 583 "yacc1.y"
{
		//循环
		yyval.tn = create_tree("statement",1,yyvsp[0].tn);
	;
    break;}
case 121:
#line 587 "yacc1.y"
{
		//跳转
		yyval.tn = create_tree("statement",1,yyvsp[0].tn);
	;
    break;}
case 122:
#line 595 "yacc1.y"
{
		yyval.tn = create_tree("labeled_statement",3,yyvsp[-2].tn,yyvsp[-1].tn,yyvsp[0].tn);
	;
    break;}
case 123:
#line 598 "yacc1.y"
{
		yyval.tn = create_tree("labeled_statement",4,yyvsp[-3].tn,yyvsp[-2].tn,yyvsp[-1].tn,yyvsp[0].tn);
	;
    break;}
case 124:
#line 605 "yacc1.y"
{
		yyval.tn = create_tree("compound_statement",2,yyvsp[-1].tn,yyvsp[0].tn);
	;
    break;}
case 125:
#line 608 "yacc1.y"
{
		yyval.tn = create_tree("compound_statement",3,yyvsp[-2].tn,yyvsp[-1].tn,yyvsp[0].tn);
	;
    break;}
case 126:
#line 614 "yacc1.y"
{
		yyval.tn = create_tree("block_item_list",1,yyvsp[0].tn);
	;
    break;}
case 127:
#line 617 "yacc1.y"
{
		yyval.tn = create_tree("block_item_list",2,yyvsp[-1].tn,yyvsp[0].tn);
	;
    break;}
case 128:
#line 623 "yacc1.y"
{
		yyval.tn = create_tree("block_item",1,yyvsp[0].tn);
	;
    break;}
case 129:
#line 626 "yacc1.y"
{
		yyval.tn = create_tree("block_item",1,yyvsp[0].tn);
	;
    break;}
case 130:
#line 632 "yacc1.y"
{
		yyval.tn = create_tree("expression_statement",1,yyvsp[0].tn);
	;
    break;}
case 131:
#line 635 "yacc1.y"
{
		yyval.tn = create_tree("expression_statement",2,yyvsp[-1].tn,yyvsp[0].tn);
	;
    break;}
case 132:
#line 642 "yacc1.y"
{
		yyval.tn = create_tree("selection_statement",5,yyvsp[-4].tn,yyvsp[-3].tn,yyvsp[-2].tn,yyvsp[-1].tn,yyvsp[0].tn);
	;
    break;}
case 133:
#line 645 "yacc1.y"
{
		yyval.tn = create_tree("selection_statement",7,yyvsp[-6].tn,yyvsp[-5].tn,yyvsp[-4].tn,yyvsp[-3].tn,yyvsp[-2].tn,yyvsp[-1].tn,yyvsp[0].tn);
	;
    break;}
case 134:
#line 648 "yacc1.y"
{
		yyval.tn = create_tree("selection_statement",5,yyvsp[-4].tn,yyvsp[-3].tn,yyvsp[-2].tn,yyvsp[-1].tn,yyvsp[0].tn);
	;
    break;}
case 135:
#line 655 "yacc1.y"
{
		yyval.tn = create_tree("iteration_statement",5,yyvsp[-4].tn,yyvsp[-3].tn,yyvsp[-2].tn,yyvsp[-1].tn,yyvsp[0].tn);
	;
    break;}
case 136:
#line 658 "yacc1.y"
{
		yyval.tn = create_tree("iteration_statement",7,yyvsp[-6].tn,yyvsp[-5].tn,yyvsp[-4].tn,yyvsp[-3].tn,yyvsp[-2].tn,yyvsp[-1].tn,yyvsp[0].tn);
	;
    break;}
case 137:
#line 661 "yacc1.y"
{
		yyval.tn = create_tree("iteration_statement",6,yyvsp[-5].tn,yyvsp[-4].tn,yyvsp[-3].tn,yyvsp[-2].tn,yyvsp[-1].tn,yyvsp[0].tn);
	;
    break;}
case 138:
#line 664 "yacc1.y"
{
		yyval.tn = create_tree("iteration_statement",7,yyvsp[-6].tn,yyvsp[-5].tn,yyvsp[-4].tn,yyvsp[-3].tn,yyvsp[-2].tn,yyvsp[-1].tn,yyvsp[0].tn);
	;
    break;}
case 139:
#line 667 "yacc1.y"
{
		yyval.tn = create_tree("iteration_statement",6,yyvsp[-5].tn,yyvsp[-4].tn,yyvsp[-3].tn,yyvsp[-2].tn,yyvsp[-1].tn,yyvsp[0].tn);
	;
    break;}
case 140:
#line 670 "yacc1.y"
{
		yyval.tn = create_tree("iteration_statement",7,yyvsp[-6].tn,yyvsp[-5].tn,yyvsp[-4].tn,yyvsp[-3].tn,yyvsp[-2].tn,yyvsp[-1].tn,yyvsp[0].tn);
	;
    break;}
case 141:
#line 677 "yacc1.y"
{
		yyval.tn = create_tree("jump_statement",2,yyvsp[-2].tn,yyvsp[-1].tn);
	;
    break;}
case 142:
#line 680 "yacc1.y"
{
		yyval.tn = create_tree("jump_statement",2,yyvsp[-1].tn,yyvsp[0].tn);
	;
    break;}
case 143:
#line 683 "yacc1.y"
{
		yyval.tn = create_tree("jump_statement",2,yyvsp[-1].tn,yyvsp[0].tn);
	;
    break;}
case 144:
#line 686 "yacc1.y"
{
		yyval.tn = create_tree("jump_statement",2,yyvsp[-1].tn,yyvsp[0].tn);
	;
    break;}
case 145:
#line 689 "yacc1.y"
{
		yyval.tn = create_tree("jump_statement",3,yyvsp[-2].tn,yyvsp[-1].tn,yyvsp[0].tn);
	;
    break;}
case 146:
#line 695 "yacc1.y"
{
		yyval.tn = create_tree("translation_unit",1,yyvsp[0].tn);
	;
    break;}
case 147:
#line 698 "yacc1.y"
{
		yyval.tn = create_tree("translation_unit",2,yyvsp[-1].tn,yyvsp[0].tn);
	;
    break;}
case 148:
#line 704 "yacc1.y"
{
		yyval.tn = create_tree("external_declaration",1,yyvsp[0].tn);
	;
    break;}
case 149:
#line 707 "yacc1.y"
{
		yyval.tn = create_tree("external_declaration",1,yyvsp[0].tn);
	;
    break;}
case 150:
#line 713 "yacc1.y"
{
		yyval.tn = create_tree("function_definition",4,yyvsp[-3].tn,yyvsp[-2].tn,yyvsp[-1].tn,yyvsp[0].tn);
	;
    break;}
case 151:
#line 716 "yacc1.y"
{
		yyval.tn = create_tree("function_definition",3,yyvsp[-2].tn,yyvsp[-1].tn,yyvsp[0].tn);
	;
    break;}
case 152:
#line 722 "yacc1.y"
{
		yyval.tn = create_tree("declaration_list",1,yyvsp[0].tn);
	;
    break;}
case 153:
#line 725 "yacc1.y"
{
		yyval.tn = create_tree("declaration_list",2,yyvsp[-1].tn,yyvsp[0].tn);
	;
    break;}
}
   /* the action file gets copied in in place of this dollarsign */
#line 543 "/usr/local/share/bison.simple"

  yyvsp -= yylen;
  yyssp -= yylen;
#ifdef YYLSP_NEEDED
  yylsp -= yylen;
#endif

#if YYDEBUG != 0
  if (yydebug)
    {
      short *ssp1 = yyss - 1;
      fprintf (stderr, "state stack now");
      while (ssp1 != yyssp)
	fprintf (stderr, " %d", *++ssp1);
      fprintf (stderr, "\n");
    }
#endif

  *++yyvsp = yyval;

#ifdef YYLSP_NEEDED
  yylsp++;
  if (yylen == 0)
    {
      yylsp->first_line = yylloc.first_line;
      yylsp->first_column = yylloc.first_column;
      yylsp->last_line = (yylsp-1)->last_line;
      yylsp->last_column = (yylsp-1)->last_column;
      yylsp->text = 0;
    }
  else
    {
      yylsp->last_line = (yylsp+yylen-1)->last_line;
      yylsp->last_column = (yylsp+yylen-1)->last_column;
    }
#endif

  /* Now "shift" the result of the reduction.
     Determine what state that goes to,
     based on the state we popped back to
     and the rule number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTBASE] + *yyssp;
  if (yystate >= 0 && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTBASE];

  goto yynewstate;

yyerrlab:   /* here on detecting error */

  if (! yyerrstatus)
    /* If not already recovering from an error, report this error.  */
    {
      ++yynerrs;

#ifdef YYERROR_VERBOSE
      yyn = yypact[yystate];

      if (yyn > YYFLAG && yyn < YYLAST)
	{
	  int size = 0;
	  char *msg;
	  int x, count;

	  count = 0;
	  /* Start X at -yyn if nec to avoid negative indexes in yycheck.  */
	  for (x = (yyn < 0 ? -yyn : 0);
	       x < (sizeof(yytname) / sizeof(char *)); x++)
	    if (yycheck[x + yyn] == x)
	      size += strlen(yytname[x]) + 15, count++;
	  msg = (char *) malloc(size + 15);
	  if (msg != 0)
	    {
	      strcpy(msg, "parse error");

	      if (count < 5)
		{
		  count = 0;
		  for (x = (yyn < 0 ? -yyn : 0);
		       x < (sizeof(yytname) / sizeof(char *)); x++)
		    if (yycheck[x + yyn] == x)
		      {
			strcat(msg, count == 0 ? ", expecting `" : " or `");
			strcat(msg, yytname[x]);
			strcat(msg, "'");
			count++;
		      }
		}
	      yyerror(msg);
	      free(msg);
	    }
	  else
	    yyerror ("parse error; also virtual memory exceeded");
	}
      else
#endif /* YYERROR_VERBOSE */
	yyerror("parse error");
    }

  goto yyerrlab1;
yyerrlab1:   /* here on error raised explicitly by an action */

  if (yyerrstatus == 3)
    {
      /* if just tried and failed to reuse lookahead token after an error, discard it.  */

      /* return failure if at end of input */
      if (yychar == YYEOF)
	YYABORT;

#if YYDEBUG != 0
      if (yydebug)
	fprintf(stderr, "Discarding token %d (%s).\n", yychar, yytname[yychar1]);
#endif

      yychar = YYEMPTY;
    }

  /* Else will try to reuse lookahead token
     after shifting the error token.  */

  yyerrstatus = 3;		/* Each real token shifted decrements this */

  goto yyerrhandle;

yyerrdefault:  /* current state does not do anything special for the error token. */

#if 0
  /* This is wrong; only states that explicitly want error tokens
     should shift them.  */
  yyn = yydefact[yystate];  /* If its default is to accept any token, ok.  Otherwise pop it.*/
  if (yyn) goto yydefault;
#endif

yyerrpop:   /* pop the current state because it cannot handle the error token */

  if (yyssp == yyss) YYABORT;
  yyvsp--;
  yystate = *--yyssp;
#ifdef YYLSP_NEEDED
  yylsp--;
#endif

#if YYDEBUG != 0
  if (yydebug)
    {
      short *ssp1 = yyss - 1;
      fprintf (stderr, "Error: state stack now");
      while (ssp1 != yyssp)
	fprintf (stderr, " %d", *++ssp1);
      fprintf (stderr, "\n");
    }
#endif

yyerrhandle:

  yyn = yypact[yystate];
  if (yyn == YYFLAG)
    goto yyerrdefault;

  yyn += YYTERROR;
  if (yyn < 0 || yyn > YYLAST || yycheck[yyn] != YYTERROR)
    goto yyerrdefault;

  yyn = yytable[yyn];
  if (yyn < 0)
    {
      if (yyn == YYFLAG)
	goto yyerrpop;
      yyn = -yyn;
      goto yyreduce;
    }
  else if (yyn == 0)
    goto yyerrpop;

  if (yyn == YYFINAL)
    YYACCEPT;

#if YYDEBUG != 0
  if (yydebug)
    fprintf(stderr, "Shifting error token, ");
#endif

  *++yyvsp = yylval;
#ifdef YYLSP_NEEDED
  *++yylsp = yylloc;
#endif

  yystate = yyn;
  goto yynewstate;

 yyacceptlab:
  /* YYACCEPT comes here.  */
  if (yyfree_stacks)
    {
      free (yyss);
      free (yyvs);
#ifdef YYLSP_NEEDED
      free (yyls);
#endif
    }
  return 0;

 yyabortlab:
  /* YYABORT comes here.  */
  if (yyfree_stacks)
    {
      free (yyss);
      free (yyvs);
#ifdef YYLSP_NEEDED
      free (yyls);
#endif
    }
  return 1;
}
#line 730 "yacc1.y"



void yyerror(char const *s)
{
	fflush(stdout);
	printf("\n%*s\n%*s\n", column, "^", column, s);
}


int main(int argc,char* argv[]) {
	yyin = fopen(argv[1],"r");
	yyparse();
	printf("\n");
	/*eval(root,0);*/	//输出语法分析树
	Praser praser(root); //进行中间代码生成
	fclose(yyin);
	ToObject tbj(praser);
	freetreeNode(root); //释放空间
	return 0;
}