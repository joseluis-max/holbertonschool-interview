#!/usr/bin/python3
''' Write a script that reads stdin line by line and computes metrics:'''

import sys

if __name__ == '__main__':
    counter = 0
    sum = 0
    metrics = {}
    try:
        for line in sys.stdin:
            line = line.rstrip()
            line = line.split(" ")
            sum += int(line[-1])
            try:
                metrics[line[-2]] += 1
            except KeyError:
                metrics[line[-2]] = 1
            counter += 1
            if counter == 10:
                counter = 0
                print("File size: {:d}".format(sum))
                for key in sorted(metrics):
                    print(f"{key}: {metrics[key]}")
    except KeyboardInterrupt:
        print("File size: {:d}".format(sum))
        for key in sorted(metrics):
            print(f"{key}: {metrics[key]}")
