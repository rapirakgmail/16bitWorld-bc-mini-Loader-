# dos-SimpleLoader
simple loader on dos 

SIMPLELD.C is a sample program that simulates the functionality of the DOS operating system.
This program supports COM files only.

The process of creating the program is as follows:

Write and compile the source code using Borland C (version 3.x) to generate an executable file (EXE).
Example command:
  bcc simpleld.c




APP2.C – Sample Application for Loader Simulation
Overview
APP2.C is a simple C program designed to serve as a sample application that is loaded and executed by a custom loader module, such as the one implemented in SIMPLELD.C. This example demonstrates how a COM-format program can be prepared and run in a DOS-like environment.

Purpose
The purpose of APP2.C is to simulate a real-mode DOS .COM file that is loaded into memory and executed by a minimal loader. It is useful for testing the correctness and behavior of the loader logic.

Build Process
The program must be converted into a .COM file before it can be used with the loader. The process consists of the following steps:

1. Compile the Source Code
Use a DOS-based C compiler such as Borland C 3.1 to compile APP2.C into a standard EXE (Executable) file.

Example:
bcc app2.c
This will generate APP2.EXE.

2. Convert the EXE to COM Format
Since .COM files are required by the loader, the EXE file must be converted to the simpler COM format. This is done using tools such as EXE2BIN, or by manually stripping the EXE header (in case of custom or low-level workflows).

Example using DOS utility:
exe2bin app2.exe app2.com
