#!/usr/bin/env python
# coding=utf-8

import urllib2

result = []

for i in range(1,6):
    urlname = 'http://acm.sgu.ru/problemset.php?contest=0&volume=' + str(i)
    print urlname
    urlfile = urllib2.urlopen(urlname) #以文件的形式打开一个网页
    html = urlfile.read() #从网页文件中读html
    start = 0
    while start < len(html):
        pos = html.find('problem.php?contest=0&problem=', start);
        if pos < 1:
            break

        pos1 = html.find('>', pos)
        pos2 = html.find('<', pos)
        id = html[pos1+1:pos2]

        pos3 = html.find('&nbsp;', pos)
        pos4 = html.find('<', pos3)
        name = html[pos3+6:pos4]

        pos5 = html.find('status.php', pos4)
        pos6 = html.find('>', pos5)
        pos7 = html.find('<', pos5)
        ac = int(html[pos6+1:pos7])
        tup = (id,name,ac)
        result.append(tup)
        start = pos7

result.sort(lambda y,x:cmp(x[2],y[2]))

file_object = open('README.md', 'w')
file_object.write('ID | TITLE | AC\n')
file_object.write(':----:|:----:|:----:\n')
for item in result:
    file_object.write('[' + item[0] + ']' + '(http://acm.sgu.ru/problem.php?contest=0&problem=' + item[0] + ')' + '|' + item[1] + '|' + str(item[2]) + '\n')

file_object.close( )