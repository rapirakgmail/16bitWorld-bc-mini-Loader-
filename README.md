# dos-SimpleLoader
simple loader on dos 

1. SIMPLELD.C is a sample program that simulates the functionality of the DOS operating system.
This program supports COM files only. (the source code using Borland C (version 3.x).

Example command:
  bcc simpleld.c

------------------------------------------------------------------------------------------------


2. APP2.C is a simple C program designed to serve as a sample application. The program must be converted into a .COM file before it can be used with the loader. The process consists of the following steps:

1. Compile the Source Code
Use a DOS-based C compiler such as Borland C 3.1 to compile APP2.C into a standard EXE (Executable) file.
Example:
  bcc app2.c
This will generate APP2.EXE.

2. Convert the EXE to COM Format
   This is done using tools such as EXE2BIN, or by manually stripping the EXE header (in case of custom or low-level workflows).
Example using DOS utility:
  exe2bin app2.exe app2.com
