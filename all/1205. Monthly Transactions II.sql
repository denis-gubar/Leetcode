# Write your MySQL query statement below
SELECT month,
       country,
       SUM(approved_count) approved_count,
       SUM(approved_amount) approved_amount,
       SUM(chargeback_count) chargeback_count,
       SUM(chargeback_amount) chargeback_amount
  FROM
(SELECT CAST(trans_date as CHAR(7)) month, 
       country,
       CASE
         WHEN state = 'approved' THEN 1
         ELSE 0
       END approved_count,
       CASE
         WHEN state = 'approved' THEN amount
         ELSE 0
       END approved_amount,
       0 chargeback_count,
       0 chargeback_amount
  FROM Transactions
 UNION ALL
SELECT CAST(Chargebacks.trans_date as CHAR(7)) month, 
       country,
	   0 approved_count,
	   0 approved_amount,
       1 chargeback_count,
       amount chargeback_amount             
  FROM Transactions INNER JOIN Chargebacks
    ON Transactions.id = Chargebacks.trans_id) data
 GROUP BY month, country
HAVING SUM(approved_count) != 0 OR
       SUM(approved_amount) != 0 OR
       SUM(chargeback_count) != 0 OR
       SUM(chargeback_amount)