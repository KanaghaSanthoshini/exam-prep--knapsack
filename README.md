# exam-prep--knapsack
We have created a simple, yet highly efficient and functional system which would provide users a way to choose and 
prioritize their time spent while preparing for exams based on the weightage of topics and the correspondent time 
required to work on them. It is a system which incorporates several algorithms to solve the above problem.

Our system is in several ways a practical application of the knapsack problem where one would focus on two aspects: 
weights and values, and analyze what the maximum profit that one could carry based on the total capacity of the 
bag/sack. . In our case, weights would be time spent on each topic, values would be the weightage or score that could be 
gained from each topic and total capacity would be the total preparation time that the user still has left.
We have approached this problem using four different algorithms: brute force algorithm, dynamic programming and 
greedy algorithm where we have tried two different approaches, one where we maximize (value) weightage first 
and another where we maximize score per unit hour first (value per unit).

BRUTE FORCE ALGORITHM: 
A method of problem solving in which every possibility is examined and the best one (or a best one) is chosen. Since 
the knapsack problem does not have a huge set of combinations on a reasonable sized dataset it can be used to solve the knapsack problem and our application 
of it for optimizing exam preparation.

DYNAMIC PROGRAMMING: 
Dynamic Programming is mainly an optimization over plain recursion, which have repeated calls for same inputs. 
This simple optimization reduces time complexities from exponential to polynomial.

GREEDY ALGORITHM: 
Greedy is an algorithmic paradigm that builds up a solution piece by piece, always choosing the next piece that offers the most 
obvious and immediate benefit. So, the problems where choosing locally optimal also leads to global solution are best fit for Greedy.
All these approaches are utilized to solve our application of the knapsack problem.

<img width="269" alt="image" src="https://github.com/KanaghaSanthoshini/exam-prep--knapsack/assets/66488291/cdeab818-d1e5-44a8-9c47-17ba848bb532">
<img width="288" alt="image" src="https://github.com/KanaghaSanthoshini/exam-prep--knapsack/assets/66488291/baf4a987-7dc9-4bde-8ea4-687dab82f1a8">

Our comparative analysis was based on parameters such as time taken for each algorithm to give the requested output, the variation 
in minimum hours required to complete the task and the chapters chosen that give us the maximum marks that can be obtained.
we conclude that Brute force algorithm is the least efficient algorithm. Greedy1 algorithm works well for smaller inputs but as 
the number of inputs increases, its efficiency decreases. Dynamic programming approach gives consistent results for different input 
formats and is thus more efficient than the previous algorithms. Greedy2 algorithm is the most efficient algorithm out of all the 
above-mentioned ones and thus is one of the most widely used method for solving the Knapsack problem and its various 
applications.

Example of what the output should be:
<img width="172" alt="image" src="https://github.com/KanaghaSanthoshini/exam-prep--knapsack/assets/66488291/60d7e2ba-d027-4a9a-81c0-66244667147d">
