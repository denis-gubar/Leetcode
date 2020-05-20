# Write your MySQL query statement below
SELECT ROUND(COALESCE(AVG(session_cnt), 0), 2) average_sessions_per_user
  FROM
(SELECT COUNT(DISTINCT session_id) session_cnt
  FROM Activity
 WHERE activity_date > DATE_SUB('2019-07-27', INTERVAL 30 DAY)
 GROUP BY user_id) data