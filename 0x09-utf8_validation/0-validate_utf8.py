#!/usr/bin/python3
""" UTF-8 Validation """


def countOnes(num):
    """ Count ones in num """
    count = 0
    for i in range(7, -1, -1):
        if num & (7 << i):
            count += 1
        else:
            break
    return count


def validUTF8(data):
    """ validaUTF8 """
    count = 0
    for d in data:
        if not count:
            count = countOnes(d)
            if count == 0:
                continue
            if count == 1 or count > 4:
                return False
            count -= 1
        else:
            count -= 1
            if countOnes(d) != 1:
                return False
    return count == 0
