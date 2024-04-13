// Copyright 2024 AQ authors, All Rights Reserved.
// This program is licensed under the AQ License. You can find the AQ license in
// the root directory.

#ifndef AQ_COMPILE_COMPILE_H_
#define AQ_COMPILE_COMPILE_H_

#include <cstddef>

namespace Aq {
/// \class Compiler
/// \brief Compile the file to bytecode
class Compiler {
 public:
  /// \fn Compiler
  /// \brief compile the file
  /// \param filename const char* Type
  Compiler(const char* filename);
  ~Compiler();

 private:
  /// \brief The source code to be analyzed.
  char* buffer_ptr_;

  /// \class Lexer
  /// \brief The `Lexer` class performs the first stage of a compiler's
  /// processing pipeline: lexical analysis. It takes raw source code as input
  /// and transforms it into a sequence of meaningful tokens, which serve as the
  /// input for subsequent stages, such as parsing.
  /// \details
  /// - **Input**: The lexer accepts source code written in a specific
  /// programming language, usually provided as a character stream or an input
  /// file.
  /// - **Tokenization**: It scans the input character-by-character, identifying
  /// and categorizing lexemes (sequences of characters with a distinct meaning)
  /// according to the language's syntax rules. These lexemes are then converted
  /// into discrete tokens, each consisting of a token type (e.g., identifier,
  /// keyword, operator, literal) and an optional associated value.
  class Lexer;

  /// \class Parser
  /// \brief The `Parser` class constitutes the second phase of a compiler or
  /// interpreter's processing pipeline, following lexical analysis. Its primary
  /// responsibility is to construct an Abstract Syntax Tree (AST) from the
  /// token stream produced by the `Lexer`.
  /// \details
  /// - **Input**: The parser receives a well-formed sequence of tokens,
  /// typically generated by a `Lexer` instance, representing the analyzed
  /// source code.
  /// - **Syntax Analysis**: It applies context-free grammar rules defined for
  /// the target programming language to validate the token sequence's
  /// structural correctness. This involves recognizing higher-level language
  /// constructs (such as expressions, statements, blocks, and declarations),
  /// ensuring they adhere to the prescribed syntactic organization.
  class Parser;

  /// \class SymbolTable
  /// \brief The `SymbolTable` class maintains a collection of symbols
  /// (variables, functions, and other objects) and their associated scopes.
  /// \details - **Input**: The symbol table accepts a sequence of tokens,
  /// typically generated by a `Lexer` instance, representing the analyzed
  /// source code.
  /// - **Syntax Analysis**: It applies context-free grammar rules defined for
  /// the target programming language to validate the token sequence's
  /// structural correctness. This involves recognizing higher-level language
  /// constructs (such as expressions, statements, blocks, and declarations),
  /// ensuring they adhere to the prescribed syntactic organization.
  class SymbolTable;

  /// \class Pair
  /// \brief The `Pair` template class encapsulates two heterogeneous objects,
  /// `T1` and `T2`, into a single entity. It serves as a convenient way to
  /// associate and manipulate two related values together, especially when
  /// there is no inherent hierarchical relationship between them.
  /// \details
  /// - **Template Parameters**:
  ///   - `T1`: The type of the first component (or "first" value) of the pair.
  ///   - `T2`: The type of the second component (or "second" value) of the
  ///   pair.
  /// - **Member Variables**:
  ///   - `first`: An instance of type `T1`, representing the first component of
  ///   the pair.
  ///   - `second`: An instance of type `T2`, representing the second component
  ///   of the pair.
  /// - **Construction**: Pairs can be constructed explicitly by specifying both
  /// `T1` and `T2` values, or implicitly through type inference when
  /// initializing with an initializer list or brace-enclosed values.
  /// - **Accessors**: The individual components of the pair can be accessed
  /// directly via the public `first` and `second` members.
  /// \tparam T1 The type of the first value stored in the pair.
  /// \tparam T2 The type of the second value stored in the pair.
  template <typename T1, typename T2>
  struct Pair;

  /// \class HashTable
  /// \brief Stores ValueType in hash table
  /// \details
  /// - **Key Type**: The key is of type `std::string`, allowing string-based
  /// lookup for stored elements.
  /// - **Value Type**: The value associated with each key is of the template
  /// parameter type `ValueType`.
  ///   Users can instantiate `HashTable` with any desired value type to suit
  ///   their specific use case.
  /// - **Hash-Based Storage**: Internally, the class employs a hash table
  /// implementation
  ///   to store and organize key-value pairs. Hashing ensures constant-time
  ///   average complexity for most operations, making `HashTable` particularly
  ///   suitable for large datasets where fast access is crucial.
  /// - **Operations**:
  ///   - **Insertion**: New key-value pairs can be inserted into the table
  ///   using appropriate member functions.
  ///   - **Retrieval**: Given a key, users can efficiently retrieve the
  ///   corresponding value.
  ///   - **Deletion**: Individual entries or entire ranges of entries can be
  ///   removed from the table.
  ///   - **Iteration**: The container supports iteration over its elements,
  ///   enabling traversal or modification of all stored key-value pairs.
  /// \tparam ValueType
  template <typename ValueType>
  class HashTable;

  /// \class LinkedList
  /// \brief The `LinkedList` template class implements a linear collection of
  /// nodes, where each node contains a value of type `DataType` and one or two
  /// pointers to adjacent nodes. Linked lists offer dynamic size, efficient
  /// insertion/deletion at arbitrary positions, and sequential access to
  /// elements.
  /// \details
  /// - **Template Parameter**:
  ///   - `DataType`: The type of the data stored in each node of the list.
  /// - **Node Structure**:
  ///   - Depending on whether the list is singly or doubly linked, nodes
  ///   contain a `DataType` value and either one (`next`) or two (`next` and
  ///   `prev`) pointers to other nodes.
  /// - **Methods**:
  ///   - **Construction/Destruction**: The list can be created empty or
  ///   initialized with a range of elements. Destruction recursively frees all
  ///   nodes in the list.
  ///   - **Element Access**:
  ///     - `Size()`: Returns the number of elements in the list.
  ///   - **Modifiers**:
  ///     - `Insert()`, `Remove()`: Inserts/Removes elements at arbitrary
  ///     positions.
  ///     - `Clear()`: Removes all elements from the list.
  ///   - **Traversal/Iteration**: Supports forward iteration over elements
  ///   using iterators or ranged-for loops.
  /// - **Performance Characteristics**:
  ///   - **Time Complexity**:
  ///     - Accessing an element by index: O(n)
  ///     - Insertion/Deletion at beginning/end: O(1) (amortized)
  ///     - Insertion/Deletion at arbitrary position: O(n)
  ///     - Traversal: O(n)
  /// \tparam DataType The type of the data stored in each node of the linked
  /// list.
  template <typename DataType>
  class LinkedList;

  /// \class DynamicArray
  /// \brief The `DynamicArray` template class provides a contiguous memory
  /// \details 
  /// - **Template Parameter**:
  ///   - `T`: The type of the data stored in the dynamic array.
  /// - **Memory Management**:
  ///   - The array internally manages its own memory, automatically growing or
  ///   shrinking as needed to accommodate changes in the number of stored
  ///   elements.
  /// - **Methods**:
  ///   - **Construction/Destruction**: The array can be created with an initial
  ///   capacity or default-constructed with zero elements. Destruction releases
  ///   the underlying memory.
  ///   - **Size**:
  ///     - `size()`: Returns the current number of elements in the array.
  ///   - **Element Access**:
  ///     - `operator[]`: Allows direct read/write access to elements by index
  ///     (bounds-checked in debug builds).
  ///   - **Modifiers**:
  ///     - `insert()`, `remove()`: Inserts/Removes elements at arbitrary
  ///     positions, shifting subsequent elements as needed.
  template <typename T>
  class DynamicArray;

  /// \class DynArray
  /// \brief The `DynArray` template class provides a contiguous memory buffer
  /// capable of holding elements of type `ArrayType`. It combines the
  /// performance benefits of traditional arrays (constant-time random access)
  /// with the flexibility of dynamically resizing to accommodate varying
  /// numbers of elements.
  /// \details
  /// - **Template Parameter**:
  ///   - `ArrayType`: The type of the data stored in the dynamic array.
  /// - **Memory Management**:
  ///   - The array internally manages its own memory, automatically growing or
  ///   shrinking as needed to accommodate changes in the number of stored
  ///   elements.
  /// - **Methods**:
  ///   - **Construction/Destruction**: The array can be created with an initial
  ///   capacity or default-constructed with zero elements. Destruction releases
  ///   the underlying memory.
  ///   - **Size**:
  ///     - `Size()`: Returns the current number of elements in the array.
  ///   - **Element Access**:
  ///     - `operator[]`: Allows direct read/write access to elements by index
  ///     (bounds-checked in debug builds).
  ///   - **Modifiers**:
  ///     - `Insert()`, `Remove()`: Inserts/Removes elements at arbitrary
  ///     positions, shifting subsequent elements as needed.
  ///     - `Resize()`: Explicitly sets the number of elements in the array,
  ///     either truncating or appending default-constructed elements.
  ///     - `Clear()`: Removes all elements from the array, resetting its size
  ///     to zero.
  ///   - **Iterators**: Supports bidirectional iteration over elements using
  ///   iterator or ranged-for loops.
  /// - **Performance Characteristics**:
  ///   - **Time Complexity**:
  ///     - Accessing an element by index: O(1)
  ///     - Insertion/Deletion at end: amortized O(1)
  ///     - Insertion/Deletion at arbitrary position: O(n)
  ///     - Traversal: O(n)
  /// \tparam ArrayType The type of the data stored in the dynamic array.
  template <typename ArrayType>
  class DynArray;

  /// \class TokenMap
  /// \brief The `TokenMap` class serves as an efficient data structure for
  /// associating unique tokens, typically strings or integer values
  /// representing lexemes in the source code,
  /// with their corresponding token kinds. This mapping is crucial for
  /// compilers, interpreters, and other language processing tools that require
  /// quick lookups of token types during lexical analysis or parsing stages.
  class TokenMap;

  /// \class Token
  /// \brief Stores token information
  class Token;

  /// \class Ast
  /// \brief Stores ast information
  class Ast;
};
}  // namespace Aq

#endif  /// AQ_COMPILE_H_