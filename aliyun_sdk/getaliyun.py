import json
jsondata = json.load(open('aliyun.json'))
bpsdata = jsondata['BpsDataPerInterval']['DataModule']
count = 0
for da in bpsdata:
    if da['HttpsBpsValue'] != 0:
        print('TimeStamp = ' + str(da['TimeStamp']))
        count += 1
if count == 0:
    print('Not Found.')