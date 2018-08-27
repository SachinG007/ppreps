def occurence(search_int):
    ans = 0
    search_int = int(search_int)
    l,u = map(int,input().split())
    
    for i in range(l+1,u):
        for l in str(i):
            if l == str(search_int):
                ans +=1
    return ans

num_input = int(input())
for i in range(num_input):
    print(occurence(input()))