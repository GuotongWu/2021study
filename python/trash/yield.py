def fibon(n):
    a = b = 1
    print('-'*5 + 'begin' + '-'*5)
    for i in range(n):
        yield a
        # 可以将yield理解为return
        a,b = b, a+b

# for n in fibon(10):
    # print(n, end=' ')


# 目标是产生15位的Fibonacci级数
f = fibon(15)
# 但是只想看到（取出）其中的前10位
for n in range(10):
    # 每次next都从上次返回（yield）的地方开始继续执行
    # 第一个next从函数开头执行，直到yield停止
    print(next(f),end=' ')
