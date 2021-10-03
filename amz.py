import requests
import time
from spi import sendNotifications
from bs4 import BeautifulSoup
site="https://www.amazon.in/Amazon-Brand-Presto-Oxo-Biodegradable-Garbage/dp/B0821PN8L4/ref=sr_1_5?crid=NS0P8RW3B18S&dchild=1&keywords=limited+time+deal+offers&qid=1624124560&smid=AT95IG9ONZD7S&sprefix=limited%2Caps%2C368&sr=8-5"
HEADERS = ({'User-Agent':
           'Mozilla/5.0 (X11; Linux x86_64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/44.0.2403.157 Safari/537.36','Accept-Language': 'en-US, en;q=0.5'})
def getprice(site,HEADERS):
    page=requests.get(site,headers=HEADERS)
    hpage=BeautifulSoup(page.content,'html.parser')
    price=hpage.find(id="priceblock_dealprice")
    if price is None:
        price=hpage.find(id="priceblock_ourprice")
    header=hpage.find(id="productTitle")
    #print(price,header)
    product=header.text.strip()
    price=float(price.text[1:])
    return product,price
prev_price=0
def make_msg(price,product,prev_price):
    msg = "Subject: " + product + " cost update"
    if prev_price<price:
        msg+="\n\nHi!\n Price increased for the product you wanted to track \n\nprevious price: "+str(prev_price)+"\n present price:"+str(price)+"\nlink: "+site+"\nThanks, Bot"
    elif prev_price>price:
        msg+="\n\nHi!\n Price decreased for the product you wanted to track \n\nprevious price: "+str(prev_price)+"\n present price:"+str(price)+"\nlink: "+site+"\nThanks, Bot"
    else:
        msg+="\n\nsame price\n price: "+str(price)
    sendNotifications(msg,"xyx@gmail.com")
#time.sleep(20*60)
print("wait over")
while True:
    product,pres_price=getprice(site,HEADERS)
    print(product,prev_price,pres_price)
    make_msg(pres_price,product,prev_price)
    prev_price=pres_price
    time.sleep(30)