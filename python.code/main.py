from class2.hi3 import base
if __name__ == '__main__':
    xiaohong = base.hi("xiaohong")
    print xiaohong.getName()
    xiaoming = base.hi2("xiaoming", 12)
    print xiaoming.setAge(13)
    print xiaoming.getNameAge()
    print "hello world"
