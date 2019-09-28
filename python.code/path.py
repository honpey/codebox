import os as os

try:
    print os.path.abspath("./tet.py")
    print os.path.basename("./test.ps")
    print os.path.dirname(os.path.abspath("./test"))
except:
    print "Fault"

print "hello world"
