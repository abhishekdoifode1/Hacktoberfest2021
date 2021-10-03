import requests
from bs4 import BeautifulSoup
import json

URL = 'https://www.dutchmultimedia.nl/top-100-meest-gebruikte-franse-werkwoorden/'
page = requests.get(URL)
soup = BeautifulSoup(page.content, 'html.parser')

result = soup.find('div', class_='table-responsive')
tbody = result.find('tbody')
trList = tbody.findAll('tr')

timedict = {}

def add_to_dict(dict):
    length = len(timedict)
    timedict[length + 1] = dict

wwDict = {}

wwList = []
for a in trList:
    wwDict = {a.findAll('td')[1].text.strip() : a.findAll('td')[2].text.strip()}
    add_to_dict(wwDict)
print(timedict)

with open('100Translation.json', 'w', encoding='utf-8') as jsonfile:
    json.dump(timedict, jsonfile, ensure_ascii=False)

