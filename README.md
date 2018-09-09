# About

This repo contains my scratch work, exercise code, etc. as I work through Accelerated C++ by Andrew Koenig and Barbara E. Moo.

Because I work on build systems at work, and I'm especially masochistic, I've opted to use the Bazel build system to compile and run the simple programs I'm writing as I work through the book, so there are BUILD and WORKSPACE files scattered throughout the directories of the repo.

# Notes

## Chapter 1 - Working with Strings
- Interface - types of operations that can be performed on a particular object (i.e. initialize, add, copy, etc.)
- Local variables are destroyed and memory returned as soon as the block exits (closing `}`)
- Strings initialize to empty/null string if you don't provide a value
- Input/output are saved to a *buffer* and which is flushed when needed. This is faster/more efficient than writing char by char because it combines several write operations into one
- `const` guarantees that a value won't change, can sometimes make program faster depending on where/how value is used
- Create a string from many copies of a string with `std::string stars(10, '*');`
- `cout << string` to write string to output, `cin >> string` to save input to string

## Chapter 2 - Looping/counting
```
while (r < 10) {
	cout << x;
	r++;
}
```
- When `while` finishes, its condition must be false
- *Loop invariant* - Property we assert will be true each time a while loop tests its condition, i.e. "We have written _r_ rows so far"
- Better to use specific size types (i.e. `std::string::size_type`) rather than just `int` as size types can vary across implementations

```
if (condition) {
	statement1
} else {
	statement2
}
```
- Compound assignment: `c *= 10;`
- *Using-declaration*: `using std::cout` allows you to use the shortname `cout` throughout a source file (if it appears within braces, it is limited to that block)
```
for (init-statement condition; expression) {
	statement
}
```
- `x ? y : z` - y if x is true, otherwise z

## Chapter 4
- An _lvalue_ is a value that denotes a non-temporary object, e.g. something that will be saved. The expression `sum / count` is not an lvalue (in fact, it's called an _rvalue_.) In the expression `x = sum / count`, x is an lvalue because it persists beyond this line. (p 56)
- Three kinds of function parameters (p 58)
	- Pass-by-value e.g. `vector<double> hw` that results in copying all of the data into a new object. This is the right thing to do if we're planning to modify the data, such as sorting a vector.
	- Read only pass-by-reference e.g. `const vector<double> hw2&` that results in only a reference to the original object, and doesn't create a copy. The `&` is what signifies it is pass-by-reference and a copy should not be made. This improves performance for some complex types like strings or other objects. Use this when we don't intend to modify the original source object (which is enforced by `const`), such as when calculating the median of a vector.
	- Non-read only pass-by-reference e.g. `vector<double> hw` that results in a reference to the original object that does allow us to make modifications. As above, saves the effort of copying the object
- Can define a data structure (`struct`) to hold related but disparate types of data such as a student's name and grades, and then create a vector<Student_info> to hold all of the students records together.
- Structs should be defined in headers as their definitions should only be included once.
- C++ (or at least the authors of Accelerated C++) seem to favor function overloading over distinctly naming functions. i.e. a function definition like double read(double homework) tells it reads homework in its signature, so there is no need to name it something like read_homework().
- Header includes: When headers are included with quotes instead of brackets (e.g. #include "median.h" instead of #include <vector>), it tells the compiler to copy the entire contents of the header file into the program in place of the #include directive.
- Header will contain a _declaration_ for functions in source files. Function body is replaced with a semicolon. Names of parameters are removed as they don't matter without the function body (so the head just declares the accepted signatures for each function.) (p67)
- Header files should declare only the names that are necessary, so it's better to be more explicit (`std::vector` as a parameter) than to use the `using std::vector` syntax in a header.
- Header files should ensure it is safe to include the file more than once, so use preprocessor directive guards. These should always be first in the file, even before any comments, as some implementations are optimized to check for this and skip reading the rest of the source file if possible.
- Source files including their corresponding header files provides some level of protection as it lets the compiler check for consistency between function declarations and definitions.
- Using the `using` syntax (i.e. `using std::vector` to shorten all other refs to `vector`) is fine within source files, as it has no effect on consumers of the functions defined within these files (unlike headers, as noted above.)

