
echo '#0------>'
bison -d -y -v 1405079.y	
echo '#1------>'
g++ -w -c -o y.o y.tab.c	

echo '#2------>'
flex 1405079.l		

echo '#3------>'
g++ -fpermissive -w -c -o l.o lex.yy.c

echo '#4------>'
g++ -o a.out y.o l.o -lfl -ly	

echo '#5------>'
./a.out	in.txt
