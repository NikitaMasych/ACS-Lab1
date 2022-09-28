# Morning!

Project implemented as laboratory work for architecture of computational systems.

Measures computational possibilities of the system.

# Project structure:
```
.
├── cmd
├── headers
│   ├── stats.hpp
│   ├── timer.hpp
│   └── warmup.hpp
├── makefile
├── object
│   ├── stats.o
│   ├── timer.o
│   └── warmup.o
├── README.md
├── src
│   ├── main.cpp
│   ├── stats.cpp
│   ├── timer.cpp
│   └── warmup.cpp
└── templates
    └── tests.ipp

```
# Technology choice explanation:

As far as C++ is a great fit for writing embedded-based application is had been chozen for developing this project. It is strongly-typed and provides immensive toolset. As a result system is preferably faster and has spectacular level of control over the types and operations.

# Preview:

After launched and done required measurements, in console window appears statistics table. 
First column contains operation, next variable type, operations/sec for specified type and operation, then relative linear diagram with respect to the maximum value of op/sec and percetage rate accordingly.

```
![http://url/to/img.png](https://github.com/NikitaMasych/ACS-Lab1/blob/main/docs/ACS-Lab1-results.png)
```

# Diagnostic results:

Tests launched on debian-based system with Intel Core i5 Tiger Lake processor and x64-bit little-endian architecture have shown that the most operation per second is achieved using "int" type and multiplication/substraction. Worst results are "long long"'s prerogative with division operation. As per floating point types, are noticeable slightly faster op/sec for x32 bit "float" over x64 "double" per addition, substraction, multiplication and significant difference per division.
