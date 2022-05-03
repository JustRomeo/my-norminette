
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
| .cpp | Yes | Yes |
| .cmake | No | No |
| .cabal | Yes | No |
| .json | No | No |
| .a | No | No |
| .c | Yes | Yes |
| .hpp | No | Yes |
| .py | Yes | Yes |
| .js | No | No |
| .sh | No | No |
| .hs | No | No |
| .h | No | Yes |
| .asm | Yes | Yes |
| .o | No | No |
| Makefile | No | No |
| .xml | No | No |
| .md | No | No |
| .sql | No | No |
| .jpg | No | No |
| .png | No | No |
| .row | No | No |



## Todo

### Flags:
- Add ignore folder flag
- add ignore extension flag
- add ignore file flag
- add ignore unkown

### System Updates:
- Double cotes (``"``) detection
- Simple cotes (``'``) detection

### Files Updates:
- Update Python files parsing
