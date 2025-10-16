# Write your MySQL query statement below
SELECT num
  FROM
((SELECT num
  FROM my_numbers
 GROUP BY num
HAVING COUNT(*) = 1
 ORDER BY num DESC
 LIMIT 1)
 UNION ALL
SELECT cast(NULL as SIGNED) num) data
LIMIT 1