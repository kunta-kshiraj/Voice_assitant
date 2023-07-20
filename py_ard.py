import socket
import datetime
import time

s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
s.connect(('192.168.29.11', 80))
v=1
while True:
    time1=datetime.datetime.now().strftime("%H %M %S")
    if(v==1):
        time4=input("Enter time in hh mm ss format : ")
        v=0
    time.sleep(1)
    if time1==time4:
        sval=str("a")
        bval=sval.encode()
        s.send(bval)
        print("done")
    if time1=="02 11 01":
        
        sval=str("b")
        bval=sval.encode()
        s.send(bval)
        print("done")
    if time1=="01 56 31":
        
        sval=str("c")
        bval=sval.encode()
        s.send(bval)
        
        print("done")
