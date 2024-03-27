# Smart pointers

## unique_ptr
- Manages a single object and does not allow copying, ensuring exclusive ownership of the object it points to.
- Ownership can be transferred to another `unique_ptr` through move semantics.
- When the `unique_ptr` goes out of scope, the object it manages is destroyed.
- Useful for resources that require unique ownership semantics, like file handles or exclusive access to devices.

## shared_ptr
- Manages an object through a control block which has a reference count. This allows multiple `shared_ptr` to point to the same object.
- The object is destroyed when the last `shared_ptr` referencing it is destroyed or reset.
- Can lead to circular dependencies and memory leaks if not used carefully (e.g., two `shared_ptr` objects pointing to each other).
- Useful for resources that are shared across different parts of an application.

## weak_ptr
- `weak_ptr` complements `shared_ptr` by holding a non-owning (weak) reference to an object that is managed by `shared_ptr`.
- Does not participate in the reference count of `shared_ptr`, so it does not prevent the object from being destroyed.
- Can be converted to a `shared_ptr` to gain temporary ownership and access the object, if it still exists.
- Useful for breaking circular dependencies among `shared_ptr` objects.
