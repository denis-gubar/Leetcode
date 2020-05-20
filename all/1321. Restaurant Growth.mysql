# Write your MySQL query statement below
SELECT visited_on, amount, ROUND(amount / 7, 2) average_amount
  FROM
(SELECT visited_on, 
       amount + 
       lag(amount) over (order by visited_on) +
       lag(amount, 2) over (order by visited_on) +
       lag(amount, 3) over (order by visited_on) +
       lag(amount, 4) over (order by visited_on) +
       lag(amount, 5) over (order by visited_on) +
       lag(amount, 6) over (order by visited_on) amount
  FROM
(SELECT visited_on, SUM(amount) amount
  FROM Customer
 GROUP BY visited_on) data) data
 WHERE amount IS NOT NULL