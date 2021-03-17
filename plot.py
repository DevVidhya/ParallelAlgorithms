#!/usr/bin/env python
import matplotlib.pyplot as plt 

x1 = [1,2,3,4,5,6,7,8,9,10]  
y1 =  [0.001000,0.002000,0.003000,0.005000,0.006000,0.008000,0.011000,0.015000,0.025000,0.026000] 
plt.plot(x1, y1, label = "Sequential") 
  
x2 = [1,2,3,4,5,6,7,8,9,10]  
y2 = [0.007000,0.008000,0.010000,0.010000,0.012000,0.018000,0.017000,0.026000,0.028000,0.029000]
plt.plot(x2, y2, label = "Cube") 
  

x3 = [1,2,3,4,5,6,7,8,9,10]  
y3 =  [0.001000,0.002000,0.004000,0.006000,0.008000,0.008000,0.012000,0.016000,0.034000,0.041000]
plt.plot(x3, y3, label = "CRCW") 
  
# naming the x axis 
plt.xlabel('Order of Matrices') 
# naming the y axis 
plt.ylabel('Runnnig time (*1000)') 
# giving a title to my graph 
plt.title('Order of Matrices vs Running time') 
  
# show a legend on the plot 
plt.legend() 
  
# function to show the plot 
plt.show()
