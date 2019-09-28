# -*- coding: UTF-8 -*-
import re

if __name__ == '__main__':
    var11 = "12a"
    if isinstance(var11, int):
        print("isdigt")
    path = "hello world/12/edit"
    if re.match(".*world/[0-3]*/edit$", path):
        print("matched")
    else:
        print("--------")

