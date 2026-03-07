*This project has been created as part of the 42 curriculum by kchibukh*

# get_next_line
---

## Description

get_next_line is a function that reads and returns a line from a file descriptor.  
The goal of this project is to understand file descriptors, static variables, and dynamic memory allocation by implementing a function that reads input line by line.

The function must return one line at a time, including the newline character (`\n`) when present, without reading the entire file into memory.

---

## Project Goal  

- Read a file descriptor line by line.
- Handle different BUFFER_SIZE values.
- Manage memory correctly without leaks.
- Preserve remaining data between function calls.
- Support multiple file descriptors (bonus).
- Return NULL when the end of file is reached or an error occurs.

---

## Instructions

---

### Compilation

The project is compiled using the cc compiler with the following flags:
-Wall -Wextra -Werror
Example compilation (mandatory):
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c
Bonus compilation:
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line_bonus.c get_next_line_utils_bonus.c
You can test with different buffer sizes:

-D BUFFER_SIZE=1
-D BUFFER_SIZE=100
-D BUFFER_SIZE=9999

---

## Resources

Linux manual pages
Peer discussions and code reviews
AI tools were used only for reviewing documentation structure and clarifying edge cases
