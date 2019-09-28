# -*- coding: UTF-8 -*-
class People:
    name = "people"
    age = 19
    print u"why info 中文output here, magic python",name,"name",age
    def __init__(self, name, age):
        self.name=name         
        self.age = age
    def setAge(self, name):
        self.name=name
