str1 = 'aaabbbccc'
iter1 = iter(str1)

for i in iter1:
    print(i,end=' ')

iter1 = iter(str1)
print('\n---------------------')

# 使用next函数遍历迭代器
while True:
    try:
        print(next(iter1),end=' ')
    except StopIteration:
        break