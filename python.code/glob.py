import glob

files = glob.glob("te.*.py")
for i in files:
    print i
