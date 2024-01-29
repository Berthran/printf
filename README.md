#_printf Project

This project aims to create a semblance of the C _printf_ function found in the _stdio.h_ library. 

## Table of Contents
- [Features](#features)
- [Getting Started](#getting-started)
- [Usage](#usage)
- [Contributing](#contributing)

## Features
- **Basic Formatting**: Format and print strings, characters, and integers.
- **Variable Arguments**: Support for variable arguments using the `...` syntax.
- **Custom Specifiers**: Implement custom specifiers for specialized formatting.
- **Error Handling**: Handle errors gracefully and provide meaningful error messages.

## Getting Started

### Prerequisites

Ensure you have a C compiler installed on your system. This project is designed to work with standard C libraries.

### Installation

1. Clone the repository:
```bash
   git clone https://github.com/Berthran/_printf.git
```
* Navigate to the project directory:
* Compile the code
* Run the executable:
```bash
cd _printf
gcc -o _printf _printf.c *.c
./_printf
```

## Usage
To use the custom printf function in your code, include the main.h header file and call the _printf function as you would with the standard printf function. You can also explore and modify the code to add custom specifiers or enhance functionality.
```bash
#include "main.h"


int main() {
    _printf("Hello, %s! You have %d apples.\n", "John", 5);

    return 0;
}
``````


## Contributing
Contributions are welcome! If you have ideas for improvements, bug fixes, or new features, please open an issue or submit a pull request. Ensure your code follows the project's coding style and conventions.

## License
This project is licensed under the MIT License, so feel free to use, modify, and distribute it.
