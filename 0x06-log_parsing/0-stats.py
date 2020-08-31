#!/usr/bin/python3
""" Parses Logs """
import sys


i = 0
FileSize = 0
status = {'200': 0, '301': 0, '400': 0, '401': 0,
          '403': 0, '404': 0, '405': 0, '500': 0}
codes = ['200', '301', '400', '401', '403', '404', '405', '500']
try:
    for line in sys.stdin:
        i += 1
        sp = line.split(' ')
        FileSize += int(sp[-1])
        status[sp[-2]] += 1
        if i % 10 == 0:
            print("File size: {}".format(FileSize))
            for code in codes:
                if status[code]:
                    print("{}: {}".format(code, status[code]))
except KeyboardInterrupt:
    print("File size: {}".format(FileSize))
    for code in codes:
        if status[code]:
            print("{}: {}".format(code, status[code]))
    raise
    sys.exit()
