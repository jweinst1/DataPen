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

Since a DataBlock is a pure array of bytes, you can write data blocks into other blocks, allowing for un-typed binary formatting.

```c++

DataBlock<3> foo;
foo[0] = 66;
foo[1] = 33;
foo[2] = 77;

DataBlock<6> parent;
parent.write(foo);
parent.print();
```

And the result is

```
[ 66 33 77 0 0 0 ]
```


## License

`DataPen` is MIT licensed.
