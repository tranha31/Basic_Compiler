/* 
 * @copyright (c) 2008, Hedspi, Hanoi University of Technology
 * @author Huu-Duc Nguyen
 * @version 1.0
 */

#include <stdlib.h>
#include <ctype.h>
#include "token.h"

struct {
  char string[MAX_IDENT_LEN + 1];
  TokenType tokenType;
} 
keywords[KEYWORDS_COUNT] = {
  {"Program", KW_PROGRAM},
  {"Const", KW_CONST},
  {"Type", KW_TYPE},
  {"Var", KW_VAR},
  {"Integer", KW_INTEGER},
  {"Char", KW_CHAR},
  {"Array", KW_ARRAY},
  {"Of", KW_OF},
  {"Function", KW_FUNCTION},
  {"Procedure", KW_PROCEDURE},
  {"Begin", KW_BEGIN},
  {"End", KW_END},
  {"Call", KW_CALL},
  {"If", KW_IF},
  {"Then", KW_THEN},
  {"Else", KW_ELSE},
  {"While", KW_WHILE},
  {"Do", KW_DO},
  {"For", KW_FOR},
  {"To", KW_TO}
};

int keywordEq(char *kw, char *string) {
  while ((*kw != '\0') && (*string != '\0')) {
    if (*kw != *string) break;
    kw ++; string ++;
  }
  return ((*kw == '\0') && (*string == '\0'));
}

TokenType checkKeyword(char *string) {
  int i;
  for (i = 0; i < KEYWORDS_COUNT; i++)
    if (keywordEq(keywords[i].string, string)) 
      return keywords[i].tokenType;
  return TK_NONE;
}

Token* makeToken(TokenType tokenType, int lineNo, int colNo) {
  Token *token = (Token*)malloc(sizeof(Token));
  token->tokenType = tokenType;
  token->lineNo = lineNo;
  token->colNo = colNo;
  return token;
}
