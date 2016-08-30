# Falcon Punch
## Usage:
   romanNumeral tests
   romanNumeral [operation] [romanNumeral] [romanNumeral]

### Operations:
    add: will cause both romanNumerals to be added together
    sub: will cause the second romanNumeral to be subtracted from the first romanNumeral

### RomanNumeral Validations:  
    1. Only comprised of the characters M, D, C, L, X, V, I
    2. The maximum result will be 3999
    3. The minimum result will be 1
    4. Can't contain more than one of each of the characters D, L, V
    5. Can't contain more than three of each of the characters C, X, I <-- I think this is supposed to be more than three in a row, but was implemented as stated in the rules of the kata.