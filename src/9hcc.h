#include <stdbool.h>

// error.c
void error_at(char *loc, char *fmt, ...);
void error(char *fmt, ...);

// parse.c

// enums / types
typedef enum {
  TK_RESERVED,
  TK_NUM,
  TK_EOF,
} TokenKind;

typedef struct Token Token;

struct Token {
  TokenKind kind;
  Token *next;
  int val;
  char *str;
  int len;
};

// prototypes difinitions
bool consume(char* op);
void expect(char *op);
int expect_number();
bool at_eof();
Token *new_token(TokenKind kind, Token *cur, char *str, int len);

Token *tokenize(char *p);

// codegen

// enums / types
typedef enum {
  ND_EQ,  // ==
  ND_NEQ, // !=
  ND_LT,  // <
  ND_LE,  // <=
  ND_ADD, // +
  ND_SUB, // -
  ND_MUL, // *
  ND_DIV, // /
  ND_NUM, // [1-9]*
} NodeKind;

typedef struct Node Node;

struct Node {
  NodeKind kind;
  Node *lhs;
  Node *rhs;
  int val;
};

// ebnf prototype definitions
Node *expr();
Node *mul();
Node *unary();
Node *primary();

// node manipulators definitions
Node *new_node(NodeKind kind, Node *lhs, Node *rhs);
Node *new_node_num(int val);

void gen(Node *node);

// debug.c
void debug_tokenized(Token *token);

// global variables

extern Token *token;
extern Node *node;
extern char *user_input;