from collections import defaultdict
import re
import os
from os import listdir
from os.path import isfile, join

onlyfiles = [f for f in listdir("Hacktoberfest2021-2") if isfile(join("Hacktoberfest2021-2", f))]
lang=defaultdict(list)
extensions = []

for i in onlyfiles:
    ext = re.findall("\.([\S]+)$",i)
    if ext:
        extensions.extend(ext)
    else:
        extensions.extend(["Others"])
#print(extensions)
#Output -> ['others', 'cpp', 'py', 'java', 'exe', 'c', 'htm', 'html', 'dart', 'ts', 'c++.txt', 'r', 'rb', 'go', 'php', 'kt', 'js', 'C', 'cs', 'ps1', 'kt.txt', 'md', 'jpeg', 'ipynb']
for i in onlyfiles:
    ext = re.findall("\.([\S]+)$",i)
    if ext and ext[0].count('.')==0:
        ext[0] = ext[0].lower()
        lang[ext[0]].append(i)
    else:
        lang["others"].append(i)

shortforms = {'js':'JavaScript-programs','kt':'Kotlin-programs','py':'Python-programs'}
for i in lang.keys():
    if len(lang[i])>=5:
        for j in lang[i]:
            if i in shortforms:
                os.replace(f"Hacktoberfest2021-2/{j}",f"Hacktoberfest2021-2/{shortforms[i]}/{j}")