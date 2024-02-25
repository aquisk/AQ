// Copyright 2024 AQ authors, All Rights Reserved.
// This program is licensed under the AQ License. You can find the AQ license in
// the root directory.

#ifndef AQ_COMPILE_COMPILE_H_
#define AQ_COMPILE_COMPILE_H_

namespace Aq {
class Compiler {
 public:
  Compiler(const char* filename);
  ~Compiler();

 private:
  char* buffer_ptr_;

  class Lexer;
  template <typename T>
  class LexMap;

  struct Token;
  class TokenMap;

  class Parser;

  class FuncDecl;
  class Expr;
  class Stmt;
  class Type;
};
}  // namespace Aq

#endif  // AQ_COMPILE_H_