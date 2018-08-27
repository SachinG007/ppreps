def is_palindrome(word):
    front = 0
    back = len(word) - 1
    while front< back:
        if not word[front].isalnum():
            front +=1
            continue
        if not word[back].isalnum():
            back -=1
            continue
        if word[front].lower() != word[back].lower():
            return("NO")
            break
        front +=1
        back -=1
    return("YES")

num_input = int(input())
for i in range(num_input):
    print(is_palindrome(input()))