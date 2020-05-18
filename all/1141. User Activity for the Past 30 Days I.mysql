# Write your MySQL query statement below
SELECT activity_date day, count(DISTINCT user_id) active_users
  FROM Activity
 WHERE activity_date > DATE_SUB('2019-07-27', INTERVAL 30 DAY)
GROUP BY activity_date
