# Abstract:

Project implemented as laboratory work for architecture of computational systems.

Measures computational possibilities of the system.
 
Uses multiple tests' reduction to the average for achieving better accuracy.

Pre-test stage also include simple warmup function call in order to stabilise first addition measurements.

Makefile contains instructions for disabling compilers optimization.

Manually overviewed assembly ensures functions intentions (screenshots are available in the docs/).

# Project structure:
```
.
├── code
│   ├── cmd
│   ├── headers
│   │   ├── stats.hpp
│   │   ├── timer.hpp
│   │   └── warmup.hpp
│   ├── makefile
│   ├── src
│   │   ├── main.cpp
│   │   ├── stats.cpp
│   │   ├── timer.cpp
│   │   └── warmup.cpp
│   └── templates
│       └── tests.ipp
├── Dockerfile
├── docs
│   ├── ACS-Lab1-results.png
│   ├── ClassicOPs.png
│   ├── DoubleAdditionClassic.png
│   ├── DoubleAdditionInline.png
│   ├── EmptyBody.png
│   ├── InlineOPs.png
│   ├── PureOPs.png
│   ├── WithAssignment.png
│   └── WithO3.png
├── main.cpp
└── README.md

```
# Docker and deployment:
```
$ docker build -t acs-lab1 . --network host
$ docker run -v $(pwd)/code:/code -it acs-lab1
bash# cd /code
bash# make launch
```
# Technology choice explanation:

As far as C++ is a great fit for writing embedded-based application is had been chozen for developing this project. It is strongly-typed and provides immensive toolset. As a result system is preferably faster and has spectacular level of control over the types and operations.

# Preview:

After launched and done required measurements, in console window appears statistics table. 
First column contains operation, next variable type, operations/sec for specified type and operation, then relative linear diagram with respect to the maximum value of op/sec and percetage rate accordingly.

![http://url/to/img.png](https://github.com/NikitaMasych/ACS-Lab1/blob/main/docs/Results.png)


# Diagnostic results:

Tests launched on debian-based system with Intel Core i5 Tiger Lake processor and x64-bit little-endian architecture have shown that the most operation per second is achieved using "int" type and addition/substraction/multiplication. Worst results are "long long"'s prerogative with division operation. As per floating point types, are slightly faster op/sec for x32 bit "float" over x64 "double" per addition, substraction, multiplication and significant difference per division.

# Error explanation:

Tests' convergence highly depends on current launched processes in the system, hence smallest change affects the results.

# Accuracy improment:

In order to achieve highter tests consistency, it is recommended to increase multiple tests count and operations per cycle.
