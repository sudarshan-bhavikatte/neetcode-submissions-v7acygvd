from typing import List

def read_integers() -> List[int]:
    char_list = input().split(",")
    int_list = []
    for c in char_list:
        int_list.append(int(c))

    return int_list

# do not modify the code below
print(read_integers())
print(read_integers())
print(read_integers())
