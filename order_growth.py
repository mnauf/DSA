import time
import math
from tabulate import tabulate
n=eval(input("Enter the value of n: "));
t1=time.time()
a=12
t2=time.time()
A=t2-t1
t3=time.time()
b=math.log10(n);
t4=time.time()
B=t4-t3
t5=time.time()
c=n;
t6=time.time()
C=t6-t5
t7=time.time()
d=n*math.log10(n);
t8=time.time()
D=t8-t7
t9=time.time()
e=n**2
t10=time.time()
E=t10-t9
t11=time.time()
f=2**n
t12=time.time()
F=t12-t11

print(tabulate([['constant',a,A], ['logn',b,B], ['n',c,C], ['nlogn',d,D], ['n**2',e,E], ['2**n',f,F]], headers=['Function', 'Value', 'Time']))
templist= [A,B,C,D,E,F]
print("The time order in acsending order is: ", sorted(templist,key=int)) 
