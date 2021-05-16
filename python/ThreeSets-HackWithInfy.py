def modS1():
    noo = 0
    c12 = 0
    c13 = 0
    if(len(s1) != 0):
        m1 = max(s1)
        for i in range(1,m1+1):
            if i in s2:     c12 += 1
            if i in s3:     c13 += 1
        if(len(s1) < c12 and len(s1) > c13):
            for i in s1:
                s2.append(i)
                noo +=1
                s1.remove(i)
            for i in s3:
                if i< m1:
                    s2.append(i)
                    noo += 1
                    s3.remove(i)
        elif(len(s1) >= c12 and len(s1) <= c13):
            for i in s2:
                if i < m1:
                    s1.append(i)
                    noo += 1
                    s2.remove(i)
            for i in s3:
                if i < m1:
                    s1.append(i)
                    noo += 1
                    s3.remove(i)
    return noo

def modS3():
    noo = modS1()
    c23 = 0
    if(len(s3) != 0):
        m2 = min(s3)
        for i in range(m2, n+1):
            if i in s2:
                c23 += 1
        if(len(s3) <= c23):
            for i in s3:
                s2.append(i)
                noo += 1
                s3.remove(i)
        else:
            for i in s2:
                if i > m2:
                    s3.append(i)
                    noo += 1
                    s2.remove(i)
    return noo
                    
n = int(input())
n1 = int(input())
s1 = [int(input()) for i in range(n1)]
n2 = int(input())
s2 = [int(input()) for i in range(n2)]
n3 = int(input())
s3 = [int(input()) for i in range(n3)]
noo = modS3()

print(noo)            

