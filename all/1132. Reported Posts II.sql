# Write your MySQL query statement below
SELECT ROUND(AVG(daily_percent), 2) average_daily_percent
  FROM
(SELECT action_date,
        COALESCE(SUM(CASE WHEN post_id IN (SELECT post_id FROM Removals) THEN 1
        ELSE 0
        END * 100)  / count(distinct post_id), 0) daily_percent
  FROM 
 (SELECT DISTINCT action_date, post_id FROM Actions
 WHERE action = 'report' and extra = 'spam') D_Actions 
 GROUP BY action_date) data