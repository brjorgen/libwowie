
# Table of Contents

1.  [Libwowie : 'Cause f\*ck it, You need a lib with this stuff anyways.](#org72f29d2)
2.  [What's in there?](#orgd3b1e43)
3.  [What's being worked on?](#org13399c4)
4.  [How to extend this lib](#org0502b8a)
    1.  [Code your own stuff - HMU on twitter if you think it's worth telling me about 🤓](#orgc314794)



<a id="org72f29d2"></a>

# Libwowie : 'Cause f\*ck it, You need a lib with this stuff anyways.

Sheer laziness is what inspired this. Aren't you tired of having to implement a bunch
of stuff you could just have at your fingertips with a single #include?


<a id="orgd3b1e43"></a>

# What's in there?

-   Data structures
    -   Linked Lists
    -   Stacks
    -   Linked-List powered Stacks (lstacks)
    -   B-Trees
    -   Binary Heaps
    -   Hashmaps (crc32)
-   Singleton buffers
-   Memory manipulation
-   String manipulation
-   A generic error interface
-   Search functions
-   <stdint.h> Type conversions
-   Linear algebra library (BSVL)

Most of these have accompanying test suites.


<a id="org13399c4"></a>

# What's being worked on?

see [module\_name]/todo.org


<a id="org0502b8a"></a>

# How to extend this lib


<a id="orgc314794"></a>

## Code your own stuff - HMU on twitter if you think it's worth telling me about 🤓

1.  Implement your extension & its Makefile (ideally with a rule for building a test binary).
2.  Implement it's error() stuff.
3.  Add it to the master Makefile.
4.  Recompile.

