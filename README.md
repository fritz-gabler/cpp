# C++ Modules — 42 School

A series of C++ exercises from the **42 School curriculum** (CPP_00 – CPP_09), progressively introducing core C++ concepts from basic OOP to advanced templates and STL algorithms.

---

## Table of Contents

| Module | Topic |
|--------|-------|
| [CPP_00](#cpp_00--introduction-to-c) | Introduction to C++ |
| [CPP_01](#cpp_01--memory-allocation-references--pointers) | Memory Allocation, References & Pointers |
| [CPP_02](#cpp_02--operator-overloading--orthodox-canonical-form) | Operator Overloading & Orthodox Canonical Form |
| [CPP_03](#cpp_03--inheritance) | Inheritance |
| [CPP_04](#cpp_04--subtype-polymorphism--abstract-classes) | Subtype Polymorphism & Abstract Classes |
| [CPP_05](#cpp_05--exceptions) | Exceptions |
| [CPP_06](#cpp_06--type-casting) | C++ Type Casting |
| [CPP_07](#cpp_07--templates) | C++ Templates |
| [CPP_08](#cpp_08--templated-containers--algorithms) | Templated Containers & Algorithms |
| [CPP_09](#cpp_09--stl-containers) | STL Containers |

---

## CPP_00 — Introduction to C++

**Topics:** Namespaces, classes, member functions, I/O streams, initialization lists, `static`, `const`, and basic OOP.

| Exercise | Description |
|----------|-------------|
| **ex00 – Megaphone** | A simple program that converts all its arguments to uppercase. Prints a default noise message if no arguments are provided. |
| **ex01 – My Awesome PhoneBook** | A phone book simulation using two classes (`PhoneBook`, `Contact`). Supports `ADD`, `SEARCH`, and `EXIT` commands with formatted console output. |
| **ex02 – The Job Of Your Dreams** | Recreates a pre-existing `Account` class by re-implementing `Account.cpp` from the provided `Account.hpp` and a reference log file. |

---

## CPP_01 — Memory Allocation, References & Pointers

**Topics:** Heap vs stack allocation, `new`/`delete`, references, pointers to member functions, `switch` statements.

| Exercise | Description |
|----------|-------------|
| **ex00 – BraainZ** | Demonstrates the difference between stack-allocated and heap-allocated `Zombie` objects. |
| **ex01 – Zombie Horde** | Allocates an array of `Zombie` objects on the heap using a single `new` call (`zombieHorde`). |
| **ex02 – HI THIS IS BRAIN** | Explores the difference between pointers and references by printing addresses and values of a string variable. |
| **ex03 – Unnecessary violence** | Implements `HumanA` (holds a `Weapon&`) and `HumanB` (holds a `Weapon*`) to contrast references and pointers as class members. |
| **ex04 – Sed is for losers** | Reads a file, replaces all occurrences of a string `s1` with `s2`, and writes the result to a new file — without using `std::string::replace`. |
| **ex05 – Harl 2.0** | Implements a `Harl` class that calls logging methods (`DEBUG`, `INFO`, `WARNING`, `ERROR`) via an array of pointers to member functions. |
| **ex06 – Harl filter** | Extends Harl 2.0 using a `switch` statement to filter and display complaint messages at and above a given log level. |

---

## CPP_02 — Operator Overloading & Orthodox Canonical Form

**Topics:** Ad-hoc polymorphism, operator overloading, Orthodox Canonical Form (OCF), fixed-point numbers.

| Exercise | Description |
|----------|-------------|
| **ex00 – My First Class in Orthodox Canonical Form** | Introduces the OCF with a `Fixed` class representing a fixed-point number (default constructor, copy constructor, copy assignment operator, destructor). |
| **ex01 – Towards a more useful fixed-point number class** | Adds constructors from `int` and `float`, plus `toFloat()`, `toInt()`, and a `<<` stream operator. |
| **ex02 – Now we're talking** | Adds arithmetic, comparison, and increment/decrement operators to `Fixed`, along with static `min`/`max` member functions. |
| **ex03 – BSP** | Uses the `Fixed` class to implement a Binary Space Partitioning function that determines if a point lies inside a triangle. |

---

## CPP_03 — Inheritance

**Topics:** Class inheritance, constructor/destructor chaining, access specifiers.

| Exercise | Description |
|----------|-------------|
| **ex00 – Aaaaand... OPEN!** | Implements the `ClapTrap` base class with hit points, energy points, and attack/repair methods. |
| **ex01 – Serena, my love!** | Derives `ScavTrap` from `ClapTrap`, overriding `attack()` and adding a `guardGate()` method. |
| **ex02 – Repetitive work** | Derives `FragTrap` from `ClapTrap`, adding a `highFivesGuys()` method. |
| **ex03 – Now it's weird!** | Implements `DiamondTrap`, which inherits from both `ScavTrap` and `FragTrap` using virtual inheritance to resolve the diamond problem. |

---

## CPP_04 — Subtype Polymorphism & Abstract Classes

**Topics:** Virtual functions, pure virtual functions, abstract classes, interfaces, deep copy.

| Exercise | Description |
|----------|-------------|
| **ex00 – Polymorphism** | Implements `Animal`, `Dog`, and `Cat` classes with a virtual `makeSound()` method. Demonstrates polymorphism and proper destruction via virtual destructor. |
| **ex01 – I don't want to set the world on fire** | Adds a `Brain` class containing an array of ideas. `Dog` and `Cat` each own a `Brain` on the heap, requiring proper deep copy semantics. |
| **ex02 – Abstract class** | Makes `Animal` abstract by making `makeSound()` a pure virtual function. Also introduces `WrongAnimal`/`WrongCat` to demonstrate non-virtual behavior. |
| **ex03 – Interface & recap** | Implements the `AMateria`, `Ice`, `Cure`, `ICharacter`, `Character`, `IMateriaSource`, and `MateriaSource` classes to simulate an RPG-style equipment system using interfaces. |

---

## CPP_05 — Exceptions

**Topics:** Exception handling, `try`/`catch`/`throw`, custom exception classes, abstract base classes.

| Exercise | Description |
|----------|-------------|
| **ex00 – Mommy, when I grow up, I want to be a bureaucrat!** | Implements a `Bureaucrat` class with a grade (1–150). Throws `GradeTooHighException` or `GradeTooLowException` on invalid grades. |
| **ex01 – Form up, maggots!** | Adds a `Form` class with sign and execute grade requirements. `Bureaucrat::signForm()` attempts to sign a form, with exception handling. |
| **ex02 – No, you need form 28B, not 28C...** | Makes `Form` abstract (`AForm`) and introduces concrete forms: `ShrubberyCreationForm`, `RobotomyRequestForm`, and `PresidentialPardonForm`, each with distinct execution behavior. |
| **ex03 – At least this beats coffee-making** | Adds an `Intern` class that can create any of the three forms by name, without the use of `if`/`else` chains. |

---

## CPP_06 — Type Casting

**Topics:** `static_cast`, `dynamic_cast`, `reinterpret_cast`, `const_cast`, type identification.

| Exercise | Description |
|----------|-------------|
| **ex00 – Conversion of scalar types** | Implements `ScalarConverter` with a static `convert()` method that parses a string literal and converts it to `char`, `int`, `float`, and `double`. |
| **ex01 – Serialization** | Implements a `Serializer` class with `serialize()` and `deserialize()` using `reinterpret_cast` to convert between a `Data*` pointer and `uintptr_t`. |
| **ex02 – Identify real type** | Creates a `Base` class and three derived classes `A`, `B`, `C`. Implements functions to randomly generate an instance and identify the real type at runtime using `dynamic_cast`. |

---

## CPP_07 — Templates

**Topics:** Function templates, template specialization.

| Exercise | Description |
|----------|-------------|
| **ex00 – Start with a few functions** | Implements generic `swap`, `min`, and `max` function templates that work with any comparable type. |
| **ex01 – Iter** | Implements an `iter` function template that applies a given function to each element of an array. |
| **ex02 – Array** | Implements an `Array<T>` class template with bounds-checked element access, copy semantics, and a `size()` method. |

---

## CPP_08 — Templated Containers & Algorithms

**Topics:** STL containers, iterators, template functions working with containers.

| Exercise | Description |
|----------|-------------|
| **ex00 – Easy find** | Implements an `easyfind` function template that searches for the first occurrence of an integer value in any iterable container. |
| **ex01 – Span** | Implements a `Span` class that stores up to N integers and can compute the shortest and longest span (difference) between its elements. Supports range-based filling via iterators. |
| **ex02 – Mutant stack** | Implements `MutantStack<T>`, a stack that exposes iterators by inheriting from `std::stack` and adding `begin()`/`end()` iterator support. |

---

## CPP_09 — STL Containers

**Topics:** `std::map`, `std::stack`, `std::vector`, `std::deque`, algorithmic design.

| Exercise | Description |
|----------|-------------|
| **ex00 – Bitcoin Exchange** | Implements `BitcoinExchange`, which reads a CSV price database into a `std::map` and evaluates bitcoin values for dates provided in an input file. |
| **ex01 – Reverse Polish Notation** | Implements an `RPN` class that evaluates mathematical expressions in Reverse Polish Notation using a `std::stack`. |
| **ex02 – PmergeMe** | Implements the Ford-Johnson merge-insertion sort algorithm using both `std::vector` and `std::deque`. Displays the sorted sequence and elapsed processing time for each container. |

---

## Build

Each exercise contains its own `Makefile`. To compile any exercise:

```bash
cd CPP_XX/exYY
make
```

The compiled binary is typically named after the exercise or `a.out`.

---

## Author

**fgabler** — [42 School](https://42.fr) student project
