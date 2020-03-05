PYC: C and Python ctypes function call and callback example

Overview
---

Python to native C function call, and C to Python callbacks, without
boilerplate (e.g. without using CPython). Compatible with both Python 2 and 3.

In src/ there is the source code for the dynamic library (example), and in
the test/ a Python script that calls to C functions, and a case where the C
code calls back to Python.

Build
---

```
./bootstrap.sh
./configure
make
make check
```

Check results manually
---

cd test
./test   # or python test.py
