# Bottom-up analyzer (C++) for arithmetical expressions

Bottom-up analyzer implemented with the State design pattern to evaluate
arithmetical expressions.

### Grammar

The grammar analyzer is based on the following grammar:

```
1. E' -> E
2. E  -> E + E
3. E  -> E * E
4. E  -> ( E )
5. E  -> val
```

## Requirements

C++ version 11 or greater.

## Makefile

### `make [debug=true]`

Generates binary files (.o) and the project executable "main". Activate the
debug mode with "debug=true".

### `make run`

Generates the executable if it does not already exist, and executes it.

### `make rebuild [debug=true]`

Force deletion of files to rebuild them. Activate the debug mode with "
debug=true".

### `make clean`

Delete binary files.

### `make cleanall`

Deletes the binary files and the "main" executable

# Example of execution

### No debug

`make run`

```
Do you want to support negative integers ? Y/N 
> Y
Support for negative integers enabled.
Enter an expression to compute or 'stop': 
> (4+6)*10+2+-60
Result: 42
Enter an expression to compute or 'stop': 
> stop
Ending the process
```

### With debug=true

`make run`

```
Do you want to support negative integers ? Y/N 
> N
Support for negative integers disabled.
Enter an expression to compute or 'stop': 
> 3*3+3
Transiting through the state I0
With symbol:
    INT
Transiting through the state I3
With symbol:
    MULTIPLICATION
Transiting through the state I0
With symbol:
    EXPR
Transiting through the state I1
With symbol:
    MULTIPLICATION
Transiting through the state I5
With symbol:
    INT
Transiting through the state I3
With symbol:
    PLUS
Transiting through the state I5
With symbol:
    EXPR
Transiting through the state I8
With symbol:
    PLUS
Transiting through the state I0
With symbol:
    EXPR
Transiting through the state I1
With symbol:
    PLUS
Transiting through the state I4
With symbol:
    INT
Transiting through the state I3
With symbol:
    END
Transiting through the state I4
With symbol:
    EXPR
Transiting through the state I7
With symbol:
    END
Transiting through the state I0
With symbol:
    EXPR
Transiting through the state I1
With symbol:
    END
Result: 12
Enter an expression to compute or 'stop': 
> stop
Ending the process
````

# LALR(1) Analysis table of the grammar

| **States** | **val** | **+** | *   | **(** | **)** | **$**  |     | **E** |
|------------|---------|-------|-----|-------|-------|--------|-----|-------|
| **0**      | d3      |       |     | d2    |       |        |     | 1     |
| **1**      |         | d4    | d5  |       |       | accept |     |       |
| **2**      | d3      |       |     | d2    |       |        |     | 6     |
| **3**      |         | r5    | r5  |       | r5    | r5     |     |       |
| **4**      | d3      |       |     | d2    |       |        |     | 7     |
| **5**      | d3      |       |     | d2    |       |        |     | 8     |
| **6**      |         | d4    | d5  |       | d9    |        |     |       |
| **7**      |         | r2    | d5  |       | r2    | r2     |     |       |
| **8**      |         | r3    | r3  |       | r3    | r3     |     |       |
| **9**      |         | r4    | r4  |       | r4    | r4     |     |       |

# States schema

![alt text](./img/states_schema.png)

# Final notes

In this project we took care of commenting all major aspects of the code.

In addition, we eliminated all issues reported by valgrind.

We also made extensive tests to ensure our work was able to answer properly to
all the expressions following the grammar.

Moreover, to fully respect the grammar we implemented a way to support negative
integers in our lexer.

Furthermore, we tried to extend the grammar with some experimental features
(not present in the final release), without editing the states (for instance by
trying to support subtractions only by editing the lexer).
