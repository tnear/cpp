# Design Patterns

Design patterns provide solutions to common software design issues.

## Creational patterns
- Singleton pattern: Ensures a class has only one instance and provides a global point of access to it. This is useful for controlling access to resources such as database connections or configuration settings.
- Factory method pattern: Defines an interface for creating an object, but lets subclasses alter the type of objects that will be created. This pattern is useful when a class cannot anticipate the class of objects it needs to create.

## Structural patterns
- Adapter pattern (wrapper): Allows the interface of an existing class to be used as another interface. It is often used to make existing classes work with others without modifying their source code.
- Composite pattern: Composes objects into tree structures to represent part-whole hierarchies. This pattern lets clients treat individual objects and compositions of objects uniformly.
- Decorator pattern: Attaches additional responsibilities to an object dynamically. Decorators provide a flexible alternative to subclassing for extending functionality.
- Flyweight pattern: Minimizes memory usage by sharing as much as possible with similar objects. Commonly used for strings.

## Behavioral patterns
- Observer pattern: Defines a one-to-many dependency between objects so that when one object changes state, all its dependents are notified and updated automatically. It's widely used in implementing event handling systems.
- Strategy pattern: Defines a family of algorithms, encapsulates each one, and makes them interchangeable. Strategy lets the algorithm vary independently from clients that use it.
- Command pattern: Encapsulates a request as an object, thereby allowing for parameterization of clients with queues, requests, and operations. It also allows for the support of undoable operations.
