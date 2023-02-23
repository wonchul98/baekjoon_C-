
x1, y1, x2, y2 = map(int, input().split())
x3, y3, x4, y4 = map(int,input().split())



vt1 = [x1-x2, y1-y2]
vt2 = [x4-x2, y4-y2]
vt3 = [x3-x2, y3-y2]

vt4 = [x4-x3, y4-y3]
vt5 = [x1-x3, y1-y3]
vt6 = [x2-x3, y2-y3]
def cross(arr1,arr2):
    return arr1[0]*arr2[1] - arr1[1]*arr2[0]
    
cr1 = cross(vt1, vt2)
cr2 = cross(vt1, vt3)
cr3 = cross(vt4, vt5)
cr4 = cross(vt4, vt6)

if cr1*cr2 == 0 and cr3*cr4==0:
    if x1 == x2 and x2 == x3 and x3 == x4:
        f_min = min(y1, y2)
        f_max = max(y1, y2)
        s_min = min(y3, y4)
        s_max = max(y3, y4)
            
    else:
        f_min = min(x1, x2)
        f_max = max(x1, x2)
        s_min = min(x3, x4)
        s_max = max(x3, x4)
    if((f_max >= s_min)and(s_max >= f_min)) :
        #print("first")
        print(1)
        exit()
    else:
        #print("second")
        print(0)
        exit()
        
if cr1*cr2 <= 0 and cr3*cr4<=0:
    print(1)
        
else:
    print(0)
        


