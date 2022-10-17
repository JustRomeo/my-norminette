
# MyNorminette
This program is intended to only display code that is "non-compliant" with a global standard.


## Handled
There are files that are detected, some are code files, some are not. The goal is just to analyze a file regardless of its extension. Thus, certain files without code can be analyzed to check their functioning or their understanding (human or machine depending on the context).

> WARNING: some files are detected but not scanned.

Some files are detected but not analyzed because there is no need for them. Some others are detected but not YET analyzed. Their parsing will come later.
Some other are not even detected by the program.
<br>
| Extension |  Code  |  analyze  |
| --------- | :----: | :-------: |
| Makefile | No | No |
| .a | No | No |
| .asm | Yes | Yes |
| .c | Yes | Yes |
| .cabal | Yes | No |
| .cmake | No | No |
| .cpp | Yes | Yes |
| .h | No | Yes |
| .hpp | No | Yes |
| .hs | No | No |
| .jpg | No | No |
| .js | No | No |
| .json | No | No |
| .md | No | No |
| .o | No | No |
| .png | No | No |
| .py | Yes | Yes |
| .row | No | No |
| .sh | No | No |
| .sql | No | No |
| .xml | No | No |


## Todo

### Flags:
- Add ignore folder flag
- add ignore extension flag
- add ignore file flag
- add ignore unkown

### Issues Update
- C proto. functions segfault

### System Updates:
- Add norme errors name (G3, O1, ...)
- Double cotes (``"``) detection
- Simple cotes (``'``) detection

### Files Updates:
- Update Python files parsing
