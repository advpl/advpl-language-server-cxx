# advpl-language-server-cxx
C++ Implementation of the Language Server Protocol for ADVPL

# Developers

  ## Contributing

   Check the [contribution guide](/CONTRIBUTING.md)

   ### Linux

   1. [(Ref)](https://duckduckgo.com/?q=build-essential) Install build-essential
   1. [(Ref)](https://cmake.org/cmake/help/v3.9/) Install CMake 3.9+
   1. [(Ref)](https://www.git-scm.com/docs/git-clone) Clone the repository
   1. [(Ref)](https://www.gnu.org/software/make/manual/make.html) Run make
   1. [(Ref)](http://www.boost.org/doc/libs/1_66_0/libs/test/doc/html/index.html) Run tests

   Example on a Debian system:

   ```bash
   $ sudo apt-get install build-essential
   $ sudo apt-get install cmake
   $ git clone https://github.com/advpl/advpl-language-server-cxx
   $ cd advpl-language-server-cxx
   $ cmake .
   $ make
   $ make test
   ```

   ### Windows

   This project depends on the following libraries:

   #### [Boost](http://www.boost.org/)

   #### [Antlr](http://www.antlr.org)

   #### Install the latest version of [Cmake](https://cmake.org/download/)

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
