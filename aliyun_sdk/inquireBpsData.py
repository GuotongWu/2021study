#引入aliyunsdkcore包
from aliyunsdkcore import client
#引入aliyunsdklie包
from aliyunsdklive.request.v20161101 import DescribeLiveDomainBpsDataRequest
#初始化client
#AK和Secrect需要自己提供（可以在阿里云控制台中找到）
AK = 'LTAI4GKEe5P4547RSdYEvQ9C'
Secret = 'iabcuTObZx6SZnYfHoazF0O8carcTv'
#以访问cn-hangzhou region为例
clt = client.AcsClient(AK, Secret, 'cn-shenzhen')
#构造需发起的API请求调用
# request = DescribeLiveStreamsFrameRateAndBitRateDataRequest.DescribeLiveStreamsFrameRateAndBitRateDataRequest()
request = DescribeLiveDomainBpsDataRequest.DescribeLiveDomainBpsDataRequest()
# request.set_StartTime('2021-02-01T08:00:00Z')
# request.set_EndTime('2021-02-05T08:00:00Z')
request.set_DomainName('newpullstream.omysycamore.top')
# request.set_AppName('apptransvideo')
# request.set_StreamName('streamtransvideo')
#发起请求
result = clt.do_action_with_exception(request)
#请求结果
#result为请求结果的ResponseBody字符串
# print(result)
#如果您需要进一步对result进行处理，可以根据每个接口的返回格式，进行格式化处理并进一步分析或使用
#对于DescribeLiveStreamsFrameRateAndBitRateDataRequest来说，它返回一个json格式的数据，我们可以用json包来处理这些response
import json
x = json.loads(result)
# print(x)
with open('aliyun.json', 'w') as f:
    json.dump(x, f, indent=1)
# print(x['FrameRateAndBitRateInfos'])