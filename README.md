# advpl-language-server-cxx
C++ Implementation of the Language Server Protocol for ADVPL

# Steps to build:

This project depends on the following libraries:
### [Boost](www.boost.org)

To install configure boost visit:
 * [Windows](http://www.boost.org/doc/libs/1_66_0/more/getting_started/windows.html)
 * [Linux/Mac](http://www.boost.org/doc/libs/1_66_0/more/getting_started/unix-variants.html)

### [Antlr](www.antlr.org)
 Download the latest version of runtime Complete ANTLR.
 Create a directory, for example:
 
 > c:\antlr4
 
  and save .jar in this folder.

### Install the latest version of [Cmake](https://cmake.org/download/)

# Language Client
Enter in client folder, and run:

>npm install

To run the Language Client you must have installed the vscode-adpvl extension

Open vscode :
> code .

Open extension.ts, configure your lsPath to correctly directory:

>const lsPath = "C:/Totvs/vscode/c_version/advpl-language-server-cxx/build/Debug/advpl-language-server-cxx.exe"

Run Build Task inside vscode.
Run extensions debug, open workspace with advpl sources and open one.

# Vscode Extensions
If you're to develop in vscode itself, the following extensions can help you.

* C/C++ (Microsoft)
* CMake (twxs)
* CMake Tools (vector-of-bool)

# This project was based on the CLANG LS

https://github.com/llvm-mirror/clang-tools-extra/tree/master/clangd