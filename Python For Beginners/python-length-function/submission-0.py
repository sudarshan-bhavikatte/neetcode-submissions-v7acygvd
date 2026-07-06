def get_longer_word(word1: str, word2: str) -> str:
    n1 = len(word1)
    n2 = len(word2)
    if(n1 >= n2):
        return word1
    else:
        return word2



# do not modify below this line
print(get_longer_word("yellow", "orange"))
print(get_longer_word("red", "blue"))
print(get_longer_word("green", "blue"))
