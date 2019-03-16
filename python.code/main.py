from class2.hi2 import base
from class2.hi2.base import hi
from class2.hi4 import base
if __name__ == '__main__':
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
    base1 = base.People
    peo = base.People("xiaolv", 12)
    print peo.name
    print peo.age
    print base1.name
    print base1.age

