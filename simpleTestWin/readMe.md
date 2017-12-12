## Simple Mutex Test in Windows

This code shows a simple mutex implementation in Windows
My GCC version 5.3.0 was having issues with std::mutex and std::thread,
so I have used MSVC instead

First two threads are launched with Mutex protection while next two threads are alunched without mutex
