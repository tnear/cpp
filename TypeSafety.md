# Type Safety

Type safety in C++ ensures data types are being used in intended ways. It helps prevent errors that can occur when data of one type is incorrectly interpreted as another type, leading to unpredictable behavior, security vulnerabilities, and software crashes. Type safety mechanisms help detect type mismatches at compile time, reducing runtime errors.

## Strong typing
C++ checks types during compilation. Certain invalid usages require an explicit cast.

## Const correctness
The `const` keyword prevents accidental changes to data that should remain constant.

## Dynamic type checking
Dynamic type checking (through `dynamic_cast`) can verify the type of objects at runtime, particularly in the context of polymorphism.

## Templates
Templates allow writing generic and type-safe code without needing void pointers.

## Scoped enumerations
Scoped enumerations provide a strongly-typed alternative to traditional C-style enumerations, preventing implicit conversions to integer types and clashes in the global namespace.

## `new` keyword
The `new` keyword returns the type being allocated, as opposed to `malloc` which returns a void pointer.