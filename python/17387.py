
x1, y1, x2, y2 = map(int, input().split())
x3, y3, x4, y4 = map(int,input().split())
vt1 = [x1-x2, y1-y2]
vt2 = [x4-x2, y4-y2]
vt3 = [x3-x2, y3-x2]
def cross(arr1,arr2):
    return arr1[0]*arr2[1] - arr1[1]*arr2[0]
    
cr1 = cross(vt1, vt2)
cr2 = cross(vt1, vt3)
print(cr1)
print(cr2)

if cr1*cr2 <= 0 : print(1)
else:print(0)
