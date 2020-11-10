# Interfaces and Inheritance

## Interfaces

interface can contain only constants, method signatures, default methods(with default modifier), static methods (with the static keyword), and nested types.

All abstract, default, and static methods in an interface are implicitly **public**!

All constant values defined in an interface are implicitly public, static, and final. Once again, you can omit these modifiers.  

A class that implements an interface must implement all the methods declared in the interface.

An interface name can be used anywhere a type can be used.

### Using an Interface as a Type

define a new interface == defining a new reference data type

You can use interface names anywhere you can use any other data type name. If you define a reference variable whose type is an interface, any object you assign to it must be an instance of a class that implements the interface.

### Evolving Interfaces
If you want to add a new method,  all classes that implement the old  interface will break. Add default and static methods are ok. Interfaces enhanced with new default or static methods do not have to modify or recompile them to accommodate the additional methods.  

### Extending Interfaces That Contain Default Methods

When you extend an interface that contains a default method, you can do the following:

- Not mention the default method at all, which lets your extended interface inherit the default method.
- Redeclare the default method, which makes it abstract.
  - [modifier] [Reference data type] [default method name] (argu)
- Redefine the default method, which overrides it.

## Inheritance
  
A subclass inherits all the public and protected members (fields, methods, and nested classes) from its superclass.  If the subclass is in the same package as its parent, it also inherits the package-private members of the parent.  
Constructors are not members, so they are not inherited by subclasses, but the constructor of the superclass can be invoked from the subclass.  

### Private Members in a Superclass

A subclass does not inherit the private members of its parent class. However, if the superclass has public or protected methods for accessing its private fields, these can also be used by the subclass.

A nested class has access to all the **private** members of its enclosing class—both fields and methods. Therefore, a public or protected nested class inherited by a subclass has indirect access to all of the private members of the superclass.

### Overriding and Hiding Methods

An overriding **instance method** can also return a subtype of the type returned by the overridden method. This subtype is called a covariant return type.

If a subclass defines a **static method** with the same signature as a static method in the superclass, then the method in the subclass hides the one in the superclass.

The distinction between hiding a static method and overriding an instance method has important implications:

- The version of the overridden instance method that gets invoked is the one in the subclass.  
- The version of the hidden static method that gets invoked depends on whether it is invoked from the superclass or the subclass.

Multiple inheritance method:

When the supertypes of a class or interface provide multiple default methods with the same signature, the Java compiler follows inheritance rules to resolve the name conflict. These rules are driven by the following two principles:

1. Instance methods are preferred over interface default methods.  
2. Methods that are already overridden by other candidates are ignored. This circumstance can arise when supertypes share a common ancestor.  
3. If two or more independently defined default methods conflict, or a default method conflicts with an abstract method, then the Java compiler produces a compiler error.

**Example : two or more independently defined default methods conflict**  

```
public interface OperateCar {
    // ...
    default public int startEngine(EncryptedKey key) {
        // Implementation
    }
}
public interface FlyCar {
    // ...
    default public int startEngine(EncryptedKey key) {
        // Implementation
    }
}
public class FlyingCar implements OperateCar, FlyCar {
    // ...
    public int startEngine(EncryptedKey key) {
        FlyCar.super.startEngine(key);
        OperateCar.super.startEngine(key);
    }
}
```
The name preceding **super** (in this example, FlyCar or OperateCar) must refer to a direct superinterface that defines or inherits a default for the invoked method.

**Inherited instance methods from classes can override abstract interface methods.**

**Static methods in interfaces are never inherited.**

### Modifiers
The access specifier for an overriding method can allow more, but not less, access than the overridden method. For example, a protected instance method in the superclass can be made public, but not private, in the subclass.

### Object as a superclass

#### clone()
clone() must be declared as

protected/public Object clone() throws CloneNotSupportedException

If an object contains a reference to an external object, we must override clone() to make the clone references clone of external object.

#### equals()
The equals() method provided in the Object class uses the identity operator (==) to determine whether two objects are equal. For primitive data types, this gives the correct result. For objects, however, it does not.

#### getClass()
You cannot override getClass.

The getClass() method returns a Class object, which has methods you can use to get information about the class, such as its name (getSimpleName()), its superclass (getSuperclass()), and the interfaces it implements (getInterfaces()).

The Class class, in the java.lang package, has a large number of methods (more than 50). For example, you can test to see if the class is an annotation (isAnnotation()), an interface (isInterface()), or an enumeration (isEnum()). You can see what the object's fields are (getFields()) or what its methods are (getMethods()), and so on.

#### hashCode()
The value returned by hashCode() is the object's hash code, which is the object's memory address in hexadecimal.

If you override the equals() method, you must also override the hashCode() method as well.

### Final Classes and Methods

You use the **final** keyword in a method declaration to indicate that the method **cannot be overridden** by subclasses.

A class that is declared final cannot be subclassed.

### Abstract Methods and Classes

An **abstract class** is a class that is declared abstract—it may or may not include abstract methods. Abstract classes cannot be instantiated, but they can be subclassed. If a class includes abstract methods, then the class itself must be declared abstract. 

When an **abstract class is subclassed**, the subclass usually provides implementations for all of the abstract methods in its parent class. However, if it does not, then the subclass must also be declared **abstract**. With abstract classes, you can declare fields that are **not static and final**.

**Note:**  
Compared to Interface: With interfaces, all fields are automatically public, static, and final, and all methods that you declare or define (as default methods) are public.

An **abstract method** is a method that is declared without an implementation.

Which should you use, abstract classes or interfaces?  
Abstract classes:
- You want to share code among several closely related classes.
- You expect that classes that extend your abstract class have many common methods or fields, or require access modifiers other than public.
- You want to declare non-static or non-final fields. This enables you to define methods that can access and modify the state of the object to which they belong.

Interfaces:  
- You expect that unrelated classes would implement your interface. For example, the interfaces Comparable and Cloneable are implemented by many unrelated classes.
- You want to specify the behavior of a particular data type, but not concerned about who implements its behavior.
- You want to take advantage of multiple inheritance of type (An object can have multiple types: the type of its own class and the types of all the interfaces that the class implements).

#### When an Abstract Class Implements an Interface
abstract class do not need to fully implement all of the interface's method.


  




