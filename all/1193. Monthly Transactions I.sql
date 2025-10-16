# Write your MySQL query statement below
SELECT CAST(trans_date as CHAR(7)) month, 
       country,
       COUNT(*) trans_count,
       SUM(CASE
             WHEN state = 'approved' THEN 1
             ELSE 0
           END) approved_count,
       SUM(amount) trans_total_amount,
       SUM(CASE
             WHEN state = 'approved' THEN amount
             ELSE 0
           END) approved_total_amount
  FROM Transactions
 GROUP BY month, country