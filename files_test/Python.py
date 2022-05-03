import os

class MyTestPythonClass:

    def __init__(self):
        super().__init__()

        print("Constructeur")

    def clear(self):
        os.system("clear")


# Main here
if __name__ == "__main__":
    _int : int = 0
    _str : str = ""
    _bool : bool = False;
    new_value = "mydata"

    _int = 7
    _str = "My value is:"
    if not _bool:
        print(_str, _int)
