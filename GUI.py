#graphical user interface for robot control
import serial
import tkinter as tk
from tkinter import messagebox
import tkinter.font as font

com =input('enter the com port')

ser = serial.Serial(com,9600) 

print("------------------started---------------------------")
def Forward():
    #msg = messagebox.showinfo( "Forward", "Your Robot is moving forward")
    ser.write(b'w')
    
def Backward():
    #msg = messagebox.showinfo( "Backward", "Your Robot is moving backward")
    ser.write(b'z')
    
def Left():
    #msg = messagebox.showinfo( "Left", "Your Robot is moving left")
    ser.write(b'a')
    
def Right():
    #msg = messagebox.showinfo( "Right", "Your Robot is moving right")
    ser.write(b'd')

def Stop():
    #msg = messagebox.showinfo( "Stop", "Your Robot is stopped")
    ser.write(b's')
    
top = tk.Tk()
top.title("Robot Control")
top.geometry("500x400")
top.configure(bg='pink')

myFont = font.Font(family='Helvetica', size=10)

forward = tk.Button(top,  font=myFont, text = "Forward", command = Forward, activebackground='rosy brown', bg='cyan')
forward.place(x = 240,y = 150)

backward = tk.Button(top,font=myFont, text = "Backward", command = Backward, activebackground='rosy brown', bg='cyan')
backward.place(x = 240,y = 250)

left = tk.Button(top,font=myFont, text = "Left", command = Left, activebackground='rosy brown', bg='cyan')
left.place(x = 200,y = 200)
right = tk.Button(top,font=myFont, text = "Right", command = Right, activebackground='rosy brown', bg='cyan')
right.place(x = 300,y = 200)

stop = tk.Button(top,font=myFont, text = "Stop", command = Stop, activebackground='rosy brown', bg='cyan')
stop.place(x = 250,y = 200)

top.mainloop()
ser.close()
