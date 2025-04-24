#!/usr/bin/env python

import struct
import sys
import re

if __name__ == '__main__':
    for line in sys.stdin:
        match = re.match(r'.*can_id=(\S+).*rtr=(\S+).*?size=(\S+).*data=(\S+)', line)
        if not match:
            continue
        cob_id = int(match.groups()[0], 16)
        rtr    = int(match.groups()[1])
        size   = int(match.groups()[2], 16)
        data   = bytes.fromhex(match.groups()[3])

        frame = (cob_id << 5 & 0b1111111111100000) | (rtr << 4 & 0b10000) | (size & 0b1111)
        frame = struct.pack('>H', frame) + data
        print(frame.hex())
