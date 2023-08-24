
<div align="center">
    <h1>:recycle:holbertonschool-simple_shell:recycle:</h1>
</div>

![Holberton School Logo](https://raw.githubusercontent.com/Groinkb/holbertonschool-simple_shell/feature/pictures/Photo%20Holberton.webp)

![UBUNTU](https://img.shields.io/badge/Ubuntu-E95420?style=for-the-badge&logo=ubuntu&logoColor=white)![C](https://img.shields.io/badge/C-00599C?style=for-the-badge&logo=c&logoColor=white)

### How to use shell ?

you can refer to the *manual* :smirk:


## Man page

The man page is a file wich explains in detail how the function works. If you want see a full explanation of this function you can run our man page this way:
```
$ man ./man_1_simple_shell
```

## Flowchart

![Flowchart](https://github.com/Groinkb/holbertonschool-simple_shell/blob/feature/pictures/Flowchart.jpg?raw=true)

### A brief description of our SHELL functions

- **AUTHORS** : to find the Github and the Email of all contributors
- **main.h** : the lists of all Macros, librairies and prototypes
- **shell.c** The main fonction, to recieve input from CLI parse and execute it
- **environ.c** : There are functions
* :zero: Change directory
* :one: Change or add environment variables
* :two: Delete an environment variable
* :three: Print our environment and a function to exit built in
- **executor.c** : There is a function
* :zero: Fork process and replace the child with a new program, and a function
* :one: Choose from an array of builtin functions
- **func_help.c** : There is functions created and used to help us. There are functions
* :zero: Concatenate two strings
* :one: Reallocate a memory block
- **tokenizer.c** : We find functions to manage tokens. There are funtions
* :zero: Split the input string into a array of arguments (tokens)
* :one: Split the environment variable PATH into an array of tokens
* :two: Validate if PATH exists and to validate spaces, tabs and line breaks

### What does our SHELL function do ?

* **First**, the parent process is created when the user runs the program. Then the isatty() function uses the open file descriptor referring to a terminal. If isatty() returns, the command prompt is displayed using write() with STDOUT_FILENO and waits for a user command line as input. When the user types a command, the getline() function reads an entire line from the stream and the strtok() function breaks the command into a non-empty token input.

* **Then** it created a separate child process using fork() that executes the entered command. Unless otherwise specified, the parent process waits for the child process to finish before continuing. After the command is marked, the excve() function brings it in and executes it, then frees all the memory allocated with free(). Finally, the program returns to the main process: it prints the prompt, and waits for another input from the user.

* **To further explain**, the tokenizer() function works in the same way as strtok(). It creates an array of pointers to store the arguments.

* **Finally**, this implementation of tokens is essential for our command prompt to continue to display after a successful execution or an error.

## Authors :fist_right::fist_left:

* Raphael Schopfer <a href="https://github.com/RaphSchp" rel="nofollow"><img align="center" alt="github" src="https://www.vectorlogo.zone/logos/github/github-tile.svg" height="24" /></a>
* Benjamin Marchal <a href="https://github.com/Groinkb" rel="nofollow"><img align="center" alt="github" src="https://www.vectorlogo.zone/logos/github/github-tile.svg" height="24" /></a>
* C#21 THONON <a href="https://www.youtube.com/watch?time_continue=2&v=D2_r4q2imnQ&embeds_referring_euri=https%3A%2F%2Fwww.google.com%2Fsearch%3Fsca_esv%3D559082108%26rlz%3D1C1ONGR_frFR1059FR1059%26q%3Dbruh%26tbm%3Dvid%26source%3Dlnms%26sa%3DX%26ved%3D2ahUKEwjl_cbXs_CA&source_ve_path=Mjg2NjIsMzY4NDIsMzY4NDIsMjM4NTE&feature=emb_title" rel="nofollow"><img align="center" alt="heart" src="https://vectorwiki.com/images/a2I5f__heart.svg" height="24" /></a>

## License

This program is distributed under the terms of the Holberton license. :goat:
:goat:
.

# holbertonschool-simple_shell
Repository for the simple-shell project.

uppdate for develop branch 
