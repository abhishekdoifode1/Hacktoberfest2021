# Importing requests module for intercating with api for translation
import requests,json

#Asking user input
word=str(input("Dear warrior want yo want to translate: "))

#Doing a get request for translation API with user input as parameter for text 
response=requests.get(url='https://api.funtranslations.com/translate/yoda.json?text='+word)

#json.loads(response.text)["error"]["message"] -- >5 requests

if(response.status_code == 429):
    print(json.loads(response.text)["error"]["message"])
elif(response.status_code == 200):
    print(json.loads(response.text)["contents"]["translated"])
elif(response.status_code==400):
    print("Kindly check your request the HTTP method you are using")
else:
    print("Something went wrong!")

#Sample Input:
# Dear warrior want yo want to translate: Master Obiwan has lost a planet.
#
#
#Sample Output:
#
#  {
#    "success": {
#      "total": 1
#    },
#    "contents": {
#      "translated": "Lost a planet,  master obiwan has.",
#      "text": "Master Obiwan has lost a planet.",
#      "translation": "yoda"
#    }
#  }
