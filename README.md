# Thread Library

A small cooperative user-level thread library written in C using `ucontext`.

## Build

```bash
make
```

This creates `libthreads.a`.

## Run an example

```bash
gcc -Wall -Iinclude examples/test1.c -L. -lthreads -o test1
./test1
```

## Clean

```bash
make clean
```

## Structure

* `include/` — public headers
* `src/` — thread, scheduler, and queue implementation
* `examples/` — test programs

## Current Features

* User-level threads
* Cooperative scheduling
* Context switching with `ucontext`
* Thread yield and exit
* FIFO ready queue

The library is currently cooperative, so threads explicitly call `thread_yield()` to give up the CPU.
