#!/usr/bin/python3
"""Computes metrics"""
import sys

if __name__ == "__main__":
    counter = 1
    sum = 0
    metrics = {200: 0, 301: 0, 400: 0, 401: 0, 403: 0, 404: 0, 405: 0, 500: 0}
    try:
        for line in sys.stdin:
            # line = line.rstrip()
            line = line.split(" ")
            sum += int(line[-1])
            code = int(line[-2])
            if code in metrics:
                metrics[code] += 1
            if counter % 10 == 0:
                print("File size: {}".format(sum))
                for key, value in sorted(metrics.items()):
                    if (value):
                        print("{}: {}".format(key, value))
            counter += 1
    except Exception:
        pass
    finally:
        print("File size: {}".format(sum))
        for key, value in sorted(metrics.items()):
            if (value):
                print("{}: {}".format(key, value))
