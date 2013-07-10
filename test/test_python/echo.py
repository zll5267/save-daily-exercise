#echo the arguments
import sys
print(sys.argv)
d = {0:'spam'}
try:
    print(d[1])
except Exception as err:
    print('error')

file = open('exam.txt','w')
print(dir(file))
print(type(file))
file.write('zhang\n')
file.write('张\n')
file.flush();
file.close();
