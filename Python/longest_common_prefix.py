def longest_common_prefix(a,b,st):
    for i in range(0,len(a)):
        if st+a[i] not in b:
            break
        else:
            st=st+a[i]
    if st=="":
        val=-1
    else:
        val=b.find(st)
    
    print("Longest common prefix is "+st)

a=input("Enter the first string: ")
b=input("Enter the second string: ")
st=""
prefix = longest_common_prefix(a,b,st)        
