# Write your MySQL query statement below
SELECT 'failed' period_state, 
       MIN(fail_date) start_date, 
       MAX(fail_date) end_date
  FROM
(SELECT fail_date, 
       DATEDIFF(fail_date, '2019-12-31') - 
       CAST(ROW_NUMBER() OVER (ORDER BY fail_date) AS SIGNED) y
  FROM Failed
 WHERE fail_date BETWEEN '2019-01-01' AND '2019-12-31') data
 GROUP BY y
UNION ALL
SELECT 'succeeded' period_state, 
       MIN(success_date) start_date, 
       MAX(success_date) end_date
  FROM
(SELECT success_date, 
       DATEDIFF(success_date, '2019-12-31') - 
       CAST(ROW_NUMBER() OVER (ORDER BY success_date) AS SIGNED) y
  FROM Succeeded
 WHERE success_date BETWEEN '2019-01-01' AND '2019-12-31') data
 GROUP BY y
 ORDER BY 2