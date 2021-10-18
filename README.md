

# Objective 

- Categorize trades in a bank´s portfolio

- Category types: 
   - DEFAULTED: Trades whose next payment date is late by more than 30 days based on a reference date which will be given.
   - HIGHRISK: Trades with value greater than 1,000,000 and client from Private Sector.
   - MEDIUMRISK: Trades with value greater than 1,000,000 and client from Public Sector.


## Input

1. The first line of the input is the reference date.
2. The second line contains an integer n, the number of trades in the portfolio. 
3. The next n lines contain 3 elements each (separated by a space). First a double that represents trade amount, second a string that represents the client’s sector and third a date that represents the next pending payment. All dates are in the format mm/dd/yyyy.

## Output

N lines with the category of each one of the n trades.

## Example   

- Smaple input:

```
12/11/2020
4
2000000 Private 12/29/2025
400000 Public 07/01/2020
5000000 Public 01/02/2024
3000000 Public 10/26/2023
```

- Sample Output:

```
HIGHRISK
DEFAULTED
MEDIUMRISK
MEDIUMRISK
```

# Question 1 - Answer

- The code is tested with Clang 10.0 on Ubuntu 20.04 ( Docker image latest)

## Project structure

- [src](./src) The project 
   - [bin](./bin) - Binary folder with main and functions to parse input and generate output.
   - [lib](./lib) - Library with the actual objective implementation  
      - [./lib/trade.h] - Trade and ITrade classes following the question structure. 
      - [./lib/category.h] - Category classes and function
   - [test](./test) - (For the future) Units tests of Trade library with catch2
- [regression-test](./regression-tests) - Regression tests to validate the actual code.
- Obs1: For DateTime logic is use boost::posix_time::ptime
- Obs2: The other library dependencies, like boost, are getting by the [Conan Package Manager](https://conan.io/).

# Question 2 - Answer 

- In this case:
   1. It will create a new category class, PEP, inheriting from ICategory and [at categoryByPriority in findTradeCategory function](./src/lib/category.cpp#L46) will be the first element to be the first category to check. 
   2. It will change the [trade classes](./src/lib/trade.h) to contain PoliticallyExposed information and it will change the [readTrade function on main](./src/bin/main.cpp#L65) file to expect the new value.

