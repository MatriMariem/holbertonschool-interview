#!/usr/bin/python3
"""
We have n number of locked boxes in front of us. Each box is numbered sequentially from 0 to n - 1 and each box may contain keys to the other boxes.
"""

def canUnlockAll(boxes):
    """a method that determines if all the boxes can be opened"""
    Unlocked = [False for i in boxes]
    Unlocked[0] = True
    Open = [False for i in boxes]
    while [True for i in range(len(boxes)) if Open[i] == False and Unlocked[i] == True]:
        for k in range(len(boxes)):
            if Unlocked[k] == True:
                Open[k] = True
                for i in boxes[k]:
                    Unlocked[i] = True
    return False not in Unlocked
