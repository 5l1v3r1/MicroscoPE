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

PIMAGE_DOS_HEADER dHeader; //For DOS header


PIMAGE_NT_HEADERS pHeader; //PE header
PIMAGE_FILE_HEADER fHeader; //File Header
PIMAGE_OPTIONAL_HEADER oHeader; //Optional Header
PIMAGE_SECTION_HEADER sHeader; //Section Header

PIMAGE_DOS_HEADER header; //Header
