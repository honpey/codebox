def fab(maxV):
    n, a, b = 0, 0, 1
    while n < maxV:
        yield b
        # print b
        a, b = b, a+b
        n = n+1

if __name__ == '__main__':
    for n in fab(5):
        print n
    print 'hello'

