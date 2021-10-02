'''
TCS Codevita Question, 2020
Elections are going on, and there are two candidates A and B, contesting with each other. There is a queue of voters and in this queue some of them are supporters of A and some of them are supporters of B. Many of them are neutral. The fate of the election will be decided on which side the neutral voters vote. Supporters of A and supporters of B make attempt to win the votes of neutral voters.
The way this can be done is explained below:
1. The voter queue is denoted by three characters, viz {-, A, B}. The - denotes neutral candidate, A denotes supporter of candidate A and B denotes supporter of candidate B.
2. Supporters of A can only move towards the left side of the queue.
3. Supporters of B can only move towards the right side of the queue.
4. Since time is critical, supporters of both A and B will move simultaneously.
5. They both will try and influence the neutral voters by moving in their direction in the queue. If supporter of A reaches the neutral voter before supporter of B reaches him, then that neutral voter will become a supporter of candidate A.
6. Similarly, if supporter of B reaches the neutral voter before supporter of A reaches him, then that neutral voter will become a supporter of candidate B.
7. Finally, if both reach at the same time, the voter will remain neutral. A neutral vote cannot decide the outcome of the election.
8. If finally, the queue has more votes for candidate A, then A wins the election. If B has more votes, then B wins that election. If both have equal votes, then it will be a coalition government.
Refer Examples section for understanding the dynamics of how the supporters influence the neutral voters.
Your task is to find the outcome of the election.
Note: There are no test cases where all votes are neutral.
Constraints
1 <= length of queue <= 10 ^ 5
Input
First line contains an integer which is length of queue of voters.
Second line contains characters {-, A, B}, in which denotes
· A = voter who is supporter of candidate A
· B = voter who is supporter of candidate B
· - = neutral voter
Output
Print candidate with maximum number of votes. If they have equal number of votes, print “Coalition government“.
Time Limit
1
Examples:-------------------------------
Example 1
Input
14
--AB--AB---A--
Output
A
Explanation:
For starting positions where there is no opposition from supporter of B, supporter of A can promote in left side of the queue. The voting queue will then look like below:
A A A B - - A B - - - A - -
From 4th place (in voting queue) B supporter is moving towards the right side, simultaneously 7th placed A supporter is also moving towards the left side. Then the voting queue will look like below:
A A A B B A A B - - - A - -
From 8th place B supporter is moving towards the right side, simultaneously 12th placed A supporter is also moving towards the left side. Then the voting queue will look like below:
A A A B B A A B B - A A - -
Since supporters of both A and B will reach the 10th voter at the same time, 10th voter will remain neutral.
Since supporter of A at 12th place cannot move towards right, last 2 voters will not be influenced and remain neutral. Then the voting queue will look like below:
A A A B B A A B B - A A - -
Since all voter have now cast their votes, election results can now be declared.
So final result is: A A A B B A A B B - A A - -
A has 7 votes, B has 4 votes hence, A wins the election.
Example 2
Input
4
A---
Output
A
Explanation:
Since supporter of A at 1st place cannot move towards right, last 3 voters will not be influenced and will remain neutral. Then the voting queue will look like below:
A - - -
Since all voter have now cast their votes, election results can now be declared.
So final result is: A - - -
A has 1 vote, B has 0 votes hence, A wins the election.
Example 3
Input
5
A---B
Output
Coalition government
Explanation:
Since supporter of A at 1st place cannot move towards right, supporter of B at 5th cannot move towards left, middle 3 voters will not be influenced and will remain neutral. Then the voting queue will look like below:
A - - - B
So final result is: A - - - B
A has 1 vote, B has 1 vote hence, output will be “Coalition government“.
'''


n=int(input())
i=list(input())
ac=bc=temp=0
latest=[0]
for j in range(n):
    if (i[j]=="A" or i[j]=="B"):
        latest.append(i[j])
    if i[j] == "A":
        if (j-1) >= 0:
            if (i[j-1] == "-" and (latest[-2] == "A" or latest[-2] == 0)):
                ac+=temp+1    
            else:
                ac+=1
        else:
            ac+=1
        temp=0
    elif i[j] == "B":
        if  j-1 >=0:
            if i[j-1] == "-" and latest[-2] == "B":
                bc+=temp+1
            else:
                bc+=1
        else:
            bc+=1
        temp=0
    else:
        temp+=1
        
if((i[-1]=="-") and (latest[-1]=="B")):
    bc+=temp
if ac>bc:
    #print("WINNER --> A ,by --",ac-bc,"vote(s)")
    print("A")
elif bc>ac:
    #print("WINNER --> B , by --",bc-ac,"vote(s)")
    print("B")
else:
    print("Coalition government")
