#include <Windows.h>
#include <iostream>
#include <stdio.h>
/*
  +----------------+
  |  MS-DOS Header |
  |    MZ Header   |
  +----------------+
  |MS-DOS Real-Mode|
  |  Stub Program  |
  |----------------+
  |    Pe File     |
  |   Signature    |
  +----------------+
  | PE File Header |
  +----------------+                      |Export Table
  |File's Optional |  <-------------------+Import Table
  |     Header     |                      |Resource Table
  +----------------+                      |Exception handling table
  | .text Section  |                      |Other...
  |     Header     |
  +----------------+
  |  .bss Section  |
  |     Header     |
  +----------------+
  |       +        |   <----- Section Table
  |       +        |
  |       +        |
  +----------------+
  | .debug Section |
  |     Header     |
  +----------------+
  | .text Section  |
  +----------------+
  |  .bss Section  |
  +----------------+
  |       +        |   <----- Other sections
  |       +        |
  |       +        |
  +----------------+
  | .debug Section |
  +----------------+
*/

HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE); //For Console Color


HANDLE hFile;
HANDLE hFileMapping;
LPVOID lpFileBase;
