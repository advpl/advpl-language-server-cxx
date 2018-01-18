grammar Advpl;
sources 
	:
	 linePreProcessor;
     
linePreProcessor : '#LINE' NUMBER STRING CRLF 
;



//-----------------------------------------------    
// tokens
//-----------------------------------------------
MINOR 	: '<';
MAJOR	: '>';
EQUALS	: '=';
MINOREQUALS 	: '<=';
MAJOREQUALS		: '>=';
DOUBLEEQUAL : '==';
DIF1	: '!=';
DIF2	: '<>';
DIF3	: '#';
CONTIDO : '$';
PLUSPLUS            : '++';
MINUSMINUS           : '--';
PLUSEQUALS 			: '+=';    
PLUS            : '+';
MINUS           : '-';    
MULT            : '*';
DIV             : '/';
POW				: '**';
PERC            : '%';
ARROBA          : '@';
ECOMERCIAL      : '&';
BEGIN			: 'BEGIN';
TRANSACTION : 	'TRANSACTION';
SEQUENCE	:	'SEQUENCE';    
BEGIN_SQL       : 'BEGINSQL' .*? 'ENDSQL'  -> channel(HIDDEN);
ALIASACCESS     :       '->';
STEP		:	'STEP';    
TO		:	'TO';    
TRUE		:	'.T.';
FALSE		:	'.F.';	
NIL             :       'NIL';
DEFINE			:	'#DEFINE';
UNDEFINE			:	'#UNDEF';
IFDEF           :       '#IFDEF';
IFNDEF          :       '#IFNDEF';

ELSEDEF         :       '#ELSE';
ENDIFDEF        :       '#ENDIF';

FOR		:	'FOR';
NEXT		:	'NEXT';
WHILE		:	'WHILE';
DO              :       'DO';
ELSEIF		:	'ELSEIF';
IF		:	'IF';
ELSE		:	'ELSE';
ENDI		:	'ENDI';
ENDIF		:	'ENDIF';
ENDIF_DOT		:	'ENDIF.';
//END_IF          :       'END IF';
ENDDO           :       'ENDDO';
ENDFOR           :       'ENDFOR';
END		:	'END';
EXTENDED	:	'EXTENDED';
CASE		:	'CASE';
ENDCASE		:	'ENDCASE';
OTHERWISE	:	'OTHERWISE';
EXIT		:	'EXIT';
LOOP		:	'LOOP';
LOCA		:	'LOCA';
LOCAL		:	'LOCAL';
PRIVATE		:	'PRIVATE';
PUBLIC		:	'PUBLIC';
STATIC		:	'STATIC';
USER		:	'USER';
WEB			:	'WEB';
MAIN		:	'MAIN';
FUNCTION	:	'FUNCTION';
FUNCTIO		:	'FUNCTIO';
PROCEDURE	: 	'PROCEDURE';
SELF		:	'SELF';
PROJECT		:   'PROJECT';
TEMPLATE	:	'TEMPLATE';
AND		:	'.AND.';
OR		:	'.OR.';
NOT		:	'.NOT.';

DEFAULT		:	'DEFAULT';

RETURN		:	'RETURN';
ASSUME          :       'ASSUME';
CLASS           :       'CLASS';
ENDCLASS        :       'ENDCLASS';
METHOD          :       'METHOD';
DATA            :       'DATA';
FROM            :       'FROM';
C_HIDDEN		:		'HIDDEN';
READONLY		:		'READONLY';
//WSSTRUCT		:		'WSSTRUCT';
//ENDWSSTRUCT		:		'ENDWSSTRUCT';
//WSCLIENT        :       'WSCLIENT';
//WSSERVICE       :       'WSSERVICE';
//NAMESPACE       :       'NAMESPACE';
//ENDWSCLIENT     :       'ENDWSCLIENT';
//ENDWSSERVICE    :       'ENDWSSERVICE';
//WSRESTFUL       :       'WSRESTFUL';
//FORMAT          :       'FORMAT';
//WSMETHOD        :       'WSMETHOD';
//WSDATA          :       'WSDATA';
//WSRECEIVE       :       'WSRECEIVE';
//WSSEND          :       'WSSEND';
DESCRIPTION     :       'DESCRIPTION';
QSSTRUCT 		: 		'QSSTRUCT';
QSMETHOD 		: 		'QSMETHOD';
MODULE	 		: 		'MODULE';
INIT	 		: 		'INIT';
AS              :       'AS';
OF              :       'OF';
PRODUCES        :       'PRODUCES';
OPTIONAL        :       'OPTIONAL';
//WSSYNTAX        :       'WSSYNTAX';
//RESPONSE        :       'RESPONSE';
REQUEST         :       'REQUEST';
QUERYPARAM      :       'QUERYPARAM';
WSREST          :       'WSREST';
CAMELCASE       :       'CAMELCASE';
PATHPARAM       :       'PATHPARAM';
GET				:		'GET';
POST			:		'POST';
PUT				:		'PUT';
DELETE			:		'DELETE';
BYREF			:		'BYREF';
//BEGIN           :       'BEGIN';
//BIRT
DATASET			: 		'DATASET';
PROCESS			:		'PROCESS';	
//COLUMNS			:		'COLUMNS';
//COLUMN			:		'COLUMN';
TITLE			:		'TITLE';
PERGUNTE		:		'PERGUNTE';
PATH			:		'PATH';
//COMMAND			:	'#COMMAND';
//XCOMMAND		:	'#XCOMMAND';

LPAREN	: '(' ;

RPAREN	: ')'  ;

LBRACK	: '['  ;

RBRACK	: ']'  ;
INCLUDE	:	'#''INCLUDE';

COMMA		:	',';
DOT			:	'.';
ATTRIB_OPERATOR
	:	':=';

NUMBER
    :   ('0'..'9')+ ('.'  ('0'..'9')+ )?
    |   '.' ('0'..'9')+ 
    ;

   
fragment
DIGITS : ( '0' .. '9' )+ ;

    
IDENTIFIER	:	( 'a' .. 'z' | 'A' .. 'Z' | '_')
        ( 'a' .. 'z' | 'A' .. 'Z' | '_' | '0' .. '9' )* ;
   

COMMENT
    :   '/*' .*? '*/'  -> channel(HIDDEN)
    ;
LINE_COMMENT:   '//' ~('\n'|'\r')*  -> channel(HIDDEN);
LINE_COMMENT_EE:   '&&' ~('\n'|'\r')*  -> channel(HIDDEN);
LINE_COMMENT_BIZARRO:   '*Ú' ~('\n'|'\r')*  -> channel(HIDDEN);
LINE_COMMENT_BIZARRO2:   '*³' ~('\n'|'\r')*  -> channel(HIDDEN);
LINE_COMMENT_BIZARRO3:   '*À' ~('\n'|'\r')*  -> channel(HIDDEN);
LINE_COMMENT_BIZARRO4:   '*--' ~('\n'|'\r')*  -> channel(HIDDEN);
LINE_COMMENT_BIZARRO5:   '*/' ~('\n'|'\r')*  -> channel(HIDDEN);
LINE_COMMENT_BIZARRO6:   '*==' ~('\n'|'\r')*  -> channel(HIDDEN);
LINE_COMMENT_BIZARRO7:   '*#' ~('\n'|'\r')*  -> channel(HIDDEN);


ASTERICO:
	'*' '*'*;
   
STRING
    :  '"' ( ~('"'|'\n') )* '"'?
    ;
STRINGSIMPLE
    :  '\'' (  ~('\''|'\n') )* '\''?
    ;
//------------------------------------------------------------
//Em davpl o CRLF ajuda a determina o fim dos expression

crlf:
        (CRLF+|';');
crlfEmpty:
        (CRLF+|';');
CRLF
  : ((('\r')? '\n' ))  
  ;

WS  :   ( ' ' | '\t')+  -> skip;
INVALID_CHAR : '�' -> skip;
INVALID_CHAR_1 : '' -> skip;
INVALID_CHAR_2 : ' ' -> skip;
INVALID_CHAR_3 :'\u0001' -> skip;
INVALID_CHAR_4 :'\u0002' -> skip;
INVALID_CHAR_14 :'\u0003' -> skip;
INVALID_CHAR_17 :'\u001f' -> skip;
INVALID_CHAR_5 :'§' -> skip;
INVALID_CHAR_6 :'¢' -> skip;
INVALID_CHAR_7 :'£' -> skip;
INVALID_CHAR_8 :'À' -> skip;
INVALID_CHAR_9 :'ß' -> skip;
INVALID_CHAR_10 :'±' -> skip;
INVALID_CHAR_11 :'Ä' -> skip;
INVALID_CHAR_12 :'Á' -> skip;
INVALID_CHAR_13 :'Ù' -> skip;
INVALID_CHAR_16 :'`' -> skip;
INVALID_CHAR_18 :'»' -> skip;
INVALID_CHAR_19 :'¿' -> skip;


/*
 * Quando le o ppo não tem mais ; como escaped
CRLF_ESCAPED
  : (';' ( ' ' | '\t')*(  ('//'|'&&') ~('\n'|'\r')*   )? ('\r')?'\n' )-> channel(HIDDEN);
  
  *  
  */
/*
CRLF_ESCAPED
  : (DOT_COMA  ('\r')?'\n')-> skip;
*/
ErrorChar
   : .
   ;