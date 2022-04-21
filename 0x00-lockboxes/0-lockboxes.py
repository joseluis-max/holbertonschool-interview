#!/usr/bin/python3
""" Unlocked All Boxes """


def canUnlockAll(boxes):
    """ Method for determinate if the all boxes can be opened """
    openedBoxes = [False] * len(boxes)
    openedBoxes[0] = True
    stack = [0]

    while stack:
        box = stack.pop()
        for key in boxes[box]:
            try:
                if not openedBoxes[key]:
                    openedBoxes[key] = True
                    stack.append(key)
            except IndexError:
                pass
        if all(openedBoxes):
            return True

    return False
