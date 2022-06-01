#!/usr/bin/python3
"""Computes metrics"""
import sys

if __name__ == "__main__":
    counter = 1
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
            if counter % 10 == 0:
                print("File size: {}".format(sum))
                for key in sorted(metrics):
                    print("{}: {}".format(key, metrics[key]))
            counter += 1
    except Exception:
        pass
    finally:
        print("File size: {}".format(sum))
        for key in sorted(metrics):
            print("{}: {}".format(key, metrics[key]))
