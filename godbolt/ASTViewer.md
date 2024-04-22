# AST Viewer

Under Add Pane, choose `AST`.

Mouse over the source code to highlight the relevant section of the AST.

C++:
```cpp
int popcount(int n) {
    int count = 0;
    while (n) {
        n &= (n - 1); // clear the least significant bit set
        count++;
    }
    return count;
}
```

AST:
```
TranslationUnitDecl
|-UsingDirectiveDecl <line:20:1, col:17> col:17 Namespace 0xce59558 'std'
`-FunctionDecl <line:22:1, line:29:1> line:22:5 popcount 'int (int)'
  |-ParmVarDecl <col:14, col:18> col:18 used n 'int'
  `-CompoundStmt <col:21, line:29:1>
    |-DeclStmt <line:23:5, col:18>
    | `-VarDecl <col:5, col:17> col:9 used count 'int' cinit
    |   `-IntegerLiteral <col:17> 'int' 0
    |-WhileStmt <line:24:5, line:27:5>
    | |-ImplicitCastExpr <line:24:12> 'bool' <IntegralToBoolean>
    | | `-ImplicitCastExpr <col:12> 'int' <LValueToRValue>
    | |   `-DeclRefExpr <col:12> 'int' lvalue ParmVar 0x11e4ad50 'n' 'int'
    | `-CompoundStmt <col:15, line:27:5>
    |   |-CompoundAssignOperator <line:25:9, col:20> 'int' lvalue '&=' ComputeLHSTy='int' ComputeResultTy='int'
    |   | |-DeclRefExpr <col:9> 'int' lvalue ParmVar 0x11e4ad50 'n' 'int'
    |   | `-ParenExpr <col:14, col:20> 'int'
    |   |   `-BinaryOperator <col:15, col:19> 'int' '-'
    |   |     |-ImplicitCastExpr <col:15> 'int' <LValueToRValue>
    |   |     | `-DeclRefExpr <col:15> 'int' lvalue ParmVar 0x11e4ad50 'n' 'int'
    |   |     `-IntegerLiteral <col:19> 'int' 1
    |   `-UnaryOperator <line:26:9, col:14> 'int' postfix '++'
    |     `-DeclRefExpr <col:9> 'int' lvalue Var 0x11e4aef0 'count' 'int'
    `-ReturnStmt <line:28:5, col:12>
      `-ImplicitCastExpr <col:12> 'int' <LValueToRValue>
        `-ImplicitCastExpr <col:12> 'int' xvalue <NoOp>
          `-DeclRefExpr <col:12> 'int' lvalue Var 0x11e4aef0 'count' 'int'
```
