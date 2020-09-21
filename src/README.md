# Lab Project 1: Tokenizer
This program takes a string inputted by a user and splits the string, using
spaces as the delimiter, into seperate word tokens.

#### Other Features:

  - Keeps a history of strings inputed by user.
  - Allows user to retrieve and reuse specific strings from history
  - Displays items currently in history and their ID

---
---
---

#### How To Use:

To compile, clean up directory, and run program:
```
.../src> make auto
```

---

To view history enter ```?``` at any time.
Example:
```
> ?
```

---

To re-tokenize a string from history enter ```!<ID>```
Example:
```
> !3
```
- *Would retrieve the 3rd string in history and then tokenize it*

---

To terminate the program enter ```~``` at any time.
Example:
```
> ~
```
---
---
---

#### Notes
- Input string must be no longer than 50 characters long.
- No known bugs at the moment

    *- Jorge Favela*
    
