# Syntax Analyzer (Parser)

This assignment is aim to build a ``parser`` for the μC language that supports print IO, arithmetic operations and some basic constructs for C with ``yacc``. At here, I'm doing build the code to analyze these tokens and check the syntax validity based on the given grammar rules as follow.

  - Define tokens and types
  - Design μC Grammar and implement the related actions
  - Handle semantic errors

## Structure

Types refers to one of the μC variables types: ``integer``, ``float``, ``string``, and ``boolean``. Useful tips for defining a type are listed below.

  - Define a type for ``yylval`` using ``%union`` by yourself. For example, ``%union { int i_val; }`` means ``yylval`` is able to be accessed via the ``int`` type using the ``i_val`` variable.
  - Define a type for token using ``%type`` and give the type name like ``<`` and ``>``.

## What can this Parser do

  1. Handle arithmetic operations,where brackets and precedence should be considered.
  2. Implement the scoping check fnction in the parser.
  3. Handle the declarations and operations for the array type.
  4. Support the variants of the assignment operators.
  5. Handle the type conversion between integer and floating-point.
  6. Supports if statements.
  7. Support for statements.
  8. Detect semantic error and show the error message. The parser should show atleast the error type and the line number.  
