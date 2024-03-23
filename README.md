![ProjectLogo](/Project-Logo-&-Screenshots/Number_Combinations.png)

## Overview

This is a simple C program that takes numbers as input and then calculates all possible combinations of them that are within the restrictions which were selected.

## Contents

- [How it works](#How-it-works)
- [Screenshots](#Screenshots)
- [How to install](#How-to-install)
- [How to compile and run](How-to-compile-and-run)
- [License](#License)


## How it works

User give numbers as inputs ... and the program calculates the cobinations of these numbers and prints the results.
The program ignores the combinations that are not within the restrictions.
Count of even numbers (x1 to x2) and the sum of the combination (y1 to y2). 

## Screenshots

Here are some screenshots of the program in action:

### Inputs

![screenshot-1](/Project-Logo-&-Screenshots/Screenshot_1.png)

### Results

![screenshot-2](/Project-Logo-&-Screenshots/Screenshot_2.png)

## How to install

1. **Clone the repository to your local machine:**
  ```bash
    git clone https://github.com/marioskam3/Number-Combinations
  ```

2. **Navigate to the project directory:**
  ```bash
    cd "Number-Combinations"
  ```

## How to compile and run

1. **You will need a c compiler**
    I am using gcc
    Download gcc with:
  ```bash
    sudo apt install gcc
  ```

2. **Compile program:**
  ```bash
    gcc -o number-combinations number-combination.c
  ```

3. **Run program:**
  ```bash
    ./number-combinations
  ```
## License

This project is licensed under the MIT License
