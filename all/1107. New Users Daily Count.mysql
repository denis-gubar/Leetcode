# Write your MySQL query statement below
SELECT Traffic.activity_date login_date, count(DISTINCT Traffic.user_id) user_count
  FROM Traffic
 WHERE Traffic.activity_date >= DATE_SUB('2019-06-30', INTERVAL 90 DAY)
   AND (Traffic.activity_date, Traffic.user_id) in
   (SELECT MIN(activity_date), user_id 
      FROM Traffic
     WHERE activity = 'login'
     GROUP BY user_id)
GROUP BY Traffic.activity_date
HAVING count(DISTINCT Traffic.user_id) > 0
ORDER BY Traffic.activity_date
