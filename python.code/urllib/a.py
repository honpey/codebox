# -*- encoding=utf-8 -*-
import hmac
import base64
import urllib
import datetime
import urllib.request
import urllib.parse
import json

'''
Open API for Baiying API
'''

request_obj = urllib.request.Request(url="127.0.0.1:8000")

response_obj = urllib.request.urlopen(request_obj)
html_code = response_obj.read().decode('utf-8')

print(html_code)
