# Write your MySQL query statement below
SELECT query_name, 
       ROUND(COALESCE(AVG(rating / position), 0), 2) quality,
       ROUND(COALESCE(
           100 * SUM(CASE
                       WHEN rating < 3 THEN 1
                       ELSE 0
                     END) /
                 COUNT(*), 
             0), 2) poor_query_percentage
  FROM Queries
 GROUP BY query_name