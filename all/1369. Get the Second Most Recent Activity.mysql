# Write your MySQL query statement below
SELECT username,
       COALESCE(prev_max_activity, max_activity) activity,
       COALESCE(prev_max_startDate, max_startDate) startDate, 
       COALESCE(prev_max_endDate, max_endDate) endDate
  FROM
(SELECT username,
       MAX(activity) OVER (PARTITION BY username) max_activity, 
       LAG(activity) OVER (PARTITION BY username) prev_max_activity, 
       startDate, 
       MAX(startDate) OVER (PARTITION BY username) max_startDate,
       LAG(startDate) OVER (PARTITION BY username) prev_max_startDate,
       MAX(endDate) OVER (PARTITION BY username) max_endDate,
       LAG(endDate) OVER (PARTITION BY username) prev_max_endDate
  FROM UserActivity) data
 WHERE startDate = max_startDate