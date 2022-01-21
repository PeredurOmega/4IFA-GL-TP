# Makefile

### `make [debug=true]`
Generates binary files (.o) and the project executable "main".
Activate the debug mode with "debug=true".

### `make run`
Generates the executable if it does not already exist, and executes it.

### `make rebuild [debug=true]`
Force deletion of files to rebuild them.
Activate the debug mode with "debug=true".

### `make clean`
Delete binary files.

### `make clean`
Deletes the binary files and the "main" executable


# Requirements

C++ version 11.


# Example of execution

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

# States schema

![alt text](./img/states_schema.png)



