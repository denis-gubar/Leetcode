# Write your MySQL query statement below
WITH Data as
(SELECT transactions_count, COUNT(*) visits_count
  FROM
(SELECT COUNT(Transactions.user_id) transactions_count
  FROM Visits LEFT JOIN Transactions
    ON Visits.user_id = Transactions.user_id
   AND Visits.visit_date = Transactions.transaction_date
 GROUP BY Visits.user_id, Visits.visit_date) data
 GROUP BY transactions_count)
SELECT Possible_Counts.transactions_count,
       COALESCE(visits_count, 0) visits_count
  FROM (SELECT ROW_NUMBER() OVER () - 1 transactions_count
  FROM (SELECT 1 FROM Transactions
       UNION ALL
       SELECT 1) x) Possible_Counts LEFT JOIN Data
 USING (transactions_count)
 WHERE Possible_Counts.transactions_count <= COALESCE((SELECT MAX(transactions_count) FROM Data), 0)
 