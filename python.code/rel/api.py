import hmac
import base64
import urllib
import datetime
import urllib.request
import urllib.parse
import json
import os

# ak 需要获取
appKey = 'prVWMqVAjtDxtEb6'
appSecrete = '5OVSohXpJI4T0zxqVG7yQqJBxnqOgg'

# GMT时间获取
GMT_FORMAT = '%a, %d %b %Y %H:%M:%S GMT'
time_format_gmt = (datetime.datetime.now() - datetime.timedelta(hours=8)).strftime(GMT_FORMAT)
print(time_format_gmt)


# 签名计算
signMessage = appKey + '\n' + time_format_gmt
quote = base64.b64encode(
    hmac.new(bytes(appSecrete.encode("utf-8")), bytes(signMessage.encode("utf-8")), digestmod='sha1')
        .digest()).decode("utf-8")

# 百应线上环境api访问地址
BASE_URL = "http://api.byrobot.cn"

def init_env():
    appKey = 'prVWMqVAjtDxtEb6'
    appSecrete = '5OVSohXpJI4T0zxqVG7yQqJBxnqOgg'

    GMT_FORMAT = '%a, %d %b %Y %H:%M:%S GMT'
    time_format_gmt = (datetime.datetime.now() - datetime.timedelta(hours=8)).strftime(GMT_FORMAT)
    print("time_format_gmt: ", time_format_gmt)

    signMessage = appKey + '\n' + time_format_gmt
    quote = base64.b64encode(
        hmac.new(bytes(appSecrete.encode("utf-8")), bytes(signMessage.encode("utf-8")), digestmod='sha1')
            .digest()).decode("utf-8")

    BASE_URL = "http://api.byrobot.cn"

def get_companys():
    print("time_format_gmt: ", time_format_gmt)
    print("time_format_gmt: ", type(time_format_gmt))

    request_obj = urllib.request.Request(url=BASE_URL + "/openapi/v1/company/getCompanys")
    request_obj.add_header("sign", quote)
    request_obj.add_header("datetime", time_format_gmt)
    request_obj.add_header("appkey", appKey)
    response_obj = urllib.request.urlopen(request_obj)
    html_code = response_obj.read().decode('utf-8')
    print("--------------------html_code",html_code)
    return html_code


def get_phones(companyId):
    request_obj = urllib.request.Request(url=BASE_URL + "/openapi/v1/company/getPhones?" + str(companyId))
    request_obj.add_header("sign", quote)
    request_obj.add_header("datetime", time_format_gmt)
    request_obj.add_header("appkey", appKey)
    response_obj = urllib.request.urlopen(request_obj)
    html_code = response_obj.read().decode('utf-8')
    return html_code


def getRobots(companyId):

    request_obj = urllib.request.Request(url=BASE_URL + "/openapi/v1/company/getRobots?companyId=" + str(companyId))

    request_obj.add_header("sign", quote)
    request_obj.add_header("datetime", time_format_gmt)
    request_obj.add_header("appkey", appKey)

    response_obj = urllib.request.urlopen(request_obj)
    html_code = response_obj.read().decode('utf-8')
    return html_code

# 获取一个公司的所有任务的列表
def getCompanyTaskList(companyId):

    request_obj = urllib.request.Request(BASE_URL + "/openapi/v1/task/getTasks?companyId=" + str(companyId))

    request_obj.add_header("sign", quote)
    request_obj.add_header("datetime", time_format_gmt)
    request_obj.add_header("appkey", appKey)

    response_obj = urllib.request.urlopen(request_obj)
    html_code = response_obj.read().decode('utf-8')
    return html_code

def post_create_job():
    textmod = {
          "companyId" : 15960,
          "taskName" : "测试任务",
          "taskType" : 2,
          "startDate" : "2019-06-09",
          "workingStartTime" : "08:00",
          "workingEndTime" : "22:00",
          "breakStartTime":"12:00",
          "breakEndTime":"14:00",
          "userPhoneIds" : [47451,47452,47453,53109],
          "callType" : 1,
          "concurrencyQuota" :1,
          "robotDefId" : 71095,
          "sceneDefId" : 1,
          "sceneRecordId" : 7,
          "remark" : "创建任务"
      }
    textmod = json.dumps(textmod).encode(encoding='utf-8')
    print(textmod)
    header_dict = {"Content-Type": "application/json"}
    req = urllib.request.Request(url=BASE_URL+'/openapi/v1/task/createTask', data=textmod, headers=header_dict)
    req.add_header("sign", quote)
    req.add_header("datetime", time_format_gmt)
    req.add_header("appkey", appKey)
    res = urllib.request.urlopen(req)
    res = res.read()
    print("post_create_job", res.decode(encoding='utf-8'))



def getDoneTaskPhone(calljobId):

    taskInfo = {
		"callJobId" : calljobId
    }

    json_result = json.dumps(taskInfo).encode(encoding='utf-8')
    header_dict = {"Content-Type": "application/json"}
    request_obj = urllib.request.Request(url=BASE_URL + "/openapi/v1/task/queryDoneTaskPhones", data=json_result, headers=header_dict)

    request_obj.add_header("sign", quote)
    request_obj.add_header("datetime", time_format_gmt)
    request_obj.add_header("appkey", appKey)

    response_obj = urllib.request.urlopen(request_obj)
    html_code = response_obj.read().decode('utf-8')

    return html_code

def importTaskCustomer(companyId, taskId, username, phone_number):

    taskInfo = {
        "companyId": companyId,
        "taskId": taskId,
        "customerInfoList":[
            {
                "name":username,
                "phone": phone_number
            },
        ]
    }

    json_result = json.dumps(taskInfo).encode(encoding='utf-8')
    print(json_result)
    header_dict = {"Content-Type": "application/json"}
    request_obj = urllib.request.Request(url=BASE_URL + "/openapi/v2/task/importTaskCustomer", data=json_result, headers=header_dict)

    request_obj.add_header("sign", quote)
    request_obj.add_header("datetime", time_format_gmt)
    request_obj.add_header("appkey", appKey)

    response_obj = urllib.request.urlopen(request_obj)
    html_code = response_obj.read().decode('utf-8')
    return html_code

print(get_companys())

