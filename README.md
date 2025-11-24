# 🚀 42 C++ Immersion - Modules 00 to 09

# 🌟 Overview

This repository documents the completion of the 42 C++ Immersion curriculum, covering fundamental concepts of the C++ language, object-oriented programming (OOP) principles, advanced features, and system programming techniques. Each module focuses on specific language aspects and culminates in practical projects designed to reinforce understanding.

The projects are structured chronologically, starting from basic syntax and memory management, progressing through inheritance, polymorphism, templates, containers, and culminating in advanced I/O and networking projects.

# 📚 Modules Summary

| Module | Core Concepts | Description | Project Examples |
| :---: | :--- | :--- | :--- |
| **`cpp00`** | **Namespaces, Classes, I/O** | Introduction to C++ syntax, classes, memory allocation/deallocation, pointers, references, and standard I/O streams. | *Megaphone, Harl* |
| **`cpp01`** | **Memory Allocation & References** | Focus on dynamic memory allocation (`new`/`delete`), pointers, references, and the difference between stack and heap memory. | *Pointers, References, and Harl's filter* |
| **`cpp02`** | **Polymorphism & Operator Overload** | Core **OOP** concepts: Ad-hoc polymorphism via operator overloading, canonical class form, copy constructor, and assignment operator. | *Fixed-point number class, ScavTrap/FragTrap* |
| **`cpp03`** | **Inheritance & Diamond Problem** | Implementation of single and multiple inheritance, virtual destructors, and managing the ambiguity of the **Diamond Problem**. | *ClapTrap inheritance chain (ScavTrap, FragTrap, DiamondTrap)* |
| **`cpp04`** | **Subtype Polymorphism & Interfaces** | Focus on pure virtual functions and abstract classes to define interfaces. Handling exceptions and up/down-casting. | *A-Z classes (Materia/Character/Cure/Ice), Polymorphic Animal class* |
| **`cpp05`** | **Exceptions & Form Handling** | Advanced exception handling, nested exceptions, custom exception classes, and designing classes for state management and controlled action flow. | *Bureaucrat, Forms (Shrubbery, Presidential, Robotomy)* |
| **`cpp06`** | **Casts & Type Conversion** | Exploration of explicit type conversion: `static_cast`, `dynamic_cast`, `const_cast`, and `reinterpret_cast`. | *Serialization of data, simple `cast` utility* |
| **`cpp07`** | **Templates & Generic Programming** | Introduction to templates for writing generic, type-agnostic functions and classes. Implementing custom container-like structures. | *Array template, template function examples* |
| **`cpp08`** | **STL & Containers** | Mastering the C++ Standard Template Library (**STL**). Extensive use of containers (`vector`, `map`, `list`), iterators, and algorithms. | *Custom function templates on STL containers* |
| **`cpp09`** | **Advanced STL/System** | Focus on complex algorithms, advanced containers, and system-level programming, often involving parsing or networking logic. | *RPN calculator, container manipulation* |

# 🛠️ Building the Projects

Each module (cpp00, cpp01, etc.) is a separate project directory and contains its own Makefile.

    make

This command will compile the executable(s) specific to that module's assignment.
