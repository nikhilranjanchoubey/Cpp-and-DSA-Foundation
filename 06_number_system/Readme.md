# NUMBER SYSTEM

C++ programs for converting numbers between different number systems (Binary and Decimal).

## Table of Contents

- [Overview](#overview)
- [Programs](#programs)
- [Key Concepts](#key-concepts)
- [Conversion Logic](#conversion-logic)
- [Common Patterns](#common-patterns)

## Overview

Programs demonstrating conversions between binary (base-2) and decimal (base-10) number systems.

## Programs

### 1. binarytodecimal.cpp - Binary to Decimal Converter
Converts a binary number to its decimal equivalent.

**Example:**
```
Input: 1010
Output: 10
```

**Conversion:** 1×2³ + 0×2² + 1×2¹ + 0×2⁰ = 8 + 0 + 2 + 0 = 10

**Logic:**
- Extract last digit (rightmost bit)
- Multiply by power of 2 (starting from 2⁰)
- Add to result
- Increase power by ×2
- Remove last digit

**Learns:** Binary to decimal conversion, power calculation, digit extraction

---

### 2. decimaltobinary.cpp - Decimal to Binary Converter
Converts a decimal number to its binary equivalent.

**Example:**
```
Input: 10
Output: 1010
```

**Conversion:** 10 ÷ 2 = 5 (rem 0) → 5 ÷ 2 = 2 (rem 1) → 2 ÷ 2 = 1 (rem 0) → 1 ÷ 2 = 0 (rem 1)
Reading remainders bottom to top: **1010**

**Logic:**
- Find remainder when divided by 2 (parity digit)
- Add remainder × power of 10
- Increase power by ×10
- Divide number by 2
- Repeat until number becomes 0

**Learns:** Decimal to binary conversion, modulo operation, building numbers

---

## Key Concepts

### Number Systems

**Decimal (Base-10):**
- Uses digits: 0, 1, 2, 3, 4, 5, 6, 7, 8, 9
- Position represents power of 10
- Example: 523 = 5×10² + 2×10¹ + 3×10⁰

**Binary (Base-2):**
- Uses digits: 0, 1
- Position represents power of 2
- Example: 101 = 1×2² + 0×2¹ + 1×2⁰ = 5

### Position Values

| Binary Position | 2⁷ | 2⁶ | 2⁵ | 2⁴ | 2³ | 2² | 2¹ | 2⁰ |
|----------------|----|----|----|----|----|----|----|----|
| **Decimal Value** | 128 | 64 | 32 | 16 | 8 | 4 | 2 | 1 |

## Conversion Logic

### Binary to Decimal Algorithm

```cpp
int ans = 0;
int power = 1;              // Start with 2⁰ = 1

while(n > 0) {
    int lastdigit = n % 10;  // Extract rightmost bit
    ans += lastdigit * power; // Add bit × power of 2
    power *= 2;              // Next power (2¹, 2², 2³, ...)
    n /= 10;                 // Remove processed bit
}
```

**Step-by-step for 1011:**
```
Step 1: digit=1, ans=0+(1×1)=1,   power=2, n=101
Step 2: digit=1, ans=1+(1×2)=3,   power=4, n=10
Step 3: digit=0, ans=3+(0×4)=3,   power=8, n=1
Step 4: digit=1, ans=3+(1×8)=11,  power=16, n=0
Result: 11
```

### Decimal to Binary Algorithm

```cpp
int ans = 0;
int power = 1;              // Build result from right to left

while(n > 0) {
    int parity = n % 2;     // Get remainder (0 or 1)
    ans += parity * power;  // Add to appropriate position
    power *= 10;            // Next decimal position
    n /= 2;                 // Divide by 2
}
```

**Step-by-step for 13:**
```
Step 1: parity=1, ans=0+(1×1)=1,     power=10, n=6
Step 2: parity=0, ans=1+(0×10)=1,    power=100, n=3
Step 3: parity=1, ans=1+(1×100)=101, power=1000, n=1
Step 4: parity=1, ans=101+(1×1000)=1101, power=10000, n=0
Result: 1101
```

## Common Patterns

### Digit Extraction
```cpp
int lastdigit = num % 10;    // Get rightmost digit
num = num / 10;              // Remove rightmost digit
```

### Building Numbers
```cpp
result = result * 10 + digit;  // Append digit to right
result = digit * power + result; // Add digit at specific position
```

### Power Calculation
```cpp
// Manual power calculation
int power = 1;
for(int i = 0; i < exponent; i++) {
    power *= base;
}
```

## Conversion Examples

### Binary to Decimal

| Binary | Calculation | Decimal |
|--------|-------------|---------|
| 1 | 1×2⁰ | 1 |
| 10 | 1×2¹ + 0×2⁰ | 2 |
| 11 | 1×2¹ + 1×2⁰ | 3 |
| 100 | 1×2² + 0×2¹ + 0×2⁰ | 4 |
| 101 | 1×2² + 0×2¹ + 1×2⁰ | 5 |
| 110 | 1×2² + 1×2¹ + 0×2⁰ | 6 |
| 111 | 1×2² + 1×2¹ + 1×2⁰ | 7 |
| 1000 | 1×2³ | 8 |
| 1111 | 1×2³ + 1×2² + 1×2¹ + 1×2⁰ | 15 |
| 10000 | 1×2⁴ | 16 |

### Decimal to Binary

| Decimal | Division Process | Binary |
|---------|------------------|--------|
| 2 | 2÷2=1(0), 1÷2=0(1) | 10 |
| 5 | 5÷2=2(1), 2÷2=1(0), 1÷2=0(1) | 101 |
| 8 | 8÷2=4(0), 4÷2=2(0), 2÷2=1(0), 1÷2=0(1) | 1000 |
| 10 | 10÷2=5(0), 5÷2=2(1), 2÷2=1(0), 1÷2=0(1) | 1010 |
| 15 | 15÷2=7(1), 7÷2=3(1), 3÷2=1(1), 1÷2=0(1) | 1111 |
| 16 | 16÷2=8(0), 8÷2=4(0), 4÷2=2(0), 2÷2=1(0), 1÷2=0(1) | 10000 |

## Quick Tips

### Binary to Decimal (Mental Math)
Remember powers of 2: 1, 2, 4, 8, 16, 32, 64, 128, 256...

**Example:** 10110₂
- Count from right: positions 1, 2, 4 have 1s
- Add: 2 + 4 + 16 = 22

### Decimal to Binary (Mental Math)
Subtract largest power of 2 repeatedly.

**Example:** 22₁₀
- 22 - 16(2⁴) = 6 → write 1
- 6 - 4(2²) = 2 → write 1 (skip 2³)
- 2 - 2(2¹) = 0 → write 1
- Result: 10110₂

## Common Mistakes

### Incorrect Power Initialization
```cpp
❌ int power = 0;         // Wrong starting value
✅ int power = 1;         // Correct (2⁰ = 1)
```

### Wrong Power Update
```cpp
❌ power += 2;            // Adds 2 (wrong)
✅ power *= 2;            // Multiplies by 2 (correct)
```

### Forgetting to Remove Digit
```cpp
❌ while(n > 0) {
    int digit = n % 10;
    // Process digit
    // Forgot: n /= 10;   // Infinite loop!
}

✅ while(n > 0) {
    int digit = n % 10;
    // Process digit
    n /= 10;             // Remove digit
}
```

### Integer Overflow
```cpp
// For large numbers, use long long
❌ int ans = 0;           // May overflow
✅ long long ans = 0;     // Safer for large values
```

## Additional Number Systems

### Octal (Base-8)
- Digits: 0-7
- Powers of 8
- Example: 17₈ = 1×8¹ + 7×8⁰ = 15₁₀

### Hexadecimal (Base-16)
- Digits: 0-9, A-F (A=10, B=11, ..., F=15)
- Powers of 16
- Example: 1F₁₆ = 1×16¹ + 15×16⁰ = 31₁₀

## Quick Reference

### Binary to Decimal Template
```cpp
int binaryToDecimal(int binary) {
    int decimal = 0;
    int power = 1;
    
    while(binary > 0) {
        int lastBit = binary % 10;
        decimal += lastBit * power;
        power *= 2;
        binary /= 10;
    }
    return decimal;
}
```

### Decimal to Binary Template
```cpp
int decimalToBinary(int decimal) {
    int binary = 0;
    int power = 1;
    
    while(decimal > 0) {
        int remainder = decimal % 2;
        binary += remainder * power;
        power *= 10;
        decimal /= 2;
    }
    return binary;
}
```

**Learning Path:** binarytodecimal.cpp → decimaltobinary.cpp

---

**Happy Coding! 🚀**
