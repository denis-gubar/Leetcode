# Write your MySQL query statement below
SELECT Id,
       Company, 
       AVG(Salary) Salary
  FROM
(SELECT Id,
       Company, 
       Salary,
       ROW_NUMBER() OVER (PARTITION BY Company ORDER BY Salary) i,
       COUNT(*) OVER (PARTITION BY Company) x
  FROM Employee) data
 WHERE abs((x + 1) / 2 - i) < 1
GROUP BY Id, Company