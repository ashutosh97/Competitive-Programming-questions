
def solve(n, t, p) : 
    
    s = list(p) 
 
    for i in range(0, t) : 
      
        for j in range(0, n - 1) :      

            if (s[j] == 'B' and
                s[j + 1] == 'G') : 
                  
                temp = s[j]; 
                s[j] = s[j + 1]; 
                s[j + 1] = temp; 
                j = j + 1    
                  
    print (''.join(s)) 
  

n = 6
t = 2
p = "BBGBBG"
solve(n, t, p) 
