# Credit Card Number Validator and Card Type Identifier

This is a simple C++ program that validates credit card numbers using the Luhn algorithm and identifies the type of credit card based on its number.

## Features

- Validates credit card numbers using the Luhn algorithm.
- Identifies the type of credit card (Visa, Mastercard, American Express, etc.).
- Supports multiple card types with specific validation criteria.
- Provides an interactive command-line interface for user input.

## Limitations
- My credit card project lacks the functionality to distinguish between active and inactive cards.
## Usage

1. Clone the repository to your local machine.
2. Compile the `CreditCardTypeValidator.cpp` file using a C++ compiler.
   
   ```bash
   g++ -o CreditCardTypeValidator.exe CreditCardTypeValidator.cpp

4. Run the compiled executable.
   
   ```bash
   ./CreditCardTypeValidator.exe

6. Follow the prompts to enter a credit card number for validation.

# Supported Card Types
- American Express
- Diners
- Discover
- Enroute
- JCB (15-digit and 16-digit)
- Mastercard
- Visa
- Voyager
- RuPay
