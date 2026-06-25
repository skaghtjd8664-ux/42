# Libft - Your very first own library

[cite_start]*This project has been created as part of the 42 curriculum by <honam>.* [cite: 236]

## Description
[cite_start]**Libft** is a project that involves coding a C library containing numerous general-purpose functions that will be used in future C school assignments[cite: 4, 15]. [cite_start]The goal of this project is to understand how standard functions work by implementing them from scratch and learning to use them effectively[cite: 14].

The library is divided into three main sections:
1. [cite_start]**Libc Functions**: Reimplementations of standard functions like `strlen`, `memcpy`, and `atoi` with the same prototypes and behaviors as the originals[cite: 106, 107].
2. [cite_start]**Additional Functions**: Functions that are either not included in the libc or exist in a different form, such as `ft_split` and `ft_itoa`[cite: 149].
3. [cite_start]**Linked List Functions**: Functions used to manipulate a list structure to easily manage data nodes[cite: 196, 201].

---

## Instructions

### Compilation
[cite_start]The project includes a **Makefile** that compiles all source files with the flags `-Wall -Wextra -Werror` using `cc`[cite: 25, 99].

* [cite_start]**Rules**: [cite: 27, 28]
    * [cite_start]`make` or `make all`: Compiles the mandatory part and creates the `libft.a` library[cite: 91].
    * [cite_start]`make bonus`: Compiles the additional linked list functions[cite: 28].
    * [cite_start]`make clean`: Removes the object files[cite: 27].
    * [cite_start]`make fclean`: Removes the object files and the generated library[cite: 27].
    * [cite_start]`make re`: Performs a full re-compilation (fclean + all)[cite: 27].

### Technical Considerations
* [cite_start]Declaring global variables is strictly forbidden[cite: 94].
* [cite_start]Helper functions must be defined as `static` to restrict their scope[cite: 96].
* The library is created using the `ar` command; [cite_start]`libtool` is forbidden[cite: 100].
* [cite_start]All files must be placed at the root of the repository[cite: 97, 246].

---

## Library Content

### Part 1 - Libc Functions
[cite_start]These functions follow the behavior of the standard man pages but are prefixed with `ft_`[cite: 107, 108].
* [cite_start]**Memory**: `memset`, `bzero`, `memcpy`, `memmove`, `memchr`, `memcmp`, `calloc` [cite: 118-132, 138].
* [cite_start]**Strings**: `strlen`, `strlcpy`, `strlcat`, `strchr`, `strrchr`, `strncmp`, `strnstr`, `strdup` [cite: 119-139].
* [cite_start]**Character Classification**: `isalpha`, `isdigit`, `isalnum`, `isascii`, `isprint`, `toupper`, `tolower` [cite: 116-134].
* [cite_start]**Conversion**: `atoi`[cite: 136].

### Part 2 - Additional Functions
* [cite_start]**String Manipulation**: `ft_substr`, `ft_strjoin`, `ft_strtrim`, `ft_split`, `ft_strmapi`, `ft_striteri` [cite: 151-182].
* [cite_start]**Conversion**: `ft_itoa`[cite: 170].
* [cite_start]**Output (File Descriptors)**: `ft_putchar_fd`, `ft_putstr_fd`, `ft_putendl_fd`, `ft_putnbr_fd` [cite: 183-193].

### Part 3 - Linked List Functions
[cite_start]These functions utilize the `t_list` structure[cite: 197].
* [cite_start]`ft_lstnew`, `ft_lstadd_front`, `ft_lstsize`, `ft_lstlast`, `ft_lstadd_back`, `ft_lstdelone`, `ft_lstclear`, `ft_lstiter`, `ft_lstmap` [cite: 201-232].

---

## Resources

### References
* [cite_start]C Standard Library Documentation (man pages)[cite: 107].
* [cite_start]42 Norminette Documentation[cite: 20].
* [cite_start]Tutorials on Dynamic Memory Allocation and Linked Lists[cite: 137, 195].

### AI Usage Disclosure
[cite_start]As required by the 42 AI instructions[cite: 239], here is how AI tools were utilized:
* [cite_start]**Conceptual Clarification**: AI was used to explain the logic behind pointer arithmetic and the behavior of `memmove` regarding overlapping memory regions[cite: 82].
* [cite_start]**Logic Verification**: Used to brainstorm edge cases for functions like `ft_split` and `ft_atoi` to ensure robustness[cite: 58].
* [cite_start]**Peer Learning**: AI was used as a secondary resource only after attempting to solve problems through reasoning and peer discussion[cite: 58, 82].