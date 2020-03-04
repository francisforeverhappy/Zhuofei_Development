- [Java (JDK 8)](#java-jdk-8)
  - [Object-Oriented Programming Concepts](#object-oriented-programming-concepts)
  - [Language Basics](#language-basics)
    - [Variables](#variables)
      - [Naming](#naming)
      - [Literals](#literals)
      - [Array](#array)
  - [Source](#source)

# Java (JDK 8)

## Object-Oriented Programming Concepts

An object stores its state in fields (variables in some programming languages) and exposes its behavior through methods (functions in some programming languages).  

Data encapsulation： Hiding internal state and requiring all interaction to be performed through an object's methods  

Benefit:  
1. Modularity: The source code for an object can be written and maintained independently of the source code for other objects. Once created, an object can be easily passed around inside the system.
2. Information-hiding: By interacting only with an object's methods, the details of its internal implementation remain hidden from the outside world.
3. Code re-use: If an object already exists (perhaps written by another software developer), you can use that object in your program. This allows specialists to implement/test/debug complex, task-specific objects, which you can then trust to run in your own code.
4. Pluggability and debugging ease: If a particular object turns out to be problematic, you can simply remove it from your application and plug in a different object as its replacement. This is analogous to fixing mechanical problems in the real world. If a bolt breaks, you replace it, not the entire machine.

Interface:  
Implementing an interface allows a class to become more formal about the behavior it promises to provide. Interfaces form a contract between the class and the outside world, and this contract is enforced at build time by the compiler. If your class claims to implement an interface, all methods defined by that interface must appear in its source code before the class will successfully compile.

Package:  
A package is a namespace that organizes a set of related classes and interfaces.  
The Java platform provides an enormous class library (a set of packages) suitable for use in your own applications. This library is known as the "Application Programming Interface", or "API" for short.

## Language Basics

### Variables

- Instance Variables (Non-Static Fields) 
  - Values are unique to each instance of a class.
- Class Variables (Static Fields)
  - Exactly one copy of this variable in existence, regardless of how many times the class has been instantiated. The  keyword **final** could be added to indicate that the number of gears will never change.
- Local Variables
  - A method will often store its temporary state in local variables. Only visible to the methods in which they are declared.
- Parameters

**Initial Value**:  
 The compiler will assign a reasonable default value for fields of eight primitive data types ( byte, short, int, long, float, double, boolean, and char. The java.lang.String class represents character strings ) types; for local variables, a default value is never assigned.  

#### Naming

- Variable names are case-sensitive. A variable's name can be any legal identifier — an unlimited-length sequence of Unicode letters and digits, beginning with a letter, the dollar sign "$" (hint: never to use), or the underscore character "_".
- Subsequent characters may be letters, digits, dollar signs, or underscore characters.

Statically-typed: all variables must first be declared before they can be used.

#### Literals

Decimal: 26  
Hexadecimal: 0x1a  
Binary: 0b11010  
Double: 11.1 or 11.1d  
float: 11.1f  
scientific notation: 1.11e1 
Unicode(char): '\u000'~'\uffff'  
String: "a" or null  
\b (backspace), \t (tab), \n (line feed), \f (form feed), \r (carriage return), \" (double quote), \' (single quote), and \\ (backslash).  

Underscore Characters  
Example:  
```java
long creditCardNumber = 1234_5678_9012_3456L;
long socialSecurityNumber = 999_99_9999L;
float pi =  3.14_15F;
long hexBytes = 0xFF_EC_DE_5E;
long hexWords = 0xCAFE_BABE;
long maxLong = 0x7fff_ffff_ffff_ffffL;
byte nybbles = 0b0010_0101;
long bytes = 0b11010010_01101001_10010100_10010010;
```
**Cannot place underscores in the following places:**
- At the beginning or end of a number
- Adjacent to a decimal point in a floating point literal
- Prior to an F or L suffix
- In positions where a string of digits is expected

#### Array

4 ways copy:
1. clone
```java
String[] a1 = {1, 3};
String[] a2 = a1.clone();
```
2. System.arraycopy
```java
public static native void arraycopy(Object src, int srcPos, Object dest, int desPos, int length)
```
3. Arrays.copyOf
```java
public static <T,U> T[] copyOf(U[] original, int newLength, Class<? extends T[]> newType) {
    @SuppressWarnings("unchecked")
    T[] copy = ((Object)newType == (Object)Object[].class)
        ? (T[]) new Object[newLength]
        : (T[]) Array.newInstance(newType.getComponentType(), newLength);
    System.arraycopy(original, 0, copy, 0,
                     Math.min(original.length, newLength));
    return copy;
}
```
4. Arrays.copyOfRange
```java
public static <T,U> T[] copyOfRange(U[] original, int from, int to, Class<? extends T[]> newType) {
    int newLength = to - from;
    if (newLength < 0)
        throw new IllegalArgumentException(from + " > " + to);
    @SuppressWarnings("unchecked")
    T[] copy = ((Object)newType == (Object)Object[].class)
        ? (T[]) new Object[newLength]
        : (T[]) Array.newInstance(newType.getComponentType(), newLength);
    System.arraycopy(original, from, copy, 0,
                     Math.min(original.length - from, newLength));
    return copy;
}
```

Useful Methods in **java.util.Arrays** class:  
1. Searching an array for a specific value to get the index at which it is placed (the **binarySearch** method).
2. Comparing two arrays to determine if they are equal or not (the **equals** method).
3. Filling an array to place a specific value at each index (the **fill** method).
4. Sorting an array into ascending order. This can be done either sequentially, using the sort method, or concurrently, using the **parallelSort** method introduced in Java SE 8. Parallel sorting of large arrays on multiprocessor systems is faster than sequential array sorting.

## Source

1. [ORACLE Java Tutorial](https://docs.oracle.com/javase/tutorial/java/index.html)  