import re as reg

def tokenize_sentence(sentence):
    return reg.split('(?<!\w\.\w.)(?<![A-Z][a-z]\.)(?<=\.|\?)\s',sentence)

def tokenize_word(word):
    return word.split(' ')

def count_words(sentence):
    words = {}
    for _ in sentence:
        try:
            words[_]+=1
        except:
            words[_] = 1
    return words

with open('input.txt', 'r') as f:
    text = f.read()

sentences = tokenize_sentence(text)

words = tokenize_word(text)

print('SPECEFIC WORDS : ')
print(words)
print('TOTAL WORD COUNT : ')
print(count_words(words))
print("VOCABULARY SIZE = " + str(len(set(words))))
print("TOTAL SENTENCE COUNT = " + str(len(sentences)))
sentences = set(sentences)

with open('output.csv', 'w') as f:
    i = 0
    for _ in sentences:
        f.write(str(i) + ',' + _ + '\n')
        i+=1