# -*- coding: UTF-8 -*-
if __name__ == '__main__':
    """
    """
    iMap = {'a':1, 'b':2, 'c':3, 'd':4}
    print("iMap:", iMap)
    data = iMap
    op = data.pop('aa', None)
    print("data:", data)
    print("op:", op)
