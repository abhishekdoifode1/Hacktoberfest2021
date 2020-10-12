"""
Renames .m4a files to .m4b

Usage:
    python m4a_to_m4b.py path
    if path not specified, will use current working directory

"""
import os
import sys

def main():

    path = os.getcwd() if len(sys.argv) == 1 else sys.argv[1]
    os.chdir(path)
    files = os.listdir(".")

    for file in files:
        if ".m4a" not in file:
            continue
        dest = file.replace(".m4a", ".m4b")
        print(f"Renaming {file} to {dest}")
        os.rename(file, dest)

if __name__ == '__main__': 
    main()


