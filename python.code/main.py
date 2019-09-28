# -*- coding: UTF-8 -*-
from class2.hi2 import base
from class2.hi2.base import hi
from class2.hi4 import base
from rel.api import get_companys
#在这里做引入的时候就出现
import re
def funca():
    from class2.hi4.base import People
    print "In FuncA"
    print People.name
    print People.age
    People.name = "xiaohong"
    People.age = 12
def funcb():
    from class2.hi4.base import People
    print "In FuncB"
    print People.name
    print People.age
    People.name = "xiaolv"
    People.age = 18


if __name__ == '__main__':
    path = "hello world edit"
    var = 10
    if var.isdigit(): 
        print("is digit")
    if re.match("edit", path):
        print("matched")
    else:
        print("--------")

    """
    xiaohong = base.hi("xiaohong")
    print xiaohong.getName()
    xiaoming = base.hi2("xiaoming", 12)
    print xiaoming.setAge(13)
    print xiaoming.getNameAge()
    print "hello world"

    xiaolv = hi("xiaolv")
    print xiaolv
    """
    res = get_company()
    print(res)
    print "Begin---------"
#    funca()
#    funcb()
   
    print "In FuncC"
    from class2.hi4.base import People
    print People.name
    print People.age
    print dir(People)
    print People.name.__class__.__name__
#    print getattr(People, "name")
#    print getattr(People, "age")

