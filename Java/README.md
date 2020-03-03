- [Java (JDK 8)](#java-jdk-8)
  - [Object-Oriented Programming Concepts](#object-oriented-programming-concepts)
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

## Source

1. [ORACLE Java Tutorial](https://docs.oracle.com/javase/tutorial/java/index.html)  