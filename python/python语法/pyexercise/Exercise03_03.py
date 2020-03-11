import math

x1, y1 = 35.2270869,-80.8431267 # Charlotte
x2, y2 = 32.0835407,-81.0998342 # Savannah
x3, y3 = 28.5383355,-81.3792365 # Orlando
x4, y4 = 33.7489954,-84.3879824 # Atlanta

d1 = 6371.01 * math.acos(math.sin(math.radians(x1)) * math.sin(math.radians(x2)) +
      math.cos(math.radians(x1)) * math.cos(math.radians(x2)) * 
      math.cos(math.radians(y1 - y2)))

d2 = 6371.01 * math.acos(math.sin(math.radians(x3)) * math.sin(math.radians(x2)) +
      math.cos(math.radians(x3)) * math.cos(math.radians(x2)) * 
      math.cos(math.radians(y3 - y2)))

d3 = 6371.01 * math.acos(math.sin(math.radians(x3)) * math.sin(math.radians(x4)) +
      math.cos(math.radians(x3)) * math.cos(math.radians(x4)) * 
      math.cos(math.radians(y3 - y4)))

d4 = 6371.01 * math.acos(math.sin(math.radians(x1)) * math.sin(math.radians(x4)) +
      math.cos(math.radians(x1)) * math.cos(math.radians(x4)) * 
      math.cos(math.radians(y1 - y4)));

d5 = 6371.01 * math.acos(math.sin(math.radians(x4)) * math.sin(math.radians(x2)) +
      math.cos(math.radians(x4)) * math.cos(math.radians(x2)) * 
      math.cos(math.radians(y4 - y2)));

s = (d1 + d4 + d5) / 2
area1 = math.sqrt(s * (s - d1) * (s - d4) * (s - d5))

s = (d2 + d3 + d5) / 2
area2 = math.sqrt(s * (s - d2) * (s - d3) * (s - d5))

print("The area is", area1 + area2, "square kilometers")
