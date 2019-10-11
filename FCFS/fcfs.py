process_queue = []
total_wtime = 0
n = int(raw_input('Enter number of process: '))
for i in xrange(n):
    process_queue.append([])#append a list object to the list
    process_queue[i].append(i+1)
    process_queue[i].append(int(raw_input('Enter p_arrival: ')))
    while process_queue[i][1]>50 or process_queue[i][1]<0:
    	process_queue[i][1]=int(raw_input('Enter p_arrival(Should be between 0-50 sec): '))
    total_wtime += process_queue[i][1]
    process_queue[i].append(int(raw_input('Enter p_bust: ')))
    while process_queue[i][2]>10 or process_queue[i][2]<0:
    	process_queue[i][2]=int(raw_input('Enter p_burst(Should be between 0-10 msec): '))
    process_queue[i].append(process_queue[i][1])
    print ''
    
process_queue.sort(key = lambda process_queue:process_queue[1])
exe=process_queue[0][1]+process_queue[0][2];
for j in xrange(n-1):
	i=j+1
	if exe < process_queue[i][1]:
		exe=process_queue[i][1]+process_queue[i][2]
	else:
		process_queue[i][3]=exe
		exe=exe+process_queue[i][2]

 
print 'ProcessName\tArrivalTime\tBurstTime\tExecutionStartTime'
for i in xrange(n):
    print process_queue[i][0],'\t\t',process_queue[i][1],'\t\t',process_queue[i][2],'\t\t',process_queue[i][3]
     
print 'Total waiting time: ',total_wtime
print 'Average waiting time: ',(total_wtime/n)
