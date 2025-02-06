# Insertion sort <Using graphics.h>
This project visualizes the **Insertion Sort algorithm** using **C++ and graphics.h**. 
It represents array elements as bars and animates the sorting process in real-time, showing how elements are compared, shifted, and inserted into their correct positions.

## Table of Contents
- [About the Code](#about-the-code)
- [Requirements](#requirements)
- [How to Compile](#how-to-compile)
  - [Using MinGW (with WinBGI)](#using-mingw-with-winbgi)
- [Usage](#usage)

## About the Code

- **Language**: C++  
- **Graphics**: Uses **WinBGI** or a similar implementation of `<graphics.h>`.  
- **Main Functions**:
  1. Prompts the user for the number of elements .  
  2. Draws the bars and highlights.  
  3. Uses the classic insertion sort algorithm to sorting through each elements  
  4. Animates each bar moves and highlights to show the comparison and movements between each elements.

## Requirements
1. Windows environment (for `<graphics.h>` / WinBGI).  
2. A compiler or IDE that supports `<graphics.h>`:
   - **Dev-C++** with WinBGI built-in.  
   - **MinGW** (GCC on Windows) with WinBGI installed manually.  

## How to Compile

### Using MinGW (with WinBGI)
1. Install WinBGI (or a `<graphics.h>` library) for MinGW.  
   - This typically involves placing `graphics.h` in `MinGW\include` and a library file (e.g., `libbgi.a`) in `MinGW\lib`.  
2. Open a terminal (Command Prompt, PowerShell) in the folder containing your `.cpp` file.  
3. Compile with:
   g++ visualization.cpp -o visualization.exe -lbgi -lgdi32 -lcomdlg32 -luuid -loleaut32 -lole32
4. Run the program: .\visualization.exe

##Usage
1. Execute the compile program
2. Enter the number of disks
3. A graphic appears showing:
  - A certain numbers of bars according to the user input will appear
  - Bars will compare with each other show red highlights of the inserted bar and comparing bar and the movements
6. Press any key to close the window
