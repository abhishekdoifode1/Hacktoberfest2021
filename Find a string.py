def count_substring(string, sub_string):
    count=0
    for i in range(0, len(string)-len(sub_string)+1):
        l = i
        for j in range(0, len(sub_string)):
            if string[l] == sub_string[j]:
                l +=1
                if j == len(sub_string)-1:
                    count = count + 1
                else:
                    continue
            else:
                break
            
    return count
                
                
                
        
    

