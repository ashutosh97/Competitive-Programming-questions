import random
process_queue = []
total_wtime = 0
n = 10
print 'Input : '
print 'ProcessName\tArrivalTime\tBurstTime'
for i in xrange(n):
    process_queue.append([])#append a list object to the list
    process_queue[i].append(i+1)
    process_queue[i].append(random.randint(0,51))
    process_queue[i].append(random.randint(1,11))
    process_queue[i].append(process_queue[i][1])
    print process_queue[i][0],'\t\t',process_queue[i][1],'\t\t',process_queue[i][2]
	

process_queue.sort(key = lambda process_queue:process_queue[1])
exe=process_queue[0][1]+process_queue[0][2];
for j in xrange(n-1):
	i=j+1
	if exe < process_queue[i][1]:
		exe=process_queue[i][1]+process_queue[i][2]
	else:
		process_queue[i][3]=exe
		exe=exe+process_queue[i][2]

print 'Output : '
print 'ProcessName\tArrivalTime\tBurstTime\tExecutionStartTime'
for i in xrange(n):
    print process_queue[i][0],'\t\t',process_queue[i][1],'\t\t',process_queue[i][2],'\t\t',process_queue[i][3]
