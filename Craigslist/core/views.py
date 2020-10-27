import requests

from bs4 import BeautifulSoup
from core.forms import SearchForm
from core.models import Search
from django.shortcuts import render


def home(request):
    return render(request,'core/home.html',context={})

def new_search(request):
    if request.method == 'POST':
        forms=SearchForm(request.POST)
        if forms.is_valid():
            stuff_to_frontend=searching(forms.cleaned_data['search'])
            forms.save()
        return render(request,'core/search.html',context={'forms':forms,'content_data':stuff_to_frontend})
    else:
        forms=SearchForm()
        # BUG: Debug forms widgets need to change
        # import pdb; import pdb; pdb.set_trace()
        return render(request,'core/search.html',context={'forms':forms})

def extrat_link(url):
    res = requests.get(url)
    html_doc = res.content
    soup = BeautifulSoup(html_doc, 'html.parser')
    img = soup.find('img')
    head = soup.find('span', {'id':'titletextonly'})
    body = soup.find('section', {'id':'postingbody'})
    return {'head':head.string, 'img':img['src'], 'body':body.text[18:130]}

def searching(query):
    BASE_URL='https://huntsville.craigslist.org/search/sss?query={}'.format(requests.compat.quote_plus(query))
    res=requests.get(BASE_URL)
    html_doc=res.content
    soup = BeautifulSoup(html_doc, 'html.parser')
    rows=soup.find_all('li',{'class':'result-row'})
    count=0
    data_list=[]
    for row in rows:
        if count >=20:
            break
        try:
            atag=row.find('a')
            link=atag['href']
            var=extrat_link(link)
            _data={}
            _data['title']=var['head']
            _data['image']=var['img']
            _data['body']=var['body']
            _data['url']=link
            data_list.append(_data)
            count=count+1
        except Exception as e:
            print(e)
            continue
    return data_list
