import requests
from bs4 import BeautifulSoup

res = requests.get('http://106.52.45.216//root/2021study/Network/HelloWorld.html')
res.raise_for_status()
res.encoding = "utf-8"
htmlSoup = BeautifulSoup(res.text, "html.parser")
tagRes = htmlSoup.select('p')

text = tagRes[0].getText()
print(text)
