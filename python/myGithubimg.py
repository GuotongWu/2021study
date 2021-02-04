import requests
import os
from bs4 import BeautifulSoup

res = requests.get('https://news.swjtu.edu.cn/shownews-21083.shtml')
res.raise_for_status()
res.encoding = "utf-8"

htmlSoup = BeautifulSoup(res.text, "html.parser")

imgElems = htmlSoup.find_all('img')
print('len(imgElems) = ' + str(len(imgElems)))
if imgElems == []:
    print('Error')
else:
    cnt = 0
    for imgElem in imgElems:
        imgURL = imgElem.get('src')
        if imgURL == '':
            continue
        else:
            # print(imgURL)
            imgURL = 'https://news.swjtu.edu.cn/' + imgURL
            print('DownLoad image %s' %(imgURL))
            imgres = requests.get(imgURL)
            imgres.raise_for_status()

            imageFile = open(os.path.join('D:\\Github\\2021study\\source', os.path.basename(imgURL)), 'wb')
            imageFile.write(imgres.content)
            cnt += 1
            imageFile.close()
            if cnt == 10:
                break