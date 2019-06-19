# 42GetNextLine
Function that returns a line ending with a newline, reading from a file descriptor.

125/100 - Max Score

I chose to use linked lists to store the buffer for each file descriptor so that it supports multiple file descriptors. I chose to just reuse the linked list functions from my libft to save time.

Bonuses:
Use only one static variable.
Read from multiple file descriptors without loosing your place.


### Usage:
Use these commands in the terminal.

1.) Download the repository.

```
git clone https://github.com/Jemmeh/42GetNextLine.git
```

2.) move into the Tests folder.

```
cd ./42GetNextLine/WorkFiles_GetNextLine/JemTestsGet_Next_Line/
```

3.) I have a Makefile to easily create the program. It will also compile libft.

```
make
```

4.) Run the program. (poem.txt is included for an example)
```
./GetNextLine fileToRead.txt
```
