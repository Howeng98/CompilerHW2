# Syntax Analyzer (Parser)

This assignment is aim to build a ``parser`` for the μC language that supports print IO, arithmetic operations and some basic constructs for C with ``yacc``. At here, I'm doing build the code to analyze these tokens and check the syntax validity based on the given grammar rules as follow.

  - Define tokens and types
  - Design μC Grammar and implement the related actions
  - Handle semantic errors

## Structure

Types refers to one of the μC variables types: ``integer``, ``float``, ``string``, and ``boolean``. Useful tips for defining a type are listed below.

  - Define a type for ``yylval`` using ``%union`` by yourself. For example, ``%union { int i_val; }`` means ``yylval`` is able to be accessed via the ``int`` type using the ``i_val`` variable.
  - Define a type for token using ``%type`` and give the type name like ``<`` and ``>``.
