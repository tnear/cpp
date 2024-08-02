# LLVM IR

Under "Add a new pane" in compilation settings, choose `LLVM IR`.

LLVM IR is *simpler* than assembly. It has a smaller instruction set. It has infinite registers/variables. It does not manage a FLAGS register. Additionally, it has explicit data types.

## Basic example
```llvm
define i64 @fib(i64) local_unnamed_addr #0 {
    %2 = icmp slt i64 %0, 2
    br i1 %2, label %9, label %3

    ; <label>:3:
    %4 = add nws i64 %0, -1
    %5 = tail call i64 @fib(i64 %4)
    %6 = add nws i64 %0, -2
    %7 = tail call i64 @fib(i64 %6)
    %8 = add nws i64 %7, %5
    ret i64 %8

    ; <label>:9:
    ret i64 %0
}
```

### Function
`@fib(i64)` means that the function above is called `fib` and accepts one input argument of type `int64`.

### Registers
- `%0`, `%1`, `%2`, ...: LLVM IR registers. Similar to variables.

### Data types
- `i64`: 64-bit signed integer
- `i1`: 1-bit integer (bool)
- `i16*`: pointer to 16-bit integer
- `[5 x i32]`: array of 5 integers
- Struct: `{ <type>, ... }`
- Vector: `< <number> x <type> >`

### Function calls
```llvm
%4 = add nws i64 %0, -1 ; this subtracts 1 from %0 and assigns to 4
%5 = tail call i64 @fib(i64 %4) ; this calls %5 = fib(%4)
```

## Aggregate type
Aggregate types are stored in memory instead of registers. An example of an aggregate type is an array or struct.

Accessing the aggregate type involves computing an address then reading or writing memory.

```c
int A[7]; // create an array of 7 integers
A[x];     // get Xth element of array A
```

Corresponding LLVM IR:
```llvm
; this line computes an address and stores it in %5
%5 = getelementptr inbounds [7 x i32], [7 x i32] * %2, i64 0, i64 %4

; this line takes that address (in %5) and stores the value in %6
%6 = load i32, i32* %5, align 4
```

### getelementptr
```
%5 = getelementptr [7 x i32], [7 x i32] * %2, i64 0, i64 %4
a                     b                   c      d       e
```

- a = output
- b = array size
- c = pointer to memory
- d = index
- e = index

`address = %2 + 0 + %4`.

## Basic blocks
The body of a function definition is partitioned into *basic blocks*. These are sequences of instructions where control only enters through the first instruction and only exits from the last.

Control flow instructions (such as the conditional branch instruction, `br`) create control-flow edges between the basic blocks of a function. This creates a control-flow graph (CFG).

## Static single assignment (SSA)
LLVM maintains the SSA invariant: every variable is assigned exactly once.

This invariant makes it easier for compilers to understand and process source code. The `phi` instruction is special handling of situations where a variable could have different values depending on the path taken.

## Common instructions
- `icmp`: integer comparison
- `br`: conditional branch. Ex: `br i1 %2, label %3, label %4`
    - This checks the boolean (`i1`) in register `%2`. If it's true, go to label `%3`. Otherwise, to go label `%4`.
- `ret`: return. Ex: `ret i64 %0` returns an `i64` in register `%0`.
- `phi`: see below

### `phi` instruction
Consider this `for` loop:
`for (int i = 0; i < n; ++i)`.

This creates this `phi` instruction:
`%9 = phi i64 [%14, %8], [0, %6]`.

There are two sets of brackets. For `[0, %6]`, it means that if execution came from basic block `%6`, assign the value of 0 to the output register `%9`. Basic block `%6` (not shown) is the entry point to the function. It initializes `i` to 0.

For `[%14, %8]`, it means that if execution came from basic block `%8`, assign value from register `%14`. The `for` loop belongs to BB `%8`, so this is jumping back to itself. The increment of register `%14` is done farther down which jumps back to the phi instruction.

## Attributes
- `nsw`: no signed wrap. Applies to integer operations which do not overflow. Allows compiler to optimize more aggressively.
- `align 4`: operation is 4-bit aligned
- `noalias`: corresponds to `restrict` keyword
- `readonly`: corresponds to `const` keyword

## Resources
- https://youtu.be/wt7a5BOztuM
