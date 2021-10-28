import requests
from bs4 import BeautifulSoup

res = requests.get('https://www.eol.cn/e_html/gk/dxpm/index.shtml')
res.raise_for_status()
res.encoding = "utf-8"
htmlSoup = BeautifulSoup(res.text, "html.parser")
tagRes = htmlSoup.select('tr')
listRes = []

cnt = 0
for t in tagRes:
    tempList = []
    w = t.getText().split('\n')
    for i in range(1,4):
        tempList.append(w[i])
    listRes.append(tempList)
    cnt += 1
    if cnt == 200:
        break

UrankFile = open('UniversityRank.txt', 'w', encoding="UTF-8")

for lres in listRes:
    # print('{0:^7}{1:^15}{2:^7}'.format(lres[0], lres[1], lres[2]))
    UrankFile.write("{0:^7}{1:^15}{2:^7}\n".format(lres[0], lres[1], lres[2]))

UrankFile.close()