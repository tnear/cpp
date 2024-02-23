# Clang-Tidy

In the assembly view, click the `Add tool` dropdown button and add `clang-tidy (trunk)`.

In the `Arguments` section, add flags such as: `--checks=modernize-*,performance-*`

## Example
*https://godbolt.org/z/q8xGTvqG1*

```cpp
int func(vector<int> v)
{
    int result = 0;
    for (vector<int>::iterator it = v.begin();
        it != v.end(); ++it)
    {
        result += *it;
    }

    return result;
}
```

Output:

```
<source>:22:5: warning: use a trailing return type for this function [modernize-use-trailing-return-type]
   22 | int func(vector<int> v)
      | ~~~ ^                  
      | auto                    -> int
<source>:25:5: warning: use range-based for loop instead [modernize-loop-convert]
   25 |     for (vector<int>::iterator it = v.begin();
      |     ^   ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
      |         (int & it : v)
   26 |         it != v.end(); ++it)
      |         ~~~~~~~~~~~~~~~~~~~~
   27 |     {
   28 |         result += *it;
      |                   ~~~
      |                   it
<source>:25:10: warning: use auto when declaring iterators [modernize-use-auto]
   25 |     for (vector<int>::iterator it = v.begin();
      |          ^
note: this fix will not be applied because it overlaps with another fix
19376 warnings generated.
Suppressed 19373 warnings (19373 in non-user code).
Use -header-filter=.* to display errors from all non-system headers. Use -system-headers to display errors from system headers as well.
```
