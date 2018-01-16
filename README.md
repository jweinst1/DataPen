# DataPen

*A C++ library for writing and reading streamed, dynamically typed data*

## Intro

`DataPen` is a C++ header library that contains several tools and utility classes to write and read objects in pure bytes. It allows objects to be used similarly to how `void*` are used in C, or simply for having a more type-free environment in C++.

## Usage

To use DataPen, just include the header files into your C++ project.

To make the test executable, in your terminal run `make all`

You can then run the tests by using the command

```
$ ./bin/DataPen
```

## Guide

`DataPen` contains several collection and container classes for handling binary data. The first of those is the `DataBlock`.

### DataBlock:

The DataBlock class holds a  "block" of bytes that are sized via a template. They can be written and read to much like a file. An Example,

```c++

DataBlock<4> block;
int i = 3;
block.write(i);

```

## License

`DataPen` is MIT licensed.
