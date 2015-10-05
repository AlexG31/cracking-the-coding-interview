# read from input and filter out pojxxxx

import codecs;

## functions
def find_pojnums(str):
    ## return a list of pojxxxx
    pojs=str.split("poj")
    nums=list()
    for pnstr in pojs:
        ## at least have 4 characters
        if len(pnstr)<4:
            continue
        if pnstr[0].isdigit() and pnstr[1].isdigit() and pnstr[2].isdigit() and pnstr[3].isdigit():
            num=int(pnstr[0:4])
            #print 'poj:',num
            nums.append(num)

    return nums
fpin=codecs.open("input1.txt","r","gbk");
fpout=codecs.open("output1.txt","w","utf-8")
fp_solved=codecs.open('SolvedID.txt',"r",'utf-8')

debug_cnt=10
problem_cnt=0

#get solved problem list
solved_problems=list()
matched_pid=list()
for str in fp_solved:
    snum=str.split()
    for num in snum:
        solved_problems.append(int(num))

for str in fpin:
    if debug_cnt<0:
        break
    #debug_cnt-=1

    nums=find_pojnums(str)

    #write to output file
    if(len(nums)>0):
        fpout.write('\r\n'*2+str)
    for num in nums:
        #check if solved
        if num in solved_problems:
            print 'Solved',num
            matched_pid.append(num)
            #skip the solved problems
            continue
        problem_cnt+=1
        fpout.write('poj%04d\r\n'%num)

print 'Total Number of Problems:',problem_cnt
print 'Total Number of Solved Problems in this list:',len(matched_pid)

fpin.close()
fpout.close()
fp_solved.close()
