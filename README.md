# Syntax Analyzer (Parser)

![parser](https://user-images.githubusercontent.com/44123278/117787489-12bb8c00-b279-11eb-846b-b76dd352d5dc.png)

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



## Debug Command and Operation

Make Makefile
```
$ make clean && make
```

Execute
```
$ ./myparser < input/in01_arithmetic.c > output/in01.out
```

Judge
```
python3 judge/judge.py -v 1
```



## Important Concepts and Note

  - Always becareful the **precedence line** of ``ADD`` ``SUB`` and ``MUL`` ``QUO`` ``REM``. Don't mess up, otherwise your arithmetic will go wrong.
  - The deeper syntax tree will be executed and the syntax grammar will execute in **Leftmost**. If you need to print anything before ``expression``, then create another branch tree to make that tokens operation can be executed and print relating message immediately.
  - Remmeber to pass **return value** back to previous syntax tree level. Otherwise your syntax tree won't work properly with return value. E.g. ``$$ = $1`` or ``$$ = $$``
  - Go through ``symbol table`` with linked-list is recommended in the following part of ``compiler_hw3``.



## Environment Setup

  - Ubuntu 20.04.2LTS
  - Install dependencies: ``$ sudo apt install gcc flex bison python3 git``



## Related Work and References

  - https://github.com/Howeng98/CompilerHW1#11-tokens-that-will-be-passed-to-the-parser
  - https://github.com/Howeng98/schoolWorks/tree/master/compiler_construction
