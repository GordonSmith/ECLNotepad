// Scintilla source code edit control
/** @file LexECL.h
 ** Lexer for ECL.
 ** 2012/01/12 Initial implementation
 **/
// Copyright 2003-2012 by HPCC Systems <gordon.smith@lexisnexis.com>
// The License.txt file describes the conditions under which this software may be distributed.

#ifndef LEXECL_H
#define LEXECL_H

#include "SciLexer.h"

#define SCLEX_ECL SCLEX_AUTOMATIC
#define SCE_ECL_DEFAULT 0
#define SCE_ECL_FIRST SCE_ECL_DEFAULT
#define SCE_ECL_COMMENT 1
#define SCE_ECL_COMMENTLINE 2
#define SCE_ECL_NUMBER 3
#define SCE_ECL_STRING 4
#define SCE_ECL_WORD0 5
#define SCE_ECL_OPERATOR 6
#define SCE_ECL_CHARACTER 7
#define SCE_ECL_UUID 8
#define SCE_ECL_PREPROCESSOR 9
#define SCE_ECL_UNKNOWN 10
#define SCE_ECL_IDENTIFIER 11
#define SCE_ECL_STRINGEOL 12
#define SCE_ECL_VERBATIM 13
#define SCE_ECL_REGEX 14
#define SCE_ECL_COMMENTLINEDOC 15
#define SCE_ECL_WORD1 16
#define SCE_ECL_COMMENTDOCKEYWORD 17
#define SCE_ECL_COMMENTDOCKEYWORDERROR 18
#define SCE_ECL_WORD2 19
#define SCE_ECL_WORD3 20
#define SCE_ECL_WORD4 21
#define SCE_ECL_WORD5 22
#define SCE_ECL_COMMENTDOC 23
#define SCE_ECL_ADDED 24
#define SCE_ECL_DELETED 25
#define SCE_ECL_CHANGED 26
#define SCE_ECL_MOVED 27
#define SCE_ECL_LAST SCE_ECL_MOVED

#endif
