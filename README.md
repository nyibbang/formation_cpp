# INGIMA C++ formation

## Sessions

* Test Driven Development - 3 sessions - June 2017
* C++11/14/17, Design Patterns and Multithreading - 2 sessions - February 2018
* Mastering C++11 - 2 sessions - October 2018

## Requirements

* git
* C++ compiler which supports C++17 features
  - gcc >= 7
  - clang >= 5
  - MSVC++ >= 14.1 (Visual Studio 2017)
* cmake >= v3.8 (https://cmake.org/)
  - How to install : https://cmake.org/install/

## Getting started

* Clone this repository
 `git clone --recursive <this_repository_url>`.

### Slides

* Slides are available as HTML files named in the *slides* subdirectory.

### Code
* All the code used in the presentations is available in the *practical* subdirectory.
* Create a directory *build* at the root of the repository (`mkdir build`), and
  go into it (`cd build`).
* Run **cmake** (`cmake ..`).
* Either build the project with the command associated with your generator (by
  default **make** with `make`), or use your favorite IDE to open the generated
  files (for instance with **Visual Studio**, open the *FormationCpp.sln* file).
