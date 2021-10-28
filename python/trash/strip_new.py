import re

def strip_new(originstr, del_str=''):
    # usefulstr = ''
    if del_str == '':
        strRule = re.compile(r'\w+')
        usefulstr = strRule.search(originstr).group()
    else:
        usefulstr = re.compile(del_str).sub('', originstr)
    return usefulstr

if __name__ == '__main__':
    a = ' 123 '
    print(strip_new(a))
    b = '123w345ww3w'
    print(strip_new(b, 'w'))