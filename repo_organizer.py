from collections import defaultdict 
import re
import os
from os import listdir
from os.path import isfile, join

'''
Collecting files with their extension in a dictionary
Moving them to their respective folder if the language has more than 3 files
Folders present already werent' changed 
To organize the repo again just run this program again 
'''
onlyfiles = [f for f in listdir("Hacktoberfest2021-2") if isfile(join("Hacktoberfest2021-2", f))]
lang=defaultdict(list)

for i in onlyfiles:
    ext = re.findall("\.([\S]+)$",i)
    if ext and ext[0].count('.')==0:
        ext[0] = ext[0].lower()
        lang[ext[0]].append(i)
    else:
        lang['other'].append(i)

shortforms = {'js':'JavaScript-programs','kt':'Kotlin-programs','py':'Python-programs'}
for i in lang.keys():
    if len(lang[i])>=3:
        for j in lang[i]:
            if i in shortforms and j!='repo_organizer.py':
                if not os.path.exists(f'Hacktoberfest2021-2/{shortforms[i]}'):
                    os.makedirs(f'Hacktoberfest2021-2/{shortforms[i]}')
                os.replace(f"Hacktoberfest2021-2/{j}",f"Hacktoberfest2021-2/{shortforms[i]}/{j}")
            else:
                folder = i+'-programs'
                if not os.path.exists(f'Hacktoberfest2021-2/{folder}'):
                    os.makedirs(f'Hacktoberfest2021-2/{folder}')
                os.replace(f"Hacktoberfest2021-2/{j}",f"Hacktoberfest2021-2/{folder}/{j}")
